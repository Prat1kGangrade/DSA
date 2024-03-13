#include<iostream>
using namespace std;

void swap(int a[],int i,int j){
  int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
}

void checkIt(int a[],int val,int cnt){
  int Pindex = cnt/2;
  if(cnt<0){
    return;
  }
  if(a[cnt]>a[Pindex]){
    swap(a,cnt,Pindex);
    checkIt(a,val,Pindex);
  }
  return;
}

int insertIt(int a[],int n,int val,int cnt){
  if(cnt>=n){
    cout<<"Heap overflow"<<endl;
    return 0;
  }
  a[cnt] = val;
  checkIt(a,val,cnt);
   cnt++;
    return cnt;
}

int main(){
  int count = 0,n=10;
  int a[n];
  count = insertIt(a,n,20,count);
  count = insertIt(a,n,10,count);
  count = insertIt(a,n,30,count);
  count = insertIt(a,n,5,count);
  count = insertIt(a,n,50,count);
  count = insertIt(a,n,40,count);

  for(int i=0;i<count;i++){
    cout<<a[i]<<" ";
  }

  return 0;
}
