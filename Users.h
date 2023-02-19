#ifndef USERS_H
#define USERS_H

// Users Class
#include <string>  
using namespace std; 

class Users
{
public:

    Users();

    void setName(string name); 
    void reduceHeart();
    void reduceMoney(int amount);
    void addMoney(int amount);

    int getHeart() const; 
    int getMoney() const; 
    string getName() const;

private: 
    string userName; 
    int heart; 
    int money; 
};

#endif