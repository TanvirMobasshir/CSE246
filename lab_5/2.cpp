#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define UNCOLOURED 0
#define BLACK 500
#define RED 200

using namespace std;

int color_buildings(vector <vector <int>> &graph, int first_colour) {
    vector <int> colours(graph.size(), UNCOLOURED);
    queue <int> node_queue;

    int total_price = first_colour;

    int source = 1;

    colours[source] = first_colour;
    node_queue.push(source);

    int v, u;
    while (!node_queue.empty()) {
        v = node_queue.front();
        node_queue.pop();

        for (int i = 0; i < graph[v].size(); i++) {
            u = graph[v][i];

            if (u >= colours.size()) {
                colours.resize(u + 1, UNCOLOURED);
            }

            if (colours[u] == UNCOLOURED) {
                if (colours[v] == BLACK) {
                    colours[u] = RED;
                    total_price += RED;

                } else {
                    colours[u] = BLACK;
                    total_price += BLACK;
                }
                node_queue.push(u);

            }
        }
    }

    return total_price;
}

int main() {
    int vertices, edges;

    cin >> vertices >> edges;

    vector <vector <int>> graph(vertices + 1);

    int v, u;
    for (int i = 0; i < edges; i++) {
        cin >> v >> u;

        graph[v].push_back(u);

        // For Undirected graphs
        if (v != u) {
            graph[u].push_back(v);
        }
    }

    int colouring_price1 = color_buildings(graph, RED);
    int colouring_price2 = color_buildings(graph, BLACK);

    if (colouring_price1 < colouring_price2) {
        cout << colouring_price1 << endl;
    } else {
        cout << colouring_price2 << endl;
    }

    return 0;
}
