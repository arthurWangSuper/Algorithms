//
// Created by k on 19-10-10.
//
#pragma once

template <typename T>
struct Node{
    Node *left_child;
    Node *right_child;
    T data;
    Node():left_child(nullptr),right_child(nullptr),data(0){}
};

template <typename T>
class BinarySortTree{
public:
    BinarySortTree():root(nullptr){}
    ~BinarySortTree(){
        destroy(root);
    }
private:
    void destroy(Node<T>* p){
        if(!p){
            return ;
        }
        destory(p->left_child);
        destory(p->right_child);
        delete p;
        p = nullptr;
    }

    void copy(Node<T>*& dest, const Node<T>* p)
    {
        if(!p) {
            return ;
        }
        dest = new Node<T>();
        dest->data = p->data;
        dest->left_child = p->left_child;
        dest->right_child = p->right_child;
        copy(dest->left_child,p->left_child);
        copy(dest->right_child,p->right_child);
    }
    bool search(Node<T>* p,Node<T>* parent,Node<T>* &target,const T key){
        if(!p) {
            target = parent;
            return false;
        }
        if(p->data == key)
        {
            target = p;
            return true;
        }
        else if(p->data >key)
        {
            search(p->left_child,p,target,key);
        }
        else
        {
            search(p->right_child,p,target,key);
        }

    }
    bool search_delete(Node<T>* p,const T key){
        if(!p)
        {
            return false;
        }
        if(p->data == key)
        {
            delete_node(p);
            return true;
        }
        else if(key < p->data){
            search_delete(p->left_child,key);
        }
        else{
            search_delete(p->right_child,key);
        }
    }
    void delete_node(Node<T>*& dest){
        // 若无左右子节点，则直接删除即可
        if(!dest->left_child&&!dest->right_child)
        {
            delete dest;
            dest = nullptr;
        } else if(!dest->left_child&&dest->right_child){
            // 若左子节点为空，右子节点不为空 右子树根节点与当前节点调换
            Node<T> *tmp = dest;
            dest = dest->right_child;
            delete tmp;
            
        } else if(dest->left_child&&!dest->right_child){
            // 若左字节点不为空，右子节点为空 左子树根节点与当前节点调换
            Node<T> *tmp = dest;
            dest = dest->left_child;
            delete tmp;
        } else {
            // 若左右子节点都不为空 找到左子树最大值 也就是左子树最右节点
            Node<T>* target = dest->left_child;
            Node<T>* target_parent;

            while(target->right_child){
                target_parent = target;
                target = target->right_child;
            }
            if(target = dest->left_child)
            {
                //没有右树
                dest->left_child = target->left_child;
            } else {
                target_parent->right_child = target->left_child;
            }
            delete target;
        }
    }
    Node<T> *root;
};