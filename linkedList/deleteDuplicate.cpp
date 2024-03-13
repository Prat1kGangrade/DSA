#include<iostream>
using namespace std;// program to delete duplicate node from sorted linked list.

class node{
public:
  int data;
  node* next;

  node(int val){
    data = val;
    next = NULL;
  }
};

deleteDuplicates(node* &head){
  node* temp = head;
  node* deleteit;
  while(temp->next != NULL){
    if(temp->data == temp->next->data){
      deleteit = temp->next;
      temp->next = temp->next->next;
      delete deleteit;
    }
    else{
    temp = temp->next;
   }
  }
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
  insertAtTail(head,1);
  insertAtTail(head,2);
  insertAtTail(head,2);
  insertAtTail(head,4);
  insertAtTail(head,4);
  insertAtTail(head,4);
  insertAtTail(head,5);
  insertAtTail(head,5);
  display(head);
  deleteDuplicates(head);
  display(head);

  return 0;
}
