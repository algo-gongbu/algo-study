import java.io.*;
import java.util.*;

// 리스트를 입력하고 정렬
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine()); // 먼저 줄 수를 입력받는다

        int []num0 = new int[41];
        int []num1 = new int[41];

        num0[0] = 1;
        num0[1] = 0;

        num1[0] = 0;
        num1[1] = 1;
        int num;

        for (int i = 2; i < 41; i++) {
            num0[i] = num0[i - 2] + num0[i - 1];
        }

        for (int i = 2; i < 41; i++) {
            num1[i] = num1[i - 2] + num1[i - 1];
        }

        for (int j =0; j < n; j++){
            num = Integer.parseInt(br.readLine());

            bw.write(num0[num] + " " + num1[num] + "\n");
        }

        bw.flush();
    }
}
