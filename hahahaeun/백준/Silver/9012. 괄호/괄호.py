count = int(input())

for i in range(count):
    vps = list(map(str, input()))
    len_vps = len(vps)
    if 2 <= len_vps <= 50:
  
        i = 0
        while vps.count('(') > 0 and vps.count(')') > 0:
            if vps[0] == ')' or vps[-1] == '(':
                break

            if vps[i] == '(' and vps[i+1] == ')':
                vps.pop(i)
                vps.pop(i)
                i -= 1

            else:
                i += 1


        if len(vps) == 0:
                    print('YES')
        else:
                print('NO')