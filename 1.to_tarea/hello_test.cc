#include "arrayStack.cc"
#include <gtest/gtest.h>
/*
AXIOMS
1. pop(newstack)   = newstack
2. pop(push(S,I))  = S
3. top(newstack)   = undefined
4. top(push(S,I))  = I
5. empty(newstack) = true
6. empty(push(S,I))= false
*/
// Demonstrate some basic assertions.

TEST(StackTest, Axioma6) {//empty(push(S,I))= false
  arrayStack<int> stack(10);
  //Stack<int> *newstack = &stack;
  
  stack.push(100);
  EXPECT_FALSE(stack.empty());
}

TEST(StackTest, Axioma5) {//empty(newstack) = true
  arrayStack<int> stack(10);
  Stack<int> *newstack = &stack;

  EXPECT_TRUE(newstack->empty());
}

TEST(StackTest, Axioma4) {
  // 4. top(push(S,I))  = I
  arrayStack<int> stack(10);
  Stack<int> *newstack = &stack;

  newstack->push(3);
  newstack->push(6);
  newstack->push(1);
  
  int p_push = 5;
  newstack->push(p_push);
  EXPECT_TRUE(newstack->top() == p_push);
}

TEST(StackTest, Axioma3){// 3. top(newstack) = undefined
  arrayStack<int> stack(10);
  Stack<int> *newstack = &stack;
  newstack->top();
  //EXPECT_FALSE(newstack->empty());
}
TEST(StackTest, Top) {
  arrayStack<int> stack(10);
  Stack<int> *newstack = &stack;
  newstack->push(3);
  newstack->push(6);
  newstack->push(1);
  EXPECT_EQ(1, newstack->top());
  newstack->pop();
  EXPECT_EQ(6, newstack->top());
  newstack->pop();
  EXPECT_FALSE(newstack->empty());
  EXPECT_EQ(3, newstack->top());
  newstack->pop();
  EXPECT_TRUE(newstack->empty());
}
TEST(StackTest, Axioma1) {//pop(newstack)   = newstack
  arrayStack<int> stack(10);
  Stack<int> *newstack = &stack;
  EXPECT_TRUE(newstack->empty());
  //arrayStack<int> stack_copy = stack;
  //Stack<int> *newstack_copy = &stack_copy;
  newstack->pop();
  EXPECT_TRUE(newstack->empty());
  //EXPECT_TRUE(stack == stack_copy);
}

