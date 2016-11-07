#ifndef _MATRIX_H_
#define _MATRIX_H_


typedef struct _matrix_{
	unsigned int width;
	unsigned int height;
	float *data;
}matrix;


/*
*
*/
matrix *matrix_new(unsigned int width,unsigned int height);

/**
 * ��ʼ������
 * @����[����] width ������
 * @����[����] height ����߶�
 * @return NUUL=ʧ��,��NULL=�ɹ�
 * @ref matrix.h
 * @note ������������ matrix *a_matrix �����ڴ�,ֻ�����������ݽṹ�����ڴ�
 * ʹ��matrix_init֮ǰ��Ҫ�����ڴ档��:
 * matrix *a_matrix = (matrix *)malloc(sizeof(matrix));
 * matrix_init(a_matrix,3,3);//��ʼ���ľ���Ϊ3x3
 * ����
 * matrix a_array;
 * matrix_init(&a_array,3,3);//��ʼ���ľ���Ϊ3x3
 * @see ���
 */
BOOL *matrix_init(matrix *a_matrix,unsigned int width,unsigned int height);


void matrix_free(matrix *a_matrix);


void matrix_uninit(matrix *a_matrix);


BOOL matrix_set(matrix *a_matrix,...);


matrix *matrixx_mul(matrix *a,matrix *b);


matrix *matrixx_add(matrix *a,matrix *b);


matrix *matrixx_subtract(matrix *a,matrix *b);

#endif
