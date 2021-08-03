def breadth_first_search(grph: list, source: int):
    queue = []
    distance = [-1] * len(grph)

    distance[source] = 0
    queue.append(source)

    while len(queue) != 0:
        vertex = queue[0]
        queue.pop(0)

        i = 0
        while i < len(grph[vertex]):
            connected_vertex = grph[vertex][i]

            if connected_vertex >= len(distance):
                distance = [-1] * (connected_vertex + 1)

            if distance[connected_vertex] == -1:
                distance[connected_vertex] = 1 + distance[vertex]
                queue.append(connected_vertex)

            i += 1

    return distance


if __name__ == '__main__':

    vertices, edges = map(int, input().split())

    rows = vertices + 1

    graph = [[] for i in range(rows)]

    i = 0
    while i < edges:
        vertex, connected_vertex = map(int, input().split())
        graph[vertex].append(connected_vertex)

        if vertex != connected_vertex:
            graph[connected_vertex].append(vertex)
        i += 1

    distances = breadth_first_search(grph=graph, source=1)

    farthest_vertex = max(distances)

    print(farthest_vertex)
