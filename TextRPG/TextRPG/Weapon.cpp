#include "Player.h"
#include "Weapon.h"

Weapon::Weapon()
{
	
}

vector<Weapon*> Weapon::LoadWeapon(int WEAPONTYPE, vector<Weapon*> WeaponList, Weapon* tmp)
{
	ifstream m_fLoad;
	int iMax;
	WeaponStatus sTmp;

	m_fLoad.open("WeaponList.txt");
	if (m_fLoad.is_open())
	{
		m_fLoad >> iMax;
		for (int i = 0; i < iMax; i++)
		{
			tmp = new Weapon;
			m_fLoad >> sTmp.m_iWEAPONTYPE;
			m_fLoad >> sTmp.m_strName >> sTmp.m_iAttack >> sTmp.m_iPrice;
			if (WEAPONTYPE == sTmp.m_iWEAPONTYPE)
			{
				tmp->SetWeapon(sTmp);
				WeaponList.push_back(tmp);
			}
		}
	}
	m_fLoad.close();
	delete tmp;

	return WeaponList;
}

void Weapon::ShowWeapon(int i, int iHeight, string WeaponTypeName)
{
	iHeight += i;
	m_DrawManager.gotoxy(WIDTH - 8, iHeight);
	cout << "가격 : " << m_WeaponStatus.m_iPrice << "  무기 타입 : " << WeaponTypeName;
	iHeight += 1;
	m_DrawManager.gotoxy(WIDTH - 12, iHeight);
	cout << "무기이름 : " << m_WeaponStatus.m_strName << "  공격력 : " << m_WeaponStatus.m_iAttack;
}

void WeaponManager::LoadAllWeapon()
{
	Bow m_Bow;
	Dagger m_Dagger;
	Gun m_Gun;
	Sword m_Sword;
	Wand m_Wand;
	Hammer m_Hammer;

	WeaponList = m_Bow.LoadWeapon(BOW, WeaponList, &m_Bow);
	WeaponList = m_Dagger.LoadWeapon(DAGGER, WeaponList, &m_Dagger);
	WeaponList = m_Gun.LoadWeapon(GUN, WeaponList, &m_Gun);
	WeaponList = m_Sword.LoadWeapon(SWORD, WeaponList, &m_Sword);
	WeaponList = m_Wand.LoadWeapon(WAND, WeaponList, &m_Wand);
	WeaponList = m_Hammer.LoadWeapon(HAMMER, WeaponList, &m_Hammer);
}

int WeaponManager::WeaponCount(int WEAPONTYPE)
{
	int iCount = 0;
	for (vector<Weapon*>::iterator iter = WeaponList.begin(); iter != WeaponList.end(); iter++)
	{
		if ((*iter)->GetWeaponType(iter) == WEAPONTYPE)
		{
			iCount++;
		}
	}
	return iCount;
}

int WeaponManager::WeaponIndex(int WEAPONTYPE)
{
	int iIndex = 0;
	for (vector<Weapon*>::iterator iter = WeaponList.begin(); iter != WeaponList.end(); iter++)
	{
		if ((*iter)->GetWeaponType(iter) == WEAPONTYPE)
		{
			break;
		}
		iIndex++;
	}
	return iIndex;
}

void WeaponManager::ShowWeaponInfo(int WEAPONTYPE, Player& User, string WeaponTypeName)
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
			m_DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		ORIGINAL
			m_DrawManager.DrawMidText("보유 Gold : ", WIDTH, iHeight);
		cout << iGold;
		iHeight += n;
		m_DrawManager.DrawMidText(WeaponTypeName, WIDTH, iHeight);
		cout << " Shop";
		YELLOW
		for (int i = 0; i < iMax; i++)
		{
			if (i > 4)
				break;
			if (WeaponList[iIndex]->GetWeaponType() == WEAPONTYPE)
			{
				WeaponList[iIndex]->ShowWeapon(n, iHeight, WeaponTypeName);
				iHeight += n + 1;
				iIndex++;
			}
		}
		ORIGINAL
			iHeight += n;
		m_DrawManager.DrawMidText("이전 페이지", WIDTH, iHeight);
		iHeight += 3;
		m_DrawManager.DrawMidText("다음 페이지", WIDTH, iHeight);
		iHeight += 3;
		m_DrawManager.DrawMidText("나가기", WIDTH, iHeight);
		if (iMax <= 5)
		{
			iSelect = m_DrawManager.MenuSelectCursor(iMax + 3, 3, WIDTH / 4, HEIGHT - 26);
			if (iSelect <= iMax)
			{
				iIndex_s = iIndex_s - 1 + iSelect;
				if (iGold < WeaponList[iIndex_s]->GetPrice())
					continue;
				else
				{
					User.BuyWeapon(WeaponList[iIndex_s]->GetPrice());
					User.EquipWeapon(WeaponList, iIndex_s);
				}
				continue;
			}
			else if (iSelect == iMax + 1)
				continue;
			else if (iSelect == iMax + 2)
				continue;
			else if (iSelect == iMax + 3)
				return;
		}
		else // 5이상일때
		{
			iSelect = m_DrawManager.MenuSelectCursor(8, 3, WIDTH / 4, HEIGHT - 26);
			if (iSelect <= 5)
			{
				iIndex_s = iIndex_s - 1 + iSelect;
				if (iGold < WeaponList[iIndex_s]->GetPrice())
					continue;
				else
				{
					User.BuyWeapon(WeaponList[iIndex_s]->GetPrice());
					User.EquipWeapon(WeaponList, iIndex_s);
				}
				continue;
			}
			else if (iSelect == 5 + 1)
			{
				ShowWeaponInfo(WEAPONTYPE, User, WeaponTypeName);
				return;
			}
			else if (iSelect == 5 + 2)
			{
				if (iMax > 5)
				{
					iMax -= 5;
				}
				ShowWeaponInfo(WEAPONTYPE, User, WeaponTypeName, iMax, iIndex);
				return;
			}
			else if (iSelect == 5 + 3)
				return;
		}
	}
}

void WeaponManager::ShowWeaponInfo(int WEAPONTYPE, Player& User, string WeaponTypeName, int iMax, int iIndex)
{
	int iSelect, iCur = 0;
	int n = 2;
	int iGold;
	int iIndex_s = iIndex;

	while (1)
	{
		system("cls");
		int iHeight = HEIGHT - 30;
		iGold = User.GetGold();
		BLUE
			m_DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		ORIGINAL
			m_DrawManager.DrawMidText("보유 Gold : ", WIDTH, iHeight);
		cout << iGold;
		iHeight += n;
		m_DrawManager.DrawMidText(WeaponTypeName, WIDTH, iHeight);
		cout << " Shop";
		YELLOW
			for (int i = 0; i < iMax; i++)
			{
				if (i > 4)
					break;
				if (WeaponList[iIndex]->GetWeaponType() == WEAPONTYPE)
				{
					WeaponList[iIndex]->ShowWeapon(n, iHeight, WeaponTypeName);
					iHeight += n + 1;
					iIndex++;
					iCur++;
				}
			}
		ORIGINAL
			iHeight += n;
		m_DrawManager.DrawMidText("이전 페이지", WIDTH, iHeight);
		iHeight += 3;
		m_DrawManager.DrawMidText("다음 페이지", WIDTH, iHeight);
		iHeight += 3;
		m_DrawManager.DrawMidText("나가기", WIDTH, iHeight);
		if (iMax <= 5)
		{
			iIndex -= iCur;
			iSelect = m_DrawManager.MenuSelectCursor(iMax + 3, 3, WIDTH / 4, HEIGHT - 26);
			if (iSelect <= iMax)
			{
				iIndex_s = iIndex_s - 1 + iSelect;
				if (iGold < WeaponList[iIndex_s]->GetPrice())
					continue;
				else
				{
					User.BuyWeapon(WeaponList[iIndex_s]->GetPrice());
					User.EquipWeapon(WeaponList, iIndex_s);
				}
				continue;
			}
			else if (iSelect == iMax + 1)
			{
				ShowWeaponInfo(WEAPONTYPE, User, WeaponTypeName);
				return;
			}
			else if (iSelect == iMax + 2)
				continue;
			else if (iSelect == iMax + 3)
				return;
		}
		else // 5이상일때
		{
			iSelect = m_DrawManager.MenuSelectCursor(8, 3, WIDTH / 4, HEIGHT - 26);
			if (iSelect <= 5)
			{
				iIndex_s = iIndex_s - 1 + iSelect;
				if (iGold < WeaponList[iIndex_s]->GetPrice())
					continue;
				else
				{
					User.BuyWeapon(WeaponList[iIndex_s]->GetPrice());
					User.EquipWeapon(WeaponList, iIndex_s);
				}
				continue;
			}
			else if (iSelect == 5 + 1)
			{
				ShowWeaponInfo(WEAPONTYPE, User, WeaponTypeName);
				return;
			}
			else if (iSelect == 5 + 2)
			{
				if (iMax > 5)
				{
					iMax -= 5;
				}
				ShowWeaponInfo(WEAPONTYPE, User, WeaponTypeName, iMax, iIndex);

				return;
			}
			else if (iSelect == 5 + 3)
				return;
		}
	}
}
Weapon::~Weapon()
{
}