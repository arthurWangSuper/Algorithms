#include<iostream>

using namespace std;

class linklist{

	 private:
                struct Node{
                        int val;
                        Node *next;
                };
        public:
		typedef Node*    iterator;
                linklist():head(new Node){};
                linklist(int size):head(new Node),tail(head->next)
		{
			if( size >1)
			{	
				Node *node = head;
				for (int n = 0; n != size;n++)
				{
		
					node->next = new Node;
					node = node->next; 
				}
			}
		};
		linklist(int size,int *array):head(new Node),tail(head->next)
		{
			if( size >1)
			{	
				Node *node = head;
				for (int n = 0; n != size;n++)
				{
		
					node->next = new Node;
					node = node->next;
					node->val = array[n]; 
				}
			}
		};
		~linklist(){
			while(head != tail)
			{
				Node *temp = head->next;			
				delete head;
				head = temp;
			}
		};
		void insert(iterator dest,int val);
		int empty();
		int erase(Node *dest);               	
		void initlinklist();
                void printlinklist();
		iterator operator[](int index)
		{
			Node* tmp = new Node;
			tmp = head;
			for(int i = 0;i<index;i++)
			{
				tmp = tmp->next;
			}
			return tmp;
		}
		void reveserlist();		       
        public:
                Node *head,*tail;
};
int linklist::empty()
{
	head->next = NULL;
}
int linklist::erase(Node *dest)
{
	Node *tmpnode = new Node;
	tmpnode = dest->next;
	dest->next = tmpnode->next;
	return 0;
	
}
void linklist::insert(iterator dest,int val)
{
	Node *newnode = new Node;
	newnode->next = dest->next;
	newnode->val = val;	
	dest->next = newnode;
}
void linklist::initlinklist()
{
	Node *node = head;
	for (int n = 0; n != 5;)
        {
		
                node->next = new Node;
                node = node->next; 
		node->val = n++;
        }
}
void linklist::printlinklist()
{
        for(Node *p = head->next;p != tail; )
        {
                cout<<p->val<<" ";
                p = p->next;
        }
	cout<<endl;
}

void linklist::reveserlist()
{
	Node *first = head->next;

	while(first->next !=tail)
	{
		Node *nextNode = first->next;

		first->next = nextNode->next;
		nextNode->next = head->next;
		head->next = nextNode;	
	}
	
}
int main()
{
        linklist *cur = new linklist();
		
	cur->initlinklist();
//	linklist::iterator it = (*cur)[2];
//	cur->insert(it,30);
	//it = (*cur)[4];
	//cur->erase(it);
        cur->reveserlist();
	cur->printlinklist();
        return 0;
}
