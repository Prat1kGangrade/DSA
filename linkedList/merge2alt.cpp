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

void merge2Alt(node* h1, node*h2){

  node* t1 = h1;
  node* t2 = h2;
  node* p1 = NULL;
  node* p2 = NULL;

  while(t1->next != NULL && t2->next != NULL){
    p1 = t1;
    t1 = t1->next;
    p1->next = t2;

    p2 = t2;
    t2 = t2->next;
    p2->next = t1;
  }
  if(t1->next == NULL){
    t1->next = t2;
  }
  else if(t2->next == NULL){
    p1 = t1->next;
    t1->next = t2;
    t2->next = p1;
  }

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
  insertAtTail(head1,7);
  //insertAtTail(head1,9);

  insertAtTail(head2,2);
  insertAtTail(head2,4);
  insertAtTail(head2,6);
  insertAtTail(head2,8);
  insertAtTail(head2,9);
  insertAtTail(head2,0);


  display(head1);
  display(head2);

  merge2Alt(head1, head2);

  display(head1);

  return 0;
}
