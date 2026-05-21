#include <iostream>
#include <climits>
using namespace std;

int main() {

    int n;
    cin >> n;

    int graph[100][100];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int source;
    cin >> source;

    int dist[100];
    bool visited[100];

    for(int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for(int count = 0; count < n - 1; count++) {

        int min = INT_MAX, u;

        for(int i = 0; i < n; i++) {
            if(!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        for(int v = 0; v < n; v++) {

            if(!visited[v] && graph[u][v] &&
               dist[u] != INT_MAX &&
               dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    cout << "Shortest Distances:\n";

    for(int i = 0; i < n; i++)
        cout << source << " -> " << i << " = " << dist[i] << endl;

    return 0;
}