#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// writing a code to implement a binary tree

class Node{
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
      this->data = data;
      left = NULL;
      right = NULL;
    }
};

static int i = 0;
//traversal using recursion
void createTree(vector<int> &v, Node* &root){
  if(i >= v.size()) return;
  if(v[i] == -1) return;
  Node* n = new Node(v[i]);
  root = n;
  i++;
  createTree(v, root->left);
  i++;
  createTree(v, root->right);
}

void preOrder(Node* root){
  if(!root) return;
  cout<<root->data<<" ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node* root){
  if(!root) return;

  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

//writing an iterative approach for inOrder traversal
void inOrderIter(Node* root){
    stack<Node*> st;
    st.push(root); 
    Node* temp = NULL;
    while(!st.empty()){
        if(st.top()->left) st.push(st.top()->left);

        else{
            temp = st.top();
            st.pop();
            cout<<temp->data<<" ";
            if(temp->right) st.push(temp->right);
        }  
    }
}

void preOrderIter(Node* root){
  stack<Node*> st;
  Node* temp = NULL;
  st.push(root);
  while(!st.empty()){
    if(st.top()->left){}
  }
}

int main(){

  vector<int> v{1,2,3,-1,-1,4,-1,-1,5,-1,6,7,-1,-1,-1};

  Node* root = NULL;

  createTree(v, root);

  inOrder(root);

  return 0;
}
