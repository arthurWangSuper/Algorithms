//leetcode 692 


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;
//leetcode 692
//Given a non-empty list of words, return the k most frequent elements.

//Your answer should be sorted by frequency from highest to lowest. 
//If two words have the same frequency, 
//then the word with the lower alphabetical order comes first.

class Solution{
public:
    vector<string> topKFrequent(vector<string>& words,int k){
        unordered_map<string,int> cnt;
        for(const string& word:words)
        {
            ++cnt[word];
        }

        typedef pair<string,int> Node;

        auto cmp = [](const Node& a,const Node& b){
            //order by alphabet ASC
            if(a.second == b.second)
                return a.first<b.first;
            return a.second > b.second;
        };

        priority_queue<Node,vector<Node>,decltype(cmp)> q(cmp);

        //O(n*log k)
        for(const auto& kv:cnt)
        {
            q.push(kv);
            if(q.size()>k)
                q.pop();
        }
        
        vector<string> ans;

        while(!q.empty()){
            ans.push_back(q.top().first);
            q.pop();
        }

        std::reverse(ans.begin(),ans.end());
        return ans;
    }
};
//leetcode 347
//Given a non-empty array of integers, return the k most frequent elements.

class Solution2{
public:
    vector<int> topKFrequent(vector<int> &nums,int k)
    {
        unordered_map<int,int> count;
        int max_freq=1;
        //统计次数
        for(const int num:nums){
            max_freq = max(max_freq,++count[num]);
        }
        //放入对应次数的buckets
        unordered_map<int,vector<int>> buckets;
        for(const auto& kv:count)
            buckets[kv.second].push_back(kv.first);
    
        vector<int> ans;

        for(int i=max_freq;i>=1;--i)
        {
            auto it = buckets.find(i);
            if(it==buckets.end()) continue;
            ans.insert(ans.end(),it->second.begin(),it->second.end());
            if(ans.size()==k) return ans;
        }
        return ans;
    }
} ;



int main()
{
    vector<string> words ={"ax","bx","aa","ax","ax","bx","bx","ax","cx","cx"};

    Solution *pS = new Solution;

    vector<string> ans = pS->topKFrequent(words,2);

    for(auto &word:ans)
    {
        cout<<word<<endl;
    }

    return 0;
}