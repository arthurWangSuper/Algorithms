/*R-B Tree*/

#include<iostream>

using namespace std;


template<typename T>
class RBtree{
	private:
		struct rbtree{
			T key;
			rbtree *leftchild;
			rbtree *rightchild；
			rbtree *parent;
			int color;
		};

	public:
		enum COLOR{
			BLACK;
			RED;
		};
	public:
		RBtree():root(NULL){};
		~RBtree(){};
		int insert_node(rbtree *node);
		int delete_node(rbtree *node);
		rbtree *search_node(rbtree *node);
		int printtree(rbtree *node);
	private:
		int insert_fixup(rbtree *node);
		int delete_fixup(rbtree *node);
		int RB_transplant(rbtree *snode,rbtree *dnode);
		rbtree *left_rotate(rbtree *node);
		rbtree *right_rotate(rbtree *node);
		rbtree *getminimumnode(rbtree *node);
	private:
		rbtree *root;
};

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
/*left rotate*/
int RBtree::left_rotate(rbtree *node)
{
/*R->P*/
/*R.l->P.r*/
	rbtree **root;
	
	*root = node->parent;
	node->rightchild->parent = node->parent;
	node->parent = node->rightchild;
	node->rightchild = node->rightchild->leftchild;
	node->rightchild->parent = node;
	
	
	return *root;
}
/*right rotate*/
int RBtree::right_rotate(rbtree *node)
{
	rbtree **root;	

	*root = node->parent;
	node->leftchild->parent = node->parent;
	node->parent = node->leftchild;
	node->leftchild = node->leftchild->rightchild;
	node->leftchild->parent = node;
	
	return *root;
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
