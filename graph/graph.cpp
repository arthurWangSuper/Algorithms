#include<iostream>
#include<vector>
class graph_matrix{
private:
	vertexType vex[MAXVEX];
	int MAT[MAXVEX][MAXVEX];
	int vexNum,EdgeNum;
};


class graph
{
	private:
		// 边表节点
		struct EdgeNode
		{
			int adjvex;
			int weight;
			EdgeNode *next;
		};
		// 顶点节点
		struct VertexNode
		{	
			int data;
			EdgeNode *firstedge;
		};
	
		struct GraphAdjList
		{
			vertexNode *Vertexlist;
			int numVertexes,numEdges;
		};
	public:
		void createALGraph();
		void depth_first_search();
		void breadth_first_search();
		void MiniSpanTree_Prim();
		void MiniSpanTrss_Kruskal();
		void ShortesrPath_Dijkstra();
		void ShortesrPath_Floyd();
		void TopologicalSort();
		void CriticalPath();
};
void main()
{
	return ;
}
