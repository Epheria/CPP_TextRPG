#pragma once
#include "Macro.h"
class Character
{
public:
	virtual void LoadDefaultInfo() = 0;
	virtual void ShowInfo() = 0;
	Character();
	virtual ~Character();
};

