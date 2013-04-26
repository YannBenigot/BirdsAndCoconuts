#include "Thing.hpp"

void Thing::update()
{
	updateCommon();
	graphicComponent->updateCommon();
	switch(mode)
	{
		case APPEARING: 
			updateAppearing(); 
			if(updatePosAppearing)
			{
				opos = pos;
				trajectoryComponent->updatePosition();
			}
			if(graphicComponent->updateAppearing())
				setMode(ALIVE);
			break;
		case ALIVE: 
			updateAlive();
			opos =  pos;
			trajectoryComponent->updatePosition();
			if(graphicComponent->updateAppearing())
				setMode(DYING);
			break;
		case DYING: 
			updateDying();
			if(updatePosDying)
			{
				opos = pos;
				trajectoryComponent->updatePosition();
			}
			if(graphicComponent->updateDying())
				setMode(DEAD);
			break;
	}
	hitboxComponent->update();
}

void Thing::setMode(Mode _mode)
{
	mode = _mode;
	switch(mode)
	{
		case APPEARING: 
			onSetAppearing();
			graphicComponent->onSetAppearing();
			break;
		case ALIVE:
			onSetAlive();
			graphicComponent->onSetAlive();
			break;
		case DYING:
			onSetDying();
			graphicComponent->onSetDying();
			break;
	}
}
