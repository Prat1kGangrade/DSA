#include<iostream>
using namespace std; // a[0]    a[2]    a[4]      it means a[0]>=a[1]<=a[2]>=a[3]
                     //     a[1]    a[3]    a[5]
void swap(int a[], int c, int b){
  int temp;
  temp=a[c];
  a[c]=a[b];
  a[b]=temp;
  return;
}

void ws(int a[], int n){

  for(int i=1;i<n;i+=2){

    if(a[i]>a[i-1]){
      swap(a,i,i-1);
    }

     if(a[i]>a[i+1] && i<=n-2){
      swap(a,i,i+1);
    }
  }
}
int main(){

  int a[] = {1,3,4,7,5,6,2};

  ws(a,7);

  for(int i=0;i<7;i++){

    cout<<a[i]<<" ";
  }
  return 0;
}
