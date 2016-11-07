#include "Vector3.h"

Vector3& Vector3::operator =(const Vector3 &a)
{
	x = a.x;
	y = a.y;
	z = a.z;
	return *this;
}
//重载==
bool Vector3::operator ==(const Vector3 &a) const
{
	return x == a.x&&y == a.y&&z == a.z;
}
//重载！=
bool Vector3::operator !=(const Vector3 &a) const
{
	return x != a.x || y != a.y || z != a.z;
}

//向量运算	

	//重载二元+
Vector3 Vector3::operator +(const Vector3 &a) const
{
	return Vector3(x + a.x, y + a.y, z + a.z);
}
//重载二元-
Vector3 Vector3::operator -(const Vector3 &a) const
{
	return Vector3(x - a.x, y - a.y, z - a.z);
}

//与标量的乘除
Vector3 Vector3::operator *(VType a) const
{
	return Vector3(a*x, a*y, a*z);
}

Vector3 Vector3::operator /(VType a) const
{
	VType b = 1.0 / a;
	return Vector3(x*b, y*b, z*b);
}
//重载自反运算符+= -= /= *=
Vector3& Vector3::operator +=(const Vector3 &a)
{
	x += a.x; y += a.y; z += a.z;
	return *this;
}
Vector3& Vector3::operator -=(const Vector3 &a)
{
	x -= a.x; y -= a.y; z -= a.z;
	return *this;
}
Vector3& Vector3::operator *=(VType a)
{
	x *= a; y *= a; z *= a;
	return *this;
}
Vector3& Vector3::operator /=(VType a)
{
	VType b = 1.0 / a;
	(*this) *= b;
	return *this;
}
//向量单位化
void Vector3::normalize()
{
	VType magSq = x*x + y*y + z*z;
	if (magSq > 0.0f)
	{
		magSq = 1.0 / sqrt(magSq);
		x *= magSq;
		y *= magSq;
		z *= magSq;
	}
}
//向量点乘
VType Vector3::operator *(const Vector3 &a) const
{
	return x*a.x + y*a.y + z*a.z;
}
//非成员函数

//求向量模 
VType vector3Mag(const Vector3 &a)
{
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}
//叉乘
Vector3 vector3CrossProduct(const Vector3 &a, const Vector3 &b)
{
	return Vector3(
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x
	);
}
// 变量左乘
Vector3 operator *(VType k, const Vector3 &v)
{
	return Vector3(k*v.x, k*v.y, k*v.z);
}
//两点间的距离
VType vector3Distance(const Vector3 &a, const Vector3 &b)
{
	VType dx = a.x - b.x;
	VType dy = a.y - b.y;
	VType dz = a.z - b.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}
//打印向量
void vector3Print(const Vector3 &a)
{
	printf("%0.2lf %0.2lf %0.2lf\n", a.x, a.y, a.z);
}