#include <bits/stdc++.h>
using namespace std;

struct Node{
     int data;
     Node* next;
     Node(int x)
     { 
          data=x;
          next=nullptr;
     }
};

void Traversal(Node* head)
{
     if(head==nullptr) return;
     cout<<head->data<<' ';
     Node* temp = head;
     temp = temp->next;
     while(temp!=head)
     {
          cout<<temp->data<<' ';
          temp=temp->next;
     }
     cout<<'\n';
     return;
}

int main()
{
     Node* first,*second,*third,*fourth;

     first = new Node(10);
     second = new Node(20);
     /*third = new Node(30);
     fourth = new Node(40);*/

     first->next=second;
     second->next=first;
     /*third->next=fourth;
     fourth->next=first;
    // first->next=first;*/

     Traversal(first);
     return 0;
}