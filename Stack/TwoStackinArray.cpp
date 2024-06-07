#include <bits/stdc++.h>
using namespace std;

class Stack{
     private:
      int* arr;
      int top1=-1,top2=0,cap=0,front=0;
     public: 
      Stack(int x)
      {
          arr = new int[x];
          top2=(x&1)?x/2:x/2-1;
          front=top2;
          cap=x;
      }
      int pop1(){
         if(top1==-1) return -1;
         return arr[top1--];
      }
      int pop2(){
          if(top2==front) return -1;
          return arr[top2--];
      }
      int size1(){
          return top1+1;
      }
      int size2(){
         return top2-front;
      }
      void push1(int x){
           if(top1==front && top2==cap-1) return;
           if(top1!=top2){
              arr[++top1]=x;
              return;
           }
           int i = top2+1;
           while(i!=front)
           {
              arr[i]=arr[i-1];
              i--;
           }
           front=front+1;
           top2++;
           arr[++top1]=x;
      }
      void push2(int x)
      {
          if(top1==front && top2==cap-1) return;
          if(top2!=cap-1){
               arr[++top2]=x;
               return;
          }
          int i=front-1;
          while(i!=top2)
          {
               arr[i]=arr[i+1];
               i++;
          }
          front=front-1;
          arr[top2]=x;
      }
      ~Stack(){
          delete[] arr;
      }
};

int main()
{
     Stack s(5);
     s.push1(1);
     s.push1(2);
     s.push1(3);
     s.push1(5);
     s.push2(4);
     cout<<s.size2()<<'\n';
     cout<<s.size1()<<'\n';
     return 0;
}