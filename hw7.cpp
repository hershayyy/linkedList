#include "dlist.h"

int main()
{
  //Get the elapsed time of this function and display it
  struct timeval timeBeg, timeEnd;
  gettimeofday(&timeBeg, 0);
  dList alpha;

  //test empty list
  alpha.display();
  cout << "\n";

  //test full list

  alpha.addNode(5);
  alpha.display();
  alpha.addNode(8);
  alpha.display();
  alpha.addNode(11);
  alpha.display();
  alpha.addNode(15);
  alpha.display();
  alpha.addNode(13);
  alpha.display();
  alpha.addNode(27);
  alpha.display();

  cout<< "\nTest addToEnd " << endl;
  alpha.addToEnd(1);
  alpha.addToEnd(22);
  alpha.display();


  cout<< "\nTest the find function for 5" << endl;
  alpha.find(5);

  cout<<"\nTest the erase function for 13"<< endl;
  alpha.erase(alpha.find(13));
  alpha.display();

  cout<< "\nTest Copy Constructor" << endl;
  dList bravo(alpha);
  cout<< "alpha : " << endl;
  alpha.display();
  cout<< "bravo : " << endl;
  bravo.display();


  cout<< "\nAdd 100,000 random numbers to a list"<< endl;
  dList delta;

  //srand(time(0)) sets the "seed" of the random generator to the current
  //time so that the random numbers start at a different point each time.
  //Without this the random numbers will be the same sequence of numbers
  //each time.
  srand(time(0));
  //Add 100,000 random numbers to list delta
  for(int i = 0; i != 100000; i++)
  {
    delta.addNode(rand());
  }

  cout<< "There are " << delta.size() << " items in this list."<< endl;
  delta.clear();
  cout<< "new size of delta is " << delta.size() << endl;

  for(int i = 0; i != 20; i++)
  {
    delta.addNode(rand() % 20 + 1);
  }

  delta.display();
  cout<< "\nTest erase"<< endl;
  //srand(time(0)+1);
  for(int i = 0; i != 20; i++)
  {
    delta.erase(delta.find(rand()% 20));
  }
  delta.display();
  cout<< "delta now has " << delta.size() << " items" << endl;


  cout<< "\nTest overloaded = operator"<< endl;
  dList charlie;
  charlie = alpha;
  cout<<"alpha : "<< endl;
  alpha.display();
  cout<<"charlie : "<< endl;
  charlie.display();

  gettimeofday(&timeEnd, 0);
  cout << "time passed : "
  << ((timeEnd.tv_sec - timeBeg.tv_sec)*1000000.0 +(timeEnd.tv_usec -
  timeBeg.tv_usec)) / 1000000 << endl;


  return 0;

}
