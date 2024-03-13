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

void display(node* head){
  node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
  }
  cout<<"NULL"<<endl;
}

node* merge2sort(node* &h1, node* &h2){

  node* dummynode = new node(-1);
  node* temp3 = dummynode;
  node* temp1 = h1;
  node* temp2 = h2;

  while(temp1 != NULL && temp2 != NULL){
    if(temp1->data < temp2->data){
      temp3->next = temp1;
      temp1 = temp1->next;
    }
    else{
      temp3->next = temp2;
      temp2 = temp2->next;
    }
    temp3 = temp3->next;
  }
  while(temp1 != NULL){
    temp3->next = temp1;
    temp1 = temp1->next;
    temp3 = temp3->next;
  }
  while(temp2 != NULL){
    temp3->next =  temp2;
    temp2 = temp2->next;
    temp3 = temp3->next;
  }

  return dummynode->next;

}

int main()
{

  node* head1 = NULL;
  node* head2 = NULL;
  insertAtTail(head1,1);
  insertAtTail(head1,2);
  insertAtTail(head1,4);
  insertAtTail(head1,6);
  insertAtTail(head1,7);
  insertAtTail(head2,3);
  insertAtTail(head2,5);
  insertAtTail(head2,8);
  insertAtTail(head2,9);

  display(head1);
  display(head2);

  node* head = merge2sort(head1,head2);

  display(head);


  return 0;
}
