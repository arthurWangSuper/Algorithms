// Leetcode 699
// Problem: On an infinite number line(x-axis), we drop given squares in the order they are given

//The i-th square dropped (positions[i] = (left, side_length)) is a square with the left-most point being positions[i][0] and sidelength positions[i][1].
//
//The square is dropped with the bottom edge parallel to the number line, and from a higher height than all currently landed squares. 
//We wait for each square to stick before dropping the next.
//
//The squares are infinitely sticky on their bottom edge, and will remain fixed to any positive length surface they touch (either the number line or another square). 
//Squares dropped adjacent to each other will not stick together prematurely.
//
//Return a list ans of heights. Each height ans[i] represents the current highest height of any square we have dropped, 
//after dropping squares represented by positions[0], positions[1], ..., positions[i].

#include <iostream>
#include <vector>
#include <map>
#include <limits.h>

using namespace std;
//map

//思路：用map存储{s,e}->h，其本身会排序
//     从现有的ranges 中找到与其相交的区间，其中应用了upper_bound,找到不小于的range的iterator
//     开始处理：区间进行拆解并更新高度（应用了vector）
class Solution{
public:
    vector<int> fallingSquares(vector<pair<int,int>>& positions){
        vector<int> ans;
        //map是会排序的
        map<pair<int,int>,int> b; //{{start,end},height}
        int maxHeight = INT_MIN;
        for(const auto& kv:positions)
        {
            int start = kv.first;
            int size = kv.second;
            int end = start + size;

            //find range intersect with new_interval
            auto it = b.upper_bound({start,end});
            if(it != b.begin()){
                auto it2 = it;
                if((--it2)->first.second > start){
                    it = it2;
                }
            }

            int baseHeight = 0;
            vector<tuple<int,int,int>> ranges;
            while(it != b.end() && it->first.first <end){
                const int s = it->first.first;
                const int e = it->first.second;
                const int h = it->second;

                if(s < start) ranges.emplace_back(s,start,h);
                if(e > end)  ranges.emplace_back(end,e,h);
                //max height of intesected ranges
                baseHeight = max(baseHeight,h);
                it = b.erase(it); 
            }

            int newHeight = size + baseHeight;
            
            b[{start,end}] = newHeight;

            //更新区间
            for(const auto& range:ranges)
                b[{get<0>(range),get<1>((range))}] = get<2>(range);

            maxHeight = max(maxHeight,newHeight);
            ans.push_back(maxHeight);
        }
        return ans;
    }

};

//C++ vector without merge

class Solution2{
public:
    vector<int> fallingSquares(vector<pair<int,int>> &positions){
        vector<int> ans;
        vector<Interval> intervals;
        int maxHeight = INT_MIN;
        for(const auto& kv:positions){
           int start  = kv.first;
           int end = start + kv.second;
           int baseHeight = 0;
           for(const Interval& interval:intervals){
               if(interval.start >= end || interval.end <= start){
                   continue;
                   baseHeight = max(baseHeight,interval.height);
               }
               int height = kv.second + baseHeight;
                intervals.push_back(Interval(start,end,height));
                maxHeight = max(maxHeight,height);
                ans.push_back(maxHeight);
           }
           return ans;
        }
    }
private:
    struct Interval
    {
        int start;
        int end;
        int height;
        Interval(int start,int end,int height):start(start),end(end),height(height)
        {}
    };
    
};

//C++ vector with merge

class Solution3{
public:
    vector<int> fallingSquares(vector<pair<int,int>> &positions){
        vector<int> ans;
        vector<Interval> intervals;
        int maxHeight = INT_MIN;
        for(const auto& kv:positions){
           vector<Interval> tmp;
           int start  = kv.first;
           int end = start + kv.second;
           int baseHeight = 0;
           for(const Interval& interval:intervals){
               //no intersect with new_interval
               if(interval.start >= end || interval.end <= start){
                   tmp.push_back(interval);
                   continue;
               }
                //with intersect with new_interval 
               baseHeight = max(baseHeight,interval.height);
               //but not contain
               if(interval.start < start || interval.end > end)
                    tmp.push_back(interval);
           }

            int height = kv.second + baseHeight;
            tmp.push_back(Interval(start,end,height));
            intervals.swap(tmp);
            maxHeight = max(maxHeight,height);
            ans.push_back(maxHeight);
        }  
        return ans;
    }
private:
    struct Interval
    {
        int start;
        int end;
        int height;
        Interval(int start,int end,int height):start(start),end(end),height(height)
        {}
    };
    
};
