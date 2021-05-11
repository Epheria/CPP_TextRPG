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

class Player;
class Weapon
{
private:
	WEAPONTYPE m_eWEAPONTYPE;
	int m_iPrice;
	string m_strName;
	int m_iAttack;
	MapDraw m_DrawManager;
public:
	void LoadWeapon(ifstream& fLoad, int iType);
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
		return (*iter)->m_eWEAPONTYPE;
	}
	int GetWeaponType()
	{
		int iType;
		iType = m_eWEAPONTYPE;
		return iType;
	}
	int GetPrice()
	{
		return m_iPrice;
	}
	int GetAttack()
	{
		return m_iAttack;
	}
	string GetName()
	{
		return m_strName;
	}
	void SetWeapon(WEAPONTYPE eType, string strName, int iAtk, int iPrice) 	// Player �� ���� Load ��� ������ Setter ��� Player.cpp 211�� + WeaponList pushback �Ҷ��� �ʿ�..
	{
		m_iAttack = iAtk;
		m_iPrice = iPrice;
		m_eWEAPONTYPE = eType;
		m_strName = strName;
	}

	Weapon();
	virtual ~Weapon();
};

class WeaponManager
{
private:
	MapDraw m_DrawManager;
	vector<Weapon*> WeaponList;
public:
	void LoadAllWeapon();
	int WeaponCount(WEAPONTYPE eType);
	void ShowWeaponInfo(WEAPONTYPE eType, Player& User, string WeaponTypeName);
	//void ShowWeaponInfo(WEAPONTYPE eType, Player& User, string WeaponTypeName, int iMax, int iIndex);
	void ShowList(vector<Weapon*> tmp, Player& User, string WeaponTypeName, int iPage, int iMax);
	int WeaponIndex(WEAPONTYPE eType);
};

class Bow : public Weapon
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