/*R-B Tree*/

#include<iostream>
#include<vector>

using namespace std;

class RBtree{
	private:
		struct rbtree{
			int key;
			rbtree *leftchild;
			rbtree *rightchild；
			rbtree *parent;
			int color;
		};

	public:
		typedef rbtree*	iterator;
		enum COLOR{
			BLACK;
			RED;
		};
	public:
		RBtree():root(NULL){};
		~RBtree(){};
		iterator creat_node(int key);
		int insert_node(rbtree *node);
		int delete_node(rbtree *node);
	
		iterator search_node(iterator node ,int key);
		int printtree(rbtree *node);
	private:
		int insert_fixup(rbtree *node);
		int delete_fixup(rbtree *node);
		int RB_transplant(rbtree *snode,rbtree *dnode);
		rbtree *left_rotate(rbtree *node);
		rbtree *right_rotate(rbtree *node);
		rbtree *getminimumnode(rbtree *node);
		rbtree* getmaxmumnode(rbtree *node);
	
		rbtree *search_key(iterator rootnode,int key);
		/*left-root-right*/
		int inorder_traverse();
		/*root-left-right*/
		int preorder_traverse();
		rbtree* successor(rbtree *node);
		rbtree* predecessor(rbtree *node);
	private:
		rbtree *root;
};
iterator RBtree::creat_node(int key);
{
	rbtree* node = new rbtree;
	rbtree** pnode = node;
	node->key = key;
	return *pnode;
}
rbtree* RBtree::getminimumnode(rbtree *node)
{
	rbtree *temp_node;
	while(node->leftchild != NULL)
	{
		temp_node = node;
		node = node->leftchild;
	}
	
	return node;
}
rbtree* RBtree::getmaxmumnode(rbtree *node)
{
	rbtree *temp_node;
	while(node->rightchild != NULL)
	{
		temp_node = node;
		node = node->rightchild;
	}
	
	return node;
}
/*left rotate*/
int RBtree::left_rotate(rbtree *node)
{
	rbtree **newroot;
	/*restore new rootnode*/
	*newroot = node->rightchild;
	*newroot->parent = node->parent;
	node->parent = *newroot;
	node->rightchild = *newroot->leftchild;
	if(*newroot->leftchild != NULL)
	{	
		node->rightchild->parent = node;
	}
	newroot->leftchild = node;
	
	return *newroot;
}
/*right rotate*/
int RBtree::right_rotate(rbtree *node)
{
	rbtree **newroot;
	/*restore new rootnode*/
	*newroot = node->leftchild;
	*newroot->parent = node->parent;
	node->parent = *newroot;
	
	node->leftchild = *newroot->rightchild;
	if(*newroot->rightchild != NULL)
	{	
		node->leftchild->parent = node;
	}
	newroot->leftchild = node;
	
	return *newroot;
}
int RB_transplant(rbtree *snode,rbtree *dnode)
{
	/*modify to T.nil later*/
	if(snode->parent == NULL)
	{
		dnode = root;
	}	
	if(snode == snode->parent->leftchild)
	{
		snode->parent->leftchild = dnode;
	}
	if(snode == snode->parent->rightchild)
	{
		snode->parent->rightchild = dnode;
	}
	dnode->parent = snode->parent;
	return 0;
}
/*insert new node*/
int RBtree::insert_node(rbtree *node)
{
		if(root == NULL)
		{
			node->color = BLACK;
			node->leftchild = NULL;
			node->rightchild = NULL;
			node->parent = NULL;
			root = node;

		}
		rbtree *cur_node = root;
		rbtree *pos_node = NULL;
		/*find pos to insert*/
		while(cur_node != NULL)
		{
			pos_node = cur_node;
			if(node->key >= cur_node->key)
			{
				cur_node = cur_node->rightchild;
			}
			else
			{
				cur_node = cur_node->leftchild;
			}
		}
		if(node->key >= pos_node->key)
		{
			/*rihgtchild*/
			node->color = RED;
			node->parent = pos_node;
			node->leftchild = NULL;
			node->rightchild = NULL;
			pos_node->rightchild = node;

		}
		else
		{
			/*leftchild*/
			node->color = RED;
			node->parent = pos_node;
			node->rightchild = NULL;
			node->leftchild = NULL;
			pos_node->leftchild = node;

		}
		/*fixup*/
		insert_fixup(node);
				
	return 0;
}
int RBtree::delete_node(rbtree *node)
{
	
	int color_orgin = RED;
	rbtree *x_node;
	/*case 1 left == NULL*/
	if(node->leftchild == NULL)
	{
		color_orgin = node->color;
		RB_transplant(node,node->rightchild);
	}
	/*case 2 right == NULL*/
	else if(node->rightchild == NULL)
	{
		color_orgin = node->color;
		RB_transplant(node,node->leftchild);
	}
	/*case 3 left != NULLL right != NULL*/
	else 
	{
		color_orgin = node->color;
		x_node = getminimumnode(node->right);
		RB_transplant(xnode,node);
	}
	if(color_orgin == BLACK)
	{
		delete_fixup(node);
	}
	
	return 0;

}

int RBtree::insert_fixup(rbtree *node)
{
	rbtree *unclenode,*parentnode，*rootnode,*grandnode;
	if(node->parent == BLACK)
	{
		return 0;
	}
	parentnode = node->parent;
	grandnode = parent->parent;
	/*leftchild*/
	if(parent = parent->leftchild)
	{
		/*uncle not be null*/
		unclenode = node->parent->rightchild;
		/*case 1: uncle is red*/
		if(unclenode->color == RED)
		{
			/*re-color*/
			unclenode->color = BLACK;
			parentnode->color = BLACK;
			insert(parentnode->parent);
		}
		/*case 2:uncle is black*/
		else
		{
			if(node = node->rightchild)
			{
					rootnode = left_rotate(parent);
			}
			/*right-rotate*/
			rootnode = right_rotate(grandnode);
			/*re-color*/
			rootnode->color = BLACK;
			rootnode->rightchild = RED;
			rootnode->leftchild = RED;
		}
	}
	else
	{
		unclenode = node->parent->leftchild;
		/*case 1: uncle is red*/
		if(unclenode->color == RED)
		{
			/*re-color*/
			unclenode->color = BLACK;
			parentnode->color = BLACK;
			insert(parentnode->parent);
		}
		/*case 2:uncle is black*/
		else
		{
			if(node = node->rightchild)
			{
					rootnode = right_rotate(parent);
			}
			/*right-rotate*/
			rootnode = left_rotate(grandnode);
			/*re-color*/
			rootnode->color = BLACK;
			rootnode->rightchild = RED;
			rootnode->leftchild = RED;
		}
	}
}

int RBtree::delete_fixup(rbtree *node)
{
	rbtree *parentnode = node->parent;
	rbtree *unclenode;
	rbtree *rootnode;
	int color_root;
	if(node->color == RED)
	{
		node->color = BLACK;	
		return 0;
	}
	
	if(node == parentnode->leftnode)
	{
		unclenode = parent->rightchild;
		/*case 1: bro is red*/
		if(unclenode->color == RED)
		{
			rootnode = right_rotate(parentnode);
			/*re-color*/
			rootnode->color = BLACK;
		}
		if(unclenode->color == BLACK)
		{
		/*case 2: bro is black and all bro's child is black*/
			if((unclenode->leftchild == BLACK)&&(unclenode->right->color == BLACK))
			{
				/*re-color*/
				unclenode->color = RED;
				delete_fixup(parentnode);
			}
		/*case 3:bro is black and leftchild is black rightchild is red*/
			if((unclenode->leftchild == BLACK)&&(unclenode->right->color == RED))
			{
				rootnode = right_rotate(unclOBenode);
				/*re-color*/
				rootnode->color = BLACK;
				rootnode->rightchild->color = RED; 
			}	
		/*case 4:bro is black and rightchild is black leftchild is red*/
			if((unclenode->leftchild == RED)&&(unclenode->right->color == BLACK))
			{
				color_root = parentnode->color;
				rootnode = left_rotate(parent);
				rootnode->color = color_root;
				rootnode->rightchild = BLACK;
			}
		}
	}
	else
	{
		unclenode = parent->leftchild;
		/*case 1: bro is red*/
		if(unclenode->color == RED)
		{
			rootnode = left_rotate(parentnode);
			/*re-color*/
			rootnode->color = BLACK;
			/*switch to case 2,3or4*/
		}
		if(unclenode->color == BLACK)
		{
		/*case 2: bro is black and all bro's child is black*/
			if((unclenode->leftchild == BLACK)&&(unclenode->right->color == BLACK))
			{
				/*re-color*/
				unclenode->color = RED;
				delete_fixup(parentnode);
			}
		/*case 3:bro is black and leftchild is black rightchild is red*/
			if((unclenode->leftchild == BLACK)&&(unclenode->right->color == RED))
			{
				rootnode = left_rotate(unclOBenode);
				/*re-color*/
				rootnode->color = BLACK;
				rootnode->leftchild->color = RED; 
			}	
		/*case 4:bro is black and rightchild is black leftchild is red*/
			if((unclenode->leftchild == RED)&&(unclenode->right->color == BLACK))
			{
				color_root = parentnode->color;
				rootnode = right_rotate(parent);
				rootnode->color = color_root;
				rootnode->leftchild = BLACK;
			}
		}	
	}
	return 0;
		
}
rbtree *search_key(iterator rootnode,int key)
{
		if(rootnode->key == key)
		{	
			return rootnode;
		}
		else if(rootnode->key>key)
		{
			if(root->leftchild != NULL)
				return search_key(root->leftchild);
			else
				return NULL;
		}
		else
		{
			if(root->rightchild != NULL)
				return search_key(root->rightchild);
			else
				return NULL;
		}
}
/*left-root-right*/
int RBtree::inorder_traverse(rbtree *rootnode)
{
	if(rootnode->leftchild != NULL)
	{
		inorder_traverse(rootnode->leftchild);
	}
	cout<<rootnode->key<<" "<<endl;
	if(rootnode->rightchild != NULL)
	{
		inorder_traverse(rootnode->rightchild);
	}
	return 0;
}
/*root-left-right*/
int RBtree::preorder_traverse()
{
	cout<<rootnode->key<<" "<<endl;
	if(rootnode->leftchild != NULL)
	{
		inorder_traverse(rootnode->leftchild);
	}
	if(rootnode->rightchild != NULL)
	{
		inorder_traverse(rootnode->rightchild);
	}
	return 0;
}
/*according to inorder_traverse*/
/*find first node dont have leftchild equal to find minmum of right*/
rbtree* RBtree::successor(rbtree *node)
{
	return getminimumnode(node->rightchild);
}
/*find minmum of right*/
rbtree* RBtree::predecessor(rbtree *node)
{
	return getmaxmumnode(node->rightchild);
}

int RBtree::RBtree_init(vector<int> ivec)
{
	int vec_size = ivec.size();
	for(int i =0;i<vec_size;i++)
	{
		/*这种表达方式是否可行，需要调试*/
		rbtree* inode = new rbtree;
		inode->key = ivec
		insert_node(inode);
	}
	return 0;
}
int RBtree::printtree(int mode)
{
	if(mode = 0)
	{
		inorder_traverse(root);
	}
	else
	{
		preorder_traverse(root);
	}
	return 0;
}
int main()
{
	int init_arry[10] = {1,2,3,4,5,6,7,8,9,10};
	vector<int> ivec(array,array+10);
	
	RBtree iRBtree = new RBtree();
	
	iRBtree.RBtree_init(ivec);
	
	printtree(0);
	
	iRBtree.insert_node(iRBtree.creat_node(12));
	
	printtree(0);
	
	iRBtree.delete_node(iRBtree.creat_node(5));
	
	printtree(0);
	
	return 0;
}
