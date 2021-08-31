#include <bits/stdc++.h>
using namespace std;

struct Component {
    int vrtx, dstnc;

    Component(int a, int b) {
        vrtx = a;
        dstnc = b;
    }

    bool operator < (const Component &a) const & {
        return dstnc < a.dstnc;
    }

    bool operator > (const Component &a) const & {
        return dstnc > a.dstnc;
    }
};

priority_queue <Component, vector <Component>, greater <Component> > priority_list;

void display_distance(vector <int> &dstnces, int sc) {
    char sc_lttr = 'a' + sc;
    cout << "Vertex \t Distance from \'" << sc_lttr << "\'" << endl;

    int i = 0;
    while (i < dstnces.size()){
        char vertex = 'a' + i;
        cout << vertex << " \t\t " << dstnces[i] << endl;
        i++;
    }
    cout << endl << endl;
}

void display_track(vector <int> &prnts, int place) {
    char trgt = place + 'a';

    stack <int> track;

    for (;place != 0;){
        track.push(place);
        place = prnts[place];
    }

    cout << "'a' to '" << trgt << "': a->";
    for (;!track.empty();) {
        char current_path = 'a' + track.top();
        track.pop();

        if (track.empty()) {
            cout << current_path;
        } else {
            cout << current_path << "->";
        }
    }
    cout << endl;
}

void dijkstra(vector <vector <int>> &graph, vector <vector <int>> &weights, int source) {
    vector <int> dstnces(graph.size(), 2147483647);
    vector <bool> went_through(graph.size(), false);
    vector <int> parents(graph.size(), -1);

    dstnces[source] = 0;

    priority_list.push(Component(source, 0));

    int vertex, nghbr, dstnc, i;

    for (;!priority_list.empty();) {
        vertex = priority_list.top().vrtx;
        priority_list.pop();

        if (went_through[vertex]) {continue;}

        went_through[vertex] = true;

        i = 0;
        while (i < graph[vertex].size()) {
            nghbr = graph[vertex][i];
            dstnc = weights[vertex][i];

            if (dstnces[vertex] + dstnc < dstnces[nghbr]) {
                parents[nghbr] = vertex;
                dstnces[nghbr] = dstnces[vertex] + dstnc;
                priority_list.push(Component(nghbr, dstnces[nghbr]));
            }
            i++;
        }
    }

    cout << "\n\n";
    display_distance(dstnces, source);

    cout << "The paths are: " << endl << endl;
    i = 1;
    while (i < graph.size()) {display_track(parents, i);
        i++;
    }
}

int main() {
    int vrtcs, edges, i = 0;

    cin >> vrtcs >> edges;

    vector <vector <int>> graph(vrtcs);
    vector <vector <int>> wghts(vrtcs);

    char vertex, nghbour;
    int dstnc;

    while (i < edges) {
        cin >> vertex >> nghbour >> dstnc;
        graph[vertex - 'a'].push_back(nghbour - 'a');
        wghts[vertex - 'a'].push_back(dstnc);

        i++;
    }

    dijkstra(graph, wghts, 0);

    return 0;
}
