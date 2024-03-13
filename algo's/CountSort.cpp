#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findMax(int a[],int n){
  int max = INT_MIN;
    for(int i=0;i<n;i++){
      if(a[i]>max){
        max = a[i];
      }
    }
    return ++max;
}

int main(){
  int n = 10;
  int a[n] = {4,3,2,1,4,3,2,1,4,3};

  int max = findMax(a,n);
  int b[max] = {0};

  for(int i=0;i<n;i++){
    b[a[i]]++;
  }
   int j=0,i=0;
  while(i<n){
    while(b[j]!=0){
      a[i] = j;
      b[j]--;
      i++;
    }
    j++;
  }

  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }

  return 0;
}
