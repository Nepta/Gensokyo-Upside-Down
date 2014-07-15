#include "Animation.h"

using namespace sf;

Animation::Animation(std::initializer_list<sf::IntRect> frames) : frameList_(frames){}

void Animation::addFrame(IntRect frame){
	frameList_.push_back(frame);
}

IntRect& Animation::next(){
	currentAnimation_ = currentAnimation_+1 < frameList_.size() ? currentAnimation_+1 : 0;
	return currentAnimation();
}

IntRect& Animation::currentAnimation(){
	return frameList_[currentAnimation_];
}
