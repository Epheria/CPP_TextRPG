#pragma once
#include "Macro.h"

typedef struct Status
{
	string m_strName;
	int m_iLevel;
	int m_iAttack;
	int m_iHP;
	int m_iDefaultHP;
	int m_iDefaultEXP;
	int m_iGetEXP;
	int m_iGold;
}Status;

class Character
{
protected:
	Status m_Status;
public:
	virtual inline int Attack() = 0;
	virtual inline bool DeathCheck();
	virtual inline int GetDamage(int HP, int Damage);

	Character();
	virtual ~Character();
};

