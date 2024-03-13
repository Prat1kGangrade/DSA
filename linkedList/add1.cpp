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

void insertAthead(node* &head, int val){
  node* n = new node(val);
  n->next = head;
  head = n;
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

void add1(node* &head){
  node* temp = head;

  temp->data += 1;
  if(temp->data == 10){
    temp->data = 0;
    add1(temp->next);
  }
  return;
}

void display(node* &head){

  node* temp = head;
  while(temp != NULL){
    cout<<temp->data;
    temp = temp->next;
  }
  cout<<endl;
}

int main()
{
  node * head = NULL;

  insert(head,1);
  insert(head,8);
  insert(head,9);
  insert(head,9);

  display(head);

  node *newhead = reverse(head);

  add1(newhead);

  //display(newhead);

  head = reverse(newhead);

  display(head);

  return 0;
}
