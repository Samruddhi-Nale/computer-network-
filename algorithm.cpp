#include <iostream>
using namespace std;

int main(){
    int n, e, i, j, k;
    int cost[10][10], dist[10], visited[10];
    int u, v, minDist;
    char a, b, s;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    // Initialize cost matrix
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            cost[i][j] = 99999;

            if (i == j)
                cost[i][j] = 0;
        }
    }

    // Enter edges and their costs
    cout << "Enter edges and costs:\n";

    for (i = 0; i < e; i++){
        cin >> a >> b >> j;

        cost[a - 'A'][b - 'A'] = j;
        cost[b - 'A'][a - 'A'] = j;
    }

    // Enter source node
    cout << "Enter source node: ";
    cin >> s;

    int source = s - 'A';

    // Initialize distances and visited array
    for (i = 0; i < n; i++){
        dist[i] = cost[source][i];
        visited[i] = 0;
    }

    dist[source] = 0;
    visited[source] = 1;

    // Dijkstra's algorithm
    for (k = 1; k < n; k++){
        minDist = 99999;
        u = -1;

        // Find the nearest unvisited node
        for (i = 0; i < n; i++){
            if (visited[i] == 0 && dist[i] < minDist){
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        // Update shortest distances
        for (v = 0; v < n; v++){
            if (visited[v] == 0 &&
                dist[u] + cost[u][v] < dist[v]){
                dist[v] = dist[u] + cost[u][v];
            }
        }
    }

    // Display result table
    cout << "\nSource\tDestination\tCost\n";

    for (i = 0; i < n; i++){
        cout << s << "\t" << char('A' + i) << "\t\t";

        if (dist[i] == 99999)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }

    return 0;
}