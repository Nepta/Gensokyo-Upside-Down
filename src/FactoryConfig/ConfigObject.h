#ifndef __ConfigObject_H__
#define __ConfigObject_H__

#include "../Animation.h"

class ConfigObject{
public:
	virtual ~ConfigObject(){}
	virtual std::string configName() = 0;
	virtual std::string spriteSheetName() = 0;
	virtual Animation::HashMap config(){
		return {
			{"up",{{0,96,32,32},{32,96,32,32},{64,96,32,32}}},
			{"right",{{0,64,32,32},{32,64,32,32},{64,64,32,32}}},
			{"left",{{0,32,32,32},{0,32,32,32},{64,32,32,32}}},
			{"down",{{0,0,32,32},{32,0,32,32},{64,0,32,32}}}
		};
	}

};

#endif /* __ConfigObject_H__ */

