#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x)
    {
          data=x;
          next=NULL;
    }
};

void Traversal(Node* head)
{
     while(head!=nullptr)
     {
          cout<<head->data<<' ';
          head=head->next;
     }
     cout<<'\n';
     return;   
}
Node* RemoveDup(Node* head)
{
      if(head==nullptr) return nullptr;
      if(head->next==nullptr) return head;
      Node* prev=head,*curr= head->next;
      while(curr!=nullptr)
      {
            if(prev->data == curr->data)
            {
                  Node* temp = curr;
                  curr=curr->next;
                  prev->next=curr;
                  delete temp;
                  continue;
            }
            prev=curr;
            curr=curr->next;
      }
      return head;
}
int main(){
      Node* head = new Node(5);
      head->next = new Node(10);
      head->next->next = new Node(15);
      head->next->next->next = new Node(20);
      head->next->next->next->next = new Node(30);
      head->next->next->next->next->next= new Node(30);


      Traversal(head);
      head = RemoveDup(head);
      Traversal(head);
      return 0;
}