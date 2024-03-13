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

node* newNode(node* &head, int pos){
  int count = 1;
  node* temp = head;

  while(count != pos){
     temp = temp->next;
     count++;
  }
  return temp;
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
/*node = {1,2,3,4,5}
  delete  3
  node = {1,2,4,5}*/
  node* head=NULL;
  insertAtTail(head,1);
  insertAtTail(head,2);
  insertAtTail(head,3);
  insertAtTail(head,4);
  insertAtTail(head,5);
  insertAtTail(head,6);

  display(head);

  node* newhead = newNode(head,3);

  display(newhead);

  deleteIn(newhead);

  return 0;
}
