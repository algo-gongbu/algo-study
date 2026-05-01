def solution(numbers, hand):
    answer = ''
    pos = {
    1:(0,0), 2:(0,1), 3:(0,2),
    4:(1,0), 5:(1,1), 6:(1,2),
    7:(2,0), 8:(2,1), 9:(2,2),
    '*':(3,0), 0:(3,1), '#':(3,2)
    }
    right_hand = '#'
    left_hand = '*'
    for i in range(len(numbers)):
        if numbers[i] == 1 or numbers[i] == 4 or numbers[i] == 7:
            answer += "L"
            left_hand = numbers[i]
        elif numbers[i] == 3 or numbers[i] == 6 or numbers[i] == 9:
            answer += "R"
            right_hand = numbers[i]
        else:
            lx, ly = pos[left_hand]
            rx, ry = pos[right_hand]
            nx, ny = pos[numbers[i]]
            left_dist = abs(lx - nx) + abs(ly - ny)
            right_dist = abs(rx - nx) + abs(ry - ny)
            if left_dist < right_dist:
                answer += "L"
                left_hand = numbers[i]
            elif left_dist > right_dist:
                answer += "R"
                right_hand = numbers[i]
            else:
                if hand == "left":
                    answer += "L"
                    left_hand = numbers[i]
                else:
                    answer += "R"
                    right_hand = numbers[i]
    return answer