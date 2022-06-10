#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using std::to_string;
using std::vector;
using std::unordered_map;
using std::string;
using std::cout;
using std::endl;


class Solution {
public:
     bool isValid(int row, int col, int elem){
        int index = row/3*3 + col/3;
        if(rows[row][elem] >0 || cols[col][elem]>0|| boxs[index][elem] > 0) {
            return false;
        }
        return true;
    }

    bool fillNextBoard(vector<vector<char>>& board,  int row, int col){

        // findnext
        bool flag = false;
        int index_col=0, index_row=0; 
        if(row == 8 && col == 8) {
            return true;
        }
        for(int i = 0; i < 9; i++){
          for(int j = 0; j < 9; j++){
              if(board[i][j] == '.') {
                    index_row = i;
                    index_col = j;
                    flag = true;
                    break;
                }
          }
          if(flag) {
             break; 
          }
        }
        if(!flag) {
            return true;
        }

        for(int num = 0; num < 9 ; num++) {
            char elem = '1'+num;
            if(!isValid(index_row,index_col,elem)){
                continue;
            } 
            int index = index_row/3*3 + index_col/3;
            rows[index_row][elem]++;
            cols[index_col][elem]++;
            boxs[index][elem]++;
            board[index_row][index_col] = elem;
            bool ret = fillNextBoard(board,index_row,index_col);
            if(!ret) {
                // 回溯
                board[index_row][index_col] = '.';
                rows[index_row][elem]--;
                cols[index_col][elem]--;
                boxs[index][elem]--;
            } else {
                return true;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
         for(int i = 0; i<9;i++){
            for(int j = 0; j < 9; j++) {
                int index = i/3*3 + j/3;
                char elem = board[i][j];
                if(elem != '.'){
                    rows[i][elem]++;
                    cols[j][elem]++;
                    boxs[index][elem]++;
                }                    
            }
        }
        fillNextBoard(board, 0, 0);
    }

    private:
        vector<unordered_map<char,int>> rows = vector<unordered_map<char,int>>(9, unordered_map<char,int>());
        vector<unordered_map<char,int>> cols = vector<unordered_map<char,int>>(9, unordered_map<char,int>());
        vector<unordered_map<char,int>> boxs = vector<unordered_map<char,int>>(9, unordered_map<char,int>());
};


int main(){
    vector<vector<char>> board{
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},    
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},   
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},    
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution *pS = new Solution();
    pS->solveSudoku(board);
     for(int i = 0; i<9;i++){
            for(int j = 0; j < 9; j++) {
                cout<<board[i][j] << " ";
            }
            cout << endl;
     }
    return 0;
}