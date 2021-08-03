#include <bits/stdc++.h>
using namespace std;


vector <int> graph[10000000];
int distances[10000000];
queue <int> q;

int breadthFirstSearch(int source, int size) {
    distances[source] = 0;
    q.push(source);

    int u, v;

    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            v = graph[u][i];

            if (distances[v] == -1) {
                distances[v] = 1 + distances[u];
                q.push(v);
            }
        }
    }

    int max_distance = -1;

    for (int i = 1; i <= size; i++) {
        if (distances[i] >= max_distance) {
            max_distance = distances[i];
        }
    }

    return max_distance;
}

int main() {
    int vertices, edges;

    cin >> vertices >> edges;

    for (int i = 0; i < vertices + 1; i++) {
        distances[i] = -1;
    }

    int u, v;
    for (int i = 0; i < edges; i++) {
        cin >> u >> v;

        graph[u].push_back(v);

        // For Undiredted graphs
        if (u != v) {
            graph[v].push_back(u);
        }
    }

    int farthest_distances = breadthFirstSearch(1, vertices);

    cout << farthest_distances << endl;

    return 0;
}
