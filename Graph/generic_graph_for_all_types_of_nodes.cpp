#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;
template <typename T>

class Graph {
    public: 
        unordered_map< T, list<T>> adjList;

        void addEdge(T u, T v, bool direction) { 

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
};


int main() {

    //integer type graph
    // Graph<int> g;

    //char type graph
    Graph<char> g1;

    g1.addEdge('a','b', 0);
    g1.addEdge('b','c', 0);
    g1.addEdge('a','c', 0);

    g1.printAdjacencyList();

}