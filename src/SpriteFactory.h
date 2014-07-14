#ifndef __SpriteFactory_H__
#define __SpriteFactory_H__

#include "AnimatedSprite.h"
#include "Animation.h"

class SpriteFactory{
	std::string path_;
	std::unordered_map<std::string, Animation> animationList_;
	std::unordered_map<std::string, sf::Texture> textureList_;
	
public:
	SpriteFactory(std::string path = "");
	AnimatedSprite create(std::string spriteName);
	void addSpriteSheet(std::string spriteSheetName);
//	void loadSpriteConf(std::string path);
	void addAnimation(std::string animationName, Animation& animation);
};

#endif /* __SpriteFactory_H__ */

