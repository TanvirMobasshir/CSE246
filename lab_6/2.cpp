#include <bits/stdc++.h>

#define red 0
#define yellow 1
#define blue 2

using namespace std;

vector <int> colors;
vector <int> sqnce;
vector <bool> visits;
__attribute__((unused)) bool has_cycle = false;

void DFS(vector <vector <int>> &grph, int vrtx, bool transpose) {
    if (transpose) {
        visits[vrtx] = true;
    } else {
        colors[vrtx] = yellow;
    }

    for (int i : grph[vrtx]) {
        if (transpose) {
            if (!visits[i]) {
                DFS(grph, i, transpose);
            }
        } else {
            if (colors[i] == red) {
                DFS(grph, i, transpose);
            } else if (colors[i] == yellow) {
                has_cycle = true;
            }
        }
    }

    if (!transpose) {
        colors[vrtx] = blue;
        sqnce.push_back(vrtx);
    }
}

int main() {
    int vertices, edges, j;

    cin >> vertices >> edges;

    vector <vector <int>> grph(vertices + 1);
    vector <vector <int>> gprh_transpose(vertices + 1);
    colors.resize(vertices + 1, red);
    visits.resize(vertices + 1, false);

    int vrtx, i;
    for (;edges--;) {
        cin >> vrtx >> i;
        grph[vrtx].push_back(i);
        gprh_transpose[i].push_back(vrtx);
    }

    j = 1;
    while (j < colors.size()){
        if (colors[j] == red) {
            DFS(grph, j, false);
        }
        j++;
    }

    reverse(sqnce.begin(), sqnce.end());

    int count = 0;
    for (int k : sqnce) {
        if (!visits[k]) {
            DFS(gprh_transpose, k, true);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
