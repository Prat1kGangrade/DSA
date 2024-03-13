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
  cout<<temp<<" "<<head<<endl;;
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
  insertAtTail(head,3);
  insertAtTail(head,4);



  display(head);

  return 0;
}

/*
#include<iostream>
using namespace std;

class Node{
public:
  int data;
  Node *next;

  Node(int data){
    this->data = data;
    next = NULL;
  }
};

void addAtTail(Node* &head ,int data){
  Node *newNode = new Node(data);
  if(head == NULL){
    head = newNode;
    return;
  }

  Node* temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }
  temp->next = newNode;
}

void display(Node *head){
  Node *temp = head;
  while(temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<"null"<<endl;
}

Node *rvrs(Node* &head){
  Node *pre = NULL;
  Node *curr = head;
  Node *nex = head->next;
  while(curr != NULL){
    curr->next = pre;
    pre = curr;
    curr = nex;
    (nex == NULL)?nex = NULL:nex = nex->next;
  }
  return pre;

}


int main(){
  Node* head = NULL;
  addAtTail(head, 3);
  addAtTail(head, 4);
  addAtTail(head, 5);
  display(head);
  Node *head1 = rvrs(head);
  display(head1);
  return 0;
}

*/
