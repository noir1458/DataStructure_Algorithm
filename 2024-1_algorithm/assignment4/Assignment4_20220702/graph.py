import sys

def insert(heap, pos, key, value):
    heap.append((key, value))
    pos[value] = len(heap) - 1
    decrease_key(heap, pos, value, key)

def decrease_key(heap, pos, value, key):
    i = pos[value]
    heap[i] = (key, value)
    while i > 0 and heap[(i - 1) // 2][0] > heap[i][0]:
        pos[heap[i][1]] = (i - 1) // 2
        pos[heap[(i - 1) // 2][1]] = i
        heap[i], heap[(i - 1) // 2] = heap[(i - 1) // 2], heap[i]
        i = (i - 1) // 2

def extract_min(heap, pos):
    if not heap:
        return None
    root = heap[0]
    last = heap.pop()
    if heap:
        heap[0] = last
        pos[last[1]] = 0
        min_heapify(heap, pos, 0)
    del pos[root[1]]
    return root

def min_heapify(heap, pos, i):
    smallest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < len(heap) and heap[left][0] < heap[smallest][0]:
        smallest = left

    if right < len(heap) and heap[right][0] < heap[smallest][0]:
        smallest = right

    if smallest != i:
        pos[heap[smallest][1]] = i
        pos[heap[i][1]] = smallest
        heap[i], heap[smallest] = heap[smallest], heap[i]
        min_heapify(heap, pos, smallest)

def MST_Prim(graph, start_vertex):
    num_vertices = len(graph)
    key = [float('inf')] * num_vertices
    parent = [None] * num_vertices
    key[start_vertex] = 0
    heap = []
    pos = {}

    for v in range(num_vertices):
        insert(heap, pos, key[v], v)

    while heap:
        _, u = extract_min(heap, pos)
        for v, weight in graph[u]:
            if v in pos and weight < key[v]:
                key[v] = weight
                parent[v] = u
                decrease_key(heap, pos, v, key[v])

    return parent

def Floyd_warshall(graph, num_vertices):
    # Initialize distance and next_vertex matrices
    dist = [[float('inf')] * num_vertices for _ in range(num_vertices)]
    next_vertex = [[None] * num_vertices for _ in range(num_vertices)]

    # Set initial distances and next vertices
    for u in range(num_vertices):
        for v, weight in graph[u]:
            dist[u][v] = weight
            next_vertex[u][v] = u
        dist[u][u] = 0
        next_vertex[u][u] = None

    # Floyd-Warshall algorithm
    for k in range(num_vertices):
        for i in range(num_vertices):
            for j in range(num_vertices):
                if dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
                    next_vertex[i][j] = next_vertex[k][j]

    # Replace None with 'NIL' for proper formatting
    for i in range(num_vertices):
        for j in range(num_vertices):
            if next_vertex[i][j] is None:
                next_vertex[i][j] = 'NIL'
            else:
                next_vertex[i][j] = next_vertex[i][j] + 1

    return dist, next_vertex

def main():
    # Read undirected graph (Prim's algorithm)
    with open(sys.argv[1], 'r') as undirected_graph:
        num_vertices, num_edges, start_vertex = map(int, undirected_graph.readline().strip().split())
        graph_prim = {i: [] for i in range(num_vertices)}
        for _ in range(num_edges):
            u, v, weight = undirected_graph.readline().strip().split()
            u = int(u)
            v = int(v)
            weight = int(weight)
            graph_prim[u].append((v, weight))
            graph_prim[v].append((u, weight))

    # Execute Prim's algorithm
    parent = MST_Prim(graph_prim, start_vertex)
    
    # Save Prim's algorithm results to file
    with open(sys.argv[3], 'w') as Prim_output:
        for vertex in range(num_vertices):
            if vertex != num_vertices-1:
                Prim_output.write(f"{vertex}\t{parent[vertex] if parent[vertex] is not None else 'NIL'}\n")
            else:
                Prim_output.write(f"{vertex}\t{parent[vertex] if parent[vertex] is not None else 'NIL'}")

    # Read directed graph (Floyd-Warshall algorithm)
    with open(sys.argv[2], 'r') as directed_graph:
        num_vertices = int(directed_graph.readline().strip())
        graph_fw = [[] for _ in range(num_vertices)]
        for i in range(num_vertices):
            row = directed_graph.readline().strip().split()
            for j in range(num_vertices):
                if row[j] != 'INF':
                    graph_fw[i].append((j, int(row[j])))
                else:
                    graph_fw[i].append((j, float('inf')))

    # Execute Floyd-Warshall algorithm
    dist, next_vertex = Floyd_warshall(graph_fw, num_vertices)

    # Save Floyd-Warshall algorithm results to file
    with open(sys.argv[4], 'w') as Floyd_output:
        Floyd_output.write("D\t" + str(num_vertices) + "\n")
        for row in dist:
            Floyd_output.write("\t".join(map(str, row)).replace('inf', 'INF') + "\n")
        
        Floyd_output.write("P\t" + str(num_vertices) + "\n")
        for i in range(len(next_vertex)):
            if i != len(next_vertex)-1:
                Floyd_output.write("\t".join(map(str, next_vertex[i])) + "\n")
            else:
                Floyd_output.write("\t".join(map(str, next_vertex[i])))

if __name__ == '__main__':
    main()
