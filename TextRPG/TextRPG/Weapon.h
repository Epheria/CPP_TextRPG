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
	vector<Weapon*> LoadWeapon(int WEAPONTYPE, vector<Weapon*> WeaponList, Weapon* tmp);
	void ShowWeapon(int i, int iHeight, string WeaponTypeName);
	virtual int UseSkill(int PlayerAtk)
	{
		return PlayerAtk;
	}
	int Random()
	{
		int random;
		srand(time(NULL));

		random = rand() % 4;
		return random;
	}
	int GetWeaponType(vector<Weapon*>::iterator iter)
	{
		return (*iter)->m_WeaponStatus.m_iWEAPONTYPE;
	}
	int GetWeaponType()
	{
		return m_WeaponStatus.m_iWEAPONTYPE;
	}
	int GetPrice()
	{
		return m_WeaponStatus.m_iPrice;
	}
	int GetAttack()
	{
		return m_WeaponStatus.m_iAttack;
	}
	string GetName()
	{
		return m_WeaponStatus.m_strName;
	}
	void SetWeapon(WeaponStatus tmp) 	// Player �� ���� Load ��� ������ Setter ��� Player.cpp 211��
	{
		m_WeaponStatus.m_iAttack = tmp.m_iAttack;
		m_WeaponStatus.m_iPrice = tmp.m_iPrice;
		m_WeaponStatus.m_iWEAPONTYPE = tmp.m_iWEAPONTYPE;
		m_WeaponStatus.m_strName = tmp.m_strName;
	}

	Weapon();
	~Weapon();
};

class WeaponManager
{
private:
	MapDraw m_DrawManager;
	vector<Weapon*> WeaponList;
public:
	void LoadAllWeapon(Weapon m_Weapon);
	int WeaponCount(int WEAPONTYPE);
	void ShowWeaponInfo(int WEAPONTYPE, Player& User, string WeaponTypeName);
	void ShowWeaponInfo(int WEAPONTYPE, Player& User, string WeaponTypeName, int iMax, int iIndex);
	int WeaponIndex(int WEAPONTYPE);
};

class Bow : public Weapon
{
private:
	MapDraw m_DrawManager;
public:
	int UseSkill(int WEAPONTYPE, int PlayerAtk)
	{
		char ch;
		int iRand = Random();
		if (iRand == 0 || iRand == 1)
		{
			YELLOW
				m_DrawManager.DrawMidText("�ӻ� �ߵ�!! 2��Ÿ!!", WIDTH, HEIGHT - 18);
			ch = _getch();
			return PlayerAtk * 2;
		}
	}
};

class Dagger : public Weapon
{
private:
	MapDraw m_DrawManager;
public:
	int UseSkill(int PlayerAtk)
	{
		char ch;
		int iRand = Random();
		if (iRand == 0 || iRand == 1)
		{
			YELLOW
				m_DrawManager.DrawMidText("�޼���� �ߵ�!! ũ��Ƽ�� ������", WIDTH, HEIGHT - 18);
			ch = _getch();
			return PlayerAtk * 3;
		}
	}
};

class Gun : public Weapon
{
private:
	MapDraw m_DrawManager;
public:
	int UseSkill(int PlayerAtk)
	{
		char ch;
		int iRand = Random();
		if (iRand == 0 || iRand == 1)
		{
			YELLOW
				m_DrawManager.DrawMidText("���� �� �ߵ�!! ũ��Ƽ�� + 2��Ÿ", WIDTH, HEIGHT - 18);
			ch = _getch();
			return PlayerAtk * 4;
		}
	}
};

class Sword : public Weapon
{
private:
	MapDraw m_DrawManager;
public:
	int UseSkill(int PlayerAtk)
	{
		char ch;
		int iRand = Random();
		if (iRand == 0 || iRand == 1)
		{
			YELLOW
				m_DrawManager.DrawMidText("�˱� �ߵ�!! ũ��Ƽ�� ������", WIDTH, HEIGHT - 18);
			ch = _getch();
			return PlayerAtk * 3;
		}
	}
};

class Wand : public Weapon
{
private:
	MapDraw m_DrawManager;
public:
	int UseSkill(int PlayerAtk)
	{
		char ch;
		int iRand = Random();
		if (iRand == 0 || iRand == 1)
		{
			YELLOW
				m_DrawManager.DrawMidText("���̾ �ߵ�!! ũ��Ƽ�� ������", WIDTH, HEIGHT - 18);
			ch = _getch();
			return PlayerAtk * 6;
		}
	}
};

class Hammer : public Weapon 
{
private:
	MapDraw m_DrawManager;
public:
	int UseSkill(int PlayerAtk)
	{
		char ch;
		int iRand = Random();
		if (iRand == 0 || iRand == 1)
		{
			YELLOW
				m_DrawManager.DrawMidText("���鰭Ÿ �ߵ�!! ũ��Ƽ�� ������", WIDTH, HEIGHT - 18);
			ch = _getch();
			return PlayerAtk * 4;
		}
	}
};