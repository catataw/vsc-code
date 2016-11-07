#pragma once
#ifndef _PSMOVES_H_
#define _PSMOVES_H_
extern int do_init;
//获取到基站的数量(摄像头)
//@return int 
#define ID_GET_BASESATION_COUNT	10000

//获取到当前已连接的手柄的数量
//@return int 
#define ID_GET_CONTROLLER_COUNT	10001

//基站(摄像头)是否连接
//@param[input] int id
//@return int
#define ID_BASESATION_IS_CONNECT 10002


//Psmove是否连接是否连接
//@param[input] int id
//@return int
#define ID_CONTROLLER_IS_CONNECT 10003


//获取去所有的手柄的空间数据
//四元数,空间位置,数据是否有效,设备是否连接
#define ID_GET_ALL_DATA 10004

typedef struct {
	unsigned long id;
	unsigned long data_length;
	char *data;
}package;

extern int *function[0xffff];

typedef void (*f)(unsigned long data_size, void *data);

int register_function(unsigned long id, void *function);

/**
 *brief			注册所有函数
 */
void register_all();

package *package_new(unsigned long id,unsigned long data_length,char *data);

void package_object_to_buffer(package *src,char *aim,int *len);

void *package_buffer_to_object(package *out, char *buffer);

void package_free(package *A);



/**
 *brief			获取到基站的数量(摄像头)
 */
int id_get_basesation_count(unsigned long data_size, void *data);

int id_get_controller_count(unsigned long data_size, void *data);

int id_basesation_is_connect(unsigned long data_size, void *data);

int id_controller_is_connect(unsigned long data_size, void *data);

int id_get_all_data(unsigned long data_size, void *data);



#endif