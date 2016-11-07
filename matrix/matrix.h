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
 * 初始化矩阵
 * @参数[输入] width 矩阵宽度
 * @参数[输入] height 矩阵高度
 * @return NUUL=失败,非NULL=成功
 * @ref matrix.h
 * @note 本函数并不对 matrix *a_matrix 申请内存,只针对里面的数据结构申请内存
 * 使用matrix_init之前需要申请内存。例:
 * matrix *a_matrix = (matrix *)malloc(sizeof(matrix));
 * matrix_init(a_matrix,3,3);//初始化的矩阵为3x3
 * 或者
 * matrix a_array;
 * matrix_init(&a_array,3,3);//初始化的矩阵为3x3
 * @see 详见
 */
BOOL *matrix_init(matrix *a_matrix,unsigned int width,unsigned int height);


void matrix_free(matrix *a_matrix);


void matrix_uninit(matrix *a_matrix);


BOOL matrix_set(matrix *a_matrix,...);


matrix *matrixx_mul(matrix *a,matrix *b);


matrix *matrixx_add(matrix *a,matrix *b);


matrix *matrixx_subtract(matrix *a,matrix *b);

#endif
