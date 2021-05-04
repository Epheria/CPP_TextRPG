#pragma once
#include "Character.h"
#include "MapDraw.h"
#include "Macro.h"

class Monster : public Character, public MonsterManager
{
private:
	Status m_MonsterStatus;
public:
	char AttackRes();

	inline int Attack()
	{
		return m_MonsterStatus.m_iAttack;
	}
	inline int GiveEXP(int index)
	{
		return m_MonsterStatus.m_iEXP;
	}
	inline int GiveGold(int index)
	{
		return m_MonsterStatus.m_iGold;
	}
	inline bool DeathCheck(int index)
	{
		if (m_MonsterStatus.m_iHP <= 0)
			return true;
		else
			return false;
	}
	inline string GetName(int index)
	{
		return m_MonsterStatus.m_strMopName;
	}
	Monster();
	~Monster();
};

class MonsterManager
{
private:
	Monster m_Monster;
	vector<Status> MonsterList;
	MapDraw DrawManager;

public:
	void ShowInfo();	
	void LoadDefaultInfo();
	void ShowMonster(int index);

	inline void ResetMonster()
	{
		MonsterList.clear();
	}
	inline vector<Status> GetMonster()
	{
		return MonsterList;
	}
	MonsterManager()
	{
	}
	~MonsterManager()
	{
	}
};