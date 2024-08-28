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
Node* DeleteKNode(Node* head,int k)
{
     if(head==nullptr) return nullptr;
     if(head==head->next) {
         delete head;
         return nullptr;
     }
     Node* curr = head;
     int cnt=1;
    do
     {
           if(k==cnt)
           {
               Node* temp = curr->next;
               curr->data = curr->next->data;
               if(curr->next==head) head = curr;
               curr->next = curr->next->next; 
               delete temp;
               break;
           }
         cnt++;
         curr=curr->next;
     }while(curr!=head);
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
     //second = new Node(20);
     //third = new Node(30);
     //fourth = new Node(40);

     //first->next=first;
     //second->next=first;
     //third->next=first;
    // fourth->next=first;

     Traversal(first);
     first=DeleteKNode(first,1);
     Traversal(first);
     return 0;
}