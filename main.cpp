#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include "kruskal.hpp"
#include "utils.hpp"

int main() {
    std::cout << "Inicio de ejecución\n";
    std::srand(time(NULL));
    std::vector<int> sizes = {32, 64, 128, 256, 512, 1024, 2048, 4096};

    for (int n : sizes) {
        double total_time = 0.0;
        for (int trial = 0; trial < 5; ++trial) {
            auto points = generate_random_points(n);
            auto edges = compute_all_edges(points);

            auto start = std::chrono::high_resolution_clock::now();
            auto mst = kruskal_sorted(false, edges, n);  // prueba una variante
            auto end = std::chrono::high_resolution_clock::now();

            total_time += std::chrono::duration<double>(end - start).count();
            std::vector<Point>().swap(points);
            std::vector<Edge>().swap(edges);
            std::vector<Edge>().swap(mst);
            
        }
        ;
        std::cout << "n = " << n << ", tiempo promedio = " << total_time / 5 << " s" << std::endl;
    }

    return 0;
}
