#pragma once
#include "Macro.h"
#include "MapDraw.h"
#include "Weapon.h"
#include "Player.h"
#include "Monster.h"
#include "Character.h"
#define START_X 0
#define START_Y 0
class GameManager : public MapDraw
{
private:
	Player m_User;
	vector<MOP> m_MonsterList;

public:
	void ShowStartMenu();
	void NewGame();
	void LoadGame();
	GameManager();
	~GameManager();
};

