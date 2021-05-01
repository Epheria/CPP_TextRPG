#include "Player.h"
#include "Weapon.h"

Weapon::Weapon()
{
	LoadWeapon();
}

int Weapon::WeaponCount(int WEAPONTYPE)
{
	int iCount = 0;
	for (vector<WeaponInfo>::iterator iter = WeaponList.begin(); iter != WeaponList.end(); iter++)
	{
		if (iter->m_iWEAPONTYPE == WEAPONTYPE)
		{
			iCount++;
		}
	}
	return iCount;
}

int Weapon::WeaponIndex(int WEAPONTYPE)
{
	int iIndex = 0;
	for (vector<WeaponInfo>::iterator iter = WeaponList.begin(); iter != WeaponList.end(); iter++)
	{
		if (iter->m_iWEAPONTYPE == WEAPONTYPE)
		{
			break;
		}
		iIndex++;
	}
	return iIndex;
}

void Weapon::ShowWeaponInfo(int WEAPONTYPE, Player& User, string WeaponTypeName)
{
	int iSelect;
	int n = 2;
	int iGold;

	while (1)
	{
		system("cls");
		int iHeight = HEIGHT - 30;
		int iMax = WeaponCount(WEAPONTYPE);
		int iIndex = WeaponIndex(WEAPONTYPE);
		int iIndex_s = iIndex;
		iGold = User.GetGold();
		BLUE
			BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		ORIGINAL
			DrawMidText("보유 Gold : ", WIDTH, iHeight);
		cout << iGold;
		iHeight += n;
		DrawMidText(WeaponTypeName, WIDTH, iHeight);
		cout << " Shop";
		YELLOW
			for (int i = 0; i < iMax; i++)
			{
				if (i > 4)
					break;
				iHeight += n;
				gotoxy(WIDTH - 8, iHeight);
				cout << "가격 : " << WeaponList[iIndex].m_iPrice << "  무기 타입 : " << WeaponTypeName;
				iHeight += 1;
				gotoxy(WIDTH - 12, iHeight);
				cout << "무기이름 : " << WeaponList[iIndex].m_strName << "  공격력 : " << WeaponList[iIndex].m_iAttack;
				iIndex++;
			}
		ORIGINAL
			iHeight += n;
		DrawMidText("이전 페이지", WIDTH, iHeight);
		iHeight += 3;
		DrawMidText("다음 페이지", WIDTH, iHeight);
		iHeight += 3;
		DrawMidText("나가기", WIDTH, iHeight);
		if (iMax <= 5)
		{
			iSelect = MenuSelectCursor(iMax + 3, 3, WIDTH / 4, HEIGHT - 26);
			if (iSelect <= iMax)
			{
				iIndex_s = iIndex_s - 1 + iSelect;
				if (iGold < WeaponList[iIndex_s].m_iPrice)
					continue;
				else
					User.BuyWeapon(WeaponList[iIndex_s].m_iPrice);
				continue;
			}
			else if (iSelect == iMax + 1)
				continue;
			else if (iSelect == iMax + 2)
			{
				NextPage(WEAPONTYPE, User, WeaponTypeName);
				return;
			}
			else if (iSelect == iMax + 3)
				return;
		}
		else
		{
			iSelect = MenuSelectCursor(8, 3, WIDTH / 4, HEIGHT - 26);
			if (iSelect <= 5)
			{
				iIndex_s = iIndex_s - 1 + iSelect;
				if (iGold < WeaponList[iIndex_s].m_iPrice)
					continue;
				else
					User.BuyWeapon(WeaponList[iIndex_s].m_iPrice);
				continue;
			}
			else if (iSelect == 6)
				continue;
			else if (iSelect == 7)
			{
				NextPage(WEAPONTYPE, User, WeaponTypeName);
				return;
			}
			else if (iSelect == 8)
				return;
		}
	}
}

void Weapon::NextPage(int WEAPONTYPE, Player& User, string WeaponTypeName)
{
	int iSelect;
	int n = 2;
	int iGold;

	while (1)
	{
		system("cls");
		int iHeight = HEIGHT - 30;
		int iMax = WeaponCount(WEAPONTYPE);
		int iIndex = WeaponIndex(WEAPONTYPE) + 5;
		int iIndex_s = iIndex;
		iGold = User.GetGold();
		BLUE
			BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		ORIGINAL
			DrawMidText("보유 Gold : ", WIDTH, iHeight);
		cout << iGold;
		iHeight += n;
		DrawMidText(WeaponTypeName, WIDTH, iHeight);
		cout << " Shop";
		YELLOW
			for (int i = 5; i < iMax; i++)
			{
				if (i > 10)
					break;
				iHeight += n;
				gotoxy(WIDTH - 8, iHeight);
				cout << "가격 : " << WeaponList[iIndex].m_iPrice << "  무기 타입 : " << WeaponTypeName;
				iHeight += 1;
				gotoxy(WIDTH - 12, iHeight);
				cout << "무기이름 : " << WeaponList[iIndex].m_strName << "  공격력 : " << WeaponList[iIndex].m_iAttack;
				iIndex++;
			}
		ORIGINAL
			iHeight += n;
		DrawMidText("이전 페이지", WIDTH, iHeight);
		iHeight += 3;
		DrawMidText("다음 페이지", WIDTH, iHeight);
		iHeight += 3;
		DrawMidText("나가기", WIDTH, iHeight);
		if (iMax - 5 <= 5)
		{
			iSelect = MenuSelectCursor(iMax - 5 + 3, 3, WIDTH / 4, HEIGHT - 26);
			if (iSelect <= iMax - 5)
			{
				iIndex_s = iIndex_s - 1 + iSelect;
				if (iGold < WeaponList[iIndex_s].m_iPrice)
					continue;
				else
					User.BuyWeapon(WeaponList[iIndex_s].m_iPrice);
				continue;
			}
			else if (iSelect == iMax - 5 + 1)
			{
				ShowWeaponInfo(WEAPONTYPE, User, WeaponTypeName);
				return;
			}
			else if (iSelect == iMax - 5 + 2)
				continue;
			else if (iSelect == iMax - 5 + 3)
				return;
		}
		else
		{
			iSelect = MenuSelectCursor(8, 3, WIDTH / 4, HEIGHT - 26);
			if (iSelect <= 5)
			{
				iIndex_s = iIndex_s - 1 + iSelect;
				if (iGold < WeaponList[iIndex_s].m_iPrice)
					continue;
				else
					User.BuyWeapon(WeaponList[iIndex_s].m_iPrice);
				continue;
			}
			else if (iSelect == 6)
			{
				ShowWeaponInfo(WEAPONTYPE, User, WeaponTypeName);
				return;
			}
			else if (iSelect == 7)
				continue;
			else if (iSelect == 8)
				return;
		}
	}
}

void Weapon::LoadWeapon()
{
	ifstream m_fLoad;
	WeaponInfo tmp;
	int iMax;

	m_fLoad.open("WeaponList.txt");

	if (m_fLoad.is_open())
	{
		m_fLoad >> iMax;
		for (int i = 0; i < iMax; i++)
		{
			m_fLoad >> tmp.m_iWEAPONTYPE >> tmp.m_strName >> tmp.m_iAttack >> tmp.m_iPrice;
			WeaponList.push_back(tmp);
		}
	}
	m_fLoad.close();
}


Weapon::~Weapon()
{
}