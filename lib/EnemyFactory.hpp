#pragma once
#include "../include/EnemyInterface.hpp"
#include "Minion.hpp"
#include "Boss.hpp"


class EnemyFactory
{
public:
    EnemyInterface *make_chooser(std::string enemy_type);
};