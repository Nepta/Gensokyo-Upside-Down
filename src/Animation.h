#ifndef __Animation_H__
#define __Animation_H__

#include <SFML/Graphics.hpp>
#include <initializer_list>
#include <unordered_map>

class Animation{
	unsigned int currentAnimation_ = 0;
	std::vector<sf::IntRect> frameList_;

public:
	Animation() = default;
	Animation(std::initializer_list<sf::IntRect>);
	void addFrame(sf::IntRect frame);
	sf::IntRect& next();
	sf::IntRect& currentAnimation();

	typedef std::unordered_map<std::string, Animation> HashMap;
};

#endif /* __Animation_H__ */

