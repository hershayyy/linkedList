#include "list.h"

int main()
{
  List list;

  //test empty list
  list.display();
  cout << "\n";

  //test full list

  list.addNode(5);
  list.display();
  list.addNode(8);
  list.display();
  list.addNode(11);
  list.display();
  list.addNode(15);
  list.display();
  list.addNode(13);
  list.display();
  list.addNode(27);
  list.display();


cout<< "\nTest Copy Constructor"<< endl;
  List list2(list);
  list2.display();

cout<< "\nTest overloaded = operator"<< endl;
  List list3;
  list3 = list;
  list3.display();


  return 0;

}
