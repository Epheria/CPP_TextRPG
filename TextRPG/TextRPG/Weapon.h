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

class Bow : public Weapon // �ӻ� : 2��Ÿ
{
private:
public:
	void LoadWeapon()
	{
		
	}
};

class Dagger : public Weapon // ġ��Ÿ : x2 + �ֵ���
{
private:
	void LoadWeapon();
public:
};

class Gun : public Weapon // ���� �� : ũ�� + 2��Ÿ
{
private:
public:
	void LoadWeapon();
};

class Sword : public Weapon // �˱� : ũ��Ƽ�� x 3
{
private:

public:
	void LoadWeapon();
};

class Wand : public Weapon // ��ȣ�� : 1ȸ ���
{
private:

public:
	void LoadWeapon();
};

class Hammer : public Weapon // ���鰭Ÿ : �� 1ȸ ����
{
private:

public:
	void LoadWeapon();
};