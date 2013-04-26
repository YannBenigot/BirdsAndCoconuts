#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>
#include <list>

typedef struct
{
	int width, height;
	sf::Texture texture;
	sf::Texture shadow;
	std::vector<std::list<sf::IntRect> > rects;
} AnimatedSpriteBase;

typedef enum 
{
	BACKGROUND, 
	BACKGROUND_MENU,
	BACKGROUND_LOST,
	BACKGROUND_WIN,
	FOREGROUND,
	FOREGROUND_WIN,
	SHOT_DEFAULT, 
	SHOT_RED, 
	SHOT_BLUE, 
	SHOT_GREEN, 
	SHOT_YELLOW, 
	SHOT_VIOLET, 
	SHOT_WHITE, 
	SHOT_GREY,
	TEXTURE_RESOURCE_COUNT
} TextureResource;

typedef enum
{
	ASBASE_TEST,
	PLAYER,
	ASBASE_RESOURCE_COUNT
} AnimatedSpriteBaseResource;


typedef enum
{
	SHOT,
	SCREAM,
	EYE_OPEN,
	SOUND_RESOURCE_COUNT
} SoundResource;

typedef enum
{
	DEFAULT,
	FONT_RESOURCE_COUNT
} FontResource;

class ResourceManager
{
	public:
		static ResourceManager * get();
		static void destroy();

		void init();
		~ResourceManager();

		sf::Texture &getTexture(TextureResource res) {return textures[res];};
		AnimatedSpriteBase &getASBase(AnimatedSpriteBaseResource res) {return asbases[res];};
		sf::SoundBuffer &getSound(SoundResource res) {return sounds[res];};
		sf::Font &getFont(FontResource res) {return fonts[res];};
	private:
		ResourceManager();
		static ResourceManager *resourceManager;

		const std::string getLocation(const std::string filename);

		sf::Texture textures[TEXTURE_RESOURCE_COUNT];
		void addTexture(TextureResource res, const std::string filename);

		AnimatedSpriteBase asbases[ASBASE_RESOURCE_COUNT];
		void addAnimatedSpriteBase(AnimatedSpriteBaseResource res, const std::string filename, int width, int height);

		sf::SoundBuffer sounds[SOUND_RESOURCE_COUNT];
		void addSound(SoundResource res, const std::string filename);

		sf::Font fonts[FONT_RESOURCE_COUNT];
		void addFont(FontResource res, const std::string filename);

};

#endif
