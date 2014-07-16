#ifndef __Animated_H__
#define __Animated_H__

#include "Animation.h"
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
class AnimatedSprite : public sf::Sprite{
	typedef std::initializer_list<Animation::HashMap::value_type> AnimationHashMapInitializer;
	std::string currentAnimation_;
	Animation::HashMap animationList_;

private:
	sf::IntRect& currentAnimation();

public:
	AnimatedSprite(sf::Texture& texture);
	AnimatedSprite(sf::Texture& texture, AnimationHashMapInitializer);
	AnimatedSprite(sf::Texture& texture, Animation::HashMap);
	void addAnimation(std::string animationName, Animation& animation);
	void nextAnimation();
	void setAnimation(std::string);
};

#endif /* __Sprite_H__ */

