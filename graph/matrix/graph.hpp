#ifndef _GRAPH_H
#define _GRAPH_H

#include <memory.h>
#include <iostream>
#include <queue>
using std::size_t;
using std::cout;
using std::endl;
using std::queue;

template<typename T,size_t N>
class graph{
    public:
        graph(){
            memset(vertex,0,sizeof(vertex));
            memset(edge,0,sizeof(edge));
        }
        graph(const T *arr, int e[N][N] ){
            memset(vertex,0,sizeof(vertex));
            memset(edge,0,sizeof(edge));

            for(int i=0;i<N;i++)
            {
                vertex[i] = arr[i];
            }
            for(int i =0;i<N;i++)
                for(int j =0;j<N;j++)
                {
                    edge[i][j] = e[i][j];
                }
        }
        ~graph();
        void DFS();
        void BFS();
	
        void print_param() const
        {
            std::cout << "vertex : " << std::endl;
            for (int i = 0; i <N;++i)
            {
                std::cout << vertex[i];
            }
            std::cout << std::endl << "adjacency metrix : " << std::endl;
            for (int i = 0; i < N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    std::cout << edge[i][j];
                }
                std::cout << std::endl;
            }
        }



    private:
        void do_DFS(int pos,bool *visit);
        T vertex[N];
        int edge[N][N];
};

template<typename T,size_t N>
void graph<T,N>::do_DFS(int pos,bool *visit)
{
    visit[pos] = true;
    cout<<vertex[pos]<<" ";
    for(int i = 0;i<N;i++)
    {
        if(edge[pos][i]&&!visit[i])
        {
            do_DFS(i,visit);
        }
    }
}

template<typename T,size_t N>
void graph<T,N>::DFS()
{
    bool visit[N];
    memset(visit,0,sizeof(visit));

    for(int i =0;i<N;i++)
    {
        if(!visit[i]){
            do_DFS(i,visit);
        }
    }
	cout<<endl;
}

template<typename T,size_t N>
void graph<T,N>::BFS()
{
    bool visit[N];
    queue<int> ideq;
    memset(visit,0,sizeof(visit));

    for(int i =0;i<N;i++)
    {
        if(!visit[i])
            ideq.push(i);
        while(!ideq.empty())
        {
            int cur = ideq.front();
            cout<<vertex[cur]<<" ";
            ideq.pop();

            for(int i = 0;i<N;i++)
            {
                if(edge[cur][i] && !visit)
                {
                    ideq.push(i);
                    visit[i] = true;
                }
            }

        }
    }
    cout<<endl;

}


#endif
