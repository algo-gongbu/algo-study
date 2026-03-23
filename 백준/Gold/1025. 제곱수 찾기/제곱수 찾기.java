import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] grid = new int[N][M];
        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            for (int j = 0; j < M; j++) {
                grid[i][j] = line.charAt(j) - '0';
            }
        }

        int maxSquare = -1;

        // 시작점 
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                
                // 행과 열의 공차
                for (int dr = -N + 1; dr < N; dr++) {
                    for (int dc = -M + 1; dc < M; dc++) {
                        
                        if (dr == 0 && dc == 0) {
                            int num = grid[r][c];
                            if (isPerfectSquare(num)) {
                                maxSquare = Math.max(maxSquare, num);
                            }
                            continue;
                        }

                        int currR = r;
                        int currC = c;
                        int num = 0;

                        while (currR >= 0 && currR < N && currC >= 0 && currC < M) {
                            num = num * 10 + grid[currR][currC];
                            
                            if (isPerfectSquare(num)) {
                                maxSquare = Math.max(maxSquare, num);
                            }
                            
                            currR += dr;
                            currC += dc;
                        }
                    }
                }
                
            }
        }

        System.out.println(maxSquare);
    }

    static boolean isPerfectSquare(int num) {
        int root = (int) Math.sqrt(num);
        return root * root == num;
    }
}