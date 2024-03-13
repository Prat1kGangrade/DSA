#include<iostream>
using namespace std;

class node{
public:
  int data;
  node *next;

  node(int val){
    data = val;
    next = NULL;
  }
};

void insert(node * &head, int val){
  node* n = new node(val);
  if(head == NULL){
    head = n;
    return;
  }

  node* temp = head;
  while(temp->next != NULL){
       temp = temp->next;
  }
  temp->next = n;
}

node* reverse(node* &head){

  node* curr = head;
  node* prev = NULL;
  node* forw;

  while(curr != NULL){
    forw = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forw;

  }
  return prev;

}

void display(node* &head){

  node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}
int main()
{
  node * head = NULL;

  for(int i=1;i<5;i++){
    insert(head,i);
  }

  node *newhead = reverse(head);

  display(newhead);

  return 0;
}
