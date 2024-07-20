import heapq

# N개로 유지하는 건 알았는데, 계속 sort해야하나? 이게 좀 고민이라
# 우선순위큐 쓰는 법 몰라서 풀이 봤음..
N = int(input())
hq = []

for _ in range(N):
    num_list = map(int, input().split())
    
    for __ in num_list:
        if len(hq) < N:
            heapq.heappush(hq, __)
        else:
            if hq[0] < __:
                heapq.heappop(hq)
                heapq.heappush(hq, __)
print(hq[0])