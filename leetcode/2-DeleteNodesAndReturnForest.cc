// leetcode 1110
// Given the root of a binary tree, each node in the tree has a distinct value.

// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

// Return the roots of the trees in the remaining forest.  You may return the result in any order.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <functional>

using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val = 0;

    TreeNode(int val):val(val){};
};

class Solution{
public:
    vector<TreeNode*> DeleteNodesAndReturnForest(TreeNode* root,vector<int> del_node){
        // 森林，由森林中各个树根节点组成
        vector<TreeNode*> ret;
        // 记录需要删除的节点
        unordered_set<int> del_node(del_node.begin(),del_node.end());

        function<TreeNode*(TreeNode*)> del = [&](TreeNode* n)->TreeNode*{
            if(!n) return nullptr;
            //相当于重新建树
            if(n->left) n->left = del(n->left);
            if(n->right) n->right = del(n->right);
            // 查找是否是需要删除的点 若不是则count为0 返回为节点
            if(!del_node.count(n->val)) return n;
            if(n->left) ret.push_back(n->left);
            if(n->right) ret.push_back(n->right);
            return nullptr; 
        };
        TreeNode *r = del(root);
        // 最后返回根节点树
        if(r) ret.push_back(r);
        return ret;

    }

};
