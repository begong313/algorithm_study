import sys

N = int(input())
num = list(map(int, sys.stdin.readline().split()))
num.sort()
num_length = len(num)
front_idx = 0
back_idx = num_length-1
sum_x = None
sum_list = []


while front_idx != back_idx:
    x = num[front_idx] + num[back_idx]
    
    if x == 0:
        if len(sum_list) == 2:
            sum_list[0] = num[front_idx]
            sum_list[1] = num[back_idx]
        else: 
            sum_list.append(num[front_idx])
            sum_list.append(num[back_idx])
        break 
    
    if not(sum_x):
        sum_x = x 
        sum_list.append(num[front_idx])
        sum_list.append(num[back_idx])
    else:   
        if abs(x) < abs(sum_x):
            sum_x = x 
            if len(sum_list) == 2:
                sum_list[0] = num[front_idx]
                sum_list[1] = num[back_idx]
            else:
                sum_list.append(num[front_idx])
                sum_list.append(num[back_idx])
                
        if x > 0:
            back_idx -= 1
        else: 
            front_idx += 1
                
print(f"{sum_list[0]} {sum_list[1]}")
                