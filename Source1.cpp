#include <iostream>

class Vector3D {
public:
	float x, y, z;
public:
	Vector3D() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
	Vector3D(const float&_x, const float &_y, const float &_z) :x(_x),y(_y),z(_z)
	{}
	Vector3D & operator=(const Vector3D & rhs)
	{
		this->x=rhs.x;
		this->y=rhs.y;
		this->z=rhs.z;
		return *this;
	}
	friend Vector3D operator+(Vector3D & Uns,const Vector3D & rhs)
	{
		Uns.x += rhs.x;
		Uns.y += rhs.y;
		Uns.z += rhs.z;
		return Uns;
	}
	friend float operator*(Vector3D & Uns, const Vector3D & rhs)
	{
		float result = 0.0f;
		result = Uns.x * rhs.x;
		result += Uns.y * rhs.y;
		result += Uns.z * rhs.z;
		return result;
	}
	friend std::ostream& operator<<(std::ostream& stream, const Vector3D obj);
};
class Matrix3x3
{
public:
	Vector3D vec_1;
	Vector3D vec_2;
	Vector3D vec_3;
public:
	Matrix3x3(const Vector3D &_vec1, const Vector3D &_vec2, const Vector3D &_vec3)
		:vec_1(_vec1),vec_2(_vec2),vec_3(_vec3)
	{}
	Matrix3x3()
	{
		vec_1 = Vector3D(0, 0, 0);
		vec_2 = Vector3D(0, 0, 0);
		vec_3 = Vector3D(0, 0, 0);
	}
	friend std::ostream& operator<<(std::ostream& stream, const Matrix3x3 obj);
	friend Vector3D operator*(Matrix3x3& Uns, const Vector3D & rhs)
	{
		Vector3D result;
		result.x = Uns.vec_1*rhs;
		result.y = Uns.vec_2*rhs;
		result.z = Uns.vec_3*rhs;
		return result;
	}
	friend Matrix3x3 operator*(Matrix3x3& Uns, const Matrix3x3 & rhs)
	{
		
		Vector3D _vec1(rhs.vec_1.x,rhs.vec_2.x,rhs.vec_3.x);
		Vector3D _vec2(rhs.vec_1.y, rhs.vec_2.y, rhs.vec_3.y);
		Vector3D _vec3(rhs.vec_1.z, rhs.vec_2.z, rhs.vec_3.z);

		_vec1 = Uns*_vec1;
		_vec2 = Uns*_vec2;
		_vec3 = Uns*_vec3;

		Vector3D _vec_1(_vec1.x, _vec2.x, _vec3.x);
		Vector3D _vec_2(_vec1.y, _vec2.y, _vec3.y);
		Vector3D _vec_3(_vec1.z, _vec2.z, _vec3.z);

		Matrix3x3 result(_vec_1, _vec_2, _vec_3);
		return result;
	}
};

std::ostream& operator<<(std::ostream &stream, const Matrix3x3 obj)
{
	stream << obj.vec_1 << '\n' << obj.vec_2 << '\n' << obj.vec_3;
	return stream;
}


std::ostream& operator<<(std::ostream &stream,const Vector3D obj) 
{
	stream << obj.x << " " << obj.y << " " << obj.z << std::endl;
	return stream;
}

int main() 
{
	Vector3D a(100,200,45), b, c(2,3,2);
	b = Vector3D(1, 1, 1);
	float k = a * b;
	std::cout << k << std::endl;

	Matrix3x3 matrix3d_1(a, b, c);
	Matrix3x3 matrix3d_2(b, a, c);
	std::cout << matrix3d_1*matrix3d_2 << std::endl;
	return 0;
}