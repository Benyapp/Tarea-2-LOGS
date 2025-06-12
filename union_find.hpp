#pragma once
#include <vector>

struct UnionFind {
    std::vector<int> parent, size;
    bool path_compression;

    UnionFind(int n, bool opt) : parent(n), size(n, 1), path_compression(opt) {
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int x) {
        if (path_compression) {
            if (x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
        } else {
            while (x != parent[x]) x = parent[x];
            return x;
        }
    }

    void unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return;
        if (size[rx] < size[ry]) std::swap(rx, ry);
        parent[ry] = rx;
        size[rx] += size[ry];
    }
};
