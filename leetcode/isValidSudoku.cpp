#include <vector>
#include <unordered_map>
 
 using std::vector;
 using std::unordered_map;
// 因为此为稀疏矩阵，最好的方法肯定是一次遍历完成
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char,int>> rows(9);
        vector<unordered_map<char,int>> cols(9);
        vector<unordered_map<char,int>> boxs(9);
        for(int i = 0; i<9;i++){
            for(int j = 0; j < 9; j++) {
                int index = i/3*3 + j/3;
                char elem = board[i][j];
                if(elem != '.'){
                    if(rows[i][elem] > 0 || cols[j][elem] >0 || boxs[index][elem] > 0) {
                        return false;
                    }
                    rows[i][elem]++;
                
                    cols[j][elem]++;
                    boxs[index][elem]++;
                    }                    
                }
            }
        return true;
    }
};