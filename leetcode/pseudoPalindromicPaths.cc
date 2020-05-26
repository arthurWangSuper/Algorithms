// leetcode 1457 Pseudo-Palindromic Paths in a Binary Tree
// 从根节点到叶子节点 是否组成回文字符串 => 奇数个字符的数量

#include <iostream>
#include <vector>
#include <functional>

using std::function;
using std::vector;

struct TreeNode{
    TreeNode *left;
    TreeNode *right;
    int val;
};

class Solution{
public:
    int pseudoPalindromicPaths(TreeNode* root){
        // vector -> hashtable 
        vector<int> counts(10);
        function<int(TreeNode* )> dfs = [&](TreeNode *node){
            if(node == nullptr) return 0;  
            ++counts[node->val];
            int c = 0;
            if(!node->left && !node->right){ // leaf node
                int odds = 0 ;
                for(int i =0 ;i <= 9;i++)
                    if(counts[i] & 1) ++odds; //判断奇数 位运算
                if(odds <= 1) c = 1; //奇数数量必须小于或者等于1
            }
            int l = dfs(node->left);
            int r = dfs(node->right);
            --counts[node->val]; // 回溯，counts 为全局数组
            return c+l+r;
        };
        return dfs(root);

    }
};
