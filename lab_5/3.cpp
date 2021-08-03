#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <int> breadth_first_search(vector <vector <int>> &graph, int source, vector <int> &distances) {
    queue <int> qu;

    distances[source] = 0;
    qu.push(source);

    int vertex, connected_vertex;

    while (!qu.empty()) {
        vertex = qu.front();
        qu.pop();

        for (int i = 0; i < graph[vertex].size(); i++) {
            connected_vertex = graph[vertex][i];

            if (connected_vertex >= distances.size()) {
                distances.resize(connected_vertex + 1, -1);
            }

            if (distances[connected_vertex] == -1) {
                distances[connected_vertex] = 1 + distances[vertex];
                qu.push(connected_vertex);
            }
        }
    }

    return distances;
}

int cnt_connecting_roads(vector <vector <int>> &graph, vector <int> &distances) {
    int cnt = 0;
    for (int i = 1; i <= distances.size() - 1; i++) {
        if (distances[i] == -1) {
            breadth_first_search(graph, i, distances);
            cnt++;
        }
    }

    int connecting_roads = cnt - 1;

    return connecting_roads;
}

int main() {
    int no_of_vertices, edges;

    cin >> no_of_vertices >> edges;

    vector <vector <int>> graph(no_of_vertices + 1);
    vector <int> distances(graph.size(), -1);

    int vertex, connected_vertex;
    for (int i = 0; i < edges; i++) {
        cin >> vertex >> connected_vertex;

        graph[vertex].push_back(connected_vertex);

        // For Undirected graphs
        if (vertex != connected_vertex) {
            graph[connected_vertex].push_back(vertex);
        }

    }

    int connecting_roads = cnt_connecting_roads(graph, distances);

    cout << connecting_roads << endl;

    return 0;
}
