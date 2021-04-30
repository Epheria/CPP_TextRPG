#pragma once
#include "Character.h"
#include "MapDraw.h"
#include "Macro.h"
class Player : public Character, public MapDraw
{
private:
	string m_strPlayerName;
	int m_iAttack;
	int m_iLevel;
	int m_iDefaultHP;
	int m_iHP;
	int m_iEXP;
	int m_iDefaultEXP;
	int m_iGetEXP;
	int m_iGold;
	bool m_bWeapon;
public:
	void LoadDefaultInfo();
	void CreateName();
	void ShowInfo();
	Player();
	~Player();
};

