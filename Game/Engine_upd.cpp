#include "Engine.h"
void Engine::update(float time_mcs) {
	if(isMission)
		mission->update(time_mcs);
}