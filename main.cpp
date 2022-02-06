#include "DepthFirstSearch.h"

int main() {
    DepthFirstSearch<int> dfs;

/////////////////////////////////////////////////////////
// create node map

/*
 *  1 --- 0
 *  |     |
 *  3 --- 2
 *  |
 *  4 --- 5
 *
 */

    // level 1
    dfs.newBidirectionalNode(0, 1);
    dfs.newBidirectionalNode(0, 2);

    // level 2
    dfs.newBidirectionalNode(1, 3);
    dfs.newBidirectionalNode(2, 3);

    // level 3
    dfs.newBidirectionalNode(3, 4);

    // level 4
    dfs.newBidirectionalNode(4, 5);

//////////////////////////////////////////////////////
//search

    dfs.search(5, 0);

    return 0;
}
