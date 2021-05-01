#pragma once
#include "Macro.h"
#include "MapDraw.h"

typedef struct WeaponInfo
{
	int m_iWEAPONTYPE;
	int m_iPrice;
	string m_strName;
	int m_iAttack;
}WeaponInfo;

class Player;
class Weapon : public MapDraw
{
private:
	vector<WeaponInfo> WeaponList;

public:
	int WeaponCount(int WEAPONTYPE);
	int WeaponIndex(int WEAPONTYPE);
	void ShowWeaponInfo(int WEAPONTYPE, Player& User, string WeaponTypeName);
	void NextPage(int WEAPONTYPE, Player& User, string WeaponTypeName);
	void LoadWeapon();
	inline vector<WeaponInfo> GetWeapon(int i)
	{
		vector<WeaponInfo> tmp;
		tmp[0] = WeaponList[i];
		return tmp;
	}
	//virtual void SkillSet() = 0;
	Weapon();
	~Weapon();
};

class Bow : public Weapon
{
private:

public:
};

class Dagger : public Weapon
{
private:

public:
};

class Gun : public Weapon
{
private:

public:
};

class Sword : public Weapon
{
private:

public:
};

class Wand : public Weapon
{
private:

public:
};

class Hammer : public Weapon
{
private:

public:
};