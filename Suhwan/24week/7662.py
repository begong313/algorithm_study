import heapq

T = int(input())

for _ in range(T):
    queue = []

    K = int(input())
    for __ in range(K):
        command = list(map(str, input().split()))
        command0 = command[0]
        command1 = int(command[1])
        
        if command0 == "I":
            heapq.heappush(queue, command1)
        else: 
            if command1 == 1:
                if queue:
                    queue.pop()
            else:
                if queue:
                    heapq.heappop(queue)
    
    if len(queue) == 0:
        print("EMPTY")
    else:
        # 최댓값
        print(queue.pop(), end=" ")
        # 최솟값
        print(heapq.heappop(queue))
        
        
# 시간초과이긴한데 이거 왜 Max heap 이랑 min heap 따로 만듬? 이해가안되네