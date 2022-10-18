#include "Enemy.h"

Enemy::Enemy(std::string name)
{
	mName = name;
}

Enemy::~Enemy()
{
}

std::string Enemy::GetName()
{
	return mName;
}

void Enemy::AddType(std::uint16_t type)
{
	mType |= type;
}

void Enemy::DisplayTypes()
{
	std::string intro = mName + " est de type :";
	std::string toAdd = "";

	if (mType & (uint16_t)EnemyType::Ragewing)
		toAdd += " Ragewing,";
	if (mType & (uint16_t)EnemyType::Lagoon)
		toAdd += " Lagoon,";
	if (mType & (uint16_t)EnemyType::Jade)
		toAdd += " Jade,";
	if (mType & (uint16_t)EnemyType::Darkflight)
		toAdd += " Shimerscale,";
	if (mType & (uint16_t)EnemyType::Mirage)
		toAdd += " Mirage,";
	if (mType & (uint16_t)EnemyType::Whisper)
		toAdd += " Whisper,";
	if (mType & (uint16_t)EnemyType::Tempest)
		toAdd += " Tempest,";
	if (mType & (uint16_t)EnemyType::Astral)
		toAdd += " Astral,";
	if (mType & (uint16_t)EnemyType::Scalescorn)
		toAdd += " Scalescorn,";
	if (mType & (uint16_t)EnemyType::Dragon)
		toAdd += " Dragon,";
	if (mType & (uint16_t)EnemyType::Shimerscale)
		toAdd += " Shimerscale,";

	intro += toAdd;
	intro.pop_back();

	std::cout << intro << std::endl;
}

uint16_t Enemy::GetType()
{
	return mType;
}

void Enemy::ChangeType(std::uint16_t type)
{
	mType = type;
}

bool Enemy::HasTypeInCommon(Enemy* otherEnemy)
{
	if(otherEnemy->GetType() & mType) return true;
	return false;
}
