/* 
leetcode 1233
Given a list of folders, remove all sub-folders in those folders and return in any order the folders after removing.

If a folder[i] is located within another folder[j], it is called a sub-folder of it.

The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. 
For example, /leetcode and /leetcode/problems are valid paths while an empty string and / are not.
*/
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> fd_us(folder.begin(),folder.end());
        vector<string> ans;
        for(auto& cur:folder)
        {
            string tmp = cur;
            bool valid = true;
            while(!tmp.empty() && valid){
                while(tmp.back() != '/') tmp.pop_back();
                tmp.pop_back();
                if(fd_us.count(tmp)) valid = false;
            }
            if(valid) ans.push_back(cur);
        }
        return ans;
    }
};
