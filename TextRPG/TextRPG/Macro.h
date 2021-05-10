#pragma once
#pragma warning(disable:4996);
#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include<fstream>
#include<time.h>
#include<vector>
using namespace std;

//////////////////////////////////////////
#define col GetStdHandle(STD_OUTPUT_HANDLE) 
#define BLACK SetConsoleTextAttribute( col,0x0000 );
#define DARK_BLUE SetConsoleTextAttribute( col,0x0001 );
#define GREEN SetConsoleTextAttribute( col,0x0002 );
#define BLUE_GREEN SetConsoleTextAttribute( col,0x0003 );
#define BLOOD SetConsoleTextAttribute( col,0x0004 );
#define PUPPLE SetConsoleTextAttribute( col,0x0005 );
#define GOLD SetConsoleTextAttribute( col,0x0006 );			//���� ����
#define ORIGINAL SetConsoleTextAttribute( col,0x0007 );
#define GRAY SetConsoleTextAttribute( col,0x0008 );
#define BLUE SetConsoleTextAttribute( col,0x0009 );
#define HIGH_GREEN SetConsoleTextAttribute( col,0x000a );
#define SKY_BLUE SetConsoleTextAttribute( col,0x000b );
#define RED SetConsoleTextAttribute( col,0x000c );
#define PLUM SetConsoleTextAttribute( col,0x000d );
#define YELLOW SetConsoleTextAttribute( col,0x000e );
//////////////////////////////////////////////////////
#define WIDTH 30
#define HEIGHT 30
#define START_X 0
#define START_Y 0
#define MAX_MONSTER 6;

enum STARTTYPE
{
	STARTTYPE_NEWSTART,
	STARTTYPE_LOADSTART
};

enum WEAPONTYPE
{
	WEAPONTYPE_BOW = 1,
	WEAPONTYPE_DAGGER,
	WEAPONTYPE_GUN,
	WEAPONTYPE_SWORD,
	WEAPONTYPE_WAND,
	WEAPONTYPE_HAMMER
};