#ifndef __Animation_H__
#define __Animation_H__

#include <SFML/Graphics.hpp>

class Animation{
	unsigned int currentAnimation_ = 0;
	std::vector<sf::IntRect> animationList_;

public:
	void addAnimation(sf::IntRect animation);
	sf::IntRect& next();
	sf::IntRect& currentAnimation();
};

#endif /* __Animation_H__ */

