#include <iostream>

class Vector3D {
private:
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
	friend Vector3D operator+(Vector3D Uns,const Vector3D & rhs)
	{
		Uns.x += rhs.x;
		Uns.y += rhs.y;
		Uns.z += rhs.z;
		return Uns;
	}
	friend std::ostream& operator<<(std::ostream& stream, const Vector3D obj);
};

std::ostream& operator<<(std::ostream &stream,const Vector3D obj) 
{
	stream << obj.x << " " << obj.y << " " << obj.z << std::endl;
	return stream;
}

int main() 
{
	Vector3D a(1,2,3), b, c;
	b = Vector3D(4, 5, 6);
	c = a + b;
	std::cout << c << std::endl;
	return 0;
}