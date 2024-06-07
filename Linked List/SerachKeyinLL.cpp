#include <bits/stdc++.h>
using namespace std;

struct Node{
     int data;
     Node* next;
     Node(int x)
     {
         data=x;
     }
};
int SearchinaLL(Node* head,int find)
{
       int cnt=1;
       while(head!=nullptr)
       {
             if(head->data==find) return cnt;
             head=head->next;
             cnt++;
       }
       return -1;
}
int FindinLL(Node* head,int find,int pos)
{
       if(head==NULL) return -1;
       if(head->data == find) return pos;

       return FindinLL(head->next,find,pos+1);
}
int SearchinaLLRecr(Node* head,int find)
{
       return FindinLL(head,find,1);
}
int main()
{
     Node* head = nullptr;
     /*head->next = new Node(15);
     head->next->next = new Node(20);
     head->next->next->next = new Node(35);*/
     int x=34;
     cout<<SearchinaLL(head,x)<<'\n';
     cout<<SearchinaLLRecr(head,x)<<'\n';
     return 0;
}