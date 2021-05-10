#include "Player.h"
#include "Weapon.h"

Weapon::Weapon()
{
	
}

void Weapon::LoadWeapon(ifstream &fLoad, int iType)
{
	m_eWEAPONTYPE = (WEAPONTYPE)iType;
	fLoad >> m_strName >> m_iAttack >> m_iPrice;
}

void Weapon::ShowWeapon(int i, int iHeight, string WeaponTypeName)
{
	iHeight += i;
	m_DrawManager.gotoxy(WIDTH - 8, iHeight);
	cout << "가격 : " << m_iPrice << "  무기 타입 : " << WeaponTypeName;
	iHeight += 1;
	m_DrawManager.gotoxy(WIDTH - 12, iHeight);
	cout << "무기이름 : " << m_strName << "  공격력 : " << m_iAttack;
}

void WeaponManager::LoadAllWeapon()
{
	ifstream fLoad;
	int iMax, iType;
	
	fLoad.open("WeaponList.txt");
	if (fLoad.is_open())
	{
		Weapon* tmp = NULL;
		fLoad >> iMax;
		for (int i = 0; i < iMax; i++)
		{
			fLoad >> iType;
			switch ((WEAPONTYPE)iType)
			{
			case WEAPONTYPE_BOW:
				tmp = new Bow();
				break;
			case WEAPONTYPE_DAGGER:
				tmp = new Dagger();
				break;
			case WEAPONTYPE_GUN:
				tmp = new Gun();
				break;
			case WEAPONTYPE_HAMMER:
				tmp = new Hammer();
				break;
			case WEAPONTYPE_SWORD:
				tmp = new Sword();
				break;
			case WEAPONTYPE_WAND:
				tmp = new Wand();
				break;
			}
			tmp->LoadWeapon(fLoad, iType);
			WeaponList.push_back(tmp);
		}

		fLoad.close();
	}

}

int WeaponManager::WeaponCount(int iType)
{
	int iCount = 0;
	for (vector<Weapon*>::iterator iter = WeaponList.begin(); iter != WeaponList.end(); iter++)
	{
		if ((*iter)->GetWeaponType(iter) == iType)
		{
			iCount++;
		}
	}
	return iCount;
}

int WeaponManager::WeaponIndex(int iType)
{
	int iIndex = 0;
	for (vector<Weapon*>::iterator iter = WeaponList.begin(); iter != WeaponList.end(); iter++)
	{
		if ((*iter)->GetWeaponType(iter) == iType)
		{
			break;
		}
		iIndex++;
	}
	return iIndex;
}

void WeaponManager::ShowWeaponInfo(int iType, Player& User, string WeaponTypeName)
{
	int iSelect;
	int n = 2;
	int iGold;

	while (1)
	{
		system("cls");
		int iHeight = HEIGHT - 30;
		int iMax = WeaponCount(iType);
		int iIndex = WeaponIndex(iType);
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
			if (WeaponList[iIndex]->GetWeaponType() == iType)
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
				ShowWeaponInfo(iType, User, WeaponTypeName);
				return;
			}
			else if (iSelect == 5 + 2)
			{
				if (iMax > 5)
				{
					iMax -= 5;
				}
				ShowWeaponInfo(iType, User, WeaponTypeName, iMax, iIndex);
				return;
			}
			else if (iSelect == 5 + 3)
				return;
		}
	}
}

void WeaponManager::ShowWeaponInfo(int iType, Player& User, string WeaponTypeName, int iMax, int iIndex)
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
				if (WeaponList[iIndex]->GetWeaponType() == iType)
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
				ShowWeaponInfo(iType, User, WeaponTypeName);
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
				ShowWeaponInfo(iType, User, WeaponTypeName);
				return;
			}
			else if (iSelect == 5 + 2)
			{
				if (iMax > 5)
				{
					iMax -= 5;
				}
				ShowWeaponInfo(iType, User, WeaponTypeName, iMax, iIndex);

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