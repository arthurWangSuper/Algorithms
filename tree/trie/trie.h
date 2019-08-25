//
// Created by k on 19-8-22.
//
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <assert.h>

using std::nullptr;
//26个字母，不分大小写（区分时,可以修改为52）
const int MaxBranchNum = 26;

/*定义trie树结点*/
class TrieNode{
public:
    char* word;//该节点表示的单词
    int count;//单词出现的次数
    TrieNode* nextBranch[MaxBranchNum];//指向26个字符节点的指针
public:
    TrieNode():word(nullptr),count(0)
    {
        memset(nextBranch, nullptr, sizeof(TrieNode*)*MaxBranchNum);
    }
};

/*定义Trie类*/
class Trie{
public:
    Trie();
    ~Trie();
    void Insert(const char* str);//插入字符串str
    bool Search(const char* str,int &count);//查找字符串str，并返回出现的次数
    bool Remove(const char* str);//删除字符串str
    void PrintALL();//打印出trie树中所有的结点
    void PrintPre(const char *str);//打印以str为前缀的单词
private:
    TrieNode *pRoot;
private:
    void Destory(TrieNode* pRoot);
    void Print(TrieNode* pRoot);
};
