// leetcode 1373 Maximum Sum BST in Binary Tree

// n <= 40000 Brute force O(n^2) => TLE
// Must be in O(n) (or O(nlogn))
// Solution: Recursion
// key question: when node is a BST

// isBST(left) == True
// isBST(right) == True
// root.val > max(left)
// root.val < min(right)
// return a tuple of: (minVal, maxVal, sum if its a BST, whether its a BST)

// 判断BST

#include <iostream>
#include <tuple>
#include <algorithm>

using std::tuple;
using std::min;
using std::max;


struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    /* data */
};


class Solution{
public:
    int maxSumBST(TreeNode *root){
        int ans = 0;
        dfs(root, &ans);
        return ans;
    }
private:
    // 
    // returns {lo, hi, sum, valid_bst}
    tuple<int, int, int, bool> dfs(TreeNode *root, int *ans){
        if(!root) return {INT_MAX, INT_MIN, 0, true};
        auto [ll, lh, ls, lv] = dfs(root->left, ans);
        auto [rl, rh, rs, rv] = dfs(root->right, ans);

        bool valid = lv && rv && root->val > lh && root->val < rl;
        int sum  = valid? ls+rs+root->val : -1;
        *ans = max(*ans, sum);
        return {min(ll, root->val),max(rh, root->val), sum, valid};

     }
};