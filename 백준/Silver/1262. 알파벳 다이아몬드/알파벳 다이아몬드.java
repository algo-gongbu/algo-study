import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int R1 = Integer.parseInt(st.nextToken());
        int C1 = Integer.parseInt(st.nextToken());
        int R2 = Integer.parseInt(st.nextToken());
        int C2 = Integer.parseInt(st.nextToken());

        // 타일 1개의 가로, 세로 길이
        int tileSize = 2 * N - 1;
        // 타일 정중앙의 인덱스
        int center = N - 1;

        StringBuilder sb = new StringBuilder();

        // 주어진 출력 범위만큼만 반복
        for (int r = R1; r <= R2; r++) {
            // 현재 행
            int rr = r % tileSize;
            
            for (int c = C1; c <= C2; c++) {
                // 현재 열
                int cc = c % tileSize;
                
                // 중심점으로부터의 맨해튼 거리
                int dist = Math.abs(rr - center) + Math.abs(cc - center);

                // 거리가 (N - 1)보다 크면 다이아몬드 밖이므로 빈 공간
                if (dist > N - 1) {
                    sb.append('.');
                } else {
                    // 거리 0부터 'a' 시작, 26으로 나눈 나머지로 알파벳 순환 처리
                    sb.append((char) ('a' + (dist % 26)));
                }
            }
            sb.append('\n');
        }

        System.out.print(sb.toString());
    }
}