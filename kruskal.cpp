#include "kruskal.hpp"
#include "union_find.hpp"
#include <algorithm>
#include <queue>

std::vector<Edge> kruskal_sorted(bool use_path_compression, const std::vector<Edge>& edges, int n) {
    std::vector<Edge> mst;
    UnionFind uf(n, use_path_compression);

    std::vector<Edge> sorted_edges = edges;
    std::sort(sorted_edges.begin(), sorted_edges.end());

    for (const auto& e : sorted_edges) {
        if (uf.find(e.u) != uf.find(e.v)) {
            mst.push_back(e);
            uf.unite(e.u, e.v);
            if ((int)mst.size() == n - 1) break;
        }
    }
    return mst;
}

std::vector<Edge> kruskal_heap(bool use_path_compression, const std::vector<Edge>& edges, int n) {
    std::vector<Edge> mst;
    UnionFind uf(n, use_path_compression);

    auto cmp = [](const Edge& a, const Edge& b) { return a.weight > b.weight; };
    std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> pq(cmp, edges);

    while (!pq.empty() && (int)mst.size() < n - 1) {
        Edge e = pq.top(); pq.pop();
        if (uf.find(e.u) != uf.find(e.v)) {
            mst.push_back(e);
            uf.unite(e.u, e.v);
        }
    }
    return mst;
}
