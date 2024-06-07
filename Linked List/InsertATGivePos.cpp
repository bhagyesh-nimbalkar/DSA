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
Node* InsertATGivePos(Node* head,int pos,int data)
{
       Node* temp = head;
       int cnt=1;
       if(pos==1)
       {
           Node* temp2 = new Node(data);
           temp2->next = head;
           return temp2; 
       }
       while(temp!=NULL)
       {
             if(cnt==pos-1)
             {
                  Node* temp2 = new Node(data);
                  temp2->next = temp->next;
                  temp->next=temp2;
             }
             cnt++;
             temp=temp->next;
       }
       return head;
}
void LinkedListTraversal(Node* head)
{
      if(head==NULL){
        cout<<'\n';
        return;
      }
      cout<<head->data<<' ';
      LinkedListTraversal(head->next);
}

int main(){
      Node* head = new Node(10);
      head->next = new Node(20);
      head->next->next = new Node(25);
      head->next->next->next = new Node(35);
      head = InsertATGivePos(head,2,5);
      LinkedListTraversal(head);
      return 0;
}