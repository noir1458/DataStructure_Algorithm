#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define _CRT_SECURE_NO_WARNINGS

#define V 16
#define E 24

//특정 원소가 속한 집합을 찾는 find함수
int find(int parent[], int i) {
    if (parent[i] != i)
        parent[i] = find(parent, parent[i]);
    return parent[i]; //재귀적으로 parent를 찾아가 최상위 노드를 찾고 반환
}

//두 집합 합치는 Union
// 사실 어느쪽에 합치든 상관은 없으나 유니온 파인드 자료구조에서는 랭크를 기준으로 트리를 병합한다
// 트리의 높이를 줄일 수 있고, find 연산의 평균 시간복잡도를 줄일 수 있다.
void Union(int parent[], int rank[], int x, int y) {
    int root1 = find(parent, x);
    int root2 = find(parent, y);

    if (rank[root1] < rank[root2]) {
        parent[root1] = root2;
    }
    else if (rank[root1] > rank[root2]) {
        parent[root2] = root1;
    }
    else {
        parent[root2] = root1;
        rank[root1]++;
    }
}


//compare - qsort
int compare(const void* a, const void* b) {
    int* edgeA = (int*)a;
    int* edgeB = (int*)b;
    if (edgeA[2] > edgeB[2])
        return 1;
    else if (edgeA[2] < edgeB[2])
        return -1;
    else
        return 0;
}

// 1. kruskal_MST
/*
간선을 가중치 기준 정렬
가중치가 가장 작은 간선부터 선택
유니온파인드 자료구조를 이용하여 간선 추가시 사이클이 생기나 확인
사이클이 안 생기는경우에 간선을 MST에 추가, MST 완성될때까지 반복
*/
void kruskal_MST(int input_graph_list[E][3]) {
    int edges[E][3];
    for (int i = 0; i < E; i++) {
        edges[i][0] = input_graph_list[i][0] - 1;
        edges[i][1] = input_graph_list[i][1] - 1;
        edges[i][2] = input_graph_list[i][2];
    }

    qsort(edges, E, sizeof(edges[0]), compare);

    int parent[V]; // parent는 초기에 자신을 부모로 갖도록 초기화됨
    int rank[V];
    for (int v = 0; v < V; v++) {
        parent[v] = v;
        rank[v] = 0;
    }

    int MST[V - 1][3]; //MST에는 V-1개의 간선이 포함된다
    int e = 0; //mst의 간선 수
    int i = 0; //정렬된 간선 배열의 인덱스

    while (e < V-1 && i < E){ // mst는 V-1개의 간선을 가져야 하고, 모든 간선을 처리할때까지 반복
        int* edge = edges[i]; // 이미 배열이 가중치 기준으로 정렬되어 있으므로, 작은 가중치 간선부터 선택하여 처리
        i++;
        int x = find(parent, edge[0]); // x,y는 루트 노드
        int y = find(parent, edge[1]);

        if (x != y) { //루트노드가 다른 경우 간선을 mst에 추가해도 사이클이 생기지 않는다
            MST[e][0] = edge[0]; // 간선을 mst에 추가
            MST[e][1] = edge[1];
            MST[e][2] = edge[2];
            e++;
            Union(parent, rank, x, y); //union함수를 사용하여 두 집합을 합친다
        }

    }
    for (i = 0; i < e; i++)
        printf("[%d] - [%d], weight:%d \n", MST[i][0] + 1, MST[i][1] + 1, MST[i][2]);

}

//2. dijkstra - Shortest Path from Node 1
void dijkstra(int graph_matrix[V][V], int src) {
    int d[V]; // 출발점에서 각 정점까지의 최단 거리 배열, 초기값 무한대
    int p[V]; // 각 정점의 이전 정점 배열, 초기값 -1
    int sptSet[V]; // 최단 경로 트리에 포함된 정점 집합

    for (int i = 0; i < V; i++) {
        d[i] = INT_MAX;
        p[i] = -1;
        sptSet[i] = 0;
    }

    d[src] = 0; // 출발점의 거리는 0

    //모든 정점에 대해서 최단경로 찾기
    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
            if (sptSet[v] == 0 && d[v] < min) { // 아직 최단 경로 트리에 포함되지 않은 정점 중에서 최단 거리를 가지는 정점 선택
                min = d[v];
                min_index = v;
            }
        int u = min_index; //최소 거리 정점
        sptSet[u] = 1; //선택된 정점을 최단 경로 트리에 포함

        //선택된 정점의 인접 정점의 거리 값 갱신
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph_matrix[u][v] && d[u] != INT_MAX && d[u] + graph_matrix[u][v] < d[v]) {
                d[v] = d[u] + graph_matrix[u][v];
                p[v] = u; // 이전 정점을 현재 정점으로 설정
            }
    }
    printf("vertex\tdistance\tpath\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\t\t", i + 1, d[i]);
        // 경로 출력
        int path[V];
        int count = 0;
        for (int v = i; v != -1; v = p[v])
            path[count++] = v;
        for (int j = count - 1; j >= 0; j--)
            printf("%d ", path[j] + 1);
        printf("\n");
    }
}


//input받은 인접 리스트를 인접 행렬로 변환하여 사용하기
void convert_list_to_matrix(int input_graph_list[E][3], int graph_matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            graph_matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < E; i++) {
        int node1 = input_graph_list[i][0] - 1;
        int node2 = input_graph_list[i][1] - 1;
        int weight = input_graph_list[i][2];

        graph_matrix[node1][node2] = weight;
        graph_matrix[node2][node1] = weight;
    }

}

// 인접행렬 출력함수
void printMatrix(int graph_matrix[V][V]) {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%d ", graph_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // node1,node2,weight 순서, 총 24개 edge
    int input_graph_list[E][3] = {
        {1,2,3},{2,3,1},{3,4,4},
        {1,5,2},{2,6,5},{3,7,1},{4,8,6},
        {5,6,1},{6,7,5},{7,8,8},
        {5,9,3},{6,10,4},{7,11,2},{8,12,6},
        {9,10,2},{10,11,4},{11,12,6},
        {9,13,2},{10,14,6},{11,15,4},{12,16,4},
        {13,14,3},{14,15,5},{15,16,7}
    };

    int graph_matrix[V][V];
    convert_list_to_matrix(input_graph_list,graph_matrix);

    printMatrix(graph_matrix);


    printf("\n");
    printf("1. Kruskal - MST\n");
    kruskal_MST(input_graph_list); // 인접리스트를 사용한다


    printf("\n");
    printf("2. dijkstra - Shortest Path from Node 1\n");
    dijkstra(graph_matrix, 0); // 인접 배열을 사용한다

    getchar();
    return 0;
}