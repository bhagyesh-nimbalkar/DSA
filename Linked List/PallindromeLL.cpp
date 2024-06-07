#include <bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    Node* next;

    Node(char x)
    {
          data=x;
          next=NULL;
    }
};

Node* Reverse(Node* head)
{
      if(head==nullptr) return nullptr;
      if(head->next==nullptr) return head;

      Node* nxt=head->next,*curr=head,*prev=head;
      while(nxt!=nullptr)
      {
           if(curr==prev)
           {
                curr->next=nullptr;
           }
           else {
               curr->next=prev;
           }
           prev=curr;
           curr=nxt;
           nxt=nxt->next;
      }
      curr->next=prev;
      return curr;
}
bool isPallindrome(Node* head)
{
      int size=0;
      Node* curr=head;
      while(curr!=nullptr)
      {
          size++;
          curr=curr->next;
      }
      int mid = (size/2)+1;
      curr=head;
      int cnt=1;
      while(cnt!=mid)
      { 
            curr=curr->next;
            cnt++;
      }
      Node* temp = Reverse(curr);
      cnt=1;
      while(cnt!=mid)
      {
          if(temp->data!=head->data) return false;

          head=head->next;
          temp=temp->next;
          cnt++;
      }
      return true;
}
void LinkedListTraversal(Node* head)
{
     while(head!=nullptr)
     {
          cout<<head->data<<' ';
          head=head->next;
     }
     cout<<'\n';
     return;
}

int main()
{
      Node* first,*second,*third,*fourth,*fifth;

      first = new Node('G');
      second = new Node('F');
      third = new Node('G');
     // fourth = new Node('G');
     // fifth = new Node('R');

      first->next=second;
      second->next=third;
     // third->next=fourth;
      //fourth->next=fifth;

      cout<<boolalpha<<isPallindrome(first)<<'\n';

      return 0;
}