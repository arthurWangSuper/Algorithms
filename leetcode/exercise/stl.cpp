//
//  stl.cpp
//  exercise
//
//  Created by wangtao on 2020/2/26.
//

#include <iostream>

using namespace std;

template <typename T>
class plus {
public:
    T operator()(const T& x, const T& y) const {return x+y;}
};

template <typename T>
class minus {
public:
    T operator()(const T& x,const T& y) const {return x-y;}
};


int main(int argc, char* argv[]){
    plus<int> plusobj;
    minus<int> minusobj;
    
    cout<< plusobj(3,5) <<endl;
    cout<< minusobj(5,3) <<endl;
    
    // 临时对象
    cout<< plus<int>()(3,5) <<endl;
    cout<< minus<int>()(5,3) <<endl;
    return 0;
}
