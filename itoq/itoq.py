import networkx as nx

def build(n, edges):
    graph = [[] for _ in range(n)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    return graph

def proxod(start, n, graph):
    """
    обход в глубину .
    Проверка на связаность и циклы
    """
    stack = [(start, -1)]
    vis = set([start])
    
    while stack:
        u, parent = stack.pop()
        for x in graph[u]:
            if x != parent:
                if x in vis:
                    return False
                vis.add(x)
                stack.append((x, u))
                
    return len(vis) == n

trees_count = 0
nx_trees_count = 0

with open("input.txt") as f:
    num_graphs = int(f.readline().strip())
    
    for _ in range(num_graphs):
             
        n, k = map(int, f.readline().split())
        
        edges = []
        for _ in range(k):
            u, v = map(int, f.readline().split())
            edges.append((u, v))
            
        graph = build(n, edges)
        if n > 0 and proxod(0, n, graph):
            trees_count += 1

        G = nx.Graph()
        G.add_nodes_from(range(n))
        G.add_edges_from(edges)
        if nx.is_tree(G):
            nx_trees_count += 1

print("Кол-во деревьев алгоритм:", trees_count)
print("Кол-во деревьев  библиотекф:", nx_trees_count)