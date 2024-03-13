#include<iostream>
using namespace std;

#define n 20

class queue{
  int* arr;
  int front;
  int back;
public:
  queue(){
    arr = new int[n];
    front = -1;
    back  = -1;
  }

  void push(int x){
    if(back == n-1){
      cout<<"queue overflowed"<<endl;
      return;
    }
    back++;
    arr[back] = x;

    if(front == -1){
      front++;
    }
  }

 void pop(){
   if(front == -1 || front > back){
     cout<<"no element in queue"<<endl;
     return;
   }

   front++;
 }

 int peek(){
   if(front == -1 || front > back){
     cout<<"no element in queue"<<endl;
     return -1;
   }

   return arr[front];
 }

 void display(){
   if(back == -1){
     cout<<"queue is empty";
     return;
   }
   for(int i=front;i<=back;i++){

     cout<<arr[i]<<" ";
   }
   cout<<endl;
 }

 bool empty(){
   if(front == -1 || front > back){
     return true;
   }
   return false;
 }

};

int main(){
  queue q;
  cout<<"lab manual by Yash Gangrade"

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
        q.push(val);
        cout<<val<<" is pushed";
        break;
      }
      case 2:{

        cout<<q.peek()<<" is popped";
        q.pop();
        break;
      }
      case 3:{
        q.display();
        break;
      }
      default:{
        cout<<"invalid key pressed";
      }
    }
  }while(ch != 0);

  //cout<<q.empty();

  return 0;
}

/*int ch,val;
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
      q.push(val);
      cout<<val<<" is pushed";
      break;
    }
    case 2:{

      cout<<<<" is popped";
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
}while(ch != 0);*/
