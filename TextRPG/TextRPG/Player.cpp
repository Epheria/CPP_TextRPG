#include "Player.h"

Player::Player()
{
	m_iEXP = 0;
	m_iWeaponSelect = 0;
	m_bWeapon = false;
}

void Player::CreateName()
{
	cin >> m_Status.m_strName;
}

void Player::LoadDefaultInfo()
{
	ifstream m_fLoad;

	m_fLoad.open("DefaultPlayer.txt");
	if (m_fLoad.is_open())
	{
		m_fLoad >> m_Status.m_iAttack;
		m_fLoad >> m_Status.m_iHP;
		m_fLoad >> m_Status.m_iDefaultEXP;
		m_fLoad >> m_Status.m_iGetEXP;
		m_fLoad >> m_Status.m_iLevel;
		m_fLoad >> m_Status.m_iGold;
		m_Status.m_iDefaultHP = m_Status.m_iHP;
	}
	m_fLoad.close();
}

void Player::ShowInfo()
{
	int iSelect;
	int iHeight = HEIGHT - 20;
	while (1)
	{
		system("cls");
		BLUE
			m_DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		YELLOW
		PlayerInfo(iHeight);
		if (m_bWeapon == true)
		{
			m_DrawManager.DrawMidText("무기타입 : ", WIDTH - 22, HEIGHT / 2);
			ShowWeaponType(m_Inventory[m_iWeaponSelect]->GetWeaponType());
			cout << " 무기이름 : " << m_Inventory[m_iWeaponSelect]->GetName() << "  공격력 : " << m_Inventory[m_iWeaponSelect]->GetAttack();
		}
		ORIGINAL
			m_DrawManager.DrawMidText("인벤토리", WIDTH, HEIGHT / 2 + 3);
		m_DrawManager.DrawMidText("나가기", WIDTH, HEIGHT / 2 + 6);
		iSelect = m_DrawManager.MenuSelectCursor(2, 3, WIDTH / 4, HEIGHT / 2 + 3);

		switch (iSelect)
		{
		case 1:
			ShowInventory();
			break;
		case 2:
			return;
		}
	}
}

void Player::PlayerInfo(int iHeight)
{
	m_DrawManager.DrawMidText("===== ", WIDTH - 8, iHeight);
	cout << m_Status.m_strName << "(" << m_Status.m_iLevel << "Lv)" << " =====" << endl;
	m_DrawManager.DrawMidText("공격력 = ", WIDTH - 10, iHeight + 1);
	cout << m_Status.m_iAttack << "\t" << " 생명력 = " << m_Status.m_iHP << "/" << m_Status.m_iDefaultHP << endl;
	m_DrawManager.DrawMidText("경험치 = ", WIDTH - 10, iHeight + 2);
	cout << m_iEXP << "/" << m_Status.m_iDefaultEXP << "\t" << " GetEXP : " << m_Status.m_iGetEXP << endl;
	m_DrawManager.DrawMidText("Gold = ", WIDTH - 11, iHeight + 3);
	cout << m_Status.m_iGold << endl;
}

void Player::ShowInventory()
{
	int iSelect;
	int n = 2;
	if (m_Inventory.empty())
		return;

	system("cls");
	int iHeight = HEIGHT - 30;
	BLUE
		m_DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	ORIGINAL
		m_DrawManager.DrawMidText("§§§ Inventory §§§", WIDTH, iHeight);
	YELLOW
		for (vector<Weapon*>::iterator iter = m_Inventory.begin(); iter != m_Inventory.end(); iter++)
		{
			iHeight += n;
			m_DrawManager.gotoxy(WIDTH - 8, iHeight);
			cout << (*iter)->GetName();
		}
	iSelect = m_DrawManager.MenuSelectCursor(m_Inventory.size(), 2, WIDTH / 4, HEIGHT - 28);
	m_iWeaponSelect = iSelect - 1;
	m_bWeapon = true;
}

void Player::ShowWeaponType(int iType)
{
	switch (iType)
	{
	case 1:
		cout << "Bow";
		break;
	case 2:
		cout << "Dagger";
		break;
	case 3:
		cout << "Gun";
		break;
	case 4:
		cout << "Sword";
		break;
	case 5:
		cout << "Wand";
		break;
	case 6:
		cout << "Hammer";
		break;
	}
}

void Player::Win(Monster m_Monster, int index)
{
	char ch;
	int getGold;
	system("cls");
	BLUE
		m_DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	RED
		m_DrawManager.gotoxy(WIDTH - 4, HEIGHT - 20);
	cout << m_Status.m_strName << " 승리!!";
	m_DrawManager.gotoxy(WIDTH - 4, HEIGHT - 17);
	cout << m_Status.m_strName << "가 경험치 ";
	m_Status.m_iGetEXP = m_Monster.GiveEXP();
	cout << m_Status.m_iGetEXP << "를 얻었습니다.";
	ch = _getch();

	getGold = m_Monster.GiveGold();
	m_Status.m_iGold += getGold;
	m_iEXP += m_Status.m_iGetEXP;
	if (m_iEXP >= m_Status.m_iDefaultEXP)
	{
		for (int i = 0; m_iEXP >= m_Status.m_iDefaultEXP; i++)
		{
			m_iEXP -= m_Status.m_iDefaultEXP;
			LevelUP();
		}
	}

	m_Status.m_iGetEXP = 0;
}

void Player::LevelUP()
{
	char ch;
	int GetAtk;
	int GetHP;

	system("cls");
	BLUE
		m_DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	RED
		m_DrawManager.gotoxy(WIDTH, HEIGHT - 20);
	cout << m_Status.m_strName << "레벨업!!";
	m_DrawManager.gotoxy(WIDTH, HEIGHT - 17);
	GetAtk = 1;
	GetHP = 10;
	cout << "공격력 " << GetAtk << " 증가!!";
	m_DrawManager.gotoxy(WIDTH, HEIGHT - 14);
	cout << "생명력 " << GetHP << " 증가!!";
	ch = _getch();

	m_Status.m_iLevel++;
	m_Status.m_iAttack += GetAtk;
	m_Status.m_iDefaultHP += GetHP;
	m_Status.m_iHP = m_Status.m_iDefaultHP;
	m_Status.m_iDefaultEXP += 3;
}

void Player::Save(ofstream& m_fSave, int iSelect, string m_FileName[])
{
	char ch;
	m_fSave.open(m_FileName[iSelect - 1]);
	if (m_fSave.is_open())
	{
		m_fSave << m_Status.m_strName << " " << m_Status.m_iAttack << " " << m_Status.m_iHP << " " << m_Status.m_iDefaultEXP << " "
			<< m_Status.m_iGetEXP << " " << m_Status.m_iLevel << " " << m_Status.m_iGold << " " << m_iEXP << " " << m_Status.m_iDefaultHP << endl;
		m_fSave << m_Inventory.size() << endl;
		if (!m_Inventory.empty())
		{
			for (vector<Weapon*>::iterator iter = m_Inventory.begin(); iter != m_Inventory.end(); iter++)
			{
				m_fSave << (*iter)->GetWeaponType(iter) << " " << (*iter)->GetName() << " " << (*iter)->GetAttack() << " " << (*iter)->GetPrice() << endl;
			}
		}
	}
	system("cls");
	BLUE
		m_DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	ORIGINAL
		m_DrawManager.gotoxy(WIDTH - 4, HEIGHT / 3 + 4);
	cout << "Save 완료";
	ch = _getch();
}

void Player::Load(ifstream& m_fLoad, int iSelect)
{
	char ch;
	int invenSize;
	WeaponStatus tmp;
	Weapon* wTmp = new Weapon; // 포인터인데 가리키는 값이 없어서 처음에 에러뜸
	// 그래서 NULL 로 초기화했더니 SetWeapon 에서 예외발생함
	// 그래서 Weapon.cpp 에서 WeaponList.txt 불러올때랑 마찬가지로 동적할당으로 변경

	m_fLoad >> m_Status.m_strName >> m_Status.m_iAttack >> m_Status.m_iHP >> 
		m_Status.m_iDefaultEXP >> m_Status.m_iGetEXP >> m_Status.m_iLevel >> m_Status.m_iGold >> m_iEXP >> m_Status.m_iDefaultHP;
	m_fLoad >> invenSize;
	if (invenSize > 0)
	{
		for (int i = 0; i < invenSize; i++)
		{
			m_fLoad >> tmp.m_iWEAPONTYPE >> tmp.m_strName >> tmp.m_iAttack >> tmp.m_iPrice;
			wTmp->SetWeapon(tmp);
			m_Inventory.push_back(wTmp);
		}
	}
	system("cls");
	BLUE
		m_DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	ORIGINAL
		m_DrawManager.gotoxy(WIDTH - 4, HEIGHT / 3 + 4);
	cout << "Load 완료";
	ch = _getch();
	delete wTmp;
}

int Player::Attack()
{
	Weapon* tmp;
	int SkillAtk;
	int SumAtk;
	if (m_Inventory.empty())
		return m_Status.m_iAttack;
	else
	{
		SumAtk = m_Status.m_iAttack + m_Inventory[m_iWeaponSelect]->GetAttack();
		tmp = m_Inventory[m_iWeaponSelect];

		switch (m_Inventory[m_iWeaponSelect]->GetWeaponType())
		{
		case 1:
		{
			Bow* tmp2;
			tmp2 = (Bow*)tmp;
			SkillAtk = tmp2->UseSkill(SumAtk);
			return SkillAtk;
		}
		case 2:
		{
			Dagger* tmp2;
			tmp2 = (Dagger*)tmp;
			SkillAtk = tmp2->UseSkill(SumAtk);
			return SkillAtk;
		}
		case 3:
		{
			Gun* tmp2;
			tmp2 = (Gun*)tmp;
			SkillAtk = tmp2->UseSkill(SumAtk);
			return SkillAtk;
		}
		case 4:
		{
			Sword* tmp2;
			tmp2 = (Sword*)tmp;
			SkillAtk = tmp2->UseSkill(SumAtk);
			return SkillAtk;
		}
		case 5:
		{
			Wand* tmp2;
			tmp2 = (Wand*)tmp;
			SkillAtk = tmp2->UseSkill(SumAtk);
			return SkillAtk;
		}
		case 6:
		{
			Hammer* tmp2;
			tmp2 = (Hammer*)tmp;
			SkillAtk = tmp2->UseSkill(SumAtk);
			return SkillAtk;
		}
		}
	}
}

Player::~Player()
{
}