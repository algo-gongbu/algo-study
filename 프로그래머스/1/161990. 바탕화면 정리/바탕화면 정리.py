def solution(wallpaper):
    answer = []
    spot = []
    for i in range(len(wallpaper)):
        for j in range(len(wallpaper[i])):
            if (wallpaper[i])[j] == '#':
                spot.append((i,j))

    lux = min(spot, key=lambda x: x[1])[1]
    luy = min(spot, key=lambda x: x[0])[0]
    rdx = max(spot, key=lambda x: x[1])[1]+1
    rdy = max(spot, key=lambda x: x[0])[0]+1
    
    answer= [luy,lux, rdy,rdx]
    
    return answer