#include <cstdio>
#include <cstring>
#include <string>

// BST的意思

bool hasPathCore(const char *matrix, int row, int col, int rows, int cols,const char *str,int pos, bool *visited)
{
	if(str[pos] == '\0')
		return true
	
	bool hasPath = false;
	// 坐标在合理范围
	// 之前没有访问到
	// 是下一个要匹配的字符
	if( row >= 0 && row < rows && col >=0 && col < cols 
			&& !visited[row * cols + col ]
			&& matrix[row*cols + col ] == str[pos]){
			++pos;
			visited[row*cols+col] = true;
			hasPath = hasPathCore(matrix, row+1, col, rows, cols, str, pos, visited)
				|| hasPathCore(matrix, row, col+1, rows, cols, str, pos, visited) 
				|| hasPathCore(matrix, row-1, col, rows, cols, str, pos, visited)
				|| hasPathCore(matrix, row, col-1, rows, cols, str, pos, visited);

			if(!hasPath)
			{	
				--pos;
				visited[row*cols+col] = false;
			}
	}
	return hasPath;
}
bool hasPath(const char* matrix,int rows, int cols, const char* str){

	if(matrix == nullptr || rows <= 0 || cols <= 0 || str == nullptr)
		return false;
	bool res = false;
	bool *visited = new bool[rows*cols];
	memset(visited, 0 ,rows*cols);
	// 当前compare的pos
	int pos = 0;
	for(int i = 0; i <= rows; ++i)
		for(int j = 0; j <= cols; ++j)
		{
			if(hasPathCore(matrix, i, j,str,pos)){
				return true;
			}
		}
	delete[] visited;
	return true;
}
