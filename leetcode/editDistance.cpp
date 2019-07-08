/*******************************************
 * Given two words word1 and word2, 
 * find the mininum number of steps 
 * required to convert word1 to word2
 * (each operation is counted as 1 step.)
 * ****************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int min(int x,int y,int z){
	return std::min(x,std::min(y,z));
}

int minDistance(string word1,string word2){
	int n1 = word1.size();
	int n2 = word2.size();
	
	if(n1==0) return n2;
	if(n2==0) return n1;

	vector<vector<int>> m(n1+1,vector<int>(n2+1));

	for(int i =0;i<m.size();i++){
		m[i][0]=i;
	}
	for(int i =0;i<m[0].size();i++){
		m[0][i]=i;
	}

	//Dynamic Programming
	int row ,col;
	for(row=1;row<m.size();row++){
		for(col=1;col<m[row].size();col++){
			if(word1[row-1]==word2[col-1]){
				m[row][col]=m[row-1][col-1];
			}else{
				int minValue = min(m[row-1][col-1],m[row-1][col],m[row][col-1]);
				m[row][col]=minValue+1;
			}
		}
	}
	return m[row-1][col-1];
}

int main(int argc,char **argv){
	string word1= "abb",word2="abccb";
	if(argc>2){
		word1 = argv[1];
		word2 = argv[2];
	}
	int steps =minDistance(word1,word2);

	cout<<word1<<","<<word2<<":"<<steps<<endl;
return
