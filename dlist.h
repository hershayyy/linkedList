/**
CS219 - Fall 2015, Dr. Liu
Joshua Yurche
HW6

This program is a double linked and circular integer list that lets you add new nodes,
display the list contents, and gives the size of the list. This program
has implemented the destructor, copy constructor, and overloaded assignment
operator, and an eraser function which finds a specific data value in the list
and deletes it from the list. There is also a function to add 100,000 integers
to the list.

The files involved in this program are:
dlist.h
dlist.cpp
hw7.cpp

To compile this program:
g++ -o hw7 dlist.cpp hw7.cpp

To run this program:
./hw7
**/


#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include <cstdlib>
#include <sys/time.h>
using namespace std;

//node structure
struct node
{
int data;
node *next;
node *prev;
};

//class for a list
class dList
{
 public:
  //constructor for new, empty, doubly linked circular list with the head node
 dList(): head(0)
    {
      head = new node;
      head -> next = head;
    };
  void display();
  void addNode(int value);
  void addToEnd(int value);
  void clear();
  node* find(int target);
  void erase(node*);
  int rand(void);

  int size();

  dList(const dList& listObject); // copy constructor

  dList& operator=(const dList& rightSide); //Overloaded assignment

  ~dList(); // destructor

 private:
  node *head; //pointer of head node
};



#endif
