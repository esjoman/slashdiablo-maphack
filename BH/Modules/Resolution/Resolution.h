#pragma once
#include "../Module.h"
#include "../../Config.h"

class Resolution : public Module {
private:
	map<std::string, Toggle> Toggles;
	bool use1300x700;

public:
	Resolution() : Module("Resolution") {};
	void OnLoad();
	void OnUnload();
	void OnGameJoin(const string& name, const string& pass, int diff);
};