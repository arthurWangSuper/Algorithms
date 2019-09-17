// leetcode  1178
// With respect to a given puzzle string, a word is valid if both the following conditions are satisfied:

// word contains the first letter of puzzle.
// For each letter in word, that letter is in puzzle.
// For example, if the puzzle is “abcdefg”, then valid words are “faced”, “cabbage”, and “baggage”; 
// while invalid words are “beefed” (doesn’t include “a”) and “based” (includes “s” which isn’t in the puzzle).
// Return an array answer, where answer[i] is the number of words in the given word list words that are valid with respect to the puzzle puzzles[i].

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
    //状态压缩
    vector<int> findnNumOfValidWords(vector<string>& words,vector<string>& puzzles){
        vector<int> ans;
        unordered_map<int,int> freq;
        for(const string& word:words){
            int mask = 0;
            for(char c:word)
            {
                mask |= 1<<(c-'a');
            }
            ++freq[mask];
        }
        for(const string& p:puzzles){
            int mask = 0;
            for(char c:p){
                mask |= 1<<(c-'a');
            }
            int first = p[0] - 'a';
            int curr = mask;

            int total = 0;

            while(curr){
                if((curr >> first)&1){
                    auto it = freq.find(curr);
                    if(it != freq.end())
                        total += it->second;
                }
                //比较高效的一种 轮询位的方式 注意这些东西
                curr = (curr-1) & mask;
            }
            ans.push_back(total);
        }
        return ans;
    }
};