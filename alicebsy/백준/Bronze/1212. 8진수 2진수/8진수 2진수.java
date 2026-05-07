import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String octal = br.readLine();
        
        if (octal.equals("0")) {
            System.out.println("0");
            return;
        }
        
        StringBuilder sb = new StringBuilder();
        String[] binary = {"000", "001", "010", "011", "100", "101", "110", "111"};
        
        for (int i = 0; i < octal.length(); i++) {
            int digit = octal.charAt(i) - '0';
            

            if (i == 0) {
                if (digit == 1) sb.append("1");
                else if (digit == 2) sb.append("10");
                else if (digit == 3) sb.append("11");
                else sb.append(binary[digit]); 
            } else {
                sb.append(binary[digit]);
            }
        }
        
        System.out.println(sb.toString());
    }
}