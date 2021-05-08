#include "Player.h"
#include "Weapon.h"

Weapon::Weapon()
{

}

void Weapon::LoadWeapon(int WEAPONTYPE, vector<Weapon*>& WeaponList, Weapon* tmp)
{
	ifstream m_fLoad;
	int iMax;

	m_fLoad.open("WeaponList.txt");
	if (m_fLoad.is_open())
	{
		m_fLoad >> iMax;
		for (int i = 0; i < iMax; i++)
		{
			m_fLoad >> tmp->m_WeaponStatus.m_iWEAPONTYPE;
			if (WEAPONTYPE == tmp->m_WeaponStatus.m_iWEAPONTYPE)
			{
				m_fLoad >> tmp->m_WeaponStatus.m_strName >> tmp->m_WeaponStatus.m_iAttack >> tmp->m_WeaponStatus.m_iPrice;
				WeaponList.push_back(tmp);
			}
		}
	}
	m_fLoad.close();
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

//int Weapon::UseSkill(int WEAPONTYPE, int PlayerAtk)
//{
//	char ch;
//	int iRand = Random();
//
//	switch (WEAPONTYPE)
//	{
//	case 1:
//		if (iRand == 0 || iRand == 1)
//		{
//			YELLOW
//				DrawMidText("속사 발동!! 2연타!!", WIDTH, HEIGHT - 18);
//			ch = _getch();
//			return PlayerAtk * 2;
//		}
//		else
//			return PlayerAtk;
//	case 2:
//		if (iRand == 0)
//		{
//			YELLOW
//				DrawMidText("급소찌르기 발동!! 크리티컬 데미지", WIDTH, HEIGHT - 18);
//			ch = _getch();
//			return PlayerAtk * 3;
//		}
//		else
//			return PlayerAtk;
//	case 3:
//		if (iRand == 0)
//		{
//			YELLOW
//				DrawMidText("더블 탭 발동!! 크리티컬 + 2연타", WIDTH, HEIGHT - 18);
//			ch = _getch();
//			return PlayerAtk * 4;
//		}
//		else
//			return PlayerAtk;
//	case 4:
//		if (iRand == 0)
//		{
//			YELLOW
//				DrawMidText("검기 발동!! 크리티컬 데미지", WIDTH, HEIGHT - 18);
//			ch = _getch();
//			return PlayerAtk * 3;
//		}
//		else
//			return PlayerAtk;
//	case 5:
//		if (iRand == 0)
//		{
//			YELLOW
//				DrawMidText("파이어볼 발동!! 크리티컬 데미지", WIDTH, HEIGHT - 18);
//			ch = _getch();
//			return PlayerAtk * 6;
//		}
//		else
//			return PlayerAtk;
//	case 6:
//		if (iRand == 0)
//		{
//			YELLOW
//				DrawMidText("지면강타 발동!! 크리티컬 데미지", WIDTH, HEIGHT - 18);
//			ch = _getch();
//			return PlayerAtk * 4;
//		}
//		else
//			return PlayerAtk;
//	}
//}

void WeaponManager::LoadAllWeapon()
{
	Bow m_Bow;
	Dagger m_Dagger;
	Gun m_Gun;
	Sword m_Sword;
	Wand m_Wand;
	Hammer m_Hammer;

	m_Bow.LoadWeapon(BOW, WeaponList, &m_Bow);
	m_Dagger.LoadWeapon(DAGGER, WeaponList, &m_Dagger);
	m_Gun.LoadWeapon(DAGGER, WeaponList, &m_Gun);
	m_Sword.LoadWeapon(DAGGER, WeaponList, &m_Sword);
	m_Wand.LoadWeapon(DAGGER, WeaponList, &m_Wand);
	m_Hammer.LoadWeapon(DAGGER, WeaponList, &m_Hammer);
}

int WeaponManager::WeaponCount(int WEAPONTYPE)
{
	int iCount = 0;
	for (vector<Weapon*>::iterator iter = WeaponList.begin(); iter != WeaponList.end(); iter++)
	{
		if ((*iter)->GetWeaponType() == WEAPONTYPE)
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
		if ((*iter)->GetWeaponType() == WEAPONTYPE)
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
				WeaponList[i]->ShowWeapon(n, iHeight, WeaponTypeName);
				iIndex++;
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
		else if(iMax == 5)
		{
			iSelect = m_DrawManager.MenuSelectCursor(8, 3, WIDTH / 4, HEIGHT - 26);
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
			{
				iMax -= 5;
				iIndex += 5;
				ShowWeaponInfo(WEAPONTYPE, User, WeaponTypeName, iMax, iIndex);
				return;
			}
			else if (iSelect == iMax + 3)
				return;
		}
	}
}

void WeaponManager::ShowWeaponInfo(int WEAPONTYPE, Player& User, string WeaponTypeName, int iMax, int iIndex)
{
	int iSelect;
	int n = 2;
	int iGold;

	while (1)
	{
		system("cls");
		int iHeight = HEIGHT - 30;
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
				WeaponList[i]->ShowWeapon(n, iHeight, WeaponTypeName);
				iIndex++;
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
		else if (iMax == 5)
		{
			iSelect = m_DrawManager.MenuSelectCursor(8, 3, WIDTH / 4, HEIGHT - 26);
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
			{
				iMax -= 5;
				iIndex += 5;
				ShowWeaponInfo(WEAPONTYPE, User, WeaponTypeName, iMax, iIndex);
				return;
			}
			else if (iSelect == iMax + 3)
				return;
		}
	}
}
Weapon::~Weapon()
{
}