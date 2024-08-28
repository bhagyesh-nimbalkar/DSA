#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* random;
    Node(int x)
    {
        data=x;
        next=random=nullptr;
    }
};

void Traversal(Node* head)
{
     while(head!=nullptr)
     {
          cout<<head->data<<' ';
          head=head->next;
     }
     cout<<"\n";
}
Node* CloneLL(Node* head)
{
      Node* curr = head;
      unordered_map<Node*,int> mp;
      vector<Node*> v;
      int i=0;
      while(curr!=nullptr)
      {
           Node* temp = new Node(curr->data);
           v.emplace_back(temp);
           mp[curr]=i;
           i++;
           curr=curr->next;
      }
      curr=head;
      i=0;
      while(curr!=nullptr)
      {
           int Nxt = mp[curr->next];
           int Rand = mp[curr->random];
          if(curr->next==nullptr)
          {
              v[i]->random=v[Rand];
              break;
          }
           v[i]->next=v[Nxt];
           v[i]->random=v[Rand];
           i++;
           curr=curr->next;
      }
      return v[0];
}
int main()
{
      Node* first,*second,*third,*fourth,*fifth;
      
      first = new Node(10);
      second = new Node(5);
      third = new Node(20);
      fourth = new Node(15);
      fifth = new Node(20);

      first->next=second;
      first->random=third;
      second->next=third;
      second->random=fourth;
      third->next = fourth;
      third->random = first;
      fourth->next=fifth;
      fourth->random = third;
      fifth->random = fourth;

      Traversal(first);
      first = CloneLL(first);
      Traversal(first);
      return 0;
}