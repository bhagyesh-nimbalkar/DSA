#include <bits/stdc++.h>
using namespace std;

class MyStack{
   private:
     int min=-1;
     stack<int> s,my;
   public:
     MyStack() = default;
     void push(int x)
     {
         if((min==-1) || (x<=min)){
             my.push(x);
             s.push(min);
             min=x;
             return;
         }
         my.push(x);
     }
     int pop()
     {
         if(my.empty()) return -1;
         int x = my.top();
         if(x==min){
             min=s.top();
             s.pop();
         }
         my.pop();
         return x;
     }
     int getMin()
     {
          return min;
     }

};

int main(){
    MyStack s;
    s.push(5);
    s.push(10);
    s.push(20);
    s.push(2);
    cout<<s.getMin()<<'\n';
    s.push(6);
    s.push(4);
    s.pop();
    s.pop();
    s.push(2);
    s.pop();
    s.push(1);
    s.pop();
    return 0;
}