#include <bits/stdc++.h>
using namespace std;

class Heap{
    private:
      int* arr;
      int size,capacity;

    public: 
      Heap(int c){
        arr = new int[c];
        size=0;
        capacity:c;
      }
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    int parent(int i){return (i-1)/2;}

    void insert(int num)
    { 
         if(size>=capacity) return;

         int index = size;
         arr[index]=num;
         size++;
         while(parent(index)>=0 && arr[parent(index)]>arr[index])
         {
                swap(arr[index],arr[parent(index)]);
                index = parent(index);
         }
         return;
    }
    void Display(){
         for(int i=0;i<size;i++) cout<<arr[i]<<' ';
    }
};



int main()
{
    Heap h(10);
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(40);
    h.insert(50);
    h.insert(100);
    h.insert(25);
    h.insert(45);
    h.insert(12);
    h.Display();
    cout<<'\n';
    return 0;
}