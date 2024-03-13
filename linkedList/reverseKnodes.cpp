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

/*void deletion(node* &head, int val){
  node* temp = head;
  while(temp->next->data != val){
    temp = temp->next;

  }
  node* todelete = temp->next;
  temp->next = temp->next->next;
  delete todelete;
}*/

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

node* reverseKnodes(node* &head, int k){
  node* prev = NULL;
  node* curr = head;
  node* forw;
  int count = 0;
  while(curr != NULL && count<k){
    forw = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forw;
    count++;
  }

  if(forw != NULL){
    head->next = reverseKnodes(forw,k);
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

  insert(head,1);
  insert(head,2);
  insert(head,3);
  insert(head,4);
  insert(head,5);
  insert(head,6);

  display(head);

  node *newhead = reverseKnodes(head, 2);

  display(newhead);


  return 0;
}
