#pragma once

#include "../../Pattern.h"

class VisitorPattern : public Pattern {
public:
	std::string get_info();
	int run();
};