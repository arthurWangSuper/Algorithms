/*LeetCode 1305.All Elements in Two Binary Search Trees*/
// Given two binary search trees root1 and root2.
// Return a list containing all the integers from both trees sorted in ascending order.
#include <iostream>
#include <vector>
#include <stack>
#include <functional>

using namespace std;

struct TreeNode{
    TreeNode *left;
    TreeNode *right;
    int val;
};

class Solution_inorder{
public:
    vector<int> getAllElements(TreeNode* root1,TreeNode* root2){
        function<void(TreeNode*,vector<int>&)> inorder=[&](TreeNode* root,vector<int>& t){
            if(root == nullptr) return;
            inorder(root->left,t);
            t.push_back(root->val);
            inorder(root->right,t);
        };

        vector<int> t1;
        vector<int> t2;

        inorder(root1,t1);
        inorder(root2,t2);
        vector<int> m;

        int i=0;
        int j=0;

        while(m.size() != t1.size()+t2.size()){
            if(j == t2.size()) m.push_back(t1[i++]);
            else if(i == t1.size()) m.push_back(t2[j++]);
            else m.push_back(t1[i]<t2[j]?t1[i++]:t2[j++]);
        }
        return m;
    }
};

class Solution_smallest{
    vector<int> getAllElements(TreeNode* root1,TreeNode* root2){
        function<void(TreeNode* ,stack<int>& )> smallest=[&](TreeNode* root,stack<int>& s){
            if(!root) return;
            s.push(root); // 将左子树全部入栈
            smallest(root->left,s);
        };

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        smallest(root1,s1);
        smallest(root2,s2);

        vector<int> ans;

        while(!s1.empty() || !s2.empty()){
            stack<TreeNode* >& s = s1.empty()?s2:s2.empty()?s1:s1.top()->val<s2.top()->val?s1:s2;
            TreeNode *n = s.top();
            s.pop;
            ans.push_back(n->val);
            smallest(n->right,s); // 刚开始在这里晕菜了，因为s是引用，所以实际写入的是s1，或者是s2
                                    // 很巧妙的写法
        }
         return ans;
    }
};