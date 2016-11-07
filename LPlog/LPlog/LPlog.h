
///////////////////////////////////////////////////////////////
//Log���¼�ڳ������й����е�һ��״̬
//
//
//globalLogʵ����Log���ȫ�ֶ���
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
	* bried		���׼����д���ַ���
	* return		��
	*/
	inline void logWriteStdout(const string &s){cout<<s;}
	/**
	* brief		�ı�����ļ�
	* return		��
	*/
	inline void changeName(const string &s){Name = s;}
	/**
	* brief		����־д��s
	* return		д��ɹ�����1��ʧ�ܷ���0
	*/
	bool logWriteFile(const string &s);
};

//ȫ����־�ļ�
extern Log globalLog;

/**
 * brief			�����������λ�Ӻ󣬵���LogWriteFile
 */
void transform(string s);

#endif // !__LPLOG_H__
