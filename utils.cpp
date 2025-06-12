#include "utils.hpp"

std::vector<Point> generate_random_points(int n) {
    std::vector<Point> points(n);
    for (auto& p : points) {
        p.x = (double)rand() / RAND_MAX;
        p.y = (double)rand() / RAND_MAX;
    }
    return points;
}

std::vector<Edge> compute_all_edges(const std::vector<Point>& points) {
    std::vector<Edge> edges;
    int n = points.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            double dx = points[i].x - points[j].x;
            double dy = points[i].y - points[j].y;
            double weight = dx * dx + dy * dy;
            edges.push_back({i, j, weight});
        }
    return edges;
}
