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
void Traversal(Node* head)
{
     while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
     }
     cout<<'\n';
     return;
}
Node* MergeLL(Node* first,Node* second)
{
      if(first==nullptr && second==nullptr) return nullptr;
      if(first==nullptr) return second;
      if(second==nullptr) return first;

      Node *head=nullptr;
      if(first->data<second->data){ head=first; first=first->next;}
      else {head=second; second=second->next;}

      Node* curr = head;
      while(first!=nullptr && second!=nullptr)
      {
            if(first->data<second->data)
            {
                  curr->next=first;
                  first=first->next;
                  curr=curr->next;
            }
            else {
                  curr->next=second;
                  second=second->next;
                  curr=curr->next;
            }
      }
      while(first!=nullptr) {
                  curr->next=first;
                  first=first->next;
                  curr=curr->next;
      }
      while(second!=nullptr)
      {
              curr->next=second;
              second=second->next;
              curr=curr->next;
      }
      return head;
}
int main()
{
     Node* first,*second,*third,*fourth,*fifth,*sixth,*seven,*eight,*nine;

     first = new Node(10);
     second = new Node(20);
     third = new Node(30);

     fourth = new Node(40);
     fifth = new Node(5); 
     sixth = new Node(15);
     seven = new Node(17);
     eight = new Node(18);
     nine = new Node(35);

     first->next=second;
     second->next=third;
     third->next=fourth;

     fifth->next=sixth;
     sixth->next=seven;
     seven->next=eight;
     eight->next=nine;

     first = MergeLL(first,fifth);
     Traversal(first);
     return 0;
}