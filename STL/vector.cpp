#include<iostream>
#include<vector>
using namespace std;

int main(){
  vector<int> v;
  v.push_back(2);            //push element in vector
  cout<<"size: "<<v.capacity()<<endl;  //checks size
  v.push_back(3);
  cout<<"size: "<<v.capacity()<<endl;
  v.push_back(4);
  cout<<"size: "<<v.capacity()<<endl;
  v.push_back(5);
  v.push_back(6);
  cout<<"before pop: ";
  for(auto i : v)
   cout<<i<<" ";
  cout<<endl;
  v.pop_back();           //pop the last element
  cout<<"after pop: ";
  for(auto i : v)
   cout<<i<<" ";cout<<endl;

  v.clear();
  cout<<"\nclear karne k baad"<<endl;
  cout<<"capacity utni hi rahegi: "<<v.capacity()<<endl;
  cout<<"size 0 ho jayega: "<<v.size()<<endl;

  vector<int> a(5,2);

  for(auto i : a)
   cout<<i<<" ";

  return 0;
}
