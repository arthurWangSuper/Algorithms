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
        void dijkstra(int *short_index,int *short_length,int num) const;
        void print_param() const



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

template<typename T,size_t N>
void graph<T,N>:: print_param() const
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

template<typename T,size_t N>
void graph<T,N>::dijkstra(int *shorter_index,int *shorter_length,int num) const;
{
    //indicate has get min value
    bool flag[N];
    memset(flag,0,sizeof(flag));

    for(int i =0;i<N;i++)
    {
        shorter_length[i] = egde[num][j];
        shorter_index = num;
    }

    int j = num;
    int k = -1;
    int min = 0;
    flag[num]=true;
    for(int n =1;n<N;n++)
    {
        min = INT_MIN;
        for(int index = 0;index<N;index++)
        {
            if(!flag[index]&&short_length[index]<min)
            {
                min = short_length[index];
                k = index;
            }
        }
        flag[k]=true;
        j=k;
        for(int _index = 0;_index<N;_index++)
        {
            if(!flag[_index]&&shorter_length[num][j]+edge[j][_index]<shorter_length[_index])
            {
                shorter_length[_index] = short_length[num][j]+edge[j][_index];
                shorter_index[_index] = j;
            }
        }
    }

}
#endif
