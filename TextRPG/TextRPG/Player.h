#pragma once
#include "Character.h"
#include "Macro.h"
class Player : public Character
{
private:
	string m_strPlayerName;
public:
	void CreateName();
	Player();
	~Player();
};

