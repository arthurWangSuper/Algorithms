void recoverTreewithoutrec(TreeNode *root)
    {
         TreeNode *first = nullptr;
         TreeNode *second = nullptr;

         bool firsttime = true;

         TreeNode *pre = nullptr;

        while(root != nullptr){
            if(root->left != nullptr){
                TreeNode *tmp = root->left;
                while(tmp->right != nullptr && tmp->right != root) {
                    //寻找其前驱节点 左子树的最右节点
                    tmp = tmp->right;
                }
                if(tmp->right == nullptr){
                    tmp->right = root;
                    root = root->left;
                }
                else{
                    if(pre != nullptr){
                      if((pre->val > root->val)&&firsttime){
                          first = pre;
                          firsttime = false;
                      } else if((pre->val > root->val)&&!firsttime){
                          second == root;
                      }
                    }
                    pre = root;
                    //还原
                    tmp->right = nullptr;
                    //visit root node
                    root = root->right;
                }
            }
            else{
                  if(pre != nullptr){
                    if((pre->val > root->val)&&firsttime){
                        first = pre;
                        firsttime = false;
                    } else if((pre->val > root->val)&&!firsttime) {
                        second == root;
                    }
                  }
                //vist right child node
                //root_left == nullptr
                root = root->right;
            }

            if(first != nullptr && second != nullptr){
                int tmp = first->val;
                first->val = second->val;
                second->val = temp;
            }

        }
    }
