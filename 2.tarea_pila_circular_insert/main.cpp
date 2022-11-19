#include <iostream>
#include "List.h"
using namespace std;

int main(){
  //List *l1 = new List();
  List l1;
  //l1.to_string();
  // cout<<l1.head()<<endl;
  l1 = l1.append(2);
  l1 = l1.append(3);
  l1 = l1.tail();
  l1.to_string();
  l1 = l1.tail();
  l1.to_string();
  l1 = l1.tail();

  /*
  //cout<<l1->head()<<endl;
  l1 = l1->append(2);
  //cout<<l1->head()<<endl;
  l1 = l1->append(3);
  //cout<<l1->head()<<endl;
  l1 = l1->append(4);
  //cout<<l1->head()<<endl;
  */
}
