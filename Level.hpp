class Level: public Entity
{
	public:
		Level();
		virtual void reset() = 0;

		virtual void spawnThing(Thing &thing);
		
