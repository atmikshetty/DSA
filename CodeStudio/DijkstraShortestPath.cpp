#include <bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges,
                     int source) {
  //  Dijkstra's shortest path using Priority Queue

  // creating an unordered map of vec for easy access
  unordered_map<int, list<pair<int, int>>> adj;
  for (int i = 0; i < edges; i++) {
    int u = vec[i][0];
    int v = vec[i][1];
    int w = vec[i][2];

    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }

  // Create a priority queue
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  vector<int> dist(vertices);
  for (int i = 0; i < vertices; i++) {
    dist[i] = INT_MAX;
  }
  dist[source] = 0;
  pq.push({0, source});

  // Iterate over the queue and find the shortest path
  while (!pq.empty()) {
    int dis = pq.top().first;   // weight is stored first
    int node = pq.top().second; // node is stored second
    pq.pop();

    for (auto it : adj[node]) { // traversing all the adjacent nodes
      int adjNode = it.first;
      int weight = it.second;

      if (dis + weight < dist[adjNode]) {
        dist[adjNode] = dis + weight;
        pq.push({dist[adjNode], adjNode});
      }
    }
  }
  return dist;
}
