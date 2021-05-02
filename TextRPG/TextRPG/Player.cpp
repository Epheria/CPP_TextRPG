#include "Player.h"

Player::Player()
{
	m_iDefaultHP = 1000;
	m_iEXP = 0;
	m_iWeaponSelect = 0;
	m_bWeapon = false;
}

void Player::CreateName()
{
	cin >> m_strPlayerName;
}

void Player::LoadDefaultInfo()
{
	ifstream m_fLoad;

	m_fLoad.open("DefaultPlayer.txt");
	if (m_fLoad.is_open())
	{
		m_fLoad >> m_iAttack;
		m_fLoad >> m_iHP;
		m_fLoad >> m_iDefaultEXP;
		m_fLoad >> m_iGetEXP;
		m_fLoad >> m_iLevel;
		m_fLoad >> m_iGold;
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
			BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		YELLOW
		PlayerInfo(iHeight);
		if (m_bWeapon == true)
		{
			DrawMidText("����Ÿ�� : ", WIDTH - 22, HEIGHT / 2);
			ShowWeaponType(m_Inventory[m_iWeaponSelect].m_iWEAPONTYPE);
			cout << " �����̸� : " << m_Inventory[m_iWeaponSelect].m_strName << "  ���ݷ� : " << m_Inventory[m_iWeaponSelect].m_iAttack;
		}
		ORIGINAL
			DrawMidText("�κ��丮", WIDTH, HEIGHT / 2 + 3);
		DrawMidText("������", WIDTH, HEIGHT / 2 + 6);
		iSelect = MenuSelectCursor(2, 3, WIDTH / 4, HEIGHT / 2 + 3);

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
	DrawMidText("===== ", WIDTH - 8, iHeight);
	cout << m_strPlayerName << "(" << m_iLevel << "Lv)" << " =====" << endl;
	DrawMidText("���ݷ� = ", WIDTH - 10, iHeight + 1);
	cout << m_iAttack << "\t" << " ����� = " << m_iHP << "/" << m_iDefaultHP << endl;
	DrawMidText("����ġ = ", WIDTH - 10, iHeight + 2);
	cout << m_iEXP << "/" << m_iDefaultEXP << "\t" << " GetEXP : " << m_iGetEXP << endl;
	DrawMidText("Gold = ", WIDTH - 11, iHeight + 3);
	cout << m_iGold << endl;
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
		BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	ORIGINAL
		DrawMidText("�סס� Inventory �סס�", WIDTH, iHeight);
	YELLOW
		for (vector<WeaponInfo>::iterator iter = m_Inventory.begin(); iter != m_Inventory.end(); iter++)
		{
			iHeight += n;
			gotoxy(WIDTH - 8, iHeight);
			cout << iter->m_strName;
		}
	iSelect = MenuSelectCursor(m_Inventory.size(), 2, WIDTH / 4, HEIGHT - 28);
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

void Player::Win(Monster& m_Monster, int index)
{
	char ch;
	int getGold;
	system("cls");
	BLUE
		BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	RED
		gotoxy(WIDTH - 4, HEIGHT - 20);
	cout << m_strPlayerName << " �¸�!!";
	gotoxy(WIDTH - 4, HEIGHT - 17);
	cout << m_strPlayerName << "�� ����ġ ";
	m_iGetEXP = m_Monster.GiveEXP(index);
	cout << m_iGetEXP << "�� ������ϴ�.";
	ch = _getch();

	getGold = m_Monster.GiveGold(index);
	m_iGold += getGold;
	m_iEXP += m_iGetEXP;
	if (m_iEXP >= m_iDefaultEXP)
	{
		for (int i = 0; m_iEXP >= m_iDefaultEXP; i++)
		{
			m_iEXP -= m_iDefaultEXP;
			LevelUP();
		}
	}

	m_iGetEXP = 0;
}

void Player::LevelUP()
{
	char ch;
	int GetAtk;
	int GetHP;

	system("cls");
	BLUE
		BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	RED
		gotoxy(WIDTH, HEIGHT - 20);
	cout << m_strPlayerName << "������!!";
	gotoxy(WIDTH, HEIGHT - 17);
	GetAtk = 1;
	GetHP = 10;
	cout << "���ݷ� " << GetAtk << " ����!!";
	gotoxy(WIDTH, HEIGHT - 14);
	cout << "����� " << GetHP << " ����!!";
	ch = _getch();

	m_iLevel++;
	m_iAttack += GetAtk;
	m_iDefaultHP += GetHP;
	m_iHP = m_iDefaultHP;
	m_iDefaultEXP += 3;
}

void Player::Save(ofstream& m_fSave, int iSelect, string m_FileName[])
{
	char ch;
	m_fSave.open(m_FileName[iSelect - 1]);
	if (m_fSave.is_open())
	{
		m_fSave << m_strPlayerName << " " << m_iAttack << " " << m_iHP << " " << m_iDefaultEXP << " "
			<< m_iGetEXP << " " << m_iLevel << " " << m_iGold << " " << m_iEXP << " " << m_iDefaultHP << endl;
		m_fSave << m_Inventory.size() << endl;
		if (!m_Inventory.empty())
		{
			for (vector<WeaponInfo>::iterator iter = m_Inventory.begin(); iter != m_Inventory.end(); iter++)
			{
				m_fSave << iter->m_iWEAPONTYPE << " " << iter->m_strName << " " << iter->m_iAttack << " " << iter->m_iPrice << endl;
			}
		}
	}
	system("cls");
	BLUE
		BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	ORIGINAL
		gotoxy(WIDTH - 4, HEIGHT / 3 + 4);
	cout << "Save �Ϸ�";
	ch = _getch();
}

void Player::Load(ifstream& m_fLoad, int iSelect)
{
	char ch;
	int invenSize;
	WeaponInfo tmp;
	m_fLoad >> m_strPlayerName >> m_iAttack >> m_iHP >> m_iDefaultEXP >> m_iGetEXP >> m_iLevel >> m_iGold >> m_iEXP >> m_iDefaultHP;
	m_fLoad >> invenSize;
	if (invenSize > 0)
	{
		for (int i = 0; i < invenSize; i++)
		{
			m_fLoad >> tmp.m_iWEAPONTYPE >> tmp.m_strName >> tmp.m_iAttack >> tmp.m_iPrice;
			m_Inventory.push_back(tmp);
		}
	}
	system("cls");
	BLUE
		BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	ORIGINAL
		gotoxy(WIDTH - 4, HEIGHT / 3 + 4);
	cout << "Load �Ϸ�";
	ch = _getch();
}

Player::~Player()
{
}