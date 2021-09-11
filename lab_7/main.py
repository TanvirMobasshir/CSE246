import json


class Element(object):
    def __init__(self, v: int, d: int):
        self.vertex = v
        self.distance = d

    def __lt__(self, other):
        return self.distance < other.distance

    def __gt__(self, other):
        return self.distance > other.distance


priority_list = []


def print_paths(parents: list, location: int):
    target = chr(location + ord('a'))
    path = []

    while location != 0:
        path.append(location)
        location = parents[location]

    print(f"Path from 'a' to '{target}' : a->", end='')
    while len(path) != 0:
        current_path = chr(ord('a') + path[-1])
        path.pop()

        print(current_path if len(path) == 0 else current_path + '->', end='')

    print()


def print_distances(distances, source):
    source_letter = chr(ord('a') + source)
    print(f"Vertex \t Distance '{source_letter}' ")

    for i in range(len(distances)):
        vertex = chr(ord('a') + i)
        print(f"{vertex} \t\t {distances[i]}")
    print()


def dijkstra(graph, weights, source):
    distances = [2147483647] * len(graph)
    visited = [False] * len(graph)
    parents = [-1] * len(graph)

    distances[source] = 0

    priority_list.append(Element(source, 0))

    while len(priority_list != 0):
        vertex = priority_list[-1].vertex
        priority_list.pop()

        if visited[vertex]:
            continue

        visited[vertex] = True

        for i in range(len(graph[vertex])):
            neighbour = graph[vertex][i]
            distance = weights[vertex][i]

            if distances[vertex] + distance < distances[neighbour]:
                parents[neighbour] = vertex
                distances[neighbour] = distances[vertex] + distance
                priority_list.append(Element(neighbour, distances[neighbour]))

    print_distances(distances=distances, source=source)

    for i in range(len(graph)):
        print_paths(parents=parents, location=i)


if __name__ == '__main__':
    verticies, edges = list(map(int, input().split()))

    graph = []
    for i in graph:
        i.append(None)
