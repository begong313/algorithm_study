import sys
sys.stdin.readline

N = int(input())
graph = {}

A, B = map(int, input().split())
origin = set([])
origin_size = len(origin)
result = {} # dict
while A != -1:
    A, B = map(int, input().split())
    if A not in graph:
        graph[A] = [B]
    else:
        graph[A].append(B)
        origin.add(A)


from collections import deque
def bfs(start_node, graph):
    global origin_set
    global result
    
    queue = deque([start_node])
    visited = set([start_node])
    dimension = 0
    dimension_size = len(graph[start_node])
    
    while queue:
        cur_node = queue.popleft()
        dimension_size -= 1
        
        if dimension_size == 0:
            dimension_size = graph
        
        for next_node in graph[cur_node]:
            if next_node not in visited:
                visited.add(next_node)
                queue.append(next_node)
            
            if len(visited) == origin_size:
                return dimension