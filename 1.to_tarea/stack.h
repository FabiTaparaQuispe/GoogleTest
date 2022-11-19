#ifndef STACK_H
#define STACK_H
 
//calse abstracta todo virtual puro
//no voy a poder crear objetos de esta clase
//absrata no hay constructor
//virtual puro
//el virtual es para redefinir en las subclases tiene implementar metodos
//en java todos metodos 
//interface
template<typename T>
class Stack{
	public:	
	virtual void push(T)=0;//no hay implementacion
	virtual void pop()=0;
	virtual T top()=0;
	virtual bool empty()=0;
};
#endif
//2 formas simples de implementar un grafo densa arreglo bidimensional indices nombres de los nodos y esparsa listas de listas
//listas :1ra 
//arreglos
//a
