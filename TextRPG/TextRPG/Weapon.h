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

class Bow : public Weapon // �ӻ� : 2��Ÿ
{
private:
	vector<WeaponStatus> BowList;
public:

};

class Dagger : public Weapon // ġ��Ÿ : x2 + �ֵ���
{
private:
	vector<WeaponStatus> DaggerList;
public:
};

class Gun : public Weapon // ���� �� : ũ�� + 2��Ÿ
{
private:
	vector<WeaponStatus> GunList;
public:
};

class Sword : public Weapon // �˱� : ũ��Ƽ�� x 3
{
private:
	vector<WeaponStatus> SwordList;

public:
};

class Wand : public Weapon // ��ȣ�� : 1ȸ ���
{
private:
	vector<WeaponStatus> WandList;

public:
};

class Hammer : public Weapon // ���鰭Ÿ : �� 1ȸ ����
{
private:
	vector<WeaponStatus> HammerList;

public:
};