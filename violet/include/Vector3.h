#ifndef __VECTOR3_H_INCLUDE__
#define __VECTOR3_H_INCLUDE__

#include<cmath>
#include<cstdio>
typedef double VType;

class Vector3 {
public:
	VType x, y, z;


//构造函数
	//默认构造 
	Vector3() {}
	//复制构造函数 
	Vector3(const Vector3 &a) :x(a.x), y(a.y), z(a.x) {}
	//带参数的构造函数 
	Vector3(VType nx, VType ny, VType nz) :x(nx), y(ny), z(nz) {}


//标准对象操作
	//重载赋值=
	Vector3 &operator =(const Vector3 &a);
	//重载==
	bool operator ==(const Vector3 &a) const;
	//重载！=
	bool operator !=(const Vector3 &a) const;


//向量运算	
	//置为零向量
	inline void zero() { x = y = z = 0.0; }
	/**
	 * brief		重载二元+
	 * suchas	b+a
	 * return	一个新的Vector3对象
	 */
	Vector3 operator +(const Vector3 &a) const;

	/** 
	 * brief		重载二元-
	 * suchas	b-a
	 * return	一个新的Vector3对象
	 */
	Vector3 operator -(const Vector3 &a) const;

	/**
	 * brief		与标量的乘除
	 * suchas		b*a
	 * return		一个新的Vector3
	 */
	Vector3 operator *(VType a) const;

	/**
	 * brief			与标量的除法
	 * suchas		b/a
	 * return		一个新的Vector3
	 */
	Vector3 operator /(VType a) const;

	//重载自反运算符+= -= /= *=
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
	 * brief		b*=a,a是一个标量
	 * return	*this
	 */
	Vector3 &operator *=(VType a);

	/**
	 * brief		b/=a,a是一个标量
	 * return	*this
	 */
	Vector3 &operator /=(VType a);


	//向量单位化
	void normalize();

	/**
	 * brief		b*a向量点乘
	 * return	一个VType的数
	 */
	VType operator *(const Vector3 &a) const;
};
//非成员函数

/**
 * brief		变量左乘
 * param k		标量
 * param v		引用一个Vector3对象
 * return		一个新的Vector3对象
 */
Vector3 operator *(VType k, const Vector3 &v);
/**
 * brief		求向量模 
 * param a		引用一个Vector3对象
 * return		一个VType标量
 */
VType vector3Mag(const Vector3 &a);
/**
 * brief		叉乘
 * param a		引用一个Vector3对象
 * param b		引用一个Vector3对象
 * return		一个新的Vector3
 */
Vector3 vector3CrossProduct(const Vector3 &a, const Vector3 &b);
/**
 * brief		两点间的距离
 * param a		引用一个Vector3对象
 * param b		引用一个Vector3对象
 * return		一个VType标量
 */
VType vector3Distance(const Vector3 &a, const Vector3 &b);
/**
 * brief		打印向量
 * param		引用一个Vector3对象
 * return		空
 */
void vector3Print(const Vector3 &a);

#endif // !