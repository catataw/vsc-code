
///////////////////////////////////////////////////////////////
//Log类记录在程序运行过程中的一个状态
//
//
//globalLog实例化Log类的全局对象
///////////////////////////////////////////////////////////////

#ifndef __LPLOG_H
#define __LPLOG_H

#include<iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

extern string address;
extern int tempLine;
extern string tempFunc;
#define logWriteFile__(s) {tempLine=__LINE__;address=__FILE__;tempFunc=__FUNCTION__;transform(s);}

class Log
{
public:
	string Name;
	Log() {}
	Log(string name):Name(name){logWriteFile("\n\n\n*************************************************\n");}

	/**
	* bried		向标准流中写入字符串
	* return		无
	*/
	inline void logWriteStdout(const string &s){cout<<s;}
	/**
	* brief		改变输出文件
	* return		无
	*/
	inline void changeName(const string &s){Name = s;}
	/**
	* brief		向日志写入s
	* return		写入成功返回1，失败返回0
	*/
	bool logWriteFile(const string &s);
};

//全局日志文件
extern Log globalLog;

/**
 * brief			输入错误所在位子后，调用LogWriteFile
 */
void transform(string s);

#endif // !__LPLOG_H__
