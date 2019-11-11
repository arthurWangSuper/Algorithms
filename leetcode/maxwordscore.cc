// leetcode 1225 maximum score words formed by letters
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {

        vector<int> counts(26);
        vector<int> scores(words.size());
        // 统计提供的字符个数
        for (auto c:letters) ++counts[c - 'a'];
        // 统计每个字母的得分
        for (int i = 0; i < words.size(); i++)
            for (auto c:word){
                scores[i] += score[c - 'a'];
            }
        int ans = 0;
        function<void(int,int)> dfs = [&](int cur,int s){
                if(cur > ans) ans = cur;
                for(int i = s;i<words.size();i++){
                    bool valid = true;
                    for(auto &c:words) valid &= --counts[c-'a']>=0;
                    if(valid) dfs(cur+scores[i],i+1);
                    for(auto &c:words) ++counts[c-'a']
                }
            }

        dfs(0,0);
        return ans;
    }
};
