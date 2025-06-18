
# Instrucciones de ejecución — Tarea 2 Kruskal

## 🧱 Requisitos

- Compilador C++ con soporte para C++17 (g++ recomendado)
- Sistema operativo compatible (Linux, macOS o Windows con WSL)

## ⚙️ Compilación

Para compilar el programa:

```bash
g++ -std=c++17 main.cpp kruskal.cpp utils.cpp -o kruskal
```

## 🚀 Ejecución

Una vez compilado, ejecuta el programa con:

```bash
./kruskal
```

Esto imprimirá los tiempos promedio para una de las variantes del algoritmo de Kruskal, según lo definido en `main.cpp`.

---

## 🔄 Cambiar variante del algoritmo

Para probar las distintas versiones del algoritmo, **modifica la siguiente línea en `main.cpp`**:

```cpp
auto mst = kruskal_sorted(false, edges, n); // variante actual
```

Reemplázala por una de las siguientes según la variante que desees evaluar:

| Variante                     | Código a usar |
|-----------------------------|---------------|
| Sorted + optimización       | `kruskal_sorted(true, edges, n);`  |
| Sorted sin optimización     | `kruskal_sorted(false, edges, n);` |
| Heap + optimización         | `kruskal_heap(true, edges, n);`    |
| Heap sin optimización       | `kruskal_heap(false, edges, n);`   |

Luego recompila y ejecuta nuevamente.

---

## 🧹 Notas

- El programa corre 5 veces cada experimento para promediar los tiempos.
- La limpieza de memoria entre pruebas está incorporada.
- Los tamaños evaluados van desde 32 hasta 4096 nodos por defecto.
