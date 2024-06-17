#pragma once
#include <math.h>

template<class T>class Vector2Template
{
public:
	Vector2Template();
	Vector2Template(T x, T y);
	~Vector2Template();
	T x;
	T y;

	Vector2Template<T>& operator = (const Vector2Template&vec);

	T& operator [] (int i);

	bool operator == (const Vector2Template&vec)const;
	bool operator != (const Vector2Template&vec)const;
	bool operator > (const Vector2Template&vec)const;
	bool operator >= (const Vector2Template&vec)const;
	bool operator <= (const Vector2Template&vec)const;

	Vector2Template& operator +=(const Vector2Template<T>&vec);
	Vector2Template& operator -=(const Vector2Template<T>&vec);
	Vector2Template& operator *=(T k);
	Vector2Template& operator /=(T k);

	Vector2Template operator+()const;
	Vector2Template operator-()const;
};

template<class T>
Vector2Template<T> operator+(const Vector2Template<T>&u, T v);
template<class T>
Vector2Template<T> operator-(const Vector2Template<T>&u, T v);
template<class T>
Vector2Template<T> operator*(const Vector2Template<T>&u, T v);
template<class T>
Vector2Template<T> operator/(const Vector2Template<T>&u, T v);
template<class T>
Vector2Template<T> operator%(const Vector2Template<T>&u, T v);

template<class T>
Vector2Template<T> operator*(T v, const Vector2Template<T>&u);

template<class T>
Vector2Template<T> operator+(const Vector2Template<T>&u, const Vector2Template<T> v);
template<class T>
Vector2Template<T> operator-(const Vector2Template<T>&u, const Vector2Template<T> v);
template<class T>
Vector2Template<T> operator*(const Vector2Template<T>&u, const Vector2Template<T> v);
template<class T>
Vector2Template<T> operator/(const Vector2Template<T>&u, const Vector2Template<T> v);
template<class T>
Vector2Template<T> operator%(const Vector2Template<T>&u, const Vector2Template<T> v);


//��ς�Ԃ�
template<class T>
Vector2Template<T> Dot(const Vector2Template<T>& va, const Vector2Template<T>& vb);

template<class T>
Vector2Template<T> Cross(const Vector2Template<T>& va, const Vector2Template<T>& vb);



template<class T>
T Magnitude(Vector2Template<T>& vec);

template<class T>
Vector2Template<T> Magnitude(Vector2Template<T>& vec1, Vector2Template<T>& vec2);

template<class T>
Vector2Template<T> Normalize(Vector2Template<T>& vec);


using Vector2 = Vector2Template<int>;
using Vector2Dbl = Vector2Template<double>;
using Vector2Flt = Vector2Template<float>;

#include "detail/Vector2.h"