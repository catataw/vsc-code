#include "LPlog.h"

Log globalLog("log.txt");
string address;
int tempLine;
string tempFunc;

bool Log::logWriteFile(const string &s)
	{
		ofstream File(Name, ios::app);//以追加的方式打开文件
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
	ofstream File(globalLog.Name, ios::app);//以追加的方式打开文件
	File <<"在"<<address<<"第"<<tempLine<<"行，函数"<<tempFunc<<":";
	File.close();
	
	globalLog.logWriteFile(s);
}
