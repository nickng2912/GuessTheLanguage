#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>
using namespace std; 

class Node 
{
public:
    Node()
    {
        next = nullptr;
    }
    Node(string value1, string value2)
    {
        country = value1; 
        sentence = value2;
        next = nullptr;
    }

    string sentence; 
    string country; 
    Node* next; 
};

class LinkedList 
{
public:
    LinkedList();

    void insertNode(string value1, string value2);
    void printList();
    void resetNode();
    void removeNode(int index);

    string* getRandomQuestion(); 
    
private:
    Node* head;
};

#endif

