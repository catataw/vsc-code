#ifndef __VECTOR3_H_INCLUDE__
#define __VECTOR3_H_INCLUDE__

#include<cmath>
#include<cstdio>
typedef double VType;

class Vector3 {
public:
	VType x, y, z;


//���캯��
	//Ĭ�Ϲ��� 
	Vector3() {}
	//���ƹ��캯�� 
	Vector3(const Vector3 &a) :x(a.x), y(a.y), z(a.x) {}
	//�������Ĺ��캯�� 
	Vector3(VType nx, VType ny, VType nz) :x(nx), y(ny), z(nz) {}


//��׼�������
	//���ظ�ֵ=
	Vector3 &operator =(const Vector3 &a);
	//����==
	bool operator ==(const Vector3 &a) const;
	//���أ�=
	bool operator !=(const Vector3 &a) const;


//��������	
	//��Ϊ������
	inline void zero() { x = y = z = 0.0; }
	/**
	 * brief		���ض�Ԫ+
	 * suchas	b+a
	 * return	һ���µ�Vector3����
	 */
	Vector3 operator +(const Vector3 &a) const;

	/** 
	 * brief		���ض�Ԫ-
	 * suchas	b-a
	 * return	һ���µ�Vector3����
	 */
	Vector3 operator -(const Vector3 &a) const;

	/**
	 * brief		������ĳ˳�
	 * suchas		b*a
	 * return		һ���µ�Vector3
	 */
	Vector3 operator *(VType a) const;

	/**
	 * brief			������ĳ���
	 * suchas		b/a
	 * return		һ���µ�Vector3
	 */
	Vector3 operator /(VType a) const;

	//�����Է������+= -= /= *=
	/**
	 * brief		b+=a
	 * return	*this
	 */
	Vector3 &operator +=(const Vector3 &a);

	/**
	 * brief		b-=a
	 * return	*this
	 */
	Vector3 &operator -=(const Vector3 &a);

	/**
	 * brief		b*=a,a��һ������
	 * return	*this
	 */
	Vector3 &operator *=(VType a);

	/**
	 * brief		b/=a,a��һ������
	 * return	*this
	 */
	Vector3 &operator /=(VType a);


	//������λ��
	void normalize();

	/**
	 * brief		b*a�������
	 * return	һ��VType����
	 */
	VType operator *(const Vector3 &a) const;
};
//�ǳ�Ա����

/**
 * brief		�������
 * param k		����
 * param v		����һ��Vector3����
 * return		һ���µ�Vector3����
 */
Vector3 operator *(VType k, const Vector3 &v);
/**
 * brief		������ģ 
 * param a		����һ��Vector3����
 * return		һ��VType����
 */
VType vector3Mag(const Vector3 &a);
/**
 * brief		���
 * param a		����һ��Vector3����
 * param b		����һ��Vector3����
 * return		һ���µ�Vector3
 */
Vector3 vector3CrossProduct(const Vector3 &a, const Vector3 &b);
/**
 * brief		�����ľ���
 * param a		����һ��Vector3����
 * param b		����һ��Vector3����
 * return		һ��VType����
 */
VType vector3Distance(const Vector3 &a, const Vector3 &b);
/**
 * brief		��ӡ����
 * param		����һ��Vector3����
 * return		��
 */
void vector3Print(const Vector3 &a);

#endif // !