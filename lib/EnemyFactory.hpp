#pragma once
#include "../include/EnemyInterface.hpp"

class EnemyFactory
{
public:
    EnemyFactory *make_chooser(std::string type);
};