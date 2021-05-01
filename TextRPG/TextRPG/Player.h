#pragma once
#include "Character.h"
#include "MapDraw.h"
#include "Macro.h"
#include "Weapon.h"
class Player : public Character, virtual MapDraw
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
	//vector<WeaponInfo> m_WeaponList;
public:
	void LoadDefaultInfo();
	void CreateName();
	void ShowInfo();

	inline int GetGold()
	{
		return m_iGold;
	}
	inline void BuyWeapon(int iPrice)
	{
		m_iGold -= iPrice;
	}
	Player();
	~Player();
};

