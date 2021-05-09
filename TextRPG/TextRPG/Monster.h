#pragma once
#include "Character.h"
#include "MapDraw.h"
#include "Macro.h"

class Monster : public Character
{
private:
	MapDraw DrawManager;
public:
	char AttackRes();
	void StatusLoad(Monster tmp, vector<Monster>& MonsterList);
	void ShowInfo(int i ,int iHeight);
	inline int Attack()
	{
		return m_Status.m_iAttack;
	}
	inline int GiveEXP(int index)
	{
		return m_Status.m_iDefaultEXP;
	}
	inline int GiveGold(int index)
	{
		return m_Status.m_iGold;
	}
	inline bool DeathCheck(int index)
	{
		if (m_Status.m_iHP <= 0)
			return true;
		else
			return false;
	}
	inline string GetName(int index)
	{
		return m_Status.m_strName;
	}
	Monster();
	~Monster();
};

class MonsterManager
{
private:
	Monster m_tmp;
	vector<Monster> MonsterList;
	MapDraw DrawManager;

public:
	void BattleInfo(int index);
	void ShowInfo();	
	void LoadDefaultInfo();

	inline void ResetMonster()
	{
		MonsterList.clear();
	}
	inline vector<Monster> GetMonster()
	{
		return MonsterList;
	}
	void GetDamage(int index)
	{
		int iDamage;
		iDamage = MonsterList[index].GetDamage()
	}
	MonsterManager()
	{
	}
	~MonsterManager()
	{
	}
};