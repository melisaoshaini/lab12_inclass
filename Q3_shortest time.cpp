#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // pair of (distance, node)

vector<int> dijkstra(vector<vector<int>>& graph, int source) {
    int n = graph.size();
    vector<int> distances(n, INT_MAX);
    distances[source] = 0;
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (dist > distances[node])
            continue;
        
        for (int i = 0; i < n; i++) {
            int neighbor = i;
            int weight = graph[node][neighbor];
            
            if (weight > 0 && dist + weight < distances[neighbor]) {
                distances[neighbor] = dist + weight;
                pq.push({dist + weight, neighbor});
            }
        }
    }
    
    return distances;
}

void printShortestDistances(vector<vector<int>>& graph) {
    int n = graph.size();
    
    for (int source = 0; source < n; source++) {
        vector<int> shortest_distances = dijkstra(graph, source);
        
        cout << "Source City: " << source << endl;
        cout << "Shortest Distances from Source City:" << endl;
        for (int i = 0; i < shortest_distances.size(); i++) {
            cout << "City " << i << ": " << shortest_distances[i] << endl;
        }
        
        cout << endl;
    }
}

int main() {
    // Adjacency matrix representation of the graph
    vector<vector<int>> adjacency_matrix = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };
    
    printShortestDistances(adjacency_matrix);
    
    return 0;
}
