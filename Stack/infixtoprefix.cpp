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
string assoc(char symbol)
{ 
      switch(symbol)
      {
           case '+':
           case '-':{
              return "ltor";
           }

           case '*':
           case '/':
           {
             return "ltor";
           }
           case '^': return "rtol";
           default: return "-1";
      }
      return "-1";
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
string InfixtoPre(string str)
{
     stack<char> st;
     string res="";
     reverse(str.begin(),str.end());
     for(int i=0;i<str.size();i++)
     {
          if(str[i]=='(') str[i]=')';
          else if(str[i]==')') str[i]='(';
     }
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
               while(!st.empty() && (Precedence(st.top())>=Precedence(str[i])))
               {
                  if(Precedence(st.top())==Precedence(str[i])){
                     if(assoc(str[i])=="ltor") break;
                  }
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
     reverse(res.begin(),res.end());
     return res;
}

int main()
{
     string infix="x+y/z-w*u";
     cout<<InfixtoPre(infix)<<'\n';
     return 0;
}