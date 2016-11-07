#pragma once
#ifndef _PSMOVES_H_
#define _PSMOVES_H_

typedef struct {
	unsigned long id;
	unsigned long data_length;
	char *data;
}command_package;

extern void *function[255];

typedef void (*f)(unsigned long data_size, void *data);

int register_function(unsigned long id,void *function);

command_package *command_package_new(unsigned long id,unsigned long data_length,char *data);

void command_package_object_to_buffer(command_package *src,char *aim,int *len);

command_package *command_package_buffer_to_object(char *buffer);

void command_package_free(command_package *A);


void A1(unsigned long data_size, void *data);

void A2(unsigned long data_size, void *data);


#endif