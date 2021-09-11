#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class minimum_spanning_tree {
public:
    vector <int> source, depth;
    vector <vector <int>> grph, edges_const;
    int total, vrtcs;

    minimum_spanning_tree(int vrtcs, vector <vector <int>> &grph) {
        this->vrtcs = vrtcs;
        this->source.resize(this->vrtcs + 1);
        this->depth.resize(this->vrtcs + 1);
        this->grph = grph;
        this->edges_const.resize(grph.size());
        this->total = 0;

        int j = 1;
        while(j <= this->vrtcs) {
            this->source[j] = -1;
            this->depth[j] = 1;
            j++;
        }

        for (auto &i : this->edges_const) {i.resize(grph.size(), -1);}
    }

    int get_root(int element) {
        if (source[element] == -1) {return element;}
        return get_root(source[element]);
    }

    void merge(int first, int second) {
        int root_first = get_root(first);
        int root_second = get_root(second);

        if (first == second) {return;}

        if (depth[root_first] >= depth[root_second]) {
            source[root_second] = root_first;
            depth[root_first] = depth[root_first] + depth[root_second];
            this->total += this->grph[first][second];
            this->edges_const[first][second] = this->grph[first][second];
        }
        else {
            source[root_first] = root_second;
            depth[root_second] = depth[root_second] + depth[root_first];
            this->total += this->grph[first][second];
            this->edges_const[first][second] = this->grph[first][second];
        }
    }

    bool query(int first_element, int second_element) {
        if (get_root(first_element) == get_root(second_element)) {return true;}
        return false;
    }
};

bool sort_by(vector <int> &first, vector <int> &second) {return first[2] < second[2];}

int main() {
    int vrtcs, edges;
    cin >> vrtcs >> edges;

    vector <vector <int>> graph(vrtcs + 1), edge_weight_list;

    int vrtx, nghbr, space;

    for (auto &i : graph) {i.resize(vrtcs + 1);}

    int k = 0;
    while(k < edges) {

        cin >> vrtx >> nghbr >> space;
        vector <int> edge_weight = {vrtx, nghbr, space};
        edge_weight_list.push_back(edge_weight);
        graph[vrtx][nghbr] = graph[nghbr][vrtx] = space;
        k++;
    }

    sort(edge_weight_list.begin(), edge_weight_list.end(), sort_by);

    minimum_spanning_tree mst(vrtcs, graph);

    for (auto &i : edge_weight_list) {
        if (!mst.query(i[0], i[1])) {mst.merge(i[0], i[1]);}
    }

    cout << endl << "Cost = ";
    cout << mst.total << endl << endl;

    cout << "Edges: " << endl;

    int i = 0;
    while(i < vrtcs - 1) {
        int j = 0;
        while(j < mst.edges_const[i].size()) {
            if (mst.edges_const[i][j] != -1) {
                cout << i << " to " << j << " - " << mst.edges_const[i][j];
                cout << endl;
            }
            j++;
        }
        i++;
    }

    return 0;
}
