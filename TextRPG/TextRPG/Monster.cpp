#include "Monster.h"

Monster::Monster()
{
	LoadDefaultInfo();
}

void Monster::LoadDefaultInfo()
{
	int iCount;
	ifstream m_fLoad;
	MOP tmp;

	m_fLoad.open("DefaultMonster.txt");
	if (m_fLoad.is_open())
	{
		m_fLoad >> iCount;

		for (int i = 0; i < iCount; i++)
		{
			m_fLoad >> tmp.m_strMopName >> tmp.m_iAttack >> tmp.m_iHP >>tmp.m_iEXP >> tmp.m_iGetEXP >> tmp.m_iLevel >> tmp.m_iGold;
			MonsterList.push_back(tmp);
		}
	}
	m_fLoad.close();
}

void Monster::ShowInfo()
{
	int i = 1;
	int iHeight = HEIGHT - 29;
	system("cls");
	BLUE
		BoxDraw(START_X, START_Y, WIDTH, HEIGHT);
	YELLOW
		for (vector<MOP>::iterator iter = MonsterList.begin(); iter != MonsterList.end(); iter++)
		{
			iHeight += i;
			gotoxy(WIDTH - 8, iHeight);
			cout << "===== " << iter->m_strMopName << "(" << iter->m_iLevel << "Lv)" << " =====" << endl;
			iHeight += i;
			gotoxy(WIDTH - 12, iHeight);
			cout << "���ݷ� = " << iter->m_iAttack << "\t" << "����� = " << iter->m_iHP << "/" << iter->m_iHP << endl;
			iHeight += i;
			gotoxy(WIDTH - 12, iHeight);
			cout << "����ġ = " << iter->m_iEXP << "/" << iter->m_iEXP << "\t" << "GetEXP : " << iter->m_iGetEXP << endl;
			iHeight += i;
			gotoxy(WIDTH - 12, iHeight);
			cout << "Gold = " << iter->m_iGold << endl;
		}
}

Monster::~Monster()
{
}