#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include "stack.h"
#define FACTOR 10
template<typename T>

class arrayStack: public Stack<T>{
  private:
    T* data;
    int size; //memory size
    //{0,1,...,}
    T* sp; //stackPointer
    void resize();
  public:
    arrayStack(int);
    //arrayStack(int s):size{s}, data{new T[size]}, sp{data}{}
    void push(T);
    void pop();
    T top();
    bool empty();
};
#endif
