import sys

line = str(input())

opend = 1
result = 0

for idx in range(1, len(line)):
    
    # 레이저 
    if line[idx-1] == "(" and line[idx] == ")":
        result += opend - 1
        opend -= 1
        
    # 막대
    else:
        # 막대 시작
        if line[idx] == "(":
            opend += 1
        # 막대 끝
        else:
            opend -= 1
            result += 1
            
print(result)