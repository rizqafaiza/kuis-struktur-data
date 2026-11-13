
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int jumlahVertex) {
        V = jumlahVertex;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "Hasil BFS: ";

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            cout << char('A' + u) << " ";

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }

        cout << endl;
    }

    void DFS_Proses(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << char('A' + u) << " ";

        for (int v = 0; v < V; v++) {
            if (adjMatrix[u][v] != 0 && !visited[v]) {
                DFS_Proses(v, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(V, false);

        cout << "Hasil DFS: ";
        DFS_Proses(start, visited);
        cout << endl;
    }

    void Dijkstra(int start, int tujuan) {
        vector<int> distance(V, INT_MAX);
        vector<bool> visited(V, false);
        vector<int> parent(V, -1);

        distance[start] = 0;

        for (int i = 0; i < V; i++) {
            int u = -1;

            for (int j = 0; j < V; j++) {
                if (!visited[j] &&
                    (u == -1 || distance[j] < distance[u])) {
                    u = j;
                }
            }

            if (u == -1 || distance[u] == INT_MAX) {
                break;
            }

            visited[u] = true;

            if (u == tujuan) {
                break;
            }

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] != 0 && !visited[v]) {
                    int newDistance =
                        distance[u] + adjMatrix[u][v];

                    if (newDistance < distance[v]) {
                        distance[v] = newDistance;
                        parent[v] = u;
                    }
                }
            }
        }

        if (distance[tujuan] == INT_MAX) {
            cout << "Tidak ada rute yang tersedia.\n";
            return;
        }

        vector<int> path;

        int current = tujuan;

        while (current != -1) {
            path.push_back(current);
            current = parent[current];
        }

        reverse(path.begin(), path.end());

        cout << "\nRute terpendek: ";

        for (int i = 0; i < path.size(); i++) {
            cout << char('A' + path[i]);

            if (i < path.size() - 1) {
                cout << " -> ";
            }
        }

        cout << "\nTotal jarak: "
             << distance[tujuan] << endl;
    }
};

int konversi(char huruf){
    int nilai_angka;
    switch(huruf){
        case 'A':
        case 'a':
            nilai_angka = 0;
            break;
        case 'B':
        case 'b':
            nilai_angka = 1;
            break;
        
        case 'C':
        case 'c':
            nilai_angka = 2;
            break;
        
        case 'D':
        case 'd':
            nilai_angka = 3;
            break;
        
        case 'E':
        case 'e':
            nilai_angka = 4;
            break;
        
        case 'F':
        case 'f':
            nilai_angka = 5;
            break;
        
        default:
            nilai_angka = 6;
            break;
    }

    return nilai_angka;
}

int main() {
    Graph graf(6);

    graf.addEdge(0, 1, 4); 
    graf.addEdge(0, 2, 2); 
    graf.addEdge(1, 2, 1); 
    graf.addEdge(1, 3, 5); 
    graf.addEdge(1, 4, 3); 
    graf.addEdge(2, 3, 8); 
    graf.addEdge(2, 4, 6); 
    graf.addEdge(3, 4, 2); 
    graf.addEdge(3, 5, 4); 
    graf.addEdge(4, 5, 3); 

    char awal, tujuan;
    int start, finish;
    int pilihan;

    do {
        cout << "SISTEM PENCARIAN RUTE KAMPUS\n";
        cout << "1. BFS\n";
        cout << "2. DFS\n";
        cout << "3. Dijkstra\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 3) {
            cout << "Masukkan vertex awal (A-F): ";
            cin >> awal;

            start = konversi(awal);

            if (start == -1) {
                cout << "Vertex awal tidak valid!\n";
                continue;
            }
        }

        switch (pilihan) {
            case 1:
                graf.BFS(start);
                break;

            case 2:
                graf.DFS(start);
                break;

            case 3:
                cout << "Masukkan vertex tujuan (A-F): ";
                cin >> tujuan;

                finish = konversi(tujuan);

                if (finish == -1) {
                    cout << "Vertex tujuan tidak valid!\n";
                    break;
                }

                graf.Dijkstra(start, finish);
                break;

            case 0:
                cout << "Program selesai.\n";
                break;

            default:
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 0);
}