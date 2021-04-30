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

public:
	void ShowStartMenu();
	void NewGame();
	void ShowGameMenu();
	void LoadGame();
	void ShowDungeon();
	GameManager();
	~GameManager();
};

