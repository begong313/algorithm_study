N, M = map(int, input().split())
weeks = M // 7 
_dict = {}

# 여기는 그냥 전처리?? 그런 느낌
for _ in range(N):
    line = list(map(str, input().split()))
    name = line[0]
    day = line[1]
    start = line[2].split(":")
    end = line[3].split(":")
    time =  (int(end[0])-(int(start[0])+1)) * 60 + int(end[1]) + 60 - int(start[1])
    
    if _dict.get(name):
        _dict[name][1] += time
        if day not in _dict[name][0]:
            _dict[name][0].append(day)

    else:
        _dict[name] = [[day], time]
    
sorted_dict = sorted(_dict.items())

result = []

for item in sorted_dict:
    # 날짜랑 시간
    activity_days = item[1][0]  
    total_time = item[1][1]  
    
    activity_days = sorted(int(day) for day in activity_days)
    
    # 날짜가 1주일에 5번이 되냐 이건데, 이걸 못하겠음 여기서 틀린건가?
    week_count = 0
    for i in range(0, len(activity_days), 7):
        week_activities = activity_days[i:i+7]
        if len(week_activities) >= 5:
            week_count += 1

    
    if week_count >= weeks and total_time >= weeks * 60 * 60:
        result.append(item)
        print(item[0])
        
if not result:
    print(-1)