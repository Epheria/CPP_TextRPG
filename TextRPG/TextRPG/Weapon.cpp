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

void WeaponManager::ShowWeaponInfo(WEAPONTYPE eType, Player& User, string WeaponTypeName)
{
	int iSelect, index;
	int iSel;
	int n = 2;
	int iGold = User.GetGold(), iCur = 0;
	vector<Weapon*> tmp;
	vector<Weapon*>::iterator iter;

	for (iter = WeaponList.begin(); iter != WeaponList.end(); iter++)
		if ((*iter)->GetWeaponType() == eType)
			tmp.push_back(*iter);

	int iCurPageIndex = 1;
	int iMaxPage = tmp.size() / 5 + 1;
	int iMax = tmp.size();
	while (1)
	{
		if (iMax > 5)
			iSel = 5;
		else
			iSel = iMax;

		ShowList(tmp, User, WeaponTypeName, iCurPageIndex, iSel);
		iSelect = m_DrawManager.MenuSelectCursor(iSel + 3, 3, WIDTH / 4, HEIGHT - 26);

		if (iSelect <= iSel)
		{
			index = 0 + (iCurPageIndex - 1) * 5;
			if (iGold < tmp[index + iSelect - 1]->GetPrice())
				continue;
			else
			{
				if (User.InvenLimitCheck() == true)
				{
					system("cls");
					BLUE
						m_DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
					ORIGINAL
						m_DrawManager.DrawMidText("인벤토리 가 꽉찼습니다.", WIDTH, HEIGHT /2);
					char ch = _getch();
					continue;
				}
				User.BuyWeapon(tmp[index + iSelect - 1]->GetPrice());
				User.EquipWeapon(tmp, index + iSelect - 1);
				continue;
			}
		}
		else if (iSelect == iSel + 1)
		{
			if (iCurPageIndex == 1)
				continue;
			iMax += 5;
			iCurPageIndex--;
			continue;
		}
		else if (iSelect == iSel + 2)
		{
			if (iCurPageIndex == iMaxPage)
				continue;
			iMax -= 5;
			iCurPageIndex++;
			continue;
		}
		else if (iSelect == iSel + 3)
			return;
	}
}

void WeaponManager::ShowList(vector<Weapon*> tmp, Player& User, string WeaponTypeName, int iPage, int iMax)
{
	int iGold, n = 2, iCur = 0;
	int index;

	index = 0 + (iPage - 1) * 5;

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
			tmp[index + i]->ShowWeapon(n, iHeight, WeaponTypeName);
			iHeight += n + 1;
		}
	ORIGINAL
		iHeight += n;
	m_DrawManager.DrawMidText("이전 페이지", WIDTH, iHeight);
	iHeight += 3;
	m_DrawManager.DrawMidText("다음 페이지", WIDTH, iHeight);
	iHeight += 3;
	m_DrawManager.DrawMidText("나가기", WIDTH, iHeight);
}

Weapon::~Weapon()
{
}