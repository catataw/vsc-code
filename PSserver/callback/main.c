#include "psmoves.h"
#include<Windows.h>
#include<stdio.h>

int main()
{

	char str[8]="1234567";
	command_package *p=command_package_new(1,8,str);
	command_package *q;
	char buffer[200];
	int len;

	command_package_pack(p,buffer,&len);

	q=command_package_unpack(buffer);
	printf("%d %d %s",q->id,q->data_length,q->data);
	command_package_free(p);
	while(1)Sleep(100);
	return 0;
}