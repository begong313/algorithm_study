N = int(input())

num_list = []

for _ in range(N):
    M = int(input())
    num_list.append(M)

result = 0
count = 0
height = 0

for _ in range(len(num_list)-1, -1, -1):
    if num_list[_] > height:
        height = num_list[_]
        result += count
        count = 1
    else:
        height = num_list[_]
        count += 1

print(result)