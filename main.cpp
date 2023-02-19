#include "Users.cpp"
#include "story.cpp"
#include "linkedlist.cpp"

#include <iostream> 
#include <string>
#include <time.h>
using namespace std; 

LinkedList getQuestions()
{
    LinkedList list; 
    list.insertNode("Vietnamese", "ướt như chuột lụt");
    list.insertNode("English", "Time flies when you're having fun");
    list.insertNode("French", "Faire d/’une pierre deux coups");
    list.insertNode("Chinese", " 半途而废");
    list.insertNode("Japanese", "弱肉強食");
    list.insertNode("Spanish", "Ser pan comido");
    list.insertNode("Thai", "กบในกะลาครอบ");
    list.insertNode("German", "Jemandem die Daumen drücken");
    list.insertNode("Italian", "un pezzo di pane");
    list.insertNode("Russia", "привет");
    list.insertNode("Swedish", "Kasta pärlor åt svin ");

    return list; 
}

int main()
{
    LinkedList list = getQuestions();

    Users u1; 
    string name;
    cout << "Hello Users!" << endl; 
    cout << "Please set your name: "; 
    cin >> name; 
    u1.setName(name);
    cout << "Hearts: " << u1.getHeart() << endl; 
    cout << "Balance: " << u1.getMoney() << endl; 
    
    int round = 1;

    cout << "Welcome " << name << " to Guess The Language" << endl;

    while(u1.getHeart() > 0 && round <= 10)
    {
        cout << "Round " << round << endl; 
        string* arr = list.getRandomQuestion();

        cout << "This is your sentence: " << arr[1] << endl;
        cout << "Where is this Language from? " << endl; 
        string answer; 
        cin >> answer; 

        if (answer == arr[0])
        {
            u1.addMoney(100);
            cout << "Correct, You Earn $100. Your New Balance is: " << u1.getMoney() << endl; 
        } else 
        {
            u1.reduceHeart(); 
            cout << "Wrong! You Have " << u1.getHeart() << " lives left!" << endl; 
        }
        round++;
    }
    if(u1.getHeart() == 0)
    {
        cout << "You Died!" << endl; 
    } else 
    {
        cout << "Congratulations, you have finish!"; 
    }
}

