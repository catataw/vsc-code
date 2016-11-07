//+------------------------------------------------------------------+
//|                                    MetaTrader Manager API Sample |
//|                 Copyright � 2001-2005, MetaQuotes Software Corp. |
//|                                         http://www.metaquotes.ru |
//+------------------------------------------------------------------+
unit Sample;
interface
uses Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
     StdCtrls,ManagerAPI;

//---- �������� ����� ��������
const
   SERVER     = 'localhost';                // ������, ��-��������� ���� 443
   MAN_LOGIN  = 11;                         // ����� ���������
   MAN_PASS   = 'Manager11';                // ������ ���������
   MAN_NAME   = 'Manager11';
   MAIL_BODY  = 'Please check your balance.';
   USER_MAIL  = 'some@some.ru';
   USER_PASS  = 'Som5e';
   USER_NAME  = 'ManAPI Test User';
   USER_GROUP = 'demoforex';                  // demo-������
//+------------------------------------------------------------------+
//| ����� �����                                                      |
//+------------------------------------------------------------------+
type
TForm1 = class(TForm)
//---- members
   Button1: TButton;
//---- methods
   procedure Button1Click(Sender: TObject);
end;

var
  Form1: TForm1;

implementation
{$R *.DFM}
//+------------------------------------------------------------------+
//| ���������� ������� �� ������ Test                                |
//| ���� ���������� ������ �����                                     |
//+------------------------------------------------------------------+
procedure TForm1.Button1Click(Sender: TObject);
var
  factory: TManagerFactory;
  manapi : IManagerInterface;
  err    : integer;
  user   : TUserRecord;
  money  : TTradeTransInfo;
  mail   : TMailBox;
  logins : array [0..1] of integer;
begin
  //---- �������� �������
  factory := TManagerFactory.Create('..\mtmanapi.dll');
  if factory=nil then exit;
  //---- ...� �� ��� ������� API
  manapi := factory.CreateAPI;
  if manapi=nil then
  begin
    factory.Free;
    exit;
  end;
  //---- ����������� � �������
  err:=manapi.Connect(SERVER);
  if  err<> RET_OK then
  begin
    ShowMessage('Unable connect to server: '+manapi.ErrorDescription(err));
    manapi:=nil; // ��� ���� ������ ������ ��� ������!
    factory.Free;
    exit;
  end;
  //---- ������������
  err:=manapi.Login(MAN_LOGIN,MAN_PASS);
  if err<> RET_OK then
  begin
    ShowMessage('Login failed: '+manapi.ErrorDescription(err));
    manapi.Disconnect;
    manapi:=nil;
    factory.Free;
    exit;
  end;
  //---- ������� ����
  ZeroMemory(@user,SizeOf(user));
  user.login:=0;                    // ����-��������� ������
  StrCopy(user.group,USER_GROUP);   // ������
  StrCopy(user.name,USER_NAME);     // ���
  StrCopy(user.password,USER_PASS); // ������
  StrCopy(user.email,USER_MAIL);    // e-mail
  user.leverage:=100;               // �����
  user.enable:=1;                   // ��������� ����
  err:=manapi.UserRecordNew(user);
  if err<> RET_OK then
  begin
    ShowMessage('Creating new account failed: '+manapi.ErrorDescription(err));
    manapi.Disconnect;
    manapi:=nil;
    factory.Free;
    exit;
  end;
  //---- �������� ������
  ZeroMemory(@money,SizeOf(money));
  money.trtype :=TT_BR_BALANCE;
  money.cmd    :=OP_BALANCE;
  money.orderby:=user.login; // � ������ ������ ��� ���� �/� �������
  money.price  :=10000.50;
  StrCopy(money.comment,'lucky man');
  err:=manapi.TradeTransaction(money);
  if err<> RET_OK then
  begin
    ShowMessage('Trade transaction failed: '+manapi.ErrorDescription(err));
    manapi.Disconnect;
    manapi:=nil;
    factory.Free;
    exit;
  end;
  //---- ������� ������
  //---- � ���������� �������, �������� ������ ����� �������� ��� �����
  //---- ��� ���������� ����� 
  ZeroMemory(@mail,SizeOf(mail));
  mail.sender :=MAN_LOGIN;
  StrCopy(mail.from,MAN_NAME);
  StrCopy(mail.subject,'Balance');
  logins[0]   :=user.login; // �� �������� ������ �����
  mail.fromto :=1;          // ���� ����� � �������� ���-��
  mail.body   :=pchar(MAIL_BODY);
  mail.bodylen:=StrLen(MAIL_BODY);
  err:=manapi.MailSend(mail,@logins);
  if err<> RET_OK then
  begin
    ShowMessage('Send mail failed: '+manapi.ErrorDescription(err));
    manapi.Disconnect;
    manapi:=nil;
    factory.Free;
    exit;
  end;
  //---- �� �����: ����������� ���
  ShowMessage('All tests successed.');
  manapi.Disconnect;
  manapi:=nil;
  factory.Free;
end;
end.
//+------------------------------------------------------------------+

