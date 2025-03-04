#include <iostream>
using namespace std;

int i, j, k, a, b, u, v, n, ne = 1;
int minEdge, mincost = 0, cost[9][9], parent[9];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    cout << "Enter the Number of Vertices: ";
    cin >> n;
    cout << "Enter the cost adjacency matrix:\n";
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> cost[i][j];
            if (cost[i][j] == 0)  // Fixed incorrect '=' assignment to '=='
                cost[i][j] = 999;
        }
    }

    cout << "The edges of Minimum Cost Spanning Tree are:\n";
    
    while (ne < n) {
        minEdge = 999; // Reset minEdge before each iteration
        
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (cost[i][j] < minEdge) {
                    minEdge = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if (uni(u, v)) {
            cout << ne++ << " edge (" << a << "," << b << ") = " << minEdge << endl;
            mincost += minEdge;
        }
        
        cost[a][b] = cost[b][a] = 999; // Mark edge as used
    }

    cout << "Minimum cost = " << mincost << endl;
    return 0;
}
