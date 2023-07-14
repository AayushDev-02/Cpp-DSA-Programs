#include <iostream>
#include <bits/stdc++.h>
using namespace std;
template <typename T>


class Graph {
public: 
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, int direction){

        adjList[u].push_back(v);

        if(direction == 0){
            adjList[v].push_back(u);
        }
    }

    void printAdjList(){

        for(auto node: adjList){
            cout << node.first << "->";

            for(auto nbr: node.second){
                cout << nbr << ", ";
            }
            cout << endl;
        }

    }

    void dfs(T src, unordered_map<T, bool> &visited){

        visited[src] = true;
        cout << src << " ";

        for(auto nbr: adjList[src]){
            if(!visited[nbr])
                dfs(nbr, visited);
        }

    }

    void topologicalSort(int src, unordered_map<int, bool> &visited, stack<int> &ans){
        visited[src] = true;

        for(auto nbr: adjList[src]){
            if(!visited[nbr]){
                topologicalSort(nbr, visited, ans);
            }
        }

        //while returning store the node in the stack
        ans.push(src);
    }


};

int main(){

    Graph<int> g;   
    int n = 8;  // no of nodes
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1);
    g.addEdge(3,5,1);
    g.addEdge(4,6,1);
    g.addEdge(5,6,1);
    g.addEdge(6,7,1);

    unordered_map<int,bool> visited;
    stack<int> ans;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            g.topologicalSort(i, visited, ans);
        }
    }

    while(!ans.empty()){
        cout << ans.top() << ", ";
        ans.pop();
    }

    return 0;
}