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
Node* InsertAtEnd(Node* head,int x)
{
      Node* temp = new Node(x);
      if(head==nullptr)
      { 
         temp->next=temp;
         return temp;
      }
      temp->next=head->next;
      head->next=temp;
      int d = head->data;
      head->data=temp->data;
      temp->data=d;

      return temp;
}
int main()
{
     Node* first,*second,*third,*fourth;

    // first = new Node(10);
    // second = new Node(20);
     //third = new Node(30);
     //fourth = new Node(40);

     //first->next=first;
     //second->next=first;
     //third->next=first;
    // fourth->next=first;

     first=InsertAtEnd(nullptr,5);
     first=InsertAtEnd(first,10);
     Traversal(first);
     return 0;
}