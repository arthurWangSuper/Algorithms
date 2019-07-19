//Leetcode 1125. In a project, you have a list of required skills req_skills, and a list of people.
//The i-th person people[i] contains a list of skills that person has
//Consider a sufficient team: a set of people such that for every required skill in req_skills,there is at least one
//person in the team who has that skill. we can represent the people with skills people[0],people[1],and people[3].

//Return any sufficient team of the smallest possible size,represented by the index of each person

//Input:req_skills=["java","nodejs","reactjs"],people = [["java"],["nodejs"],["nodejs","reactjs"]]

//Constraints:

//1) 1 <= req_skills.length <= 16
//2) 1 <= people.length <= 60
//3) 1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
//4) Elements of req_skills and people[i] are (respectively) distinct.
//5) req_skills[i][j], people[i][j][k] are lowercase English letters.
//6) It is guaranteed a sufficient team exists.


//tag: bitmmap dp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits.h>


using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::unordered_map;

class Solution{
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills,vector<vector<string>> &people){
        const int n = req_skills.size();
        //位运算
        const int target = (1<<n)-1;

        vector<int> skills;
        for(const auto& p:people)
        {
            int mask = 0;

            for(const string &s:p)
                mask |= (1<<std::find(begin(req_skills),end(req_skills),s)-begin(req_skills));
            skills.push_back(mask);
        }

        //倒序推断，所以将dp设置为INT_MAX，但是为何除于2 不得而知
        vector<int> dp((1<<n),INT_MAX/2);
        //记录其轨迹
        vector<std::pair<int,int>> pt((1<<n));
        dp[0] = 0;
        //倒序推断
        for(int i=0;i<people.size();++i) {
            const int k = skills[i];

            if (k == 0) continue;
            for (int j = target; j >= 0; --j)
                if (dp[j] + 1 < dp[j | k]) {
                    dp[j | k] = dp[j] + 1;
                    pt[j | k] = {j, i};
                }
        }
		
        int t =target;
        vector<int> ans;
        while(t){
            ans.push_back(pt[t].second);
            t = pt[t].first;
        }

        return ans;
    }
};

class Solution2{
public:
    vector<int> smallestSufficientTeam(vector<string> &req_skills,vector<vector<string>> &people){
        const int n = req_skills.size();
        const int target = (1<<n)-1;

        vector<int> skills;
        for(const auto& p:people)
        {
            int mask = 0;

            for(const string &s:p)
                mask |= (1<<std::find(begin(req_skills),end(req_skills),s)-begin(req_skills));
            skills.push_back(mask);
        }

        unordered_map<int,vector<int>> dp;
        dp[0]={};

        for(int i=0;i<people.size();++i){
            unordered_map<int,vector<int>> tmp(dp);

            for(const auto& kv:dp){
                int k = kv.first|skills[i];
                //如果不存在，或者是use i 之后比用之前小
                if(!tmp.count(k)||kv.second.size()+1<tmp[k].size()){
                    tmp[k] = kv.second;
                    tmp[k].push_back(i);
                }
                tmp.swap(dp);
            }
        }
        return dp[(1<<n)-1];
    }

};

int main()
{
    vector<string> req_skills{"java","nodejs","reactjs"};
    vector<vector<string>> people ={{"java"},{"nodejs"},{"nodejs","reactjs"}};
    Solution *pS = new Solution;

    vector<int> res = pS->smallestSufficientTeam(req_skills,people);

    for(auto ele:res)
        cout<<ele<<" ";
    cout<<endl;
    return 0;
}
