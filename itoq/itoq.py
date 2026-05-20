import networkx as nx

def build(n, edges):
    graph = [[] for _ in range(n)]
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)
    return graph

def proxod(start, n, graph):
    """
    Алгоритм обхода графа в глубину .
    Проверяет, является ли граф связным и нет ли в нем циклов.
    """
    stack = [(start, -1)]
    vis = set([start])
    
    while stack:
        u, parent = stack.pop()
        for x in graph[u]:
            if x != parent:
                if x in vis:
                    # Если пришли в уже посещенную вершину (и это не родитель) — это цикл
                    return False
                vis.add(x)
                stack.append((x, u))
                
    # Если циклов нет, проверяем, обошли ли мы все вершины (связность)
    return len(vis) == n

# --- Основная часть программы ---

trees_count = 0
nx_trees_count = 0

with open("input.txt") as f:
    # 1. Читаем самую первую строку — количество графов
    num_graphs = int(f.readline().strip())
    
    # 2. Запускаем цикл для каждого графа
    for _ in range(num_graphs):
        
        # Читаем строку с вершинами (n) и ребрами (k)
        n, k = map(int, f.readline().split())
        
        edges = []
        # Запускаем внутренний цикл, чтобы считать ровно k рёбер
        for _ in range(k):
            u, v = map(int, f.readline().split())
            edges.append((u, v))
            
        # Строим граф
        graph = build(n, edges)
        
        # --- Проверка нашим алгоритмом ---
        if n > 0 and proxod(0, n, graph):
            trees_count += 1
            
        # --- Проверка библиотекой (для задания) ---
        G = nx.Graph()
        G.add_nodes_from(range(n))
        G.add_edges_from(edges)
        if nx.is_tree(G):
            nx_trees_count += 1

# Вывод результатов в консоль
print("Количество деревьев (наш алгоритм):", trees_count)
print("Количество деревьев (из библиотеки):", nx_trees_count)