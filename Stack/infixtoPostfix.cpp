#include <bits/stdc++.h>
using namespace std;

int Precedence(char symbol)
{ 
      switch(symbol)
      {
           case '+':
           case '-':{
              return 1;
           }

           case '*':
           case '/':
           {
             return 2;
           }
           case '^': return 3;
           default: return -1;
      }
      return -1;
}
bool isChar(char x)
{
      switch(x){
         case '+': return true;
         case '-': return true;
         case '*': return true;
         case '/': return true;
         case '^': return true;
         default: return false;
      }
      return false;
}
string InfixtoPost(string str)
{
     stack<char> st;
     string res="";
     for(int i=0;i<str.size();i++)
     {
          if(str[i]=='('){ st.push(str[i]); }
          else if(str[i]==')')
          {
               
               while(st.top()!='(')
               {
                    
                    res+=st.top();
                    st.pop();
               }
               st.pop();
          }
          else if(isChar(str[i]))
          {
               while(!st.empty() && (Precedence(st.top())>Precedence(str[i])))
               {
                   res+=st.top();
                   st.pop();
               }
               st.push(str[i]);
          }
          else {
             res+=str[i];
          }
     }
     while(!st.empty()){
         res+=st.top();
         st.pop();
     }
     return res;
}

int main()
{

     string infix="(a+b)*(c+d)";
     cout<<InfixtoPost(infix)<<'\n';
     return 0;
}