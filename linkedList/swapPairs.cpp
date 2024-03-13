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

void insertAtTail(node* &head, int val){
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

node* swapPair(node* &head){
     node* s1 = head;
     node* s2 = head->next;
     node* gift = head->next;
     node* temp;

     while(s2 != NULL && s1 != NULL){
       if(s2->next == NULL){
         s1->next = NULL;
         s2->next = s1;
         break;
       }
       else if(s2->next->next == NULL){
         s1->next = s2->next;
         s2->next = s1;
         s1->next->next = NULL;
         break;
       }
       else{
         s1->next = s2->next->next;
       }
       temp = s2->next;
       s2->next = s1;
       s2 = s1->next;
       s1 = temp;
     }
     return gift;
}

void show(node* &head){
  node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
  }
  cout<<"NULL"<<endl;
}

int main(){

    node *head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    insertAtTail(head,10);
    node* newHead = swapPair(head);
    show(newHead);
  return 0;
}
