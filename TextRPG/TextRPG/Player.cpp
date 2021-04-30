#include "Player.h"

Player::Player()
{
	m_iLevel = 1;
	m_iAttack = 5;
	m_iDefaultHP = 50;
	m_iHP = 50;
	m_iEXP = 0;
	m_iDefaultEXP = 10;
	m_iGetEXP = 0;
	m_iGold = 1000;
	m_bWeapon = true;
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
		m_fLoad >> m_
	}
}

void Player::ShowInfo()
{
	system("cls");
	BLUE
	BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	YELLOW
	DrawMidText("===== ", WIDTH - 8, HEIGHT / 2 - 4);
	cout << m_strPlayerName << "(" << m_iLevel << "Lv)" << " =====" << endl;
	DrawMidText("공격력 = ", WIDTH - 10, HEIGHT / 2 - 3);
	cout << m_iAttack << "\t" << " 생명력 = " << m_iDefaultHP << "/" << m_iHP << endl;
	DrawMidText("경험치 = ", WIDTH - 10, HEIGHT / 2 - 2);
	cout << m_iEXP << "/" << m_iDefaultEXP << "\t" << " GetEXP : " << m_iGetEXP << endl;
	DrawMidText("Gold = ", WIDTH - 11, HEIGHT / 2 - 1);
	cout << m_iGold << endl;
	if (m_bWeapon == true)
	{
		DrawMidText("무기타입 : ", WIDTH - 14, HEIGHT / 2);
	}
}

Player::~Player()
{
}