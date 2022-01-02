#include <iostream>

using namespace std;

int maxf = 1000000000;
bool S[50];  // Mảng chứa các đỉnh 
int D[50];   // Mảng lưu trọng số đường đi đến các đỉnh    
int trace[50]; // mảng lưu vết  

class Graph {
private:
    int** adjMatrix;
    int numVertices;
    
public:
    // khởi tạo ma trận có tất cả phần tử bằng 0
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = 0;
        }
    }
    // thêm đỉnh
    void add_edge(int u, int v, int wt);
    // in ra ma trận 
    void Print_matrix();

    int min_distance();
    // in ra đường đi ngắn nhất
    void printPath(int trace[], int vertex_end);
    void print_solution(int vertex_start, int vertex_end);

    // Thuật toán tìm đường đi ngắn nhất từ đỉnh start đến đỉnh end
    void Find_shortest_path(int vertex_start, int vertex_end);
    
    ~Graph() {
        for (int i = 0; i < numVertices; i++)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

void Graph::add_edge(int u, int v,int wt) {
    adjMatrix[u][v] = wt;
}

void Graph::Print_matrix() 
{
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++)
            cout << adjMatrix[i][j] << " ";
        cout << "\n";
    }
}

int Graph::min_distance()
{
    // cài đặt giá trị min
    int min = maxf;
    int min_index;

    for (int v = 0; v < numVertices; v++)
    {
        if (S[v] == false && D[v] <= min)
        {
            min = D[v];
            min_index = v;
        }
    }

    return min_index;
}

void Graph::printPath(int trace[] ,int vertex_end)
{
    if (trace[vertex_end] == -1)
        return;

    printPath(trace, trace[vertex_end]);
    cout << vertex_end <<" ";
}

void Graph::print_solution(int vertex_start, int vertex_end)
{
    cout << "Khoang cach\tduong di\n";
    cout << D[vertex_end] << "\t\t" << vertex_start << " ";
    
    printPath(trace, vertex_end);
}

void Graph::Find_shortest_path(int vertex_start,int vertex_end)
{
    for (int i = 0; i < numVertices; i++)
    {
        trace[0] = -1;
        D[i] = maxf;
        S[i] = false;
    }
 
    // khởi tạo khoảng cách đỉnh bắt đầu là 0
    D[vertex_start] = 0;

    // Tìm đường đi ngắn nhất, duyệt qua tất cả các đỉnh
    for (int count = 0; count < numVertices - 1; count++)
    {
        // chọn một đỉnh có khoảng cách nhỏ nhất từ mảng D[] 
        int u = min_distance();

        // đánh dấu đỉnh đã chọn
        S[u] = true;

        // cập nhật giá trị D[] (khoảng cách ngắn nhất qua các đỉnh)
        for (int v = 0; v < numVertices; v++)
        {
            if (!S[v] && adjMatrix[u][v] && D[v] > D[u] + adjMatrix[u][v])
            {
                D[v] = D[u] + adjMatrix[u][v];
                trace[v] = u;
            }
        }
    }
    // in ra khoảng cách ngắn nhất và đường đi 
    print_solution(vertex_start, vertex_end);
}

int main()
{
    Graph graph(5);

    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 2, 9);
    graph.add_edge(1, 2, 2);
    graph.add_edge(1, 4, 8);
    graph.add_edge(2, 3, 2);
    graph.add_edge(3, 4, 3);

    graph.Print_matrix();

    int start, end;
    cout << "Nhap vao dinh bat dau va ket thuc: ";
    cin >> start>> end;

    graph.Find_shortest_path(start, end);

    return 0;
}