#include "Macro.h"
#include "GameManager.h"
using namespace std;
void main()
{
	system("mode con: cols=60 lines=30");
	GameManager GM;
	GM.ShowStartMenu();
}