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

    int key[100];
    bool mstSet[100];

    for(int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;

    int totalWeight = 0;

    for(int count = 0; count < n; count++) {

        int min = INT_MAX, u;

        for(int v = 0; v < n; v++) {

            if(!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        }

        mstSet[u] = true;
        totalWeight += key[u];

        for(int v = 0; v < n; v++) {

            if(graph[u][v] &&
               !mstSet[v] &&
               graph[u][v] < key[v]) {

                key[v] = graph[u][v];
            }
        }
    }

    cout << "Minimum Spanning Weight: "
         << totalWeight;

    return 0;
}