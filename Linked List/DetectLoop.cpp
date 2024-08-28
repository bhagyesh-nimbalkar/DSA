#include <bits/stdc++.h>
using namespace std;

struct Node{
      int data;
      Node* next;
      Node(int x)
      {
          data =x;
          next=nullptr;
      }
};

bool isLoop(Node* head)
{
     if(head==nullptr) return false;
     if(head->next==nullptr) return false;

     Node* fast=head,*slow=head;
    do{
          fast=fast->next->next;
          slow=slow->next;

          if(fast==slow) return true;
     }while(fast!=nullptr && fast->next!=nullptr);
     return false;
}
int main()
{
     Node* head = new Node(10);
     Node* second = new Node(15);
     Node* third = new Node(12);
     Node* fourth = new Node(20);
     head->next=second;
     second->next=third;
     third->next=fourth;

     cout<<boolalpha<<isLoop(head)<<'\n';
     return 0;
}