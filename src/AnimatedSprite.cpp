#include "AnimatedSprite.h"

using namespace sf;
using namespace std;

AnimatedSprite::AnimatedSprite(Texture& texture) : Sprite(texture){}

AnimatedSprite::AnimatedSprite(Texture& texture, AnimationHashMapInitializer animationList) :
Sprite(texture), animationList_(animationList){}
	
AnimatedSprite::AnimatedSprite(Texture& texture, Animation::HashMap animationList) :
Sprite(texture), animationList_(animationList){
	auto firstElement = animationList_.begin();
	setAnimation(firstElement->first);
}

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

