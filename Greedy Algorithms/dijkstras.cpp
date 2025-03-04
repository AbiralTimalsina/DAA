#include<iostream>
using namespace std;

#define infinity 999

void dij(int n, int v, int cost[10][10], int dist[10]) {
    int i, u, count, w, flag[10], min;
    for(i = 1; i <= n; i++) {
        flag[i] = 0;
        dist[i] = cost[v][i];
    }
    flag[v] = 1;
    count = 1;
    
    while(count < n) {
        min = infinity;
        u = -1;
        
        for(w = 1; w <= n; w++) {
            if(!flag[w] && dist[w] < min) {
                min = dist[w];
                u = w;
            }
        }
        
        if(u == -1) break;
        flag[u] = 1;
        count++;
        
        for(w = 1; w <= n; w++) {
            if(!flag[w] && cost[u][w] != infinity && dist[u] + cost[u][w] < dist[w]) {
                dist[w] = dist[u] + cost[u][w];
            }
        }
    }
}

int main() {
    int n, v, i, j, cost[10][10], dist[10];
    cout << "Enter the number of nodes: ";
    cin >> n;
    
    cout << "Enter the cost matrix:\n";
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cin >> cost[i][j];
            if(i != j && cost[i][j] == 0) {
                cost[i][j] = infinity;
            }
        }
    }
    
    cout << "Enter the source node: ";
    cin >> v;
    
    dij(n, v, cost, dist);
    
    cout << "The distances from the source node are:\n";
    for(i = 1; i <= n; i++) {
        if(i != v) {
            cout << v << " -> " << i << " cost = " << dist[i] << endl;
        }
    }
    
    return 0;
}