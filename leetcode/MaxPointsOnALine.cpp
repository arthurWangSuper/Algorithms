#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct Point{
    int x;
    int y;
    Point():x(),y(){}
};

class Solution{
public:
    int MaxPionts(vector<Point> &points){
        int n = points.size();
        int ans = 0;

        for(int i=0;i<n;++i){
            std::map<std::pair<int,int>,int> count;
            int same_points = 1;
            int max_points = 0;
            const Point& p1 = points[i];
            for(int j=i+1;j<n;++j){
                const Point& p2=points[j];
                if(p1.x==p2.x && p1.y==p1.x)
                    ++same_points;
                else
                    max_points =max(max_points,++count[getslope(p1,p2)]);    
            }
            ans = max(ans,same_points+max_points);
        }
        return ans;
    }
private:
    std::pair<int,int> getslope(const Point& p1,const Point& p2){
        const int dx = p2.x-p1.x;
        const int dy = p2.y-p1.y;

        //horizontal line
        if(dy == 0) return {p1.y,0};
        //vertical line 
        if(dx == 0) return {0,p1.x};

        const int d = gcd(dx,dy);
        return {dy/d,dx/d};
    }
    //求最大公约数
    int gcd(int m,int n)
    {
        //m:21  n:15
        return n==0?m:gcd(n,m%n);
    }

};