//leetcode 692 


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;
//leetcode 692

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
//给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
//要求：
//你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
//你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

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