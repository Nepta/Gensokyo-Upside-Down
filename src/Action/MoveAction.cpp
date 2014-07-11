#include "MoveAction.h"
#include <SFML/Graphics.hpp>

MoveAction::MoveAction(AnimatedSprite& sprite) : AnimatedSpriteAction(sprite){}

MoveAction* MoveAction::setDirection(MoveAction::Direction direction){
	direction_ = direction;
	return this;
}

void MoveAction::execute(){
	sf::Vector2f position = sprite().getPosition();
	switch(direction_){
		case MoveAction::UP:
			position.y--;
			sprite().setAnimation("up");
			break;
		case MoveAction::RIGHT:
			position.x++;
			sprite().setAnimation("right");
			break;
		case MoveAction::DOWN:
			position.y++;
			sprite().setAnimation("down");
			break;
		case MoveAction::LEFT:
			position.x--;
			sprite().setAnimation("left");
			break;
		case MoveAction::UNKNOWN:
		default: break;
	}
	sprite().setPosition(position);
}

