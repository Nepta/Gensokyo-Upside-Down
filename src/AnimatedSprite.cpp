#include "AnimatedSprite.h"

using namespace sf;

AnimatedSprite::AnimatedSprite(Texture &texture) : Sprite(texture){}

void AnimatedSprite::addAnimation(IntRect animation){
	animationList_.push_back(animation);
	this->setTextureRect(animation);
}

void AnimatedSprite::nextAnimation(){
	currentAnimation_ = currentAnimation_+1 < animationList_.size() ? currentAnimation_+1 : 0;
	this->setTextureRect(animationList_[currentAnimation_]);
}
