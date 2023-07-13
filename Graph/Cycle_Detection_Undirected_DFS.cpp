#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
#include <List>
using namespace std;
template <typename T>

class Graph {
    public: 
        unordered_map<T, list<T>> adjList;

        void addEdge(int u, int v, bool direction) {

            // if direction = 0 --> undirected graph
            // if direction = 1 --> directed graph

            //in both cases u->v edge to banti hi banti h
            adjList[u].push_back(v);    // create an edge from u to v

            if(direction == 0){
                //undirected edge
                adjList[v].push_back(u);  // since edge is undirected v to u edge also exist;
            }
        } 

        void printAdjacencyList() {
            for(auto node: adjList){

                cout << node.first << "-> ";

                for(auto neighbour: node.second){
                    cout << neighbour << ", ";
                }

                cout << endl;
            }
        }


        //BFS
        void bfs(T src, unordered_map<T, bool> &visited) {
            queue<T> q;

            //insert the first node and mark it visited
            q.push(src);
            visited[src] = true;

            while(!q.empty()){
                //find the front node
                T frontNode = q.front();
                q.pop();

                //print the front node
                cout << frontNode << ", ";

                //insert the neightbour
                for(auto neighbour: adjList[frontNode]){
                    if(!visited[neighbour]){
                        q.push(neighbour);
                        visited[neighbour] = true;
                    }
                }
            }

        }

        //DFS
        void dfs (T src, unordered_map<T, bool> &visited) {
            // print the source 
            cout << src << ", ";
            visited[src] = true;

            //pass a recursive call for all the neighbours
            for(auto neighbour: adjList[src]){
                if(!visited[neighbour]){
                    dfs(neighbour, visited);
                }
            }
        }

        bool checkCyclicUsingDFS(T src, unordered_map<T, bool> &visited, int parent) {

            visited[src] = true;

            for(auto nbr: adjList[src]){

                if(!visited[nbr]){
                    bool ans = checkCyclicUsingDFS(nbr, visited, src);
                    if(ans == true){
                        return true;
                    }
                }

                if(visited[nbr] && nbr != parent){
                    //cycle is present
                    return true;
                }

            }

            return false;

        }

};

int main(){

    Graph<int> g;   
    int n = 5;  // no of nodes
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,3,0);
    g.addEdge(3,4,0);


    g.printAdjacencyList();
    cout << endl;

    unordered_map<int, bool> visited;
    bool ans = false;

    for(int i=0; i<n; i++){
        if(!visited[i]){
            ans = g.checkCyclicUsingDFS(i, visited, -1);
            if(ans == true) break;
        }
    }

    if(ans == true){
        cout << "Cycle is present!" << endl;
    }
    else{
        cout << "No cycle found" << endl;
    }

    return 0;
}

//BFS