#include "dlist.h"

//Display the list to the screen
void dList::display()
{
  //temp = Temporary pointer
  node * temp = new node();
  temp = head -> next;

  cout<< "List contents : "<< endl;

//Display for an empty list
  if(temp == head)
    {
      cout<< "This list is empty"<< endl;
      return;
    }
    else
    //Display for a list with nodes
    {
      do
      {
        cout<< temp -> data << " : ";
        temp = temp -> next;
      } while(temp != head);
    }

  cout<< endl;
}

//addNode will add a new node to the front of the list
//right behind the head node (prev points head)
void dList::addNode(int value)
{
  node *temp = new node();
  temp -> data = value;
  temp -> next = head -> next;
  temp -> prev = head;
  head -> next = temp;
  temp -> next -> prev = temp;
}

//addToEnd will add a new node to the end of the list
//right before the head node (next points to head)
void dList::addToEnd(int value)
{
  node *temp = new node();
  temp -> data = value;
  temp -> prev = head -> prev;
  temp -> next = head;
  head -> prev = temp;
  temp -> prev -> next = temp;
}

//This function is used to clear entire lists, leaving only the head node
//pointing to itself.
void dList::clear()
{
  node* curr;
  node* temp;
  curr = head -> next;

  while(curr != head)
  {
    temp = curr;
    curr = curr -> next;
    delete temp;
  }
  head -> next = head;
  head -> prev = head;
}

//The find function finds the target node and returns its pointer.
node* dList::find(int target)
{
  node *temp = head;
  for(temp; temp -> next != head; temp = temp -> next)
  {
    if(temp -> next -> data == target)
    {
      cout << temp -> next -> data << " has been found."<< endl;
      return temp -> next;
    }
  }
  //If target is not found in the list, return temp -> next (which is head)
  return temp -> next;
}

//The erase function erases the target node using the pointer found in
//the find function.
void dList::erase(node* a)
{
  if(a != head)
  {
    node *temp, *temp2;
    temp = a-> prev;
    temp2 = a -> next;
    temp -> next = temp2;
    temp2 -> prev = temp;
  }
}

//Counts the number of nodes in the list by traversing the list
int dList::size()
{
  int count = 0;
  node* temp = head;
  while(temp -> next != head)
    {
      count++;
      temp = temp -> next;
    }
  return count;
}

//destructor will delete entire lists after the program is closed
   dList::~dList()
{
  node *temp, *temp2;
  temp = head -> next;
  temp2 = temp;
  while(temp != head)
    {
      temp2 = temp -> next;
      delete temp;
      temp = temp2;
      //display();
    }
  delete head;
}


//Copy constructor copies the data of one list into another list
dList::dList(const dList& listObject)
{
  head = new node;
  head -> next = head;
  head -> prev = head;
  node *temp;
  for (temp = listObject.head -> next; temp != listObject.head; temp = temp-> next)
  {
    addToEnd(temp -> data);
  }
}

//Overloading the = operator to make one list exactly like another list
dList& dList::operator=(const dList& rightSide)
{

  if(this != &rightSide)
  {
    node* temp;

    clear();

    for(temp = rightSide.head -> next; temp != rightSide.head; temp = temp -> next)
    {
      addToEnd(temp -> data);
    }
  }

  return *this;
}
