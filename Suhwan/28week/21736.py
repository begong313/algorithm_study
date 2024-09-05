import sys

sys.stdin.readline

N, M = map(int, input().split())

graph = []
where_row, where_col = 0, 0
for i in range(N):
    line = input()
    d = []
    
    for k in range(len(line)):
        d.append(line[k])
        if line[k] == 'I':
            where_row, where_col = i, k
    graph.append(d)
    
    
from collections import deque

def bfs(start_row, start_col, graph):
    result = 0
    queue = deque([(start_row, start_col)])
    visited = set([(start_row, start_col)])
    rows, cols = len(graph), len(graph[0])
    
    dx = [0,0,-1,1]
    dy = [1,-1,0,0]
    
    while queue:
        row, col = queue.popleft()
        
        for i in range(4):
            next_row = row+dx[i]
            next_col = col+dy[i]
            if 0<= next_row < rows and 0<= next_col < cols:
                if (next_row, next_col) not in visited:
                    if graph[next_row][next_col] != 'X':
                        visited.add((next_row, next_col))
                        queue.append((next_row, next_col))
                        
                        if graph[next_row][next_col] == 'P':
                            result += 1
    return result
                    
result = bfs(where_row, where_col, graph)          
                    

if result != 0:
    print(result)
else:
    print("TT")