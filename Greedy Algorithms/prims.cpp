#include <iostream>
using namespace std; 

int main() {
    int a, b, u, v, n, i, j, ne = 1;
    int visited[10] = {0}, minEdge, mincost = 0, cost[10][10];

    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the adjacency matrix:\n";

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
                cost[i][j] = 999; // Replace 0 with a large value (999)
        }
    }

    visited[0] = 1; // Start from the first node

    while (ne < n) {
        minEdge = 999; // Reset minEdge before searching

        for (i = 0; i < n; i++) {
            if (visited[i]) { // Check only visited nodes
                for (j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < minEdge) { // Check unvisited nodes
                        minEdge = cost[i][j];
                        a = u = i;
                        b = v = j;
                    }
                }
            }
        }

        visited[b] = 1; // Mark the selected node as visited
        cout << ne++ << " edge (" << a << "," << b << ") = " << minEdge << endl;
        mincost += minEdge;
        cost[a][b] = cost[b][a] = 999; // Mark the edge as used
    }

    cout << "Minimum cost = " << mincost << endl;
    return 0;
}
