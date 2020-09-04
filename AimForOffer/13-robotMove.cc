//=====================
//面试题13:机器人的运动范围
//题目：地上有一个ｍ行ｎ列的方格。一个机器人从坐标(0,0)的格子开始移动，
//它每一次可以向左右上下移动一格，但不能进入行坐标和列坐标的数位之和大于ｋ的
//格子。例如，当ｋ为18时,机器人能够进入方格(35,37),因为3+5+3+7=18,
//但是它不能进入(35,38),因为3+5+3+8=19。请问该机器人能够到达多少个格子



#include <cstdio>

int getDigitSum(int num);
bool Check(int threshold, int row, int col, int rows, int cols, bool *visited);
int moveCountCore(int threshold, int row, int col, int rows, int cols, bool *visited);
int moveCount(int threshold, int rows, int cols);

int moveCount(int threshold, int rows, int cols){
	if(threshold < 0 || rows <=0 || cols <= 0){
		return 0;
	}
	
	bool *visited = new bool[rows*cols];

	for(int i = 0; i < rows*cols; ++i)
		visited[i] = false;
	
	int count = moveCountCore(threshold, 0, 0, rows, cols, visited);

	delete[] visited;

	return count;
}

int moveCountCore(int threshold, int row, int col, int rows, int cols, bool *visited){
	int count = 0;
	if(Check(threshold, row, col, rows, cols, visited)){
		visited[row*cols + col] =true;		
		// check为true，因此先+1
		count = 1 + moveCountCore(threshold, row-1, col, rows, cols, visited)
			+ moveCountCore(threshold, row+1, col, rows, cols, visited)
			+ moveCountCore(threshold, row, col-1, rows, cols, visited)
			+ moveCountCore(threshold, row, col+1, rows, cols, visited);
	}

	return count;
}

int getDigitSum(int num){
	int sum = 0;
	while(num > 0){
		sum += num%10;
		num /= 10;
	}
	return sum;
}

bool Check(int threshold, int row, int col, int rows, int cols, bool *visited){
	if(row >= 0 && row < rows && col >=0 && col < cols && getDigitSum(row)+getDigitSum(col) < threshold && !visited[row*cols+col])
		return true;
	return false;
}

int main(int argc, char* argv[]){
	printf("count is %d\n",moveCount(15,20,20));
}
