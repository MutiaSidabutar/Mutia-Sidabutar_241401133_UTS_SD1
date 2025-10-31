#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    char to;
    int weight;
};

map<char, vector<Edge>> graph;

map<char, string> tempat = {
    {'A', "Ikan Bakar Pak Harry"},
    {'B', "Gudang Kaleng Bekas"},
    {'C', "Sushi Kucing Alya"},
    {'D', "Kedai IKLC"},
    {'E', "Pasar Ikan Tengah Malam"}
};

void dfs(char node, map<char, bool> &visited) {
    cout << node;
    visited[node] = true;

    for (auto &e : graph[node]) {
        if (!visited[e.to]) {
            cout << " -> ";
            dfs(e.to, visited);
        }
    }
}

void dijkstra(char start, char goal) {
    map<char, int> dist;
    map<char, char> parent;

    for (auto &g : graph) dist[g.first] = INT_MAX;
    dist[start] = 0;

    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        char u = pq.top().second;
        pq.pop();

        if (u == goal) break;

        for (auto &e : graph[u]) {
            int newDist = d + e.weight;
            if (newDist < dist[e.to]) {
                dist[e.to] = newDist;
                parent[e.to] = u;
                pq.push({newDist, e.to});
            }
        }
    }

    vector<char> path;
    for (char at = goal; at != start; at = parent[at])
        path.push_back(at);
    path.push_back(start);
    reverse(path.begin(), path.end());

    cout << "\n\nJALUR TERCEPAT PARUL (Dijkstra(BFS)):\n";
    for (int i = 0; i < path.size(); i++) {
        cout << tempat[path[i]] << " (" << path[i] << ")";
        if (i != path.size() - 1) {
            int jarak = 0;
            for (auto &e : graph[path[i]]) {
                if (e.to == path[i+1]) {
                    jarak = e.weight;
                    break;
                }
            }
            cout << "\n" << jarak << "m\n";
        }
    }

    cout << "\n\nJalur terpendek: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i];
        if (i != path.size() - 1) cout << " -> ";
    }

    cout << "\nTotal jarak: " << dist[goal] << " meter\n";
}

int main() {
    
    graph['A'] = {{'C', 2}, {'B', 5}};
    graph['B'] = {{'A', 5}, {'D', 4}};
    graph['C'] = {{'A', 2}, {'D', 1}};
    graph['D'] = {{'B', 4}, {'C', 1}, {'E', 3}};
    graph['E'] = {{'D', 3}};

    cout << "PENJELAJAHAN PARUL (DFS dari A): ";
    map<char, bool> visited;
    dfs('A', visited);

    dijkstra('A', 'E');

    return 0;
}

