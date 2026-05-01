def solution(board, moves):
    answer = []
    count = 0
    for n in moves:
        for i in range(len(board)):
            if board[i][n - 1] != 0:
                if not answer or answer[-1] != board[i][n - 1]:
                    answer.append(board[i][n - 1])
                else:
                    count += 2
                    answer.pop()
                board[i][n - 1] = 0
                break
    return count