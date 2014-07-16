#ifndef __CirnoConfig_H__
#define __CirnoConfig_H__

#include "ConfigObject.h"

class CirnoConfig : public ConfigObject{
	std::string configName(){
		return "cirno";
	}
	
	std::string spriteSheetName(){
		return "cirno.png";
	}
};

#endif /* __CirnoConfig_H__ */

