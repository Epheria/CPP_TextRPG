#include "Monster.h"
Monster::Monster()
{
}

void MonsterManager::LoadDefaultInfo()
{
	int iCount;
	ifstream m_fLoad;
	Status tmp;

	m_fLoad.open("DefaultMonster.txt");
	if (m_fLoad.is_open())
	{
		m_fLoad >> iCount;

		for (int i = 0; i < iCount; i++)
		{
			m_fLoad >> tmp.m_strMopName >> tmp.m_iAttack >> tmp.m_iHP >>tmp.m_iEXP >> tmp.m_iGetEXP >> tmp.m_iLevel >> tmp.m_iGold;
			tmp.m_iDefaultHP = tmp.m_iHP;
			MonsterList.push_back(tmp);
		}
	}
	m_fLoad.close();
}

void MonsterManager::ShowInfo()
{
	int i = 1;
	int iHeight = HEIGHT - 29;
	system("cls");
	BLUE
		DrawManager.BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	YELLOW
		for (vector<Status>::iterator iter = MonsterList.begin(); iter != MonsterList.end(); iter++)
		{
			iHeight += i;
			DrawManager.gotoxy(WIDTH - 8, iHeight);
			cout << "===== " << iter->m_strMopName << "(" << iter->m_iLevel << "Lv)" << " =====" << endl;
			iHeight += i;
			DrawManager.gotoxy(WIDTH - 12, iHeight);
			cout << "공격력 = " << iter->m_iAttack << "\t" << "생명력 = " << iter->m_iHP << "/" << iter->m_iDefaultHP << endl;
			iHeight += i;
			DrawManager.gotoxy(WIDTH - 12, iHeight);
			cout << "경험치 = " << iter->m_iEXP << "/" << iter->m_iEXP << "\t" << "GetEXP : " << iter->m_iGetEXP << endl;
			iHeight += i;
			DrawManager.gotoxy(WIDTH - 12, iHeight);
			cout << "Gold = " << iter->m_iGold << endl;
		}
}

void MonsterManager::ShowMonster(int index)
{
	DrawManager.gotoxy(WIDTH - 8, HEIGHT - 5);
	cout << "===== " << MonsterList[index].m_strMopName << "(" << MonsterList[index].m_iLevel << "Lv)" << " =====" << endl;
	DrawManager.gotoxy(WIDTH - 12, HEIGHT - 6);
	cout << "공격력 = " << MonsterList[index].m_iAttack << "\t" << "생명력 = " << MonsterList[index].m_iHP << "/" << MonsterList[index].m_iDefaultHP << endl;
	DrawManager.gotoxy(WIDTH - 12, HEIGHT - 7);
	cout << "경험치 = " << MonsterList[index].m_iEXP << "/" << MonsterList[index].m_iEXP << "\t" << "GetEXP : " << MonsterList[index].m_iGetEXP << endl;
	DrawManager.gotoxy(WIDTH - 12, HEIGHT - 8);
	cout << "Gold = " << MonsterList[index].m_iGold << endl;
}

char Monster::AttackRes()
{
	char Attack[] = { '1', '2', '3' };
	int res;
	res = rand() % 2;
	return Attack[res];
}

Monster::~Monster()
{
}