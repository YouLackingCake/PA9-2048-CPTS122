#pragma once
#include "GameModeBase.hpp"

class ClassicMode : public GameMode
{
public:
	void calculateScore(int tileValue) override;
};
