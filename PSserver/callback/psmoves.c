#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "psmoves.h"

void *function[255];

int register_function(unsigned long id, void *_function) {
	if (id < 255) {
		function[id] = _function;

		return 1;
	}
	else {
		return 0;
	}
}

command_package *command_package_new(unsigned long id,unsigned long data_length,char *data){
	command_package *a_package = NULL;
	a_package = (command_package *)malloc(sizeof(command_package));
	a_package->id = id;
	a_package->data_length = data_length;

	a_package->data = (char *)malloc(data_length);
	memcpy(a_package->data,data,data_length);
	return a_package;
}

void command_package_object_to_buffer(command_package *src,char *aim,int *len)
{
	char *p;
	if(src == NULL) return;
	p = aim;
	*(unsigned long *)p = src->id;
	p += sizeof(unsigned long);

	*(unsigned long *)p = src->data_length;
	p += sizeof(unsigned long);

	memcpy(p,src->data,src->data_length);

	*len = src->data_length+2*sizeof(unsigned long);
}
command_package *command_package_buffer_to_object(char *buffer)
{
	char *p=buffer;
	int ul=sizeof(unsigned long);
	unsigned long id = *(unsigned long *)p;
	unsigned long length;
	p+=ul;
	length = *(unsigned long *)p;
	p+=ul;
	return command_package_new(id,length,p);
}
void command_package_free(command_package *A)
{
	free(A->data);
	free(A);
}


void A1(unsigned long data_size, void *data) {
	printf("A1");
}

void A2(unsigned long data_size, void *data) {
	printf("A2");
}