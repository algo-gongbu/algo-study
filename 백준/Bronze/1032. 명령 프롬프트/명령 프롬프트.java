import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        
        String[] files = new String[N];
        for (int i = 0; i < N; i++) {
            files[i] = br.readLine();
        }

        StringBuilder sb = new StringBuilder();
        int len = files[0].length();

        for (int i = 0; i < len; i++) {
            char c = files[0].charAt(i); 
            boolean isSame = true;

            for (int j = 1; j < N; j++) {
                if (c != files[j].charAt(i)) {
                    isSame = false;
                    break; 
                }
            }

            if (isSame) {
                sb.append(c);
            } else {
                sb.append('?');
            }
        }

        System.out.println(sb.toString());
    }
}