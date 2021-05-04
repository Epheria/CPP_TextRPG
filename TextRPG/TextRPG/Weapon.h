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
	int WeaponCount(int WEAPONTYPE);
	int WeaponIndex(int WEAPONTYPE);
	void ShowWeaponInfo(int WEAPONTYPE, Player& User, string WeaponTypeName);
	void NextPage(int WEAPONTYPE, Player& User, string WeaponTypeName);
	void LoadWeapon();
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

class Bow : public Weapon // 속사 : 2연타
{
private:
	vector<WeaponStatus> BowList;
public:

};

class Dagger : public Weapon // 치명타 : x2 + 주도권
{
private:
	vector<WeaponStatus> DaggerList;
public:
};

class Gun : public Weapon // 더블 탭 : 크리 + 2연타
{
private:
	vector<WeaponStatus> GunList;
public:
};

class Sword : public Weapon // 검기 : 크리티컬 x 3
{
private:
	vector<WeaponStatus> SwordList;

public:
};

class Wand : public Weapon // 보호막 : 1회 방어
{
private:
	vector<WeaponStatus> WandList;

public:
};

class Hammer : public Weapon // 지면강타 : 적 1회 기절
{
private:
	vector<WeaponStatus> HammerList;

public:
};