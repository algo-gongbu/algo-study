import sys
s = sys.stdin.readline().strip()

a_count = s.count('a')
window_size = a_count

new_s = s + s
min_b = float('inf')

for i in range (len(s)):
    window = new_s[i: i + window_size]
    
    b_count = window.count('b')
    
    if b_count < min_b:
        min_b = b_count
        
print(min_b)