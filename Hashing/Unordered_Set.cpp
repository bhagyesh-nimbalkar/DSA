#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     cout<<"Enter the data Entry: ";
     cin>>n;
     //unordered_map<int,int> m;
     unordered_set<int> m;
     for(int i=0;i<n;i++)
     {
           int key,value;
          /*cout<<"Enter the Key:";
          cin>>key;*/
          cout<<"Enter the Value: ";
          cin>>value;
          m.insert(value);
     }
     for(auto X:m)
     {
          cout<<X<<"\n";
     }
     cout<<m.size()<<'\n';
     return 0;
}