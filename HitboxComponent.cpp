#include <typeinfo>
#include "HitboxComponent.hpp"
#include "Vector.hpp"
#include "Debug.hpp"

HitboxComponent::HitboxComponent(sf::Vector2f &_pos, sf::Vector2f &_opos) : pos(_pos), opos(_opos)
{
}

float HitboxComponent::GetMinDist(HitboxComponent &ha, HitboxComponent &hb)
{
	sf::Vector2f orig = ha.opos-hb.opos;
	sf::Vector2f speed = (ha.pos-ha.opos)-(hb.pos-hb.opos);
	float minDistTime = - (speed | orig) / sqnorm(speed);

	//DBG(orig << " - " << speed << " - mD = " << minDistTime);

	if(minDistTime < 0)
		// Dist(t) is increasing : min dist was reached just before update 
		return sqnorm(orig);
	else if(minDistTime > 1)
		// Dist(t) is decreasing : min dist is reached at end of update
		return sqnorm(ha.pos-hb.pos);
	else
		// Dist(t) is reached during update at minDistTime
		return sqnorm(orig+speed*minDistTime);
}

float HitboxComponent::GetColTime(HitboxComponent &ha, HitboxComponent &hb)
{
	sf::Vector2f orig = ha.opos-hb.opos;
	sf::Vector2f speed = (ha.pos-ha.opos)-(hb.pos-hb.opos);
	float minDistTime = - (speed | orig) / sqnorm(speed);

	if(minDistTime < 0)
		// Dist(t) is increasing: min dist was reached just before update 
		return 0;
	else if(minDistTime > 1)
		// Dist(t) is decreasing: min dist is reached at end of update
		return 1;
	else
		// Dist(t) is reached during update at minDistTime
		return minDistTime;
}


