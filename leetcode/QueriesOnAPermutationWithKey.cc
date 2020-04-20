#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution_vector{
public:
    vector<int> processQueries(vector<int>& queries, int m){
        vector<int> p(m);
        iota(begin(p), end(p), 1);
        vector<int> ans;

        for(int q : queries) {
            for(int i=0;i<m;++i){
                if(p[i] != q) continue;
                for(int j = i;j>0;--j)
                    p[j] = p[j-1];
                p[0]=q;
                ans.push_back(i);
            }
        }

    }
};

// 修改索引
class Solution_map{
public:
    vector<int> processQueries(vector<int>& queries, int m){
        vector<int> p(m+1);
        iota(begin(p), end(p), -1);

        vector<int> ans;
        for(int q:queries){
            ans.push_back(p[q]);
            for(int i = 1; i<=m; ++i){
                if(p[i] < p[q]) ++p[i];
            }
            p[q] = 0;
        }

    }
};


// Fenwick
class Fenwick{
public:
    explicit Fenwick(int n):vals_(n){}
    // sum(A[1~i])
    int query(int i) const {
        int s = 0;
        while(i>0){
            s += vals_[i];
            i -= i & -i;
        }
        return s;
    }

    // A[i] += delta
    void update(int i, int delta){
        while(i < vals_.size()){
            vals_[i] += delta;
            i += i & -i;
        }
    }
private:
    vector<int> vals_;
};

class Solution_Fenwick{
public:
    vector<int> processQueries(vector<int> &queries, int m){
        Fenwick tree(m*2+1);
        vector<int> pos(m+1);
        for(int i = 1; i <= m; ++i){
            pos[i] = i + m;
            tree.update(i+m, 1);
        }

        vector<int> ans;
        for(int q:queries){
            ans.push_back(tree.query(pos[q]-1));
            tree.update(pos[q], -1); // set to 0
            tree.update(pos[q] = m--, 1); // move to the front
        }
    }
};