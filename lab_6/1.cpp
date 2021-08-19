#include <bits/stdc++.h>

#define red 0
#define yellow 1
#define blue 2

using namespace std;

vector <int> colors;
bool is_cycle = false;

void DFS(vector <vector <int>> &grph, int vrtx) {
    colors[vrtx] = yellow;

    for (int i : grph[vrtx]) {
        if (colors[i] == red) {
            DFS(grph, i);
        } else if (colors[i] == yellow) {
            is_cycle = true;
        }
    }
    colors[vrtx] = blue;
}

int main() {
    int vertices, edges, k;

    cin >> vertices >> edges;

    vector <vector <int>> graph(vertices + 1);
    colors.resize(vertices + 1, red);

    int vrtx, i;
    for (;edges--;) {
        cin >> vrtx >> i;

        graph[vrtx].push_back(i);
    }

    k = 1;
    while (k < colors.size()){
        if (colors[k] == red){
            DFS(graph, k);
        }
        k++;
    }

    if (is_cycle) {
        cout << "no" << endl;
    } else {
        cout << "yes" << endl;
    }

    return 0;
}
