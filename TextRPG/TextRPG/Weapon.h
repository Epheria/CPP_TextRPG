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

class Bow : public Weapon // �ӻ� : 2��Ÿ
{
private:

public:

};

class Dagger : public Weapon // ġ��Ÿ : x2 + �ֵ���
{
private:

public:
};

class Gun : public Weapon // ���� �� : ũ�� + 2��Ÿ
{
private:

public:
};

class Sword : public Weapon // �˱� : ũ��Ƽ�� x 3
{
private:

public:
};

class Wand : public Weapon // ��ȣ�� : 1ȸ ���
{
private:

public:
};

class Hammer : public Weapon // ���鰭Ÿ : �� 1ȸ ����
{
private:

public:
};