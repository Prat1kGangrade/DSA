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

void oddFirst(node* &head){

  node* temp1 = head;
  node* temp2 = head->next;
  node* temp3 = head->next;

  while(temp2 != NULL && temp2->next != NULL){
    temp1->next = temp2->next;
    temp1 = temp1->next;
    temp2->next = temp1->next;
    temp2 = temp2->next;
  }
  temp1->next = temp3;

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
/*node = {1,2,3,4,5,6}

  node = {1,3,5,2,4,6}*/
  node* head=NULL;
  insertAtTail(head,1);
  insertAtTail(head,2);
  insertAtTail(head,3);
  insertAtTail(head,4);
  insertAtTail(head,5);
  insertAtTail(head,6);
  insertAtTail(head,7);

  display(head);

  oddFirst(head);

  display(head);

  return 0;
}
