#include "GameManager.h"

GameManager::GameManager()
{
	m_bGameOver = false;
	char buf[20];
	for (int i = 0; i < 10; i++)
	{
		sprintf(buf, "SavePlayer%d.txt", i + 1);
		m_FileName[i] = buf;
	}
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
		DrawMidText("☆★ DungeonRPG ★☆", WIDTH, HEIGHT / 2 - 4);
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
	DrawMidText("Player 이름 입력 : ", WIDTH, HEIGHT / 2);
	m_User.CreateName();
	m_User.LoadDefaultInfo();
	m_MonsterManager.LoadDefaultInfo();
	m_WeaponManager.LoadAllWeapon();
	ShowGameMenu();
}

void GameManager::ShowFileList()
{
	ifstream m_fLoad[10];
	for (int i = 0; i < 10; i++)
	{
		m_fLoad[i].open(m_FileName[i]);
	}


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
				cout << i + 1 << "번슬롯 : (파일여부 : ○)";
			}
			else
			{
				iHeight += 2;
				gotoxy(WIDTH - 10, iHeight);
				cout << i + 1 << "번슬롯 : (파일여부 : ×)";
			}
		}
	gotoxy(WIDTH - 10, iHeight + 2);
	cout << "11.돌아가기";
	for (int i = 0; i < 10; i++)
	{
		m_fLoad[i].close();
	}
}

void GameManager::LoadGame()
{
	ifstream m_fLoad;
	int iSelect;
	while (1)
	{
		ShowFileList();
		iSelect = MenuSelectCursor(11, 2, WIDTH / 4, HEIGHT - 28 + 2);
		switch (iSelect)
		{
		case 1:
			LoadCheck(m_fLoad, iSelect);
			return;
		case 2:
			LoadCheck(m_fLoad, iSelect);
			return;
		case 3:
			LoadCheck(m_fLoad, iSelect);
			return;
		case 4:
			LoadCheck(m_fLoad, iSelect);
			return;
		case 5:
			LoadCheck(m_fLoad, iSelect);
			return;
		case 6:
			LoadCheck(m_fLoad, iSelect);
			return;
		case 7:
			LoadCheck(m_fLoad, iSelect);
			return;
		case 8:
			LoadCheck(m_fLoad, iSelect);
			return;
		case 9:
			LoadCheck(m_fLoad, iSelect);
			return;
		case 10:
			LoadCheck(m_fLoad, iSelect);
			return;
		case 11:
			m_fLoad.close();
			return;
		}

	}
}

void GameManager::LoadCheck(ifstream& m_fLoad, int iSelect)
{
	m_fLoad.open(m_FileName[iSelect - 1]);
	if (!m_fLoad.is_open())
	{
		system("cls");
		BLUE
			BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		ORIGINAL
			DrawMidText("해당 파일이 없습니다.", WIDTH, HEIGHT / 2);
		system("pause");
		return;
	}
	else
	{
		m_bGameOver = false;
		m_User.Load(m_fLoad, iSelect);
		m_MonsterManager.LoadDefaultInfo();
		m_WeaponManager.LoadAllWeapon();

		ShowGameMenu();
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
		DrawMidText("☆★ Menu ★☆", WIDTH, HEIGHT / 2 - 10);
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
			m_MonsterManager.ShowInfo();
			ch = _getch();
			break;
		case 4:
			ShowShopMenu();
			break;
		case 5:
			SaveGame();
			break;
		case 6:
			m_MonsterManager.ResetMonster();
			m_User.LoadDefaultInfo();
			m_User.ResetWeapon();
			m_WeaponManager.ClearWeaponList();
			return;
		}
	}
}

void GameManager::SaveGame()
{
	int iSelect;
	ofstream m_fSave;

	while (1)
	{
		ShowFileList();
		iSelect = MenuSelectCursor(11, 2, WIDTH / 4, HEIGHT - 28 + 2);

		if (iSelect >= 1 && iSelect <= 10)
		{
			m_User.Save(m_fSave, iSelect, m_FileName);
		}
		else if (iSelect == 11)
			return;
	}

}

void GameManager::ShowDungeon()
{
	int iSelect;

	system("cls");
	BLUE
		BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	ORIGINAL
	DrawMidText("===== 던전 입구 =====", WIDTH, HEIGHT / 2 - 10);
	DrawMidText("1층던전 : [고블린]", WIDTH, HEIGHT / 2 - 7);
	DrawMidText("2층던전 : [오크]", WIDTH, HEIGHT / 2 - 4);
	DrawMidText("3층던전 : [늑대인간]", WIDTH, HEIGHT / 2 - 1);
	DrawMidText("4층던전 : [오우거]", WIDTH, HEIGHT / 2 + 2);
	DrawMidText("5층던전 : [스켈레톤아처]", WIDTH, HEIGHT / 2 + 5);
	DrawMidText("6층던전 : [리치]", WIDTH, HEIGHT / 2 + 8);
	DrawMidText("돌아가기", WIDTH, HEIGHT / 2 + 11);
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
	char input;
	int PlayerAtk, MonsterAtk;
	srand(time(NULL));
	while (1)
	{
		system("cls");
		BLUE
			BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
		YELLOW
			m_User.PlayerInfo(HEIGHT - 28);
		ORIGINAL
			DrawMidText("가위 : 1   바위 : 2   보 : 3", WIDTH, HEIGHT - 23);
		RED
			DrawMidText("------------------------ vs ----------------------------", WIDTH, HEIGHT - 15);
		ORIGINAL
			m_MonsterManager.BattleInfo(index);
		MonsterAtk = m_MonsterManager.GetMonster()[index].AttackRes();
		
		input = _getch();
		if (input != '1' && input != '2' && input != '3')
			continue;
		else
		{
			if (input == '1')
				PlayerAtk = ATTACK_ROCK;
			else if (input == '2')
				PlayerAtk = ATTACK_SCISSORS;
			else if (input == '3')
				PlayerAtk = ATTACK_PAPER;
		}
		flag = WinnerCheck(MonsterAtk, PlayerAtk, index);
		if (flag == true)
		{
			m_MonsterManager.GetDamage(index , m_User.Attack());
			if (m_MonsterManager.DeathCheck(index) == true)
			{
				m_User.Win(m_MonsterManager.GetMonster(index), index);
				m_MonsterManager.ResetMonster();
				m_MonsterManager.LoadDefaultInfo();
				return;
			}
			else
				continue;
		}
		else
		{
			string strMonsterName;
			char ch;
			strMonsterName = m_MonsterManager.GetName(index);
			if (MonsterAtk == PlayerAtk)
				continue;

			m_User.GetDamage(m_MonsterManager.GetAttack(index));
			if (m_User.DeathCheck() == true)
			{
				system("cls");
				BLUE
					BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
				GameOver();
				return;
			}
			else
				continue;
		}
	}
}

bool GameManager::WinnerCheck(int MonsterAtk, int UserAtk, int index)
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
	else if (MonsterAtk == ATTACK_SCISSORS && UserAtk == ATTACK_ROCK)
	{
		gotoxy(WIDTH, HEIGHT - 19);
		PrintAttack(UserAtk);
		DrawMidText("Win", WIDTH, HEIGHT - 20);
		DrawMidText("Lose", WIDTH, HEIGHT - 10);
		gotoxy(WIDTH, HEIGHT - 9);
		PrintAttack(MonsterAtk);
		ch = _getch();
	}
	else if (MonsterAtk == ATTACK_PAPER && UserAtk == ATTACK_SCISSORS)
	{
		gotoxy(WIDTH, HEIGHT - 19);
		PrintAttack(UserAtk);
		DrawMidText("Win", WIDTH, HEIGHT - 20);
		DrawMidText("Lose", WIDTH, HEIGHT - 10);
		gotoxy(WIDTH, HEIGHT - 9);
		PrintAttack(MonsterAtk);
		ch = _getch();
	}
	else if (MonsterAtk == ATTACK_ROCK && UserAtk == ATTACK_PAPER)
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

void GameManager::PrintAttack(int iAttack)
{
	if (iAttack == ATTACK_SCISSORS)
		cout << "가위";
	else if (iAttack == ATTACK_ROCK)
		cout << "바위";
	else if (iAttack == ATTACK_PAPER)
		cout << "보";
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
			DrawMidText("♧ ♣ S H O P ♣ ♧", WIDTH, HEIGHT / 2 - 10);
		DrawMidText("Dagger", WIDTH, HEIGHT / 2 - 7);
		DrawMidText("Gun", WIDTH, HEIGHT / 2 - 4);
		DrawMidText("Sword", WIDTH, HEIGHT / 2 - 1);
		DrawMidText("Wand", WIDTH, HEIGHT / 2 + 2);
		DrawMidText("Bow", WIDTH, HEIGHT / 2 + 5);
		DrawMidText("Hammer", WIDTH, HEIGHT / 2 + 8);
		DrawMidText("돌아가기", WIDTH, HEIGHT / 2 + 11);
		iSelect = MenuSelectCursor(7, 3, WIDTH / 4, HEIGHT / 2 - 7);

		switch (iSelect)
		{
		case 1:
			m_WeaponManager.ShowWeaponInfo(WEAPONTYPE_DAGGER, m_User, "Dagger");
			break;
		case 2:
			m_WeaponManager.ShowWeaponInfo(WEAPONTYPE_GUN, m_User, "Gun");
			break;
		case 3:
			m_WeaponManager.ShowWeaponInfo(WEAPONTYPE_SWORD, m_User, "Sword");
			break;
		case 4:
			m_WeaponManager.ShowWeaponInfo(WEAPONTYPE_WAND, m_User, "Wand");
			break;
		case 5:
			m_WeaponManager.ShowWeaponInfo(WEAPONTYPE_BOW, m_User, "Bow");
			break;
		case 6:
			m_WeaponManager.ShowWeaponInfo(WEAPONTYPE_HAMMER, m_User, "Hammer");
			break;
		case 7:
			return;
		}
	}
}

void GameManager::GameOver()
{
	RED
	gotoxy(WIDTH - 4, HEIGHT - 15);
	cout << "Game Over";
	char ch = _getch();
	m_MonsterManager.ResetMonster();
	m_User.LoadDefaultInfo();
	m_User.ResetWeapon();
	m_bGameOver = true;
}

GameManager::~GameManager()
{
}