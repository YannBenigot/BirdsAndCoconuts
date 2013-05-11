#include "Graphics.hpp"

class GraphicComponentEmbeddedTransformable: public GraphicComponent
{
	private:
		Transformable *transformable;

	public:
		GraphicComponentEmbeddedTransformable(Transformable &_transformable): transformable(&_transformable) {};
		void setTransformable(Transformable *_transformable) {transformable = _transformable;};

		virtual void draw(Layer *layers) const {transformable->draw(layers);};
		virtual void rotate(float angle) {transformable->rotate(angle);};
		virtual void scale(float factor) {transformable->scale(factor);}
		virtual void scale(Vector2f factor) {transformable->scale(factor);}
		virtual void setOpacity(float ratio) {transformable->setOpacity(ratio);}
};
