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
Node* DeleteHead(Node* head)
{
     if(head==nullptr) return nullptr;
     if(head->next==head)
     {
        delete head;
        return nullptr;
     }
     head->data = head->next->data;
     Node* ref = head->next->next;
     delete head->next;
     head->next = ref;
     return head;
}
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

     first = nullptr;//new Node(10);
    // second = new Node(20);
     //third = new Node(30);
    // fourth = new Node(40);

     //first->next=first;
     //second->next=first;
    // third->next=first;
    // fourth->next=first;

     Traversal(first);
     first=DeleteHead(first);
     Traversal(first);
     return 0;
}