#include<iostream>
using namespace std;

node* buildTree(int preorder[], int inorder[], int start, int end){
  static int idx = 0;

  int curr = preorder[idx];
  idx++;
  node* node = new node(curr);

  int pos = search(inorder, start, end, curr);
  node->left = buildTree(preorder, inorder, start, pos-1);
  node->left = buildTree(preorder, inorder, pos+1, end);
}

int main(){
   int preorder[] = {1,2,3,4,5};
   int inorder[] = {4,2,1,5,3};


  return 0;
}
