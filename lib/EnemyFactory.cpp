#include "EnemyFactory.hpp"

EnemyInterface *EnemyFactory :: make_chooser(std::string enemy_type)
{
    if(enemy_type == "minion") {return new Minion(); }
    else if(enemy_type == "boss") {return new Boss();} 
}