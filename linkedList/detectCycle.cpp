#include<iostream>
using namespace std;

class node{          //defined a class named node
   public:
     int data;
     node* next;

     node(int val){         //a constructor
       data = val;
       next=NULL;
     }
};

void removeCycle(node* &head){
  node* fast = head;
  node* slow = head;
  do{
    slow = slow->next;
    fast = fast->next->next;
  }while(fast != slow);
  fast = head;
  while(fast->next != slow->next){
    fast = fast->next;
    slow = slow->next;
  }
  slow->next = NULL;
}

bool detectCycle(node* &head){
	node* fast = head;
	node* slow = head;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(fast == slow){
			return true;
		}
	}
	return false;
}

void makeCycle(node* &head, int pos){

  node* temp = head;
  node* linkIt;
    int count = 1;
  while(temp->next != NULL){
    if(count == pos){
      linkIt = temp;
    }
    temp = temp->next;
    count++;
  }
  temp->next = linkIt;
}

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
    cout<<temp->data<<" -> ";
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
  insertAtTail(head,7);

  makeCycle(head,4);
  cout<<detectCycle(head)<<endl;

  removeCycle(head);

  cout<<detectCycle(head)<<endl;

  display(head);

  return 0;
}
