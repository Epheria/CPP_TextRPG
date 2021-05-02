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

public:

};

class Dagger : public Weapon // 치명타 : x2 + 주도권
{
private:

public:
};

class Gun : public Weapon // 더블 탭 : 크리 + 2연타
{
private:

public:
};

class Sword : public Weapon // 검기 : 크리티컬 x 3
{
private:

public:
};

class Wand : public Weapon // 보호막 : 1회 방어
{
private:

public:
};

class Hammer : public Weapon // 지면강타 : 적 1회 기절
{
private:

public:
};