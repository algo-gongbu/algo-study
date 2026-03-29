import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long N = Long.parseLong(st.nextToken());
        long L = Long.parseLong(st.nextToken());
        long W = Long.parseLong(st.nextToken());
        long H = Long.parseLong(st.nextToken());

        double low = 0;
        double high = Math.min(L, Math.min(W, H));

        for (int i = 0; i < 100; i++) {
            double mid = (low + high) / 2;

            long countL = (long) (L / mid);
            long countW = (long) (W / mid);
            long countH = (long) (H / mid);

            if (countL == 0 || countW == 0 || countH == 0) {
                high = mid;
                continue;
            }


            if ((double) countL * (double) countW * (double) countH >= N) {
                low = mid;
            } else {
                high = mid;
            }

        }


        System.out.println(low);
    }
}