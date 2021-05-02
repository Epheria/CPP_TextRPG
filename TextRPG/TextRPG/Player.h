#pragma once
#include "Character.h"
#include "MapDraw.h"
#include "Macro.h"
#include "Weapon.h"
#include "Monster.h"
class Player : public Character, public Weapon
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
	int m_iWeaponSelect;
	bool m_bWeapon;
	vector<WeaponInfo> m_Inventory;
	Weapon m_Weapon;

public:
	void LoadDefaultInfo();
	void CreateName();
	void ShowInfo();
	void PlayerInfo(int iHeight);
	void ShowWeaponType(int iType);
	void ShowInventory();
	void LevelUP();
	void Win(Monster& m_Monster, int index);
	void Save(ofstream& m_fSave, int iSelect);
	void Load(ifstream& m_fLoad, int iSelect);

	inline int GetGold()
	{
		return m_iGold;
	}
	inline void BuyWeapon(int iPrice)
	{
		m_iGold -= iPrice;
	}
	inline void EquipWeapon(vector<WeaponInfo> WeaponList, int index)
	{
		WeaponInfo tmp;
		tmp.m_iAttack = WeaponList[index].m_iAttack;
		tmp.m_iPrice = WeaponList[index].m_iPrice;
		tmp.m_iWEAPONTYPE = WeaponList[index].m_iWEAPONTYPE;
		tmp.m_strName = WeaponList[index].m_strName;
		
		m_Inventory.push_back(tmp);
		m_bWeapon = true;
	}
	inline bool DeathCheck()
	{
		if (m_iHP <= 0)
			return true;
		else
			return false;
	}
	inline int Attack()
	{
		int SkillAtk;
		int SumAtk;
		if (m_Inventory.empty())
			return m_iAttack;
		else
		{
			SumAtk = m_iAttack + m_Inventory[m_iWeaponSelect].m_iAttack;
			SkillAtk = m_Weapon.UseSkill(m_Inventory[m_iWeaponSelect].m_iWEAPONTYPE, SumAtk);
			return SkillAtk;
		}
	}
	inline void GetDamage(int Damage)
	{
		m_iHP -= Damage;
	}
	inline void ResetWeapon()
	{
		m_iDefaultHP = 1000;
		m_iEXP = 0;
		m_bWeapon = false;
		m_Inventory.clear();
	}
	Player();
	~Player();
};

