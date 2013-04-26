#include "../HitboxComponents/CircularHitbox.hpp"
#include <iostream>

int main(void)
{
	sf::Vector2f caPos(0, 0);
	sf::Vector2f caOPos(-1, 0);
	sf::Vector2f cbPos(0, 0);
	sf::Vector2f cbOPos(1, 0);

	CircularHitbox ca(caPos, caOPos, 0.1);
	CircularHitbox cb(cbPos, cbOPos, 0.1);

	if(ca.collision(cb))
		std::cout << "OK" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	caPos.x = 1.0;
	cbPos.x = -1.0;
	if(cb.collision(ca))
		std::cout << "OK" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	caPos.x = -2.0;
	if(cb.collision(ca))
       		std::cout << "FAIL" << std::endl;
	else
		std::cout << "OK" << std::endl;


	sf::Vector2f ccPos(0, 0);
	sf::Vector2f cdPos(0, 0.6);
	sf::Vector2f cdOPos(0, 1.1);
	CircularHitbox cc(ccPos, ccPos, 1);
	CircularHitbox cd(cdPos, cdOPos, 1);
	if(cc.collision(cd))
		std::cout << "OK" << std::endl;
	else
		std::cout << "FAIL" << std::endl;

	return 0;
}

