#pragma once
#include "Macro.h"
#include "MapDraw.h"
#include "Weapon.h"
#include "Player.h"
#include "Monster.h"
#include "Character.h"
class GameManager : public MapDraw
{
private:
	Player m_User;
	Monster m_Monster;
	Weapon m_Weapon;
	bool m_bGameOver;

public:
	void ShowStartMenu();
	void NewGame();
	void LoadGame();
	void LoadCheck(ifstream& m_fLoad, int iSelect);
	void ShowFileList();
	void SaveGame();
	void ShowGameMenu();
	void ShowDungeon();
	void ShowShopMenu();
	void Battle(int index);
	bool WinnerCheck(char MonsterAtk, char UserAtk, int index);
	void PrintAttack(char ch);
	void GameOver();
	GameManager();
	~GameManager();
};

