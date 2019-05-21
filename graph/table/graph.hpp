#ifndef _GRAPH_H
#define _GRAPH_H

#include <iostream>
#include <memory.h>

using std::cout;
using std::endl;
using std::vector;
using std::queue;

struct edge_base{
    //node num
    int vertex_num;
    struct edge_base *next;
};
template<typename T>
struct vertex_base{
    //node info
    T data;
    edge_base *first_edge;
};

template<typename T,std::size_t SIZE>
class graph{
    public:
        graph(){
            memset(vertex_type,0,sizeof(vertex_type));
        }
        graph(const T * vertex,vector<int> edge[SIZE]){
            memset(vertex_type,0,sizeof(vertex_type));
            for(int i = 0;i<SIZE;i++)
            {
                vertex_type[i].data = vertex[i];
                for(int j = 0;j<edge[i].size();j++)
                {
                    //此处有创建新的节点，需要在析构函数中删除
                    edge_base *tmp = new edge_base; 
                    tmp->vertex_num = edge[i][j];
                    tmp->next = vertex_type[i].first_edge;
                    vertex_type[i].first_edge = tmp;
                }
            }

        }
        ~graph(){
            for(int i =0;i<SIZE;i++)
            {
                if(vertex_type[i].first_edge)
                {
                    edge_base *tmp = vertex_type[i].first_edge;
                    vertex_type[i].first_edge = tmp->next;
                    delete tmp; 

                }
            }
        }

        void print_param() const;
        void DFS();
        void BFS();

    private:
        void do_DFS(int i,bool* visit);
        vertex_base<T> vertex_type[SIZE];

};

template<typename T,size_t SIZE>
void graph<T,SIZE>::BFS()
{
    bool visit[SIZE];
    memset(visit,0,sizeof(visit));
    std::queue<int> Que;
    for(int i =0;i<SIZE;i++)
    {
        if(!visit[i]){
            cout<<vertex_type[i].data<<" ";
            Que.push(i);
            visit[i] =true;
            while(!Que.empty())
            {
                int tmp_index = Que.front();
                Que.pop();
                for(edge_base *tmp = vertex_type[tmp_index].first_edge;tmp != NULL;tmp=tmp->next)
                {
                    if(!visit[tmp->vertex_num])
                    {
                        cout<<vertex_type[tmp->vertex_num].data<<" ";
                        visit[tmp->vertex_num] =true;
                        Que.push(tmp->vertex_num);
                    } 
                }
            }

        }
    }
    cout<<endl;
}

template<typename T,size_t SIZE>
void graph<T,SIZE>::do_DFS(int i,bool* visit)
{
    for(edge_base *tmp = vertex_type[i].first_edge;tmp != NULL;tmp=tmp->next)
    {
        if(!visit[tmp->vertex_num])
        {
            cout<<vertex_type[tmp->vertex_num].data<<" ";
            visit[tmp->vertex_num] =true;
            do_DFS(tmp->vertex_num,visit);
        } 
    }
}

template<typename T,size_t SIZE>
void graph<T,SIZE>::DFS()
{
    bool visit[SIZE];
    memset(visit,0,sizeof(visit));
    for(int i = 0;i<SIZE;i++)
    {
        if(!visit[i])
        {
            cout<<vertex_type[i].data<<" ";
            visit[i]=true;
            do_DFS(i,visit);
        }
    }
    cout<<endl;
}

template<typename T,size_t SIZE>
void graph<T,SIZE>::print_param() const
{
    for(int i = 0;i<SIZE;i++)
    {
        cout << vertex_type[i].data << " " << vertex_type[i].first_edge << "    ";
        edge_base* temp = vertex_type[i].first_edge;
        while (temp)
        {
            cout << temp->vertex_num << " " <<temp->next << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
}

#endif
