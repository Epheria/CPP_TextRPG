#pragma once
#include "Character.h"
#include "MapDraw.h"
#include "Macro.h"
#include "Weapon.h"
#include "Monster.h"
class Player : public Character
{
private:
	MapDraw m_DrawManager;
	int m_iEXP;
	int m_iWeaponSelect;
	bool m_bWeapon;
	vector<Weapon*> m_Inventory;

public:
	void LoadDefaultInfo();
	void CreateName();
	void ShowInfo();
	void PlayerInfo(int iHeight);
	void ShowWeaponType(int iType);
	void ShowInventory();
	void ReleaseWeapon();
	void DeleteWeapon();
	void LevelUP();
	void Win(Monster m_Monster, int index);
	void Save(ofstream& m_fSave, int iSelect, string m_FileName[]);
	void Load(ifstream& fLoad, int iSelect);
	int Attack();

	inline bool InvenLimitCheck()
	{
		if (m_Inventory.size() > 9)
			return true;
		else
			return false;
	}
	inline int GetGold()
	{
		return m_iGold;
	}
	inline void BuyWeapon(int iPrice)
	{
		m_iGold -= iPrice;
	}
	inline void EquipWeapon(vector<Weapon*> WeaponList, int index)
	{
		Weapon* tmp;
		tmp = WeaponList[index];

		m_Inventory.push_back(tmp);
		m_bWeapon = true;
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

