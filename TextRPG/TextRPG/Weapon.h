#pragma once
#include "Macro.h"
#include "MapDraw.h"
/*
���� ����
: �޴� ������ if ������ ����� iSelect ������ŭ ���ϸ� 1���� 2���� 3���� 4���� 5���� �׿� �°� �޴��� ������ �����ϴ�.

weapon �ڽĵ��� �θ��� load�� �ҷ��ͼ�
�ڽ��� �����͸� ��ĳ�����ؼ� -> WeaponManager �� ����Ʈ�� �����ϸ�ȴ�.
�׸��� �ڽĵ��� ��ų�� �������̵��ؼ� �� ���� ���� ���� ���ָ� �ȴ�.
*/
typedef struct WeaponStatus
{
	int m_iWEAPONTYPE;
	int m_iPrice;
	string m_strName;
	int m_iAttack;
}WeaponStatus;

class Player;
class Weapon
{
private:
	MapDraw m_DrawManager;
	WeaponStatus m_WeaponStatus;
public:
	void LoadWeapon(int WEAPONTYPE, vector<Weapon*>& WeaponList, Weapon* tmp);
	//int UseSkill(int WEAPONTYPE, int PlayerAtk);
	int Random()
	{
		int random;
		srand(time(NULL));

		random = rand() % 4;
		return random;
	}
	int GetWeaponType()
	{
		return m_WeaponStatus.m_iWEAPONTYPE;
	}
	int GetPrice()
	{
		return m_WeaponStatus.m_iPrice;
	}
	void ShowWeapon(int i, int iHeight, string WeaponTypeName);
//	virtual void SkillSet() = 0;
	Weapon();
	~Weapon();
};

class WeaponManager
{
private:
	MapDraw m_DrawManager;
	vector<Weapon*> WeaponList;

public:
	void LoadAllWeapon();
	int WeaponCount(int WEAPONTYPE);
	void ShowWeaponInfo(int WEAPONTYPE, Player& User, string WeaponTypeName);
	void ShowWeaponInfo(int WEAPONTYPE, Player& User, string WeaponTypeName, int iMax, int iIndex);
	int WeaponIndex(int WEAPONTYPE);
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