#include "GameManager.h"

GameManager::GameManager()
{
	m_bGameOver = false;
}

void GameManager::ShowStartMenu()
{
	int iSelect;

	while (1)
	{
		m_bGameOver = false;
		system("cls");
		BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		ORIGINAL
		DrawMidText("�١� DungeonRPG �ڡ�", WIDTH, HEIGHT / 2 - 4);
		DrawMidText("New Game", WIDTH, HEIGHT / 2 - 1);
		DrawMidText("Load Game", WIDTH, HEIGHT / 2 + 2);
		DrawMidText("Game Exit", WIDTH, HEIGHT / 2 + 5);
		iSelect = MenuSelectCursor(3, 3, WIDTH / 3, HEIGHT / 2 - 1);
		switch (iSelect)
		{
		case 1:
			NewGame();
			break;
		case 2:
			LoadGame();
			break;
		case 3:
			return;
		}
	}
}

void GameManager::NewGame()
{
	system("cls");
	BLUE
	BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	YELLOW
	DrawMidText("Player �̸� �Է� : ", WIDTH, HEIGHT / 2);
	m_User.CreateName();
	m_User.LoadDefaultInfo();
	m_Monster.LoadDefaultInfo();
	ShowGameMenu();
}

void GameManager::LoadGame()
{
	ifstream m_fLoad[10];
	int iSelect;
	string str[] = { "SavePlayer1.txt", "SavePlayer2.txt", "SavePlayer3.txt", "SavePlayer4.txt","SavePlayer5.txt", "SavePlayer6.txt","SavePlayer7.txt","SavePlayer8.txt"
	,"SavePlayer9.txt" ,"SavePlayer10.txt" };
	for (int i = 0; i < 10; i++)
	{
		m_fLoad[i].open(str[i]);
	}

	while (1)
	{
		int iHeight = HEIGHT - 28;
		system("cls");
		BLUE
			BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		GREEN
			for (int i = 0; i < 10; i++)
			{
				if (m_fLoad[i].is_open())
				{
					iHeight += 2;
					gotoxy(WIDTH - 10, iHeight);
					cout << i << "������ : (���Ͽ��� : ��)";
				}
				else
				{
					iHeight += 2;
					gotoxy(WIDTH - 10, iHeight);
					cout << i << "������ : (���Ͽ��� : ��)";
				}
			}
		gotoxy(WIDTH - 10, iHeight + 2);
		cout << "11.���ư���";
		iSelect = MenuSelectCursor(11, 2, WIDTH / 4, HEIGHT -28 + 2);
		switch (iSelect)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
			if (!m_fLoad->is_open())
			{
				system("cls");
				BLUE
					BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
				ORIGINAL
					DrawMidText("�ش� ������ �����ϴ�.", WIDTH, HEIGHT / 2);
				system("pause");
				break;
			}
			else
			{
				m_fLoad[iSelect].open(str[iSelect]);
				
			}
		case 11:
			for (int i = 0; i < 10; i++)
			{
				m_fLoad[i].close();
			}
			return;
		}
	}
}

void GameManager::ShowGameMenu()
{
	char ch;
	int iSelect;
	while (1)
	{
		if (m_bGameOver == true)
			return;

		system("cls");
		BLUE
		BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		ORIGINAL
		DrawMidText("�١� Menu �ڡ�", WIDTH, HEIGHT / 2 - 10);
		DrawMidText("Dungeon", WIDTH, HEIGHT / 2 - 7);
		DrawMidText("Player Info", WIDTH, HEIGHT / 2 - 4);
		DrawMidText("Monster Info", WIDTH, HEIGHT / 2 - 1);
		DrawMidText("Weapon Shop", WIDTH, HEIGHT / 2 + 2);
		DrawMidText("Save", WIDTH, HEIGHT / 2 + 5);
		DrawMidText("Exit", WIDTH, HEIGHT / 2 + 8);
		iSelect = MenuSelectCursor(6, 3, WIDTH / 3, HEIGHT / 2 - 7);
		switch (iSelect)
		{
		case 1:
			ShowDungeon();
			break;
		case 2:
			m_User.ShowInfo();
			break;
		case 3:
			m_Monster.ShowInfo();
			ch = _getch();
			break;
		case 4:
			ShowShopMenu();
			break;
		case 5:
			
			break;
		case 6:
			m_Monster.ResetMonster();
			m_User.LoadDefaultInfo();
			m_User.ResetWeapon();
			return;
		}
	}
}

void GameManager::ShowDungeon()
{
	int iSelect;

	system("cls");
	BLUE
		BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	ORIGINAL
	DrawMidText("===== ���� �Ա� =====", WIDTH, HEIGHT / 2 - 10);
	DrawMidText("1������ : [���]", WIDTH, HEIGHT / 2 - 7);
	DrawMidText("2������ : [��ũ]", WIDTH, HEIGHT / 2 - 4);
	DrawMidText("3������ : [�����ΰ�]", WIDTH, HEIGHT / 2 - 1);
	DrawMidText("4������ : [�����]", WIDTH, HEIGHT / 2 + 2);
	DrawMidText("5������ : [���̷����ó]", WIDTH, HEIGHT / 2 + 5);
	DrawMidText("6������ : [��ġ]", WIDTH, HEIGHT / 2 + 8);
	DrawMidText("���ư���", WIDTH, HEIGHT / 2 + 11);
	iSelect = MenuSelectCursor(7, 3, WIDTH / 4, HEIGHT / 2 - 7);
	while (1)
	{
		switch (iSelect)
		{
		case 1:
			Battle(0);
			return;
		case 2:
			Battle(1);
			return;
		case 3:
			Battle(2);
			return;
		case 4:
			Battle(3);
			return;
		case 5:
			Battle(4);
			return;
		case 6:
			Battle(5);
			return;
		case 7:
			return;
		}
	}
}

void GameManager::Battle(int index)
{
	bool flag = false;
	char input, MonsterAtk;
	srand(time(NULL));
	while (1)
	{
		system("cls");
		BLUE
			BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		YELLOW
			m_User.PlayerInfo(HEIGHT - 28);
		ORIGINAL
			DrawMidText("���� : 1   ���� : 2   �� : 3", WIDTH, HEIGHT - 23);
		RED
			DrawMidText("------------------------ vs ----------------------------", WIDTH, HEIGHT - 15);
		ORIGINAL
			m_Monster.ShowMonster(index);
		MonsterAtk = m_Monster.Attack();
		
		input = _getch();
		if (input != '1' && input != '2' && input != '3')
			continue;
		flag = WinnerCheck(MonsterAtk, input, index);
		if (flag == true)
		{
			m_Monster.GetDamage(index, m_User.Attack());
			if (m_Monster.DeathCheck(index) == true)
			{
				m_User.Win(m_Monster, index);
				m_Monster.ResetMonster();
				m_Monster.LoadDefaultInfo();
				return;
			}
			else
				continue;
		}
		else
		{
			string strMonsterName;
			char ch;
			strMonsterName = m_Monster.GetName(index);
			if (MonsterAtk == input)
				continue;

			m_User.GetDamage(m_Monster.DealDamage(index));
			system("cls");
			BLUE
				BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
			RED
				gotoxy(WIDTH, HEIGHT - 20);
			cout  << strMonsterName << " �¸�!!";
			ch = _getch();
			if (m_User.DeathCheck() == true)
			{
				GameOver();
				return;
			}
			else
				continue;
		}
	}
}

bool GameManager::WinnerCheck(char MonsterAtk, char UserAtk, int index)
{
	char ch;
	if (MonsterAtk == UserAtk)
	{
		gotoxy(WIDTH, HEIGHT - 19);
		PrintAttack(UserAtk);
		DrawMidText("Draw", WIDTH, HEIGHT - 20);
		DrawMidText("Draw", WIDTH, HEIGHT - 10);
		gotoxy(WIDTH, HEIGHT - 9);
		PrintAttack(MonsterAtk);
		ch = _getch();
		return false;
	}
	else if (MonsterAtk == '1' && UserAtk == '2')
	{
		gotoxy(WIDTH, HEIGHT - 19);
		PrintAttack(UserAtk);
		DrawMidText("Win", WIDTH, HEIGHT - 20);
		DrawMidText("Lose", WIDTH, HEIGHT - 10);
		gotoxy(WIDTH, HEIGHT - 9);
		PrintAttack(MonsterAtk);
		ch = _getch();
	}
	else if (MonsterAtk == '2' && UserAtk == '3')
	{
		gotoxy(WIDTH, HEIGHT - 19);
		PrintAttack(UserAtk);
		DrawMidText("Win", WIDTH, HEIGHT - 20);
		DrawMidText("Lose", WIDTH, HEIGHT - 10);
		gotoxy(WIDTH, HEIGHT - 9);
		PrintAttack(MonsterAtk);
		ch = _getch();
	}
	else if (MonsterAtk == '3' && UserAtk == '1')
	{
		gotoxy(WIDTH, HEIGHT - 19);
		PrintAttack(UserAtk);
		DrawMidText("Win", WIDTH, HEIGHT - 20);
		DrawMidText("Lose", WIDTH, HEIGHT - 10);
		gotoxy(WIDTH, HEIGHT - 9);
		PrintAttack(MonsterAtk);
		ch = _getch();
	}
	else
	{
		gotoxy(WIDTH, HEIGHT - 19);
		PrintAttack(UserAtk);
		DrawMidText("Lose", WIDTH, HEIGHT - 20);
		DrawMidText("Win", WIDTH, HEIGHT - 10);
		gotoxy(WIDTH, HEIGHT - 9);
		PrintAttack(MonsterAtk);
		ch = _getch();
		return false;
	}

	return true;
}

void GameManager::PrintAttack(char ch)
{
	if (ch == '1')
		cout << "����";
	else if (ch == '2')
		cout << "����";
	else if (ch == '3')
		cout << "��";
}

void GameManager::ShowShopMenu()
{
	int iSelect;

	while (1)
	{
		system("cls");
		BLUE
			BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		ORIGINAL
			DrawMidText("�� �� S H O P �� ��", WIDTH, HEIGHT / 2 - 10);
		DrawMidText("Dagger", WIDTH, HEIGHT / 2 - 7);
		DrawMidText("Gun", WIDTH, HEIGHT / 2 - 4);
		DrawMidText("Sword", WIDTH, HEIGHT / 2 - 1);
		DrawMidText("Wand", WIDTH, HEIGHT / 2 + 2);
		DrawMidText("Bow", WIDTH, HEIGHT / 2 + 5);
		DrawMidText("Hammer", WIDTH, HEIGHT / 2 + 8);
		DrawMidText("���ư���", WIDTH, HEIGHT / 2 + 11);
		iSelect = MenuSelectCursor(7, 3, WIDTH / 4, HEIGHT / 2 - 7);

		switch (iSelect)
		{
		case 1:
			m_Weapon.ShowWeaponInfo(DAGGER, m_User, "Dagger");
			break;
		case 2:
			m_Weapon.ShowWeaponInfo(GUN, m_User, "Gun");
			break;
		case 3:
			m_Weapon.ShowWeaponInfo(SWORD, m_User, "Sword");
			break;
		case 4:
			m_Weapon.ShowWeaponInfo(WAND, m_User, "Wand");
			break;
		case 5:
			m_Weapon.ShowWeaponInfo(BOW, m_User, "Bow");
			break;
		case 6:
			m_Weapon.ShowWeaponInfo(HAMMER, m_User, "Hammer");
			break;
		case 7:
			return;
		}
	}
}

void GameManager::GameOver()
{
	RED
	gotoxy(WIDTH, HEIGHT - 17);
	cout << "Game Over";
	char ch = _getch();
	m_Monster.ResetMonster();
	m_User.LoadDefaultInfo();
	m_User.ResetWeapon();
	m_bGameOver = true;
}

GameManager::~GameManager()
{
}