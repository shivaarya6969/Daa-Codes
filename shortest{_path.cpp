#include <iostream>
#include <climits>
using namespace std;

int shortestPath(int graph[][100], int u, int v,
                 int k, int n) {

    if(k == 0 && u == v)
        return 0;

    if(k == 1 && graph[u][v] != 0)
        return graph[u][v];

    if(k <= 0)
        return INT_MAX;

    int res = INT_MAX;

    for(int i = 0; i < n; i++) {

        if(graph[u][i] != 0 && u != i && v != i) {

            int rec = shortestPath(graph, i, v, k - 1, n);

            if(rec != INT_MAX)
                res = min(res, graph[u][i] + rec);
        }
    }

    return res;
}

int main() {

    int n;
    cin >> n;

    int graph[100][100];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int source, dest, k;

    cin >> source >> dest;
    cin >> k;

    int ans = shortestPath(graph, source, dest, k, n);

    if(ans == INT_MAX)
        cout << "No path of length k is available";
    else
        cout << "Weight of shortest path = " << ans;

    return 0;
}