//leetcode 735
//We are given an array asteroids of integers representing asteroids in a row.

//For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left).
//Each asteroid moves at the same speed.

//Find out the state of the asteroids after all collisions. 
//If two asteroids meet, the smaller one will explode. 
//If both are the same size, both will explode. 
//Two asteroids moving in the same direction will never meet.

#include <iostream>
#include <vector>
using namespace std;
//解题思路，利用的是 stack的思想，但是由vector来实现(貌似这种做法很常见)
class Solution{
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        vector<int> s;
        for(int i=0;i<asteroids.size();++i){
            const int size = asteroids[i];
            if(size > 0){
                //To right ,OK
                s.push_back(size);
            }else{
                //To left 
                if(s.empty() || s.back()<0){
                    //OK when all are negtives
                    s.push_back(size);
                } else if(abs(s.back()<=abs(size))){
                 //Top of the stack is going right
                 //its size is less than the current one

                 //the current one still alive
                 if(abs(s.back())<abs(size)) --i;
                 s.pop_back();//Destory the top one moving right       
                }
            }
        }
        //s must look like [-s1,-s2,...,si,...,sj,...]
        return s;
    }
};
