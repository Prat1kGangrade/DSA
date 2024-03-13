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

int size(node* head){
  node* temp = head;
  int count = 1;
  while(temp != NULL){
    temp = temp->next;
    count++;
  }
  return count;
}

int findNth(node* head,int pos){
  node* temp = head;
  int endPos = size(head)-pos;
  int count = 1;
  while(count != endPos){
    temp = temp->next;
    count++;
  }

  return temp->data;

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
  insertAtTail(head,3);
  insertAtTail(head,4);
  insertAtTail(head,5);
  insertAtTail(head,6);
  display(head);

  cout<<findNth(head,2);

  return 0;
}
