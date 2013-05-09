#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#define DefOpB(op, whattoreturn, type) \
	inline type op(const sf::Vector2f &a, const sf::Vector2f &b) { return whattoreturn; }; \
	inline type op(sf::Vector2f && a, const sf::Vector2f &b) { return whattoreturn; }; \
	inline type op(const sf::Vector2f &a, sf::Vector2f && b) { return whattoreturn; }; \
	inline type op(sf::Vector2f && a, sf::Vector2f && b) { return whattoreturn; };

#define DefFunc(func, whattoreturn, type) \
	inline type func(const sf::Vector2f &v) { return whattoreturn; }; \
	inline type func(sf::Vector2f && v) { return whattoreturn; };

DefOpB(operator+, sf::Vector2f(a.x+b.x, a.y+b.y), sf::Vector2f);
DefOpB(operator-, sf::Vector2f(a.x-b.x, a.y-b.y), sf::Vector2f);
DefOpB(operator|, a.x*b.x+a.y*b.y, float);

DefFunc(sqnorm, v|v, float);
DefFunc(norm, sqrtf(v|v), float);

inline float squared(float f) {return f*f;}

inline std::ostream& operator<<(std::ostream &os, const sf::Vector2f &v)
{
	return os << "sf::Vector2f(" << v.x << ", " << v.y << ")";
}

namespace Vector2
{
	extern sf::Vector2f Zero;

	sf::Vector2f radial(float angle);
}

