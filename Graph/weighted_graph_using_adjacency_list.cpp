#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph {
    public: 
        unordered_map<int, list<pair<int,int>>> adjList;

        void addEdge(int u, int v, int weight, bool direction) {

            // if direction = 0 --> undirected graph
            // if direction = 1 --> directed graph

            //in both cases u->v edge to banti hi banti h
            adjList[u].push_back({v,weight});    // create an edge from u to v

            if(direction == 0){
                //undirected edge
                adjList[v].push_back({u,weight});  // since edge is undirected v to u edge also exist;
            }
        } 

        void printAdjacencyList() {
            for(auto node: adjList){

                cout << node.first << "-> ";

                for(auto neighbour: node.second){
                    cout << " ( " << neighbour.first << " , " << neighbour.second << " ) " << ", ";
                }

                cout << endl;
            }
        }
};


int main() {

    Graph g;
    //undirected edge input
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);

    //directed input
    g.addEdge(0,1,5,1);
    g.addEdge(1,2,4,1);
    g.addEdge(0,2,3,1);


    cout << endl;
    g.printAdjacencyList();


    return 0;
}