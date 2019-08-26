#include <iostream>
#include <limits.h>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution{
public:
    int maxPathSum(TreeNode* root){
        if(!root)
            return 0;
        int ans = INT_MIN;
        maxPathSum(root,ans);
        return ans;
    }
private:
    int maxPathSum(TreeNode* root,int& ans){
        if(!root) return 0;
        int l = std::max(0,maxPathSum(root->left,ans));
        int r = std::max(0,maxPathSum(root->right,ans));
        int sum = l+r+root->val;
        ans = std::max(ans,sum);

        return std::max(l,r)+root->val;
    }
};