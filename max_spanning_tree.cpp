#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(Edge a, Edge b) {
    return a.w > b.w;
}

int parent[100];

int find(int i) {

    while(parent[i] != i)
        i = parent[i];

    return i;
}

void Union(int a, int b) {

    int x = find(a);
    int y = find(b);

    parent[x] = y;
}

int main() {

    int V, E;
    cin >> V >> E;

    Edge edges[E];

    for(int i = 0; i < E; i++) {
        cin >> edges[i].u
             >> edges[i].v
             >> edges[i].w;
    }

    sort(edges, edges + E, compare);

    for(int i = 0; i < V; i++)
        parent[i] = i;

    int maxWeight = 0;

    for(int i = 0; i < E; i++) {

        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if(u != v) {
            maxWeight += edges[i].w;
            Union(u, v);
        }
    }

    cout << "Maximum Spanning Weight: "
         << maxWeight;

    return 0;
}