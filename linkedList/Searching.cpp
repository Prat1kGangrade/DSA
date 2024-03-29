#include<iostream>
using namespace std;

class node{          //defined a class named node
   public:
     int data;
     node* next;

     node(int val){         //a constructor
       data=val;
       next=NULL;
     }
};

void insertAtTail(node* &head, int val){

  node* n = new node(val);

  if(head==NULL){
    head=n;
    return;
  }

  node* temp=head;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  temp->next=n;
}

bool find(node* head,int key){
  node* temp = head;
  while(temp != NULL){
    if(temp->data == key){
      return true;
    }
    temp = temp->next;
  }
  return false;
}

int main()
{
  node* head=NULL;
  insertAtTail(head,1);
  insertAtTail(head,2);
  insertAtTail(head,3);

  cout<<find(head,3);

  return 0;
}
