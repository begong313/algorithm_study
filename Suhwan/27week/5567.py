from collections import deque
import sys
sys.stdin.readline

def bfs(start_node, graph, friend, result):
    queue = deque([start_node])
    visited = set([start_node])
    
    while queue:
        cur_node = queue.popleft()
        
        # cur_node가 graph에 존재하는지 확인
        if cur_node not in graph:
            continue
        
        for next_node in graph[cur_node]:
            if next_node not in visited and (next_node in friend or cur_node in friend):
                visited.add(next_node)
                result.append(next_node)
                queue.append(next_node)
    return -1

N = int(input())
M = int(input())

graph = {}
friend = [] 

for i in range(M):
    A, B = map(int, input().split())
    if A in graph: 
        graph[A].append(B)
    else:
        graph[A] = [B]
    
    # 양방향 그래프일 경우, B에서 A로의 연결도 추가해야 함
    if B in graph:
        graph[B].append(A)
    else:
        graph[B] = [A]
    
    # 1 3 -> 3
    # 3 1 -> 3 
    if A == 1:
        friend.append(B)
    elif B == 1:
        friend.append(A)

result = []
if len(friend) == 0:
    print("0")
else:
    bfs(1, graph=graph, friend=friend, result=result)
    print(len(result))