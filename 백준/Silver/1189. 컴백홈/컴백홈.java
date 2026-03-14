import java.util.Scanner;

public class Main {
    static int R, C, K;
    static char[][] map;
    static boolean[][] visited;
    
    // 상하좌우 탐색을 위한 방향 배열
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    
    static int answer = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNextInt()) {
            R = sc.nextInt();
            C = sc.nextInt();
            K = sc.nextInt();
            
            map = new char[R][C];
            visited = new boolean[R][C];
            
            for (int i = 0; i < R; i++) {
                String line = sc.next();
                map[i] = line.toCharArray();
            }
            visited[R - 1][0] = true;
            dfs(R - 1, 0, 1);
            
            System.out.println(answer);
        }
        
        sc.close();
    }

    static void dfs(int r, int c, int dist) {
        if (r == 0 && c == C - 1) {
            if (dist == K) {
                answer++;
            }
            return;
        }

        if (dist >= K) {
            return;
        }

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C) {
                if (!visited[nr][nc] && map[nr][nc] != 'T') {
                    visited[nr][nc] = true; // 방문 
                    dfs(nr, nc, dist + 1);  // 다음 칸
                    visited[nr][nc] = false; // 백트래킹
                }
            }
        }
    }
}