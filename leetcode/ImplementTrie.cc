//LeetCode 208
//Problem:
//Implement a trie with insert,search,and startsWith methods;
//Node:
//You may assume that all inputs are consist of lowercase letters a-z

//Time complexity O(1)
//Space complexity O(prefixes) O(n*1^2)

//array
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using std::vector;
using std::string;

class Trie{
public:
    Trie():root_(new TrieNode()){}

    void Insert(const string& word){
        TrieNode *p = root_.get();

        for(const char c:word){
            if(!p->children[c-'a']){
                p->children[c-'a'] = new TrieNode();
            }
            p = p->children[c-'a'];
        }
        p->is_word =true;
    }
    bool search(const string& word) const{
        const TrieNode *p = find(word);
        return p&&p->is_word;
    }
    bool startsWith(const string& perfix) const {
        return find(perfix) != nullptr;
    }
private:
    struct TrieNode{
        TrieNode():is_word(false),children(26,nullptr){}
        ~TrieNode(){
            for(TrieNode *child:children)
                if(child) delete child;
        }
        bool is_word;
        vector<TrieNode*> children;
    };
    const TrieNode* find(const string& prefix) const {
        const TrieNode* p = root_.get();
        for(const char c:prefix){
            p=p->children[c-'a'];
            if(p = nullptr) break;
        }
        return p;
    }
    std::unique_ptr<TrieNode> root_;
};
