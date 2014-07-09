#include "EventManager.h"

using namespace sf;

void EventManager::addEvent(Event event){
	if(event.type == Event::KeyPressed || event.type == Event::KeyReleased){
		bool keyPressed = event.type == Event::KeyPressed;
		switch(event.key.code){
			case Keyboard::Key::Z:
				eventList_["up"] = keyPressed;
				break;
			case Keyboard::Key::Q:
				eventList_["left"] = keyPressed;
				break;
			case Keyboard::Key::S:
				eventList_["down"] = keyPressed;
				break;
			case Keyboard::Key::D:
				eventList_["right"] = keyPressed;
				break;
			default:break;
		}
	}
}

bool EventManager::have(std::string event){
	return eventList_[event];
}

void EventManager::flushEvent(){
	eventList_.clear();
}

