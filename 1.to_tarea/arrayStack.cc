#include "arrayStack.h"
#include <assert.h>
#include <iostream>
using namespace std;
/*
AXIOMS:
1. pop(newstack) = newstack                
2. pop(push(S, I)) = S                     
3. top(newstack) = undefined               
4. top(push(S, I)) = I                     
5. empty(newstack) = true                             
6. empty(push(S, I)) = false               
7. empty(pop(push(newstack, I))) = true    
*/
template<typename T>
arrayStack<T>::arrayStack(int s){
  size = s;
  data = new T[s];
  sp = data;
  //de acuerdo al axioma 5 que nos dice que 
  //empty(newstack)=true, nos indica que en un
  //inicio la pila estaba vacia en el constructor
  assert (empty());
}

template<typename T>
void arrayStack<T>::push(T e){
  if(size== (sp -data))//esta lleno
    resize();
  *sp = e;
  sp++;
  //postcondition
  //si se agrega un elemento a la pila
  //se debe verificar que ese elemento este en el top
  //ya que es el ultimo ingresado
  //esto corresponderia al axioma 4
  assert(top()==e);
  //si se tiene una pila vacia y se ingresa un elemento
  //entonces la pila ya no estaria vacia de acuerdo
  //al axioma 6 
  assert(!empty());//empty()=false
  //de acuerdo al axioma 2
  //pop(push(S,I))=S entiendo del axioma que
  //si agrego un elemento a la pila y luego lo retiro
  //en realida la pila queda como estuvo al inicio
  //sabemos que sp-1 = ultimo elemento de la pila
  //sp -1 deberia ser igual a e 
  //assert((sp-1) == (data + (sp - data)));

}
template<typename T>
void arrayStack<T>::pop(){
  if(empty())
    assert(empty()==true);
  //axioma 1 ya que newtack seria empty
  //1. pop(newstack)=newstack
    return;	
  sp--;
}

template <typename T>
T arrayStack<T>::top(){
  assert(!empty());//precondicion de acuerdo al axioma 3
  return *(sp -1);
}
template<typename T>
bool arrayStack<T>::empty(){
  return sp == data;

}
template<typename T>
void arrayStack<T>::resize(){
  T *newData = new T[size + FACTOR];
  for(int i =0; i< size; i++)
    newData[i] = data[i];
      delete[] data;
  data = newData;
  //sp = data + size - 1; 
  //sp = data + size; 
  size += FACTOR;
}
/*
int main(){
  arrayStack<int> arr1(5);
  arr1.push(3);
  arr1.push(6);
  arr1.push(1);
  cout<<arr1.top()<<endl;//1
  arr1.pop();
  cout<<arr1.top()<<endl;//6
  arr1.pop();
  cout<<arr1.top()<<endl;//3
  arr1.pop();
  cout<<arr1.top()<<endl;//0
  arr1.pop();
}
*/


//como se que estoy apuntando al sgte del ultimo 
//num elementos del arreglos = size 
//compara sp mas alla ultima pos data+size
//sp-data
