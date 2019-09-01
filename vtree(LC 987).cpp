/*
Given a binary tree, print the binary tree vertically from the smallest vertical level to the biggest vertical level. 
Nodes with the same vertical level should be printed at the same line, and these nodes should be printed from top to 
bottom, from left to right.
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a) {
      val = a;
      left = NULL;
      right = NULL;
    }
};

class Solution {
public:
  vector<vector<int>> verticalTreeTraversal(TreeNode* root) {
    int vertLevel = 0;
    vector<vector<int>> res;
    if (!root) return res;
    map<int, vector<int>> ht;
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty()) {
      pair<TreeNode*, int> node = q.front();
      q.pop();
      ht[node.second].push_back(node.first->val);
      if (node.first->left) q.push(make_pair(node.first->left, node.second - 1));
      if (node.first->right) q.push(make_pair(node.first->right, node.second + 1));
    }
        
    for (auto it = ht.begin(); it != ht.end(); it++) {
      vector<int> v = it->second;
      res.push_back(v);
    }
    return res;
  }
};

int main() {
  TreeNode* one = new TreeNode(1);
  TreeNode* two = new TreeNode(2);
  TreeNode* three = new TreeNode(3);
  TreeNode* four = new TreeNode(4);
  TreeNode* five = new TreeNode(5);
  TreeNode* six = new TreeNode(6);
  TreeNode* seven = new TreeNode(7);
  TreeNode* eight = new TreeNode(8);
  TreeNode* nine = new TreeNode(9);
  TreeNode* ten = new TreeNode(10);
  TreeNode* eleven = new TreeNode(11);
  one->left = two;
  one->right = three;
  two->left = four;
  two->right = five;
  three->left = six;
  three->right = seven;
  five->right = ten;
  ten->right = eleven;
  six->right = eight;
  seven->right = nine;
  
  Solution s;
  vector<vector<int>> res = s.verticalTreeTraversal(one);
  
  for (int i = 0; i < res.size(); i++) {
    for (int j = 0; j < res[i].size(); j++) {
      cout << res[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
