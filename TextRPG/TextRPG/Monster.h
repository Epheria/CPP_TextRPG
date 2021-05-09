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
	inline int GiveEXP()
	{
		return m_Status.m_iDefaultEXP;
	}
	inline int GiveGold()
	{
		return m_Status.m_iGold;
	}
	inline string GetName()
	{
		return m_Status.m_strName;
	}

	int ShowHP()
	{
		return m_Status.m_iHP;
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
	void GetDamage(int index, int damage)
	{
		MonsterList[index].GetDamage(damage);
	}
	bool DeathCheck(int index)
	{
		return MonsterList[index].DeathCheck();
	}
	Monster GetMonster(int index)
	{
		return MonsterList[index];
	}
	string GetName(int index)
	{
		return MonsterList[index].GetName();
	}
	int GetAttack(int index)
	{
		return MonsterList[index].Attack();
	}
	MonsterManager()
	{
	}
	~MonsterManager()
	{
	}
};