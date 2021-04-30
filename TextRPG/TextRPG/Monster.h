#pragma once
#include "Character.h"
#include "MapDraw.h"
#include "Macro.h"

typedef struct MOP
{
	string m_strMopName;
	int m_iLevel;
	int m_iAttack;
	int m_iHP;
	int m_iEXP;
	int m_iGetEXP;
	int m_iGold;
}MOP;

class Monster : public Character, public MapDraw
{
private:
	MOP MonInfo;
	vector<MOP> MonsterList;
public:
	void LoadDefaultInfo();
	void ShowInfo();
	Monster();
	~Monster();
};
