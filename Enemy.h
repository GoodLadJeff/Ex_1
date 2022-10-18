#pragma once
#include <iostream>
#include <string>
#include <windows.h>
#include "EnemyType.h"
class Enemy
{
private:
	std::string mName;
	std::uint16_t mType = 0;
public:
	Enemy(std::string name = "default enemy");
	~Enemy();

	std::string GetName();
	void AddType(std::uint16_t type);
	void DisplayTypes();
	uint16_t GetType();
	void ChangeType(std::uint16_t type);
	bool HasTypeInCommon(Enemy* otherEnemy);
};

