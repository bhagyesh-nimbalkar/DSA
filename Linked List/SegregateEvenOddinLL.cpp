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

Node* segregate(Node* head)
{
       if(head==nullptr) return nullptr;
       Node* firstOdd=nullptr,*firstEven=nullptr;
       Node* curr = head,*lastO=nullptr,*lastE=nullptr;
       while(curr!=nullptr)
       {
             if(curr->data%2==0)
             {
                   if(firstEven==nullptr) 
                   { 
                        firstEven = curr;
                        curr=curr->next;
                        lastE=firstEven;
                        lastE->next=nullptr;
                        continue;
                   }
                   else 
                   {
                         lastE->next=curr;
                         lastE=curr;
                         curr=curr->next;
                         lastE->next=nullptr;
                         continue;
                   }
             }
             else {
                  if(firstOdd==nullptr) 
                   { 
                        firstOdd = curr;
                        curr=curr->next;
                        lastO=firstOdd;
                        lastO->next=nullptr;
                        continue;
                   }
                   else 
                   {
                         lastO->next=curr;
                         lastO=curr;
                         curr=curr->next;
                         lastO->next=nullptr;
                         continue;
                   }
             }
       }
       if(lastE==nullptr) return firstOdd;
       lastE->next=firstOdd;
       return firstEven;
}
int main()
{
     Node* first,*second,*third,*fourth,*fifth,*sixth;
     //first = new Node(17);
     //second = new Node(15);
     third = new Node(5);
     fourth = new Node(10); 
     //fifth = new Node(5);
     sixth = new Node(7);


     //first->next=second;
     //second->next=third;
     third->next=fourth;
     fourth->next=sixth;
     //fifth->next=sixth;

     first = segregate(third);
     Traversal(first);
     return 0;
}