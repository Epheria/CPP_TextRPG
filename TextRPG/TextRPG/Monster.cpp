#include "Monster.h"

Monster::Monster()
{
	
}

void Monster::CreateMonster()
{
	
}

void Monster::ShowInfo()
{
	system("cls");
	BLUE
		BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	YELLOW
		DrawMidText("===== ", WIDTH - 8, HEIGHT / 2 - 4);
	cout << MonInfo.m_strMopName << "(" << MonInfo.m_iLevel << "Lv)" << " =====" << endl;
	DrawMidText("공격력 = ", WIDTH - 10, HEIGHT / 2 - 3);
	cout << MonInfo.m_iAttack << "\t" << " 생명력 = " << MonInfo.m_iDefaultHP << "/" << MonInfo.m_iHP << endl;
	DrawMidText("경험치 = ", WIDTH - 10, HEIGHT / 2 - 2);
	cout << MonInfo.m_iEXP << "/" << MonInfo.m_iDefaultEXP << "\t" << " GetEXP : " << MonInfo.m_iGetEXP << endl;
	DrawMidText("Gold = ", WIDTH - 11, HEIGHT / 2 - 1);
	cout << MonInfo.m_iGold << endl;
}

Monster::~Monster()
{
}