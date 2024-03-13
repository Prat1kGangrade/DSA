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

node* mergeAlt(node* h1, node* h2){
  node* t1 = h1;
  node* t2 = h2;
  node* prev1 = NULL;
  node* prev2 = NULL;

  while(t1->next != NULL && t2->next != NULL){
    prev1 = t1;
    t1 = t1->next;
    prev1->next = t2;
    prev2 = t2;
    t2 = t2->next;
    prev2->next = t1;
  }

  while(t1 != NULL){
    prev1 = t1;
    t1 = t1->next;
    prev1->next = t1;
  }

  while(t2 != NULL){
    prev2 = t2;
    t2 = t2->next;
    prev2->next = t2;
  }

  return h1;

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
  node* head1 = NULL;
  node* head2 = NULL;
  insertAtTail(head1,1);
  insertAtTail(head1,3);
  insertAtTail(head1,5);
  insertAtTail(head2,2);
  insertAtTail(head2,4);
  insertAtTail(head2,6);
  insertAtTail(head2,8);
  insertAtTail(head2,10);

  display(head1);
  display(head2);

  node* newhead = mergeAlt(head1,head2);

  display(newhead);

  return 0;
}
