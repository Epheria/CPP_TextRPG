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
	
int WeaponManager::WeaponCount(WEAPONTYPE eType)
{
	int iCount = 0;
	for (vector<Weapon*>::iterator iter = WeaponList.begin(); iter != WeaponList.end(); iter++)
	{
		if ((*iter)->GetWeaponType(iter) == eType)
		{
			
			iCount++;
		}
	}
	return iCount;
}

int WeaponManager::WeaponIndex(WEAPONTYPE eType)
{
	int iIndex = 0;
	for (vector<Weapon*>::iterator iter = WeaponList.begin(); iter != WeaponList.end(); iter++)
	{
		if ((*iter)->GetWeaponType(iter) == eType)
		{
			break;
		}
		iIndex++;
	}
	return iIndex;
}

void WeaponManager::ShowWeaponInfo(WEAPONTYPE eType, Player& User, string WeaponTypeName)
{
	int iSelect, index = 0;
	int n = 2;
	int iGold = User.GetGold(), iCur = 0;
	vector<Weapon*> tmp;
	vector<Weapon*>::iterator iter;
	vector<Weapon*>::iterator iter2;

	for (iter = WeaponList.begin(); iter != WeaponList.end(); iter++)
		if ((*iter)->GetWeaponType() == eType)
			tmp.push_back(*iter);

	int iMax = tmp.size();
	iter = tmp.begin();

	while (1)
	{
		if (tmp.size() <= 5)
		{
			ShowList(tmp, User, WeaponTypeName);
			iSelect = m_DrawManager.MenuSelectCursor(tmp.size() + 3, 3, WIDTH / 4, HEIGHT - 26);
			if (iSelect <= tmp.size())
			{
				if (iGold < tmp[iSelect - 1]->GetPrice())
					continue;
				else
				{
					User.BuyWeapon(tmp[iSelect - 1]->GetPrice());
					User.EquipWeapon(tmp, iSelect - 1);
				}
				continue;
			}
			else if (iSelect == tmp.size() + 1)
				continue;
			else if (iSelect == tmp.size() + 2)
				continue;
			else if (iSelect == tmp.size() + 3)
				return;
		}
		else
		{
			int iSel;
			if (iMax > 5)
			{
				iSel = 5;
			}
			else
			{
				iSel = iMax;
			}

			iter = ShowList(tmp, iter, User, WeaponTypeName);
			iter2 = iter;

			iSelect = m_DrawManager.MenuSelectCursor(iSel + 3, 3, WIDTH / 4, HEIGHT - 26);
			index += iSelect - 1;

			if (iSelect <= 5)
			{
				if (iGold < tmp[index]->GetPrice())
				{
					index = 0;
					continue;
				}
				else
				{
					User.BuyWeapon(tmp[index]->GetPrice());
					User.EquipWeapon(tmp, index);
					iter = iter2;
				}
				index = 0;
				continue;
			}
			else if (iSelect == 6)
			{
				if (iMax != tmp.size())
				{
					index -= 5;
					iMax += 5;
					iter - 4;
				}
				else
				{
					iter = iter2;
				}
				continue;
			}
			else if (iSelect == 7)
			{
				if (iMax > 5)
				{
					index += 5;
					iMax -= 5;
				}
				else
				{
					iter = iter2;
				}
				continue;
			}
			else if (iSelect == 8)
				return;
		}
	}
}

void WeaponManager::ShowList(vector<Weapon*> tmp, Player& User, string WeaponTypeName)
{
	int iGold, n = 2, iCur = 0;

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
		for (vector<Weapon*>::iterator iter = tmp.begin(); iter != tmp.end(); iter++)
		{
			if (iCur == 5)
			{
				iCur = 0;
				break;
			}
			(*iter)->ShowWeapon(n, iHeight, WeaponTypeName);
			iHeight += n + 1;
			iCur++;
		}
	ORIGINAL
		iHeight += n;
	m_DrawManager.DrawMidText("이전 페이지", WIDTH, iHeight);
	iHeight += 3;
	m_DrawManager.DrawMidText("다음 페이지", WIDTH, iHeight);
	iHeight += 3;
	m_DrawManager.DrawMidText("나가기", WIDTH, iHeight);
}

vector<Weapon*>::iterator WeaponManager::ShowList(vector<Weapon*>& tmp, vector<Weapon*>::iterator& iter, Player& User, string WeaponTypeName)
{
	int iSelect, iGold, n = 2, iCur = 0;
	vector<Weapon*>::iterator titer;

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
		for (titer = iter; titer != tmp.end(); titer++)
		{
			if (iCur == 5)
			{
				iCur = 0;
				break;
			}
			(*titer)->ShowWeapon(n, iHeight, WeaponTypeName);
			iHeight += n + 1;
			iCur++;
		}
	ORIGINAL
		iHeight += n;
	m_DrawManager.DrawMidText("이전 페이지", WIDTH, iHeight);
	iHeight += 3;
	m_DrawManager.DrawMidText("다음 페이지", WIDTH, iHeight);
	iHeight += 3;
	m_DrawManager.DrawMidText("나가기", WIDTH, iHeight);

	return titer;
}

//void WeaponManager::ShowWeaponInfo(WEAPONTYPE eType, Player& User, string WeaponTypeName, int iMax, int iIndex)
//{
//	int iSelect, iCur = 0;
//	int n = 2;
//	int iGold;
//	int iIndex_s = iIndex;
//
//	while (1)
//	{
//		system("cls");
//		int iHeight = HEIGHT - 30;
//		iGold = User.GetGold();
//		BLUE
//			m_DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
//		ORIGINAL
//			m_DrawManager.DrawMidText("보유 Gold : ", WIDTH, iHeight);
//		cout << iGold;
//		iHeight += n;
//		m_DrawManager.DrawMidText(WeaponTypeName, WIDTH, iHeight);
//		cout << " Shop";
//		YELLOW
//			for (int i = 0; i < iMax; i++)
//			{
//				if (i > 4)
//					break;
//				if (WeaponList[iIndex]->GetWeaponType() == eType)
//				{
//					WeaponList[iIndex]->ShowWeapon(n, iHeight, WeaponTypeName);
//					iHeight += n + 1;
//					iIndex++;
//					iCur++;
//				}
//			}
//		ORIGINAL
//			iHeight += n;
//		m_DrawManager.DrawMidText("이전 페이지", WIDTH, iHeight);
//		iHeight += 3;
//		m_DrawManager.DrawMidText("다음 페이지", WIDTH, iHeight);
//		iHeight += 3;
//		m_DrawManager.DrawMidText("나가기", WIDTH, iHeight);
//		if (iMax <= 5)
//		{
//			iIndex -= iCur;
//			iSelect = m_DrawManager.MenuSelectCursor(iMax + 3, 3, WIDTH / 4, HEIGHT - 26);
//			if (iSelect <= iMax)
//			{
//				iIndex_s = iIndex_s - 1 + iSelect;
//				if (iGold < WeaponList[iIndex_s]->GetPrice())
//					continue;
//				else
//				{
//					User.BuyWeapon(WeaponList[iIndex_s]->GetPrice());
//					User.EquipWeapon(WeaponList, iIndex_s);
//				}
//				continue;
//			}
//			else if (iSelect == iMax + 1)
//			{
//				ShowWeaponInfo(eType, User, WeaponTypeName);
//				return;
//			}
//			else if (iSelect == iMax + 2)
//				continue;
//			else if (iSelect == iMax + 3)
//				return;
//		}
//		else // 5이상일때
//		{
//			iSelect = m_DrawManager.MenuSelectCursor(8, 3, WIDTH / 4, HEIGHT - 26);
//			if (iSelect <= 5)
//			{
//				iIndex_s = iIndex_s - 1 + iSelect;
//				if (iGold < WeaponList[iIndex_s]->GetPrice())
//					continue;
//				else
//				{
//					User.BuyWeapon(WeaponList[iIndex_s]->GetPrice());
//					User.EquipWeapon(WeaponList, iIndex_s);
//				}
//				continue;
//			}
//			else if (iSelect == 5 + 1)
//			{
//				ShowWeaponInfo(eType, User, WeaponTypeName);
//				return;
//			}
//			else if (iSelect == 5 + 2)
//			{
//				if (iMax > 5)
//				{
//					iMax -= 5;
//				}
//				ShowWeaponInfo(eType, User, WeaponTypeName, iMax, iIndex);
//
//				return;
//			}
//			else if (iSelect == 5 + 3)
//				return;
//		}
//	}
//}

Weapon::~Weapon()
{
}