#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }// 1 2 3
  cout<<endl;
  vector<int>::iterator it;
  for(it=v.begin();it!=v.end();it++)
  {
    cout<<*it<<" ";
  }// 1 2 3
  cout<<endl;
  for(auto i:v){
    cout<<i<<" ";
  }// 1 2 3
  cout<<endl;

  v.pop_back(); // 1 2 _it will pop the end element

  vector<int> v2 (3,50);
  // 50 50 50

  swap(v,v2); // v me v2 ki value and vice versa

  for(auto element:v){
    cout<<element<<" ";
  }
  cout<<endl;
  for(auto element:v2){
    cout<<element<<" ";
  }

  sort(v.begin(),v.end());


  return 0;
}
