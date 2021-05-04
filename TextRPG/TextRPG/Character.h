#pragma once
#include "Macro.h"

typedef struct Status
{
	string m_strMopName;
	int m_iLevel;
	int m_iAttack;
	int m_iHP;
	int m_iDefaultHP;
	int m_iEXP;
	int m_iGetEXP;
	int m_iGold;
}Status;

class Character
{
private:
	Status tmp;
public:
	virtual inline int Attack() = 0;
	virtual inline bool DeathCheck();
	virtual inline int GetDamage(int HP, int Damage);

	Character();
	virtual ~Character();
};

