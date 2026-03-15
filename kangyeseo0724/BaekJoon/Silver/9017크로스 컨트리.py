import sys
t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    team = list(map(int, sys.stdin.readline().split()))
    
    count = {}
    for i in team:
        if i not in count:
            count[i] = 1
        else:
            count[i] += 1
    
    #valid_team = {}
    valid_team: dict[int, list[int]] = {}
    rank = 1
    
    for i in team:
        if count[i] == 6:
            if i not in valid_team:
                valid_team[i] = []
            valid_team[i].append(rank)
            rank += 1
    
    result = []
    for i in valid_team:
        totalScore = sum(valid_team[i][:4])
        fifthScore = valid_team[i][4]
        
        result.append((totalScore, fifthScore, i))
    
    result.sort()
    
    print(result[0][2])