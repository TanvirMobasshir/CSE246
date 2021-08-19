#include <iostream>
#include <vector>
#include <algorithm>

#define red 0
#define yellow 1
#define blue 2

using namespace std;

vector <int> colors;
__attribute__((unused)) bool has_cycle = false;

void DFS(vector <vector <int>> &grph, int vrtx) {
    colors[vrtx] = yellow;

    for (int i : grph[vrtx]) {
        if (colors[i] == red) {
            DFS(grph, i);
        } else if (colors[i] == yellow) {
            has_cycle = true;
        }
    }

    colors[vrtx] = blue;
}

vector <int> get_mother_vertices(vector <vector <int>> &grph, vector <vector <int>> &grph_transpose) {
    int last_dfs_call = -1, i;

    fill(colors.begin(), colors.end(), red);

    i = 1;
    while (i < grph.size()){
        if (colors[i] == red){
            DFS(grph, i);
            last_dfs_call = i;
        }
        i++;
    }

    fill(colors.begin(), colors.end(), red);
    DFS(grph, last_dfs_call);

    i = 1;
    while (i < grph.size()){
        if (colors[i] == red){
            vector <int> empty_vector;
            empty_vector.push_back(-1);

            return empty_vector;
        }
        i++;
    }

    int mother_vertex = last_dfs_call;
    fill(colors.begin(), colors.end(), red);
    DFS(grph_transpose, mother_vertex);

    vector <int> output;

    i = 1;
    while (i < grph.size()){
        if (colors[i] == blue){
            output.push_back(i);
        }
        i++;
    }

    return output;
}

int main() {
    int vertices, edges, vrtx, i;

    cin >> vertices >> edges;

    vector <vector <int>> grph(vertices + 1);
    vector <vector <int>> grph_transpose(vertices + 1);
    colors.resize(vertices + 1, red);

    for (;edges--;) {
        cin >> vrtx >> i;

        grph[vrtx].push_back(i);
        grph_transpose[i].push_back(vrtx);
    }

    vector <int> mother_vertices = get_mother_vertices(grph, grph_transpose);

    if (mother_vertices[0] == -1) {
        cout << 0 << "\n";
    } else {
        cout << mother_vertices.size() << "\n";
    }

    return 0;
}
