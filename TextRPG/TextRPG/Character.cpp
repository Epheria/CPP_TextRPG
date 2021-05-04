#include "Character.h"

Character::Character()
{
}

inline int Character::Attack()
{

}

inline int Character::GetDamage(int HP, int Damage)
{
	return HP - Damage;
}

inline bool Character::DeathCheck()
{
	return false;
}


Character::~Character()
{
}