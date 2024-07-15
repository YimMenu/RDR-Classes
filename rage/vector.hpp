#pragma once
#include <cmath>

#pragma pack(push, 0x10)
namespace rage
{
	template<typename T>
	class vector2
	{
	public:
		T x, y;

		constexpr vector2(T x, T y) :
			x(x),
			y(y)
		{
		}

		constexpr vector2() :
			x(),
			y()
		{
		}
	};

	template<typename T>
	class vector3
	{
	public:
		T x, y, z;

		constexpr vector3(T x, T y, T z) :
			x(x),
			y(y),
			z(z)
		{
		}

		constexpr vector3() :
			x(),
			y(),
			z()
		{
		}

		template<typename T>
		bool operator==(const vector3<T>& other) const
		{
			return this->x == other.x && this->y == other.y && this->z == other.z;
		}

		template<typename T>
		bool operator!=(const vector3<T>& other) const
		{
			return this->x != other.x || this->y != other.y || this->z != other.z;
		}
	};

	template<typename T>
	class vector4
	{
	public:
		T x, y, z, w;

		constexpr vector4(T x, T y, T z, T w) :
			x(x),
			y(y),
			z(z),
			w(w)
		{
		}

		constexpr vector4() :
			x(),
			y(),
			z(),
			w()
		{
		}
	};

	template<typename T>
	union matrix34
	{
		T data[3][4];
		struct { struct { T x, y, z, w; } rows[3]; };
	};

	template<typename T>
	union matrix44
	{
		T data[4][4];
		struct { struct { T x, y, z, w; } rows[4]; };
	};

	typedef vector2<float> fvector2;
	typedef vector4<float> fvector4;
	typedef matrix34<float> fmatrix34;
	typedef matrix44<float> fmatrix44;

	class fvector3 : public vector3<float>
	{
		using vector3::vector3;

		fvector3 operator+(const fvector3& other) const
		{
			fvector3 vec;
			vec.x = this->x + other.x;
			vec.y = this->y + other.y;
			vec.z = this->z + other.z;
			return vec;
		}

		fvector3 operator-(const fvector3& other) const
		{
			fvector3 vec;
			vec.x = this->x - other.x;
			vec.y = this->y - other.y;
			vec.z = this->z - other.z;
			return vec;
		}

		fvector3 operator*(const fvector3& other) const
		{
			fvector3 vec;
			vec.x = this->x * other.x;
			vec.y = this->y * other.y;
			vec.z = this->z * other.z;
			return vec;
		}

		fvector3 operator*(const float& other) const
		{
			fvector3 vec;
			vec.x = this->x * other;
			vec.y = this->y * other;
			vec.z = this->z * other;
			return vec;
		}

		inline float GetMagnitude() const
		{
			return std::sqrt(x * x + y * y + z * z);
		}

		inline float GetDistance(const rage::fvector3& other) const
		{
			return (*this - other).GetMagnitude();
		}
	};
}
#pragma pack(pop)