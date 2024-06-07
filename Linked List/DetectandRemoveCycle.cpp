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
pair<bool,Node*> isLoop(Node* head)
{
      Node* slow = head,*fast=head;
      while(fast!=nullptr && fast->next!=nullptr)
      {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return {true,slow};
      }
      return {false,nullptr};
}
Node* DetectandRemove(Node* head)
{
       if(head==nullptr) return nullptr;
       pair<bool,Node*> res = isLoop(head);
       if(!res.first) return head;

       Node* fast= res.second;
       Node* slow = head;
       while(slow!=fast)
       {
          slow=slow->next;
          fast=fast->next;
       }
       while(fast->next!=slow)
       {
             fast=fast->next;
       }
       fast->next=nullptr;
       return head;
}
int main()
{
     Node* first,*second,*third,*fourth;
     first = new Node(10);
     second = new Node(15);
     third = new Node(5);
     fourth = new Node(20); 

     first->next=second;
     second->next=third;
     third->next=fourth;
     fourth->next=first;

     first = DetectandRemove(first);
     Traversal(first);
     return 0;
}