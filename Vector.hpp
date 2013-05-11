#ifndef _VECTOR_HPP
#define _VECTOR_HPP

#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

typedef sf::Vector2f Vector2f;

#define DefOpB(op, whattoreturn, type) \
	inline type op(const Vector2f &a, const Vector2f &b) { return whattoreturn; }; \
	inline type op(Vector2f && a, const Vector2f &b) { return whattoreturn; }; \
	inline type op(const Vector2f &a, Vector2f && b) { return whattoreturn; }; \
	inline type op(Vector2f && a, Vector2f && b) { return whattoreturn; };

#define DefFunc(func, whattoreturn, type) \
	inline type func(const Vector2f &v) { return whattoreturn; }; \
	inline type func(Vector2f && v) { return whattoreturn; };

DefOpB(operator+, Vector2f(a.x+b.x, a.y+b.y), Vector2f);
DefOpB(operator-, Vector2f(a.x-b.x, a.y-b.y), Vector2f);
DefOpB(operator|, a.x*b.x+a.y*b.y, float);

DefFunc(sqnorm, v|v, float);
DefFunc(norm, sqrtf(v|v), float);

inline float squared(float f) {return f*f;}

inline std::ostream& operator<<(std::ostream &os, const Vector2f &v)
{
	return os << "Vector2f(" << v.x << ", " << v.y << ")";
}

namespace Vector2fHelper
{
	extern Vector2f Zero;

	Vector2f radial(float angle);
}

#endif