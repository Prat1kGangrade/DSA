#include<iostream>
using namespace std;

bool find(int a[], int  n, int key){
  int s = 0;
  int e = n;

  while(s<=e){
    int mid = (e+s)/2;

    if(a[mid] == key){
      return true;
    }
  else if(a[mid]>key){
    e = mid-1;
  }
  else{
    s = mid+1;
  }
}
  return false;
}

int main()
{
  int a[] = {2,4,6,8,12,34,47,58};
  int n = sizeof(a)/sizeof(a[0]);

 for(int i=0;i<n;i++){
   cout<<a[i]<<" ";
 }
 cout<<endl<<"enter key: ";
  int key;
  cin>>key;
  cout<<find(a,n,key);

  return 0;
}
