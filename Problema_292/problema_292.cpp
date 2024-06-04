#include <climits>
#include <iostream>
#include <queue>
#include <vector>

// Function to implement Dijkstra's algorithm
void dijkstra(std::vector<std::vector<std::pair<int, int>>> &graph, int source) {
    // graph is a vector of vectors of pairs, each vector of pairs represents a node and
    // its neighbors, each pair represents a neighbor and the weight of the edge
    int n = graph.size();
    std::vector<int> dist(n, INT_MAX);
    std::vector<bool> visited(n, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        for (auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances from the source
    for (int i = 0; i < n; i++) {
        std::cout << "Shortest distance from source to node " << i << ": " << dist[i]
                  << std::endl;
    }
}

int main() {
    // Example usage
    int n = 5; // Number of nodes
    std::vector<std::vector<std::pair<int, int>>> graph(n);

    // Add edges to the graph
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({3, 3});
    graph[3].push_back({4, 2});

    int source = 0; // Source node

    dijkstra(graph, source);

    return 0;
}
