#pragma once
#include "../include/Enemy.hpp"
#include "Minion.hpp"
#include "Boss.hpp"


class EnemyFactory
{
public:
    Enemy *make_chooser(std::string enemy_type);
};