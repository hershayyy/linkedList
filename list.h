/**
CS219 - Fall 2015, Dr. Liu
Joshua Yurche
HW5

This program is a single linked integer list that lets you add new nodes,
display the list contents, and gives the size of the list. This program
has implemented the destructor, copy constructor, and overloaded assignment
operator.

The files involved in this program are:
list.h
list.cpp
hw5.cpp

To compile this program:
g++ -o hw5 list.cpp hw5.cpp

To run this program:
./hw5
**/


#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

//node structure
struct node
{
int data;
node *next;
};


//class for a list
class List
{
 public:
  //constructor for new, empty, list with a head and tail node
 List(): head(0), tail(0)
    {
      head = new node;
      tail = new node;
      head-> next = tail;
    };
  void display();
  void addNode(int value);
  void addToEnd(int eValue);
  void clear();

  int size();

  List(const List& listObject); // copy constructor

  List& operator=(const List& rightSide); //Overloaded assignment

  ~List(); // destructor

 private:
  node *head; //pointer of head node
  node *tail; // pointer of the tail node
};



#endif
