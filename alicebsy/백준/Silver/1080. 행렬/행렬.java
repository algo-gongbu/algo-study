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
        
        char[][] A = new char[N][M];
        char[][] B = new char[N][M];
        
        // 행렬 A
        for (int i = 0; i < N; i++) {
            A[i] = br.readLine().toCharArray();
        }
        
        // 행렬 B
        for (int i = 0; i < N; i++) {
            B[i] = br.readLine().toCharArray();
        }
        
        int count = 0;
        
        for (int i = 0; i <= N - 3; i++) {
            for (int j = 0; j <= M - 3; j++) {
                if (A[i][j] != B[i][j]) {
                    flip(A, i, j);
                    count++;
                }
            }
        }
        
        boolean isSame = true;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (A[i][j] != B[i][j]) {
                    isSame = false;
                    break;
                }
            }
            if (!isSame) break;
        }
        
      
        if (isSame) {
            System.out.println(count);
        } else {
            System.out.println(-1);
        }
    }
    
    static void flip(char[][] A, int r, int c) {
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                A[i][j] = A[i][j] == '0' ? '1' : '0';
            }
        }
    }
}