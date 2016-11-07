#pragma once
#ifndef _PSMOVES_H_
#define _PSMOVES_H_
extern int do_init;
//��ȡ����վ������(����ͷ)
//@return int 
#define ID_GET_BASESATION_COUNT	10000

//��ȡ����ǰ�����ӵ��ֱ�������
//@return int 
#define ID_GET_CONTROLLER_COUNT	10001

//��վ(����ͷ)�Ƿ�����
//@param[input] int id
//@return int
#define ID_BASESATION_IS_CONNECT 10002


//Psmove�Ƿ������Ƿ�����
//@param[input] int id
//@return int
#define ID_CONTROLLER_IS_CONNECT 10003


//��ȡȥ���е��ֱ��Ŀռ�����
//��Ԫ��,�ռ�λ��,�����Ƿ���Ч,�豸�Ƿ�����
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
 *brief			ע�����к���
 */
void register_all();

package *package_new(unsigned long id,unsigned long data_length,char *data);

void package_object_to_buffer(package *src,char *aim,int *len);

void *package_buffer_to_object(package *out, char *buffer);

void package_free(package *A);



/**
 *brief			��ȡ����վ������(����ͷ)
 */
int id_get_basesation_count(unsigned long data_size, void *data);

int id_get_controller_count(unsigned long data_size, void *data);

int id_basesation_is_connect(unsigned long data_size, void *data);

int id_controller_is_connect(unsigned long data_size, void *data);

int id_get_all_data(unsigned long data_size, void *data);



#endif