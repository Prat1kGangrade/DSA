#include<iostream>
using namespace std;

void swap(int a[],int i,int j){
  int temp = a[i];
      a[i] = a[j];
      a[j] = temp;
}

void icheckIt(int a[],int val,int cnt){
  int Pindex = cnt/2;
  if(cnt<0){
    return;
  }
  if(a[cnt]>a[Pindex]){
    swap(a,cnt,Pindex);
    icheckIt(a,val,Pindex);
  }
  return;
}

int insertIt(int a[],int n,int val,int cnt){
  if(cnt>=n){
    cout<<"Heap overflow"<<endl;
    return 0;
  }
  a[cnt] = val;
  icheckIt(a,val,cnt);
   cnt++;
    return cnt;
}

void dcheckIt(int a[],int leastCnt,int maxCnt){
  if(leastCnt<maxCnt){
    int lchild = leastCnt*2;
    int rchild = lchild+1;
    if(rchild>maxCnt || lchild>maxCnt){
        return;

    }
    else{
      if(a[lchild]>a[rchild]){
        if(a[lchild]>a[leastCnt]){
          swap(a,lchild,leastCnt);
          dcheckIt(a,lchild,maxCnt);
        }
      }
      else if(a[rchild]>a[leastCnt]){
        swap(a,rchild,leastCnt);
        dcheckIt(a,rchild,maxCnt);
      }
    }
  }
  return;
}

int deleteIt(int a[],int cnt){
  if(cnt<=0){
    cout<<"heap underflow";
  }

  int temp = a[0];
  a[0] = a[cnt-1];
  cnt--;
  dcheckIt(a,0,cnt);
  a[cnt] = temp;
  return cnt;
}

int main(){
  int count = 0,n=11;
  int a[n] = {20, 35, 81, 11, 54, 20, 4, 22, 17, 13, 65};

  for(int i=0;i<n;i++){
    count = insertIt(a,n,a[i],count);
  }
  for(int i=0;i<n;i++){
    count = deleteIt(a,count);
  }
  for(int i=0;i<n;i++){
    cout<<a[i]<<" ";
  }


  return 0;
}
