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

    void topologicalSortBFS(int n, vector<int> &ans){
        queue<int> q;
        unordered_map<int, int> indegree;

        //sabki indegree calculate kar lo
        for(auto i: adjList){
            int src = i.first;

            for(auto nbr: i.second){
                indegree[nbr]++;
            }
        }

        //put all nodes inside queue which has indegeree 0
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        //bfs logic
        while (!q.empty()){
            int frontNode = q.front();
            q.pop();

            ans.push_back(frontNode);

            for(auto nbr: adjList[frontNode]){
                indegree[nbr]--;
                //check for 0 again
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }
    }

};

int main(){

    Graph<int> g;   
    int n = 8;  // no of nodes
    g.addEdge(2,4,1);
    g.addEdge(2,5,1);
    g.addEdge(5,3,1);
    g.addEdge(4,6,1);
    g.addEdge(3,7,1);
    g.addEdge(6,7,1);
    g.addEdge(7,0,1);
    g.addEdge(7,1,1);

    unordered_map<int,bool> visited;
    // stack<int> ans;

    // for(int i=0; i<n; i++){
    //     if(!visited[i]){
    //         g.topologicalSort(i, visited, ans);
    //     }
    // }

    // while(!ans.empty()){
    //     cout << ans.top() << ", ";
    //     ans.pop();
    // }


    vector<int> ans;

    //connected or disconnected graph
    g.topologicalSortBFS(n, ans);
    

    //printing ans
    cout << "Printing Topological sort using BFS : " << endl; 
    for(auto i: ans){
        cout << i << " ";
    }

    cout << endl;

    return 0;
}