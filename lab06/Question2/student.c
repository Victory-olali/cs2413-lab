#include "graph.h"
// Description

// Write a function that counts how many nodes are isolated.
// A node is isolated if it has no edges connected to it.
// // The graph is stored as an adjacency matrix. 
// Graph* g is a pointer to a Graph struct, which contains a 2D array adj[MAX_NODES][MAX_NODES]. 
// The value at adj[u][v] is 1 if there is an edge between nodes u and v, and 0 otherwise.




int count_isolated(Graph* g) {
    int isolated_count = 0;
    
    // For each node, check if it has any edges
    for (int i = 0; i < MAX_NODES; i++) {
        int is_isolated = 1;
        
        // Check if the entire row is 0 (no edges connected to node i)
        for (int j = 0; j < MAX_NODES; j++) {
            if (g->adj[i][j] == 1) {
                is_isolated = 0;
                break;
            }
        }
        
        if (is_isolated) {
            isolated_count++;
        }
    }
    
    return isolated_count;
}















// Tip: In the adjacency matrix, that means the entire row for that node contains only 0s.
