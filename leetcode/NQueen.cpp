/*The n-queens puzzle*/

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::cout;
using std::string;
using std::endl;

//declare function 
vector<vector<string> > solveNQueens(int n);
void solveNQueensRecursive(int n,int currentRow,vector<int> &solution,vector<vector<string>> &result);
bool isValid(int attemptedColumn,int attemptedRow,vector<int> &queenInColumn);


vector<vector<string>> solveNQueens(int n){
	vector<vector<string>> result;
	vector<int> solution(n);

	solveNQueensRecursive(n,0,solution,result);
	
	return result;
}

void solveNQueensRecursive(int n,int currentRow,vector<int> &solution,vector<vector<string>> &result){
	if(currentRow == n){
		//vector<string> s;
		vector<string> s(n,string(n,'.'));

		for(int row =0;row<n;row++)
		{
			s[row][solution[row]]='Q';
		}
		result.push_back(s);
		return;
	}
	
	for(int col =0;col<n;col++)
	{
		if(isValid(col,currentRow,solution)){
			solution[currentRow]=col;

			solveNQueensRecursive(n,currentRow+1,solution,result);
		}
	}

}

//because we check by row so we dont need to check if Row is conflect
bool isValid(int attemptedColumn,int attemptedRow,vector<int> &queenInColumn){
	for(int i=0;i<attemptedRow;i++){
		if(attemptedColumn == queenInColumn[i]||abs(attemptedColumn-queenInColumn[i]) == abs(attemptedRow-i)){
			return false;
		}
	}
	return true;
}


void printMatrix(vector<vector<string>> &matrix){
	for(int i=0;i<matrix.size();i++)
	{	cout<<"===="<<endl;
		for(int j=0;j<matrix[i].size();j++){
			cout<<matrix[i][j]<<endl;
		}
	}
}

int main(int argc,char *argv[]){
	int n =8;
	if(argc>1)
	{
		n = atoi(argv[1]);
	}
	vector<vector<string>> result = solveNQueens(n);
	printMatrix(result);

	return 0;

}
