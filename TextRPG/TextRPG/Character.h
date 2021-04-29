#pragma once
#include "Macro.h"
class Character
{
public:
	virtual void CreateName() = 0;

	Character();
	virtual ~Character();
};

