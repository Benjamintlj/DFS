//
// Created by Benjamin Lewis-Jones on 06/02/2022.
//

#ifndef DFS_DEPTHFIRSTSEARCH_H
#define DFS_DEPTHFIRSTSEARCH_H
/////////////////////////////////////////////////////////
// dependencies
#include <map>
#include <list>
#include <iostream>
#include <queue>

using namespace std;


/////////////////////////////////////////////////////////
// class definition

template<typename T>
class DepthFirstSearch {
    // attributes
private:
    map<T, list<T>> nodeMap;
    map<T, bool> visited;

    // methods
public:
    // creates new bidirectional node in the node map, linking primary and secondary
    void newBidirectionalNode(T primary, T secondary);

    // searches for the target using Depth First Search from the source
    bool search(T target, T source);
};



/////////////////////////////////////////////////////////
// method definitions

template<typename T>
void DepthFirstSearch<T>::newBidirectionalNode(T primary, T secondary) {
    nodeMap[primary].push_back(secondary);
    nodeMap[secondary].push_back(primary);
}

template<typename T>
bool DepthFirstSearch<T>::search(T target, T source) {

    cout << source << endl;

    if(source == target) {
        cout << "target found" << endl;
        return true;
    }

    visited[source] = true;

    for(T neighbour : nodeMap[source])
        if(!visited[neighbour])
            if(search(target, neighbour))
                return true;
}

#endif //DFS_DEPTHFIRSTSEARCH_H
