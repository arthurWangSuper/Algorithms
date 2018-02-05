#include<iostream>
#include<vector>

class graph
{
	private:
		struct EdgeNode
		{
			int adjvex;
			int weight;
			EdgeNode *next;
		};
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
