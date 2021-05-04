#pragma once
#include "Macro.h"
#include "MapDraw.h"

typedef struct WeaponStatus
{
	int m_iWEAPONTYPE;
	int m_iPrice;
	string m_strName;
	int m_iAttack;
}WeaponStatus;

class Player;
class Weapon : public MapDraw
{
private:
	WeaponStatus m_WeaponStatus;
public:
	virtual void LoadWeapon();

	void StatusLoad(vector<Weapon> WeaponList);
	int WeaponIndex(int WEAPONTYPE);
	void ShowWeaponInfo(int WEAPONTYPE, Player& User, string WeaponTypeName);
	void NextPage(int WEAPONTYPE, Player& User, string WeaponTypeName);
	int UseSkill(int WEAPONTYPE, int PlayerAtk);
	int Random()
	{
		int random;
		srand(time(NULL));

		random = rand() % 4;
		return random;
	}
//	virtual void SkillSet() = 0;
	Weapon();
	~Weapon();
};

class WeaponManager
{
private:
	Weapon* m_Weapon;
	vector<Weapon> WeaponList;
public:
	int WeaponCount(int WEAPONTYPE);
	void LoadWeapon();

};

class Bow : public Weapon // 속사 : 2연타
{
private:
public:
	void LoadWeapon()
	{
		
	}
};

class Dagger : public Weapon // 치명타 : x2 + 주도권
{
private:
	void LoadWeapon();
public:
};

class Gun : public Weapon // 더블 탭 : 크리 + 2연타
{
private:
public:
	void LoadWeapon();
};

class Sword : public Weapon // 검기 : 크리티컬 x 3
{
private:

public:
	void LoadWeapon();
};

class Wand : public Weapon // 보호막 : 1회 방어
{
private:

public:
	void LoadWeapon();
};

class Hammer : public Weapon // 지면강타 : 적 1회 기절
{
private:

public:
	void LoadWeapon();
};