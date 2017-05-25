#include "list.h"


//Adding nodes to the list
void List::addNode(int value)
{
  node* temp = new node();
  temp -> data = value;
  temp -> next = head -> next;
  head -> next = temp;

  if (temp != tail)
  {
    while (temp -> next != tail)
    {
      temp = temp -> next;
    }
    temp -> next = tail;
  }
  else
  {
    head = temp;
  }
}

void List::addToEnd(int eValue)
{
  node *np;
  node *pre;
  for(np = head; np ->next != tail; np = np -> next);

    pre = new node;
    pre -> data = eValue;
    np -> next = pre;
    pre -> next = tail;

}

//Display the list to the screen
void List::display()
{
  //Temporary pointer
  node * temp = new node();
  temp = head -> next;

  cout<< "List contents : "<< endl;

//Display for an empty list
  if(temp == tail)
    {
      cout<< "This list is empty"<< endl;
      return;
    }
    else
    {
      do
      {
        cout<< temp -> data << " : ";
        temp = temp -> next;
      } while(temp != tail);
    }

  cout<< endl;
}


//Counts the number of nodes in the list by traversing the list
int List::size()
{
  int count = 0;
  node* node = head;
  while(node != 0)
    {
      count++;
      node = node -> next;
    }
  return count;
}

//destructor deletes the list after program has ended.
   List::~List()
{
  node *ptr, *sptr;
  ptr = head -> next;
  sptr = ptr;
  while(ptr != tail)
    {
      sptr = ptr -> next;
      delete ptr;
      ptr = sptr;
      //display();
    }
  delete head;
  delete tail;
}


//Copy constructor copies the contents from one list into a new list.
List::List(const List& listObject)
{
  head = new node;
  tail = new node;
  head-> next = tail;
  node *temp;
  for (temp = listObject.head -> next; temp != listObject.tail; temp = temp-> next)
  {
    addToEnd(temp -> data);
  }

}

// clears the contents of a list leaving only the head and tail nodes.
void List::clear()
{
  node* curr;
  node* temp;
  curr = head -> next;

  while(curr != tail)
  {
    temp = curr;
    curr = curr ->next;
    delete temp;
  }
}

//takes one list, clears it if it has contents, then makes it the same as another list.
List& List::operator=(const List& rightSide)
{

  if(this != &rightSide)
  {
    node* temp;

    clear();

    for(temp = rightSide.head ->next; temp != rightSide.tail; temp = temp -> next)
    {
      addToEnd(temp -> data);
    }
  }

  return *this;
}
