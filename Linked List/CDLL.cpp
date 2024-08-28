#include <bits/stdc++.h>
using namespace std;

struct Node{
      int data;
      Node* prev,*next;
      Node(int x)
      {
          data=x;
          next=prev=nullptr;
      }
};

void Traversal(Node* head)
{
      if(head==nullptr) return;
      Node* curr = head;
      do{
           cout<<curr->data<<' ';
           curr = curr->next;
      }while(curr!=head);
      cout<<'\n';
}


int main()
{
     Node* first,*second,*third;

     first = new Node(10);
     second = new Node(20);
     third = new Node(30);

     first->prev=third;
     first->next=second;
     second->prev=first;
     second->next=third;
     third->prev=second;
     third->next=first;
     return 0;
}