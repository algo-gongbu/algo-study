import sys

sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def solve():
    n, m = map(int, input().split())
    structure = {}
    
    for _ in range(n + m):
        p, c, is_folder = input().split()
        if p not in structure:
            structure[p] = []
        structure[p].append((c, is_folder))

    def get_files(folder_name):
        files = []
        if folder_name in structure:
            for child, is_folder in structure[folder_name]:
                if is_folder == '1':
                    files.extend(get_files(child))
                else:
                    files.append(child)
        return files

    q = int(input())
    for _ in range(q):
        query = input().strip().split('/')
        target_folder = query[-1]
        
        all_files = get_files(target_folder)
        file_types = set(all_files)
        
        print(f"{len(file_types)} {len(all_files)}")

solve()