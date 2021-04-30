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
			ch = _getch();
			break;
		case 3:
			m_Monster.ShowInfo();
			ch = _getch();
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
	DrawMidText("���ư���]", WIDTH, HEIGHT / 2 + 11);
	iSelect = MenuSelectCursor(6, 3, WIDTH / 3, HEIGHT / 2 - 7);
	while (1)
	{
		switch (iSelect)
		{
		case 1:

		case 2:

		case 3:

		case 4:

		case 5:

		case 6:

		case 7:
			return;
		}
	}
}

GameManager::~GameManager()
{
}