#include "LPlog.h"

Log globalLog("log.txt");
string address;
int tempLine;
string tempFunc;

bool Log::logWriteFile(const string &s)
	{
		ofstream File(Name, ios::app);//��׷�ӵķ�ʽ���ļ�
		if (!File)
		{
			cout << "open log file error!!!\n";
			return 0;
		}
		File<< s;
		File.close();
		return true;
}

void transform(string s)
{
	ofstream File(globalLog.Name, ios::app);//��׷�ӵķ�ʽ���ļ�
	File <<"��"<<address<<"��"<<tempLine<<"�У�����"<<tempFunc<<":";
	File.close();
	
	globalLog.logWriteFile(s);
}
