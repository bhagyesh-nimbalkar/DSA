#include <iostream>
using namespace std;

void Generate(string t,string s,int i)
{
     if(i==s.size()) 
     {
        cout<<t<<'\n';
        return;
     }
     Generate(t,s,i+1);
     Generate(t+s[i],s,i+1);
     return;
}
int main()
{
      string s = "ABCD";
      Generate("",s,0);
      return 0;
}