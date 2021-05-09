#include "Monster.h"
Monster::Monster()
{
}

void Monster::StatusLoad(Monster tmp, vector<Monster>& MonsterList)
{
	int iCount;
	ifstream m_fLoad;
	m_fLoad.open("DefaultMonster.txt");
	if (m_fLoad.is_open())
	{
		m_fLoad >> iCount;
		for (int i = 0; i < iCount; i++)
		{
			m_fLoad >> tmp.m_Status.m_strName >> tmp.m_Status.m_iAttack >> tmp.m_Status.m_iHP >> tmp.m_Status.m_iDefaultEXP 
				>> tmp.m_Status.m_iGetEXP >> tmp.m_Status.m_iLevel >> tmp.m_Status.m_iGold;
			tmp.m_Status.m_iDefaultHP = tmp.m_Status.m_iHP;
			MonsterList.push_back(tmp);
		}
	}
}

void Monster::ShowInfo(int i, int iHeight)
{
	YELLOW
		iHeight += i;
	DrawManager.gotoxy(WIDTH - 8, iHeight);
	cout << "===== " << m_Status.m_strName << "(" << m_Status.m_iLevel << "Lv)" << " =====" << endl;
	iHeight += i;
	DrawManager.gotoxy(WIDTH - 12, iHeight);
	cout << "공격력 = " << m_Status.m_iAttack << "\t" << "생명력 = " << m_Status.m_iHP << "/" << m_Status.m_iDefaultHP << endl;
	iHeight += i;
	DrawManager.gotoxy(WIDTH - 12, iHeight);
	cout << "경험치 = " << m_Status.m_iDefaultEXP << "/" << m_Status.m_iDefaultEXP << "\t" << "GetEXP : " << m_Status.m_iGetEXP << endl;
	iHeight += i;
	DrawManager.gotoxy(WIDTH - 12, iHeight);
	cout << "Gold = " << m_Status.m_iGold << endl;
}

char Monster::AttackRes()
{
	char Attack[] = { '1', '2', '3' };
	int res;
	res = rand() % 2;
	return Attack[res];
}

void MonsterManager::LoadDefaultInfo()
{
	Monster tmp;
	tmp.StatusLoad(tmp, MonsterList);	
}

void MonsterManager::ShowInfo()
{
	int i = 1;
	int iHeight = HEIGHT - 29;
	system("cls");
	BLUE
		DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	for (vector<Monster>::iterator iter = MonsterList.begin(); iter != MonsterList.end(); iter++)
	{
		iter->ShowInfo(i, iHeight);
		iHeight += 4;
	}
}

void MonsterManager::BattleInfo(int index)
{
	MonsterList[index].ShowInfo(1, HEIGHT - 8);
}

Monster::~Monster()
{
}