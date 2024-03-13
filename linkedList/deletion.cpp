#include<iostream>
using namespace std;

class node{          //defined a class named node
   public:
     int data;
     node *next;

     node(int val){         //a constructor
       data=val;
       next=NULL;
     }
};

void insertAtTail(node* &head, int val){

  node *n = new node(val);

  if(head==NULL){
    head=n;
    return;
  }

  node *temp=head;
  while(temp->next!=NULL){
    temp = temp->next;
  }
  temp->next=n;
}

void deleteAtHead(node* &head){

  node* todelete = head;
  head = head->next;
  delete todelete;
}

void deleteIn(node* &head, int val){

  if(head == NULL){

    return ;
  }
  if(head->next == NULL){
    deleteAtHead(head);
  }
  node* temp = head;
  while(temp->next->data!=val){
    temp = temp->next;
  }
     node* todelete = temp->next;
  temp->next = temp->next->next;

  delete todelete;

}

void display(node *head){
  node *temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}

int main()
{
  node *head=NULL;
  insertAtTail(head,1);
  insertAtTail(head,2);
  insertAtTail(head,3);
  insertAtTail(head,4);
  deleteIn(head,3);
  display(head);
  return 0;
}
