#include "List.h"
#include <iostream>
#include <assert.h>
/*
AXIOMS
1. size(new) == 0
2. size(append(L, E)) > 0
3. empty(new) == True
4. empty(append(L, E)) = False
5. head(new) = error
6. head(append(append(new, E), F)) = E  //primer elemento
7. head(append(new,E)) = E
8. tail(new) = error
9. tail(append(L,E)) = L
10.head(tail(append(append(new, E),F))) == 1
*/
using namespace std;

List::List(){
  last = NULL;
  assert(isEmpty()==true);//axioma 3
  assert(size()==0);//axioma1 
}

List& List::append(int data){

  //assert(!isEmpty()&&(last->next->data==head()));
  //axioma 6 y 7 si la lista esta vacia y el elemento 
  //siguiente al ultimo siempre va a ser el head
  //cuando agregue elementos a la lista
  Node *n = new Node();
  n->data = data;

  if(isEmpty()){
    n->next = n;
    last = n;
    return *this;
  }else{
    n->next = last->next;
    last->next = n;
    last = n;
    return *this;
  }
  assert(size()>0);//axioma 2 y 4 size(append(L, E)) > 0
  assert(!isEmpty());//axioma 4 empty(append(L, E)) = False
  //assert(!(isEmpty() == true) && (size()!=1));
  //axioma 3 size(append(new, E)) == 1
}

int List::head(){
  assert(!isEmpty());//precondicion ->axioma5 isEmpty()==false
  return last->next->data;
}

List& List::tail(){
  assert(!isEmpty());//axioma 8
  if(last->next==last){
    last=NULL;
    return *this;
  }
  last->next=last->next->next;
  //axioma 8 
  //size(tail(append(new, E)))=0 ->axioma que 
  //verifica que el tamanio se agrego y quito 
  //un elemento a una lista nueva sea cero
  assert(size()>=1&&!isEmpty());
  
  return *this;

}

int List::size(){
  int c = 0;
  Node *pnt = last;

  while(pnt){
    pnt = pnt->next;
    if(pnt==last)
      pnt = 0;
    c++;
  }
  return c;
}

bool List::isEmpty(){
  return last == NULL;
}

List& List::insert_k(int index, int data){
  int s = size();//cantidad
  if(s < index) 
    return *this;//this hace referencia a List
  if(s == index)
    return append(data);
  
  Node *pnt = last;//con este puntero iteraciones

  Node *n = new Node();//nuevo nodo creo
  n->data = data;
  while(index--){
    pnt = pnt->next;//saltar al sgte
  }
  n->next = pnt->next;
  pnt->next = n;
  return *this;
}


List* List::deletek(int index){
  if(!isEmpty()){
    if(last == last->next){
      if(index == 0){
        last = NULL;
      return this;
      }
    }
  }
  return this;
}

void List::to_string(){
  cout<<"Lista: ";
  
  if(!isEmpty()){
    Node *pnt = last;
    while(pnt){
      pnt = pnt->next;
      cout<<pnt->data<<" ";
      if(pnt==last)
        pnt = 0;
    }
  }
  //cout<<"\n";
}
