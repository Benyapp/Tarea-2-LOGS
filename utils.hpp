#pragma once
#include <vector>
#include <cstdlib>
#include <cmath>

struct Point {
    double x, y;
};

struct Edge {
    int u, v;
    double weight;

    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

std::vector<Point> generate_random_points(int n);
std::vector<Edge> compute_all_edges(const std::vector<Point>& points);
