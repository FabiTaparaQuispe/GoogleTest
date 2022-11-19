#ifndef LIST_H

#define LIST_H

typedef struct Node{
  int data;
  struct Node *next;
}Node;

class List{
  Node *last;
  public:
    List();
    List& append(int);
    int head();
    List& tail();
    int size();
    bool isEmpty();
    List* deletek(int);
    List& insert_k(int, int);
    void to_string();
};

#endif
