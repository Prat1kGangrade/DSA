#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define n 100

class Stack{
  int* arr;
  int top;

public:
  Stack(){
    arr = new int[n];
    top = -1;

  }

void push(int x){
  if(top == n-1){
    cout<<"stack overflow"<<endl;
    return;
  }
  top++;
  arr[top] = x;
  return;
}

void pop(){
  if(top == -1){
    cout<<"no element to pop"<<endl;
    return;
  }
  top--;
}

void Top(){
  if(top == -1){
    cout<<"no element in stack"<<endl;
    return;
  }
  cout<<arr[top];
}

void display(){
  if(top == -1){
    cout<<"stack is empty";
    return;
  }
  for(int i=0;i<=top;i++){
    cout<<arr[i]<<endl;
  }
}

void empty(){
 top = -1;
}

};

int main(){
  Stack st;
  int ch,val;
  cout<<"press 1 for push\n"
        "press 2 for pop\n"
        "press 3 for display\n"
        "press 0 for exit\n";
  do{
    cout<<"\nEnter your choice: ";
    cin>>ch;

    switch(ch){
      case 0:{
        exit(0);
        break;
      }
      case 1:{
        cout<<"\nenter the value to push: ";
        cin>>val;
        st.push(val);
        cout<<val<<" is pushed";
        break;
      }
      case 2:{
        st.Top();
        cout<<" is popped";
        st.pop();
        break;
      }
      case 3:{
        st.display();
        break;
      }
      default:{
        cout<<"invalid key pressed";
      }
    }
  }while(ch != 0);


  return 0;
}
