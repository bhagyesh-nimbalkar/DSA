#include <bits/stdc++.h>
using namespace std;
class AddressTable{
     private:
       int* arr;
     public:
       AddressTable(int x)
       {
          arr = new int[x];
          for(int i=0;i<x;i++)  arr[i]=-1;
       }
       void insert(int x)
       {
             arr[x]=x;
             cout<<"Inserted Successfully\n";
       }
       void search(int x)
       {
             string res =  (arr[x]!=-1)?"Present":"Not Present";
             cout<<res<<'\n';
       }
       void del(int x)
       {
             arr[x]=-1;
             cout<<"Deleted Successfully.\n";
       }
       ~AddressTable(){
          delete[] arr;
       }
};
int main()
{
     AddressTable adt(1000);
     adt.insert(5);
     adt.insert(10);
     adt.insert(200);
     adt.search(10);
     adt.search(100);
     adt.del(10);
     adt.search(10);
     adt.insert(300);
     adt.del(300);
     adt.search(300);
     return 0;
}