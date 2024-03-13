#include<iostream>
using namespace std;

class node{
   public:
     int data;
     node* next;

     node(int val){
       data=val;
       next=NULL;
     }
};

node* rotateArr(node* &head, int pos){
  int count = 0;
  node* temp = head;
  node* prev = NULL;

  while(temp->next != NULL){
    prev = temp;
    temp = temp->next;
  }
   temp->next = head;


    while(pos != count){
      prev = temp;
      temp = temp->next;
      count++;
    }
    head = temp;
    prev->next = NULL;

    return head;

}

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

void display(node* head){
  node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}

int main()
{
  node* head=NULL;
  insertAtTail(head,10);
  insertAtTail(head,20);
  insertAtTail(head,30);
  insertAtTail(head,40);
  insertAtTail(head,50);
  insertAtTail(head,60);
  insertAtTail(head,70);
  display(head);

  node* newhead = rotateArr(head,7);

  display(newhead);

  return 0;
}
