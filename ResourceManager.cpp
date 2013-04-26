#include "ResourceManager.hpp"
#include <iostream>
#include <string.h>
#include "Debug.hpp"

std::string MainDir = std::string(".");
ResourceManager *ResourceManager::resourceManager = NULL;

ResourceManager *ResourceManager::get()
{
	if(resourceManager == NULL)
		resourceManager = new ResourceManager();
	
	return resourceManager;
}

void ResourceManager::destroy()
{
	delete resourceManager;
}

ResourceManager::~ResourceManager()
{
}

ResourceManager::ResourceManager()
{
}

const std::string ResourceManager::getLocation(const std::string filename)
{
#ifdef WINDOWS
	return std::string(MainDir+std::string("\\")+filename);
#else
	return std::string(MainDir+std::string("/")+filename);
#endif
}

const int SHADOW_AMPL = 64;
void ResourceManager::addTexture(TextureResource res, const std::string filename)
{
	std::cout << "Loading texture " << filename << " for resource " << res << std::endl;
	textures[res].loadFromFile(getLocation(filename));
}

void ResourceManager::addAnimatedSpriteBase(AnimatedSpriteBaseResource res, const std::string filename, int width, int height)
{
	AnimatedSpriteBase &asbase = asbases[res];
	std::cout << "Loading animated sprite base " << filename << " for resource " << res << std::endl;
	asbase.width = width;
	asbase.height = height;
	// Texture loading
	asbase.texture.loadFromFile(getLocation(filename));

	// Shadow creation
	sf::Image image = asbase.texture.copyToImage();
	sf::Image iShadow;
	sf::Color curPixel;
	iShadow.create(image.getSize().x, image.getSize().y, sf::Color(0, 0, 0, 0));
	for(unsigned int x=0; x<image.getSize().x; x++)
		for(unsigned int y=0; y<image.getSize().y; y++)
		{
			curPixel = image.getPixel(x, y);
			if(curPixel.a > 0)
			{
				iShadow.setPixel(x, y, sf::Color(0, 0, 0, SHADOW_AMPL*curPixel.a/255));
			}
		}
	asbase.shadow.loadFromImage(iShadow);
	// Rects definition (for animation)
	int nModes = asbase.texture.getSize().y/height;
	int maxNImages = asbase.texture.getSize().x/width;
	DBG("Resource " << res << " opened, " << nModes << " modes, " << maxNImages << " individual images per line\n");


	for(int iMode = 0; iMode < nModes; iMode++) 
	{
		asbase.rects.push_back(std::list<sf::IntRect>());
		for(int iImage = 0; iImage < maxNImages; iImage++)
		{
			// Check if empty image
			for(int x = 0; x < width; x++)
				for(int y = 0; y < height; y++)
				{
					curPixel = image.getPixel(width*iImage+x, height*iMode+y);
					if(curPixel.a > 0)
						goto AddImage;
				}
			break;
			AddImage:
			asbase.rects[iMode].push_back(sf::IntRect(width*iImage, height*iMode, width, height));
		}
	}
}

void ResourceManager::addSound(SoundResource res, const std::string filename)
{
	std::cout << "Loading sound " << filename << " for resource " << res << std::endl;
	sounds[res].loadFromFile(getLocation(filename));
}

void ResourceManager::addFont(FontResource res, const std::string filename)
{
	std::cout << "Loading font " << filename << " for resource " << res << std::endl;
	fonts[res].loadFromFile(getLocation(filename));
}

void ResourceManager::init()
{
/*	addTexture(BACKGROUND, "bg.png");
	addTexture(BACKGROUND_MENU, "bg_menu.png");
	addTexture(BACKGROUND_LOST, "bg_lost.png");
	addTexture(BACKGROUND_WIN, "bg_win.png");
	addTexture(FOREGROUND, "fg.png");
	addTexture(FOREGROUND_WIN, "fg_win.png");
	addTexture(SHOT_RED, "shot_red.png");
	addTexture(SHOT_GREEN, "shot_green.png");
	addTexture(SHOT_YELLOW, "shot_yellow.png");
	addTexture(SHOT_VIOLET, "shot_violet.png");
	addTexture(SHOT_WHITE, "shot_white.png");
	addTexture(SHOT_GREY, "shot_grey.png");*/
	addTexture(SHOT_BLUE, "shot_blue.png");
	addTexture(SHOT_DEFAULT, "shot.png");

	/*addAnimatedSpriteBase(PLAYER, "player.png", 32, 32);*/
	addAnimatedSpriteBase(ASBASE_TEST, "test.png", 32, 32);

	/*addSound(SHOT, "shot.wav");
	addSound(SCREAM, "scream.wav");
	addSound(EYE_OPEN, "eyeopen.ogg");

	addFont(DEFAULT, "font.ttf");*/
}

