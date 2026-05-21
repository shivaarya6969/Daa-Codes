#include <iostream>
using namespace std;

bool dfs(int graph[][100], int visited[], int recStack[],
         int node, int n) {

    visited[node] = 1;
    recStack[node] = 1;

    for(int i = 0; i < n; i++) {

        if(graph[node][i]) {

            if(!visited[i] &&
               dfs(graph, visited, recStack, i, n))
                return true;

            else if(recStack[i])
                return true;
        }
    }

    recStack[node] = 0;

    return false;
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

    int visited[100] = {0};
    int recStack[100] = {0};

    bool cycle = false;

    for(int i = 0; i < n; i++) {

        if(!visited[i]) {

            if(dfs(graph, visited, recStack, i, n)) {
                cycle = true;
                break;
            }
        }
    }

    if(cycle)
        cout << "Yes Cycle Exists";
    else
        cout << "No Cycle Exists";

    return 0;
}