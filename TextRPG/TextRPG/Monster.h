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
	int m_iDefaultHP;
	int m_iEXP;
	int m_iGetEXP;
	int m_iGold;
}MOP;

class Monster : public Character, virtual MapDraw
{
private:
	vector<MOP> MonsterList;
public:
	void LoadDefaultInfo();
	void ShowInfo();
	void ShowMonster(int index);
	char Attack();
	inline vector<MOP> GetMonster()
	{
		return MonsterList;
	}
	inline int DealDamage(int index)
	{
		return MonsterList[index].m_iAttack;
	}
	inline int GiveEXP(int index)
	{
		return MonsterList[index].m_iEXP;
	}
	inline int GiveGold(int index)
	{
		return MonsterList[index].m_iGold;
	}
	inline void GetDamage(int index, int damage)
	{
		MonsterList[index].m_iHP -= damage;
	}
	inline bool DeathCheck(int index)
	{
		if (MonsterList[index].m_iHP <= 0)
			return true;
		else
			return false;
	}
	inline void ResetMonster()
	{
		MonsterList.clear();
	}
	inline string GetName(int index)
	{
		return MonsterList[index].m_strMopName;
	}
	Monster();
	~Monster();
};
