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
	//vector<MOP> MonsterList;
	//vector<WeaponInfo> WeaponList;
public:
	void ShowStartMenu();
	void NewGame();
	void ShowGameMenu();
	void LoadGame();
	void ShowDungeon();
	void ShowShopMenu();
	GameManager();
	~GameManager();
};

