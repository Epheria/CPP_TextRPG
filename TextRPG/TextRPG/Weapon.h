#pragma once
#include "Macro.h"
#include "MapDraw.h"

/*
상점 구현
: 메뉴 선택을 if 문으로 만들고 iSelect 개수만큼 더하면 1개든 2개든 3개든 4개든 5개든 그에 맞게 메뉴가 구현이 가능하다.

weapon 자식들을 부모의 load로 불러와서
자식의 포인터를 업캐스팅해서 -> WeaponManager 의 리스트에 저장하면된다.
그리고 자식들의 스킬은 오버라이딩해서 다 따로 따로 구현 해주면 된다.
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
	void SetWeapon(WEAPONTYPE eType, string strName, int iAtk, int iPrice) 	// Player 의 무기 Load 기능 때문에 Setter 사용 Player.cpp 211줄 + WeaponList pushback 할때도 필요..
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
				m_DrawManager.DrawMidText("속사 발동!! 2연타!!", WIDTH, HEIGHT - 18);
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
				m_DrawManager.DrawMidText("급소찌르기 발동!! 크리티컬 데미지", WIDTH, HEIGHT - 18);
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
				m_DrawManager.DrawMidText("더블 탭 발동!! 크리티컬 + 2연타", WIDTH, HEIGHT - 18);
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
				m_DrawManager.DrawMidText("검기 발동!! 크리티컬 데미지", WIDTH, HEIGHT - 18);
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
				m_DrawManager.DrawMidText("파이어볼 발동!! 크리티컬 데미지", WIDTH, HEIGHT - 18);
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
				m_DrawManager.DrawMidText("지면강타 발동!! 크리티컬 데미지", WIDTH, HEIGHT - 18);
			ch = _getch();
			return PlayerAtk * 4;
		}
	}
};