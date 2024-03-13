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
  a[0] = a[cnt-1];
  cnt--;
  dcheckIt(a,0,cnt);
  return cnt;
}

int main(){
  int count = 0,n=10;
  int a[n];
  count = insertIt(a,n,60,count);
  count = insertIt(a,n,50,count);
  count = insertIt(a,n,40,count);
  count = insertIt(a,n,10,count);
  count = insertIt(a,n,5,count);
  count = insertIt(a,n,20,count);
  count = insertIt(a,n,30,count);
  count = insertIt(a,n,45,count);
  count = deleteIt(a,count);
  count = deleteIt(a,count);
  count = deleteIt(a,count);

  for(int i=0;i<count;i++){
    cout<<a[i]<<" ";
  }

  return 0;
}
