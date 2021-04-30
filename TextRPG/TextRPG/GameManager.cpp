#include "GameManager.h"

GameManager::GameManager()
{
}

void GameManager::ShowStartMenu()
{
	int iSelect;

	while (1)
	{
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
	ShowGameMenu();
}

void GameManager::ShowGameMenu()
{
	char ch;
	int iSelect;
	while (1)
	{
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
		
			break;
		case 2:
			m_User.ShowInfo();
			ch = _getch();
			break;
		case 3:
			m_MonsterList.
			break;
		case 4:

			break;
		case 5:
			
			break;
		case 6:
			return;
		}
	}
}

void GameManager::LoadGame()
{

}

GameManager::~GameManager()
{
}