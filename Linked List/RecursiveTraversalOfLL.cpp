#include <bits/stdc++.h>
using namespace std;


struct LL{
    int data;
    LL* next;

    LL(int x)
    {
          data=x;
          next=NULL;
    }
};
void LinkedListTraversal(LL* head)
{
      if(head==NULL){
        cout<<'\n';
        return;
      }
      cout<<head->data<<' ';
      LinkedListTraversal(head->next);
}
int main(){
      LL* head = NULL;//new LL(10);
    /*  head->next = new LL(20);
      head->next->next = new LL(30);
      head->next->next->next = new LL(40);*/
      LinkedListTraversal(head);
      return 0;
}