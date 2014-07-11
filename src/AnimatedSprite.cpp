#include "AnimatedSprite.h"

using namespace sf;

AnimatedSprite::AnimatedSprite(Texture &texture) : Sprite(texture){}

void AnimatedSprite::addAnimation(std::string animationName, Animation& animation){
	animationList_[animationName] = animation;
	setAnimation(animationName);
}

void AnimatedSprite::nextAnimation(){
	IntRect& nextAnimation = animationList_[currentAnimation_].next();
	this->setTextureRect(nextAnimation);
}

void AnimatedSprite::setAnimation(std::string animation){
	this->currentAnimation_ = animation;
	this->setTextureRect(currentAnimation());
}

IntRect& AnimatedSprite::currentAnimation(){
	return animationList_[currentAnimation_].currentAnimation();
}
