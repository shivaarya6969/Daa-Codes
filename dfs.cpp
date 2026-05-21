#include <iostream>
using namespace std;

void dfs(int graph[][100], int visited[], int v, int dest, int n, bool &found) {

    visited[v] = 1;

    if(v == dest) {
        found = true;
        return;
    }

    for(int i = 0; i < n; i++) {

        if(graph[v][i] == 1 && !visited[i]) {
            dfs(graph, visited, i, dest, n, found);
        }
    }
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

    int source, dest;
    cin >> source >> dest;

    int visited[100] = {0};
    bool found = false;

    dfs(graph, visited, source, dest, n, found);

    if(found)
        cout << "Yes Path Exists";
    else
        cout << "No Such Path Exists";

    return 0;
}