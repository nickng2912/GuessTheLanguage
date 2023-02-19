#include "linkedlist.h"
#include <string>
#include <iostream>
#include <ctime>
using namespace std; 

LinkedList::LinkedList()
{
    head = nullptr;
}

void LinkedList::insertNode(string value1, string value2)
{   
    Node* tempNode = new Node(value1, value2);

    if(head == nullptr)
    {
        head = tempNode;  
        return;
    } 

    Node* temp = head; 
    
    while(temp->next != NULL)
    { 
        temp = temp->next;
    }

    temp->next = tempNode;
}

void LinkedList::resetNode()
{   
    while(head != NULL)
    {
        Node* temp = head; 
        head = temp->next;
        delete temp; 
    }
}

void LinkedList::removeNode(int index)
{
    if(index < 1) {
        cout<<"\nposition should be >= 1.";
    } else if (index == 1 && head != NULL) {
      
    //2. if the position is 1 and head is not null, make
    //   head next as head and delete previous head 
    Node* nodeToDelete = head;
    head = head->next;
    free(nodeToDelete);
    } else {
    
    //3. Else, make a temp node and traverse to the 
    //   node previous to the position
    Node* temp = head;
    for(int i = 1; i < index-1; i++) {
      if(temp != NULL) {
        temp = temp->next;
      }
    }
 
    //4. If the previous node and next of the previous  
    //   is not null, adjust links 
    if(temp != NULL && temp->next != NULL) {
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete); 
    } else {

      //5. Else the given node will be empty.
      cout<<"\nThe node is already null.";
    }       
  }
}

void LinkedList::printList()
{
    Node* temp = head;
  
    // Check for empty list.
    if (head == NULL) {
        cout << "List empty" << endl;
        return;
    }
  
    // Traverse the list.
    while (temp != NULL) {
        cout << temp->country << ": " << temp->sentence << endl; 
        temp = temp->next;
    }
    cout << "Current Size of List: ";
}


string* LinkedList::getRandomQuestion()
{
    string* arr = new string[2];
    srand(time(NULL));

    int size = 0; 
    
    Node* tracker = head; 
    while(tracker != NULL)
    {
        tracker = tracker->next;
        size++; 
    }

    int randomNumber = rand() % size + 1;

    Node* value = head; 
    
    if(randomNumber == 1)
    {
        arr[0] = value->country;
        arr[1] = value->sentence;
        this->removeNode(randomNumber);
        return arr;
    } else 
    {
        for(int i = 0; i < randomNumber-1;i++)
        {
            value = value->next;
        }
        arr[0] = value->country;
        arr[1] = value->sentence;
        this->removeNode(randomNumber);
        return arr;
    }
}