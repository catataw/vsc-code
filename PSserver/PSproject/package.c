#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "package.h"
#include "psmove_tracker.h"
#include<psmove.h>
int *function[0xffff];
int do_init;
int register_function(unsigned long id, void *_function) {
	if (id < 0xffff) {
		function[id] = _function;
		return 1;
	}
	else {
		return 0;
	}
}
void register_all()
{
	register_function(ID_GET_BASESATION_COUNT, id_get_basesation_count);
	register_function(ID_GET_CONTROLLER_COUNT, id_get_controller_count);
	register_function(ID_BASESATION_IS_CONNECT, id_basesation_is_connect);
	register_function(ID_CONTROLLER_IS_CONNECT, id_controller_is_connect);
	register_function(ID_GET_ALL_DATA, id_get_all_data);
}
package *package_new(unsigned long id,unsigned long data_length,char *data){
	package *a_package = NULL;
	a_package = (package *)malloc(sizeof(package));
	a_package->id = id;
	a_package->data_length = data_length;

	a_package->data = (char *)malloc(data_length);
	memcpy(a_package->data,data,data_length);
	return a_package;
}

void package_object_to_buffer(package *src,char *aim,int *len)
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
void *package_buffer_to_object(package *out,char *buffer)
{
	char *p=buffer;
	int ul=sizeof(unsigned long);
	unsigned long id = *(unsigned long *)p;
	unsigned long length;
	p+=ul;
	length = *(unsigned long *)p;
	p+=ul;
	out = package_new(id,length,p);
}
void package_free(package *A)
{
	free(A->data);
	free(A);
}

int id_get_basesation_count(unsigned long data_size, void *data)
{
	int return_int = psmove_tracker_count_connected();
}

int id_get_controller_count(unsigned long data_size, void *data)
{
	psmove_count_connected();
}

int id_basesation_is_connect(unsigned long data_size, void *data)
{
	return do_init;
}

int id_controller_is_connect(unsigned long data_size, void *data)
{
	return do_init;
}

int id_get_all_data(unsigned long data_size, void *data)
{

}

