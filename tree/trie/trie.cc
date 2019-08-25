
// Created by k on 19-8-22.
//

#include "trie.h"
#include <cstring>

Trie::Trie() {
    pRoot = new TrieNode();//注意字典树的根不存放字符
}

Trie::~Trie() {
    Destory(pRoot);
}

void Trie::Insert(const char* str){
    assert(nullptr != str);

    int index;
    TrieNode *pLoc = pRoot;

    for(int i = 0;str[i];i++){
        index = str[i] - 'a';
        /*检查是否为非法字符*/
        if(index < 0 || index > MaxBranchNum){
            return;
        }
        if(nullptr == pLoc->nextBranch[index]){//该单词的前缀不存在，要生成该结点
            pLoc->nextBranch[index] = new TrieNode();
        }
        pLoc = pLoc->nextBranch[index];
    }

    if(nullptr != pLoc->word){//该单词已经出现过
        pLoc->count++;
        return;
    }
    else
    {
        pLoc->count++;
        pLoc->word = new char[strlen(str)+1];
        assert(nullptr != pLoc->word);
        strcpy(pLoc->word,str);
    }
}

bool Trie::Search(const char* str,int &count){
    assert(str != nullptr);
    int i =0;
    int index = -1;
    TrieNode *pLoc = pRoot;
    while(pLoc && *str){
        index = *str - 'a';

         /*检查是否为非法字符*/
        if(index < 0 || index > MaxBranchNum){
            return false;
        }
        //应该是这样吧？？？ 原文中没有这一段
        if(nullptr == pLoc->nextBranch[index]){//该单词的前缀不存在
            return false;
        }
        pLoc->nextBranch[index];
        str++;
    }
    if(pLoc&&pLoc->word){
        count =pLoc->count;
        return true;
    }
    return false;
}
