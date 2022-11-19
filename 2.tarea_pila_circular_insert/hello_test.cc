#include "List.cc"
#include <gtest/gtest.h>

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
// Demonstrate some basic assertions.


TEST(LisTest, Assertion1_3_8) {

  List *a = new List();
  a->tail();
  a->head();
  EXPECT_TRUE(a->tail());//axioma 8 tail(new) = error
  EXPECT_TRUE(a->isEmpty());//axioma 1, 3, 8
}
TEST(LisTest, Assertion6) {
  List *a = new List();
  int X= 3;
  int Y=4;
  //EXPECT_TRUE(a->append(X)->append(Y)->head()==x);//head(append(append(new, E), F)) =   //primer elemento
}
TEST(LisTest, Assertion5) {
  List *a = new List();
  EXPECT_TRUE(a->head());//axioma 5 head(new) = error
}

TEST(LisTest, Assertions) {

  List *a = new List();
  int tam = 11;
  for(int i=0;i < tam;i++){
    a->append(i);
    a->tail();//axioma 9
  } // Expect two strings not to be equal.
  EXPECT_TRUE(a->size()>0);//axioma 2 y 4
  EXPECT_EQ(tam, a->size());
  EXPECT_FALSE(a->isEmpty());
}

TEST(LisTest, Assertions) {

  List *a = new List();
  int tam = 11;
  for(int i=0;i < tam;i++){
    a->append(i);
    a->tail();//axioma 9
  } // Expect two strings not to be equal.
  EXPECT_TRUE(a->size()>0);//axioma 2 y 4
  EXPECT_EQ(tam, a->size());
  EXPECT_FALSE(a->isEmpty());
}
