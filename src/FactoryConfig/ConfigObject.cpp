#include "ConfigObject.h"

ConfigObject::ConfigObject(std::string configName, std::string spriteSheetName) : 
configName_(configName), spriteSheetName_(spriteSheetName){}

Animation::HashMap ConfigObject::config(){
	return {
		{"up",{{0,96,32,32},{32,96,32,32},{64,96,32,32}}},
		{"right",{{0,64,32,32},{32,64,32,32},{64,64,32,32}}},
		{"left",{{0,32,32,32},{0,32,32,32},{64,32,32,32}}},
		{"down",{{0,0,32,32},{32,0,32,32},{64,0,32,32}}}
	};
}

std::string ConfigObject::configName(){
	return configName_;
}
std::string ConfigObject::spriteSheetName(){
	return spriteSheetName_;
}

