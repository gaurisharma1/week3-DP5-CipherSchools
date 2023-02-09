#include <bits/stdc++.h>
using namespace std;
class Graph
{
    int v;
    list<int> *adj;

public:
    Graph(int v)
    {
        this->v = v;
        this->adj = new list<int>[this->v];
    }
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int source, bool *visited, vector<int> &result)
    {
        visited[source] = true;
        result.push_back(source);
        for (auto itr = adj[source].begin(); itr != adj[source].end(); itr++)
        {
            if (!visited[*itr])
            {
                dfs(*itr, visited, result);
            }
        }
    }

    vector<int> dfs()
    {
        vector<int> result;
        bool *visited = new bool[this->v];
        for (int i = 0; i < this->v; i++)
        {
            visited[i] = false;
        }
        int count = 0;
        for (int i = 0; i < this->v; i++)
        {
            if (!visited[i])
            {
                count++;
                dfs(i, visited, result);
            }
        }
    }
    vector<int> bfs()
    {
        vector<int> result;
        bool *visited = new bool[this->v];
        for (int i = 0; i < this->v; i++)
        {
            visited[i] = false;
        }
        list<int> q;
        int source = 0;
        visited[source] = true;
        q.push_back(source);
        while (!q.empty())
        {
            source = q.front();
            q.pop_front();
            result.push_back(source);
            for (auto itr = adj[source].begin(); itr != adj[source].end(); itr++)
            {
                if (!visited[*itr])
                {
                    visited[*itr] = true;
                    q.push_back(*itr);
                }
            }
        }
        return result;
    }
    bool IsCyclic(int source, int parent, bool *visited)
    {
        visited[source] = true;
        for (auto itr = adj[source].begin(); itr != adj[source].end(); itr++)
        {
            if (!visited[*itr])
            {
                if (IsCyclic(*itr, source, visited))
                {
                    return true;
                }
                else
                {
                    if (*itr != parent)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
    }

        bool IsCyclic(){
            bool *visited = new bool[this->v];
            for (int i = 0; i < this->v; i++)
            {
                visited[i] = false;
            }
            for (int i = 0; i < this->v; i++)
            {
                if (!visited[i])
                {
                    if (IsCyclic(i,-1, visited))
                    return true;
                }
            }
            return false;
        }

        bool is_Cyclic(int source, bool *visited,bool* recursive){
            visited[source] = true;
            recursive[source] = true;
            for(auto itr = adj[source].begin(); itr!= adj[source].end(); itr++){
                if(!visited[*itr] && is_Cyclic(*itr,visited,recursive)){
                    return true;
                }else if(recursive[*itr]==true){
                    return true;
                }

            }


            recursive[source] = false;
            return false;
            
        }

        bool isCyclic(){
            bool *visited = new bool[this->v];
            bool *recursive = new bool[this->v];
            for(int i=0;i<this->v;i++){
                recursive[i]=visited[i]=false;
            }
            for(int i=0;i<this->v;i++){
                if((isCyclic(i,visited,recursive))){
                    return true;
                }
            }
            return false;
        
        }
    
};
class DisjointSets{
    public :
    DisjointSets(int N);
    int Find(int u);
    void Union(int u,int v);
    
};
class Edge{
    public:
    int source,destination;
    double weight;
    Edge(int u,int v,double W){
        this->source=u;
        this->destination=v;
        this->weight = W;
    }
};
bool comparator(const Edge &a,const Edge &b){
    return a.weight<=b.weight;
}
class Graph{
int v,E;
vector<Edge> edges;
public:
Graph(int v,int E){
    this->v=v;
    this->E=E;
}
void AddEdge(int u,int v,double w){
    this->edges.push_back(Edge(u,v,w));
}
    vector<Edge> Kruskal(){
        vector<Edge> result;
        double minweight =0.0;
        sort(this->edges.begin(),this->edges.end(),comparator);
        DisjointSets ds(this->v);
        for(auto itr = this->edges.begin();itr!=this->edges.end();itr++){
            int u = itr->source;
            int v = itr->destination;
            int parentU = ds.Find(u),parentV = ds.Find(v);
            if(parentU==parentV){

            }else{
                    minweight += itr->weight;
                    result.push_back(*itr);
                    ds.Union(u,v);
                    
            }

        }
        return {result,minweight};
        }

};
class Graph1{
    int V;
    list<int>adj;
    public:
    void topologicalSort(int source,bool* visited, vector<int> result){
        for(auto itr = adj[source].begin(); itr != adj[source].end();itr++){
            if(!visited[*itr]){
                topologicalSort(*itr,visited,result);
            }
        }
        result.push_back(source);
    }

    vector<int> topologicalSort(){
        vector<int> result;
        bool *visited = new bool[this->V];
        for(int i=0;i<this->V;i++){
            visited[i] = false;
        }
        for(int i=0;i<this->V;i++){
            if(!visited[i]){
                topologicalSort(i,visited,result);
            }
        }
        reverse(result.begin(),result.end());


    }

}
    
int main()
    {
        return 0;
    }
