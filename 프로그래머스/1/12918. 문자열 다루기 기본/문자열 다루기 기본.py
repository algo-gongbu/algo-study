def solution(s):
    for i in range(len(s)):
        if len(s) == 4 or len(s) == 6:
            if not s[i].isdigit():
                return False            
        else:
            return False
        
    return True