#include <iostream>
#include <queue>
using namespace std;

bool isBipartite(int graph[][100], int n) {

    int color[100];

    for(int i = 0; i < n; i++)
        color[i] = -1;

    queue<int> q;

    color[0] = 0;
    q.push(0);

    while(!q.empty()) {

        int u = q.front();
        q.pop();

        for(int v = 0; v < n; v++) {

            if(graph[u][v]) {

                if(color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[v] == color[u]) {
                    return false;
                }
            }
        }
    }

    return true;
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

    if(isBipartite(graph, n))
        cout << "Yes Bipartite";
    else
        cout << "Not Bipartite";

    return 0;
}