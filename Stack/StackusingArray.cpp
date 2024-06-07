#include <bits/stdc++.h>
using namespace std;

class Stack{
     private:
       int* arr;
       int top=-1,cap=0;
     public:
       Stack() = default;
       Stack(int x)
       {
           arr = new int[x];
           cap=x;
       }
       bool isEmpty(){
          return top==-1;
       }
       void push(int x)
       {
           if(top==cap-1) return;
           arr[++top]=x;
       }
       int pop()
       {
            if(isEmpty()) return -1;
            return arr[top--];
       }
       int size(){
           return top+1;
       }
       int peek(){
           if(isEmpty()) return -1;
           return arr[top];
       }
       ~Stack(){
           delete[] arr;
       }
};
int main()
{
     Stack s(5);
     s.push(5);
     s.push(10);
     s.push(20);
     s.push(30);
     s.push(40);
     s.push(50);
     cout<<s.pop()<<'\n';
     cout<<s.size()<<'\n';
     cout<<s.peek()<<'\n';
     cout<<boolalpha<<s.isEmpty()<<'\n';
     return 0;
}