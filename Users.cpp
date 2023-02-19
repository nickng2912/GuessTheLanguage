#include "Users.h"
#include <string>


Users::Users()
{
    heart = 3; 
    money = 1000;
}

void Users::setName(string name)
{
    userName = name; 
}

void Users::reduceHeart()
{
    heart--; 
}

void Users::reduceMoney(int amount)
{
    money = money - amount; 
}

void Users::addMoney(int amount)
{
    money = money + amount;
}

int Users::getHeart() const 
{
    return heart;
}

int Users::getMoney() const 
{
    return money;
}

string Users::getName() const 
{
    return userName;
}