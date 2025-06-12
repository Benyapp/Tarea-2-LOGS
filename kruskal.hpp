#pragma once
#include <vector>
#include "utils.hpp"

std::vector<Edge> kruskal_sorted(bool use_path_compression, const std::vector<Edge>& edges, int n);
std::vector<Edge> kruskal_heap(bool use_path_compression, const std::vector<Edge>& edges, int n);
