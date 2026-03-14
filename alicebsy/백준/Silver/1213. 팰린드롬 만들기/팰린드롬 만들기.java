import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNext()) {
            String name = sc.next();
            int[] alpha = new int[26];
            
            for (int i = 0; i < name.length(); i++) {
                alpha[name.charAt(i) - 'A']++;
            }
            
            int oddCount = 0;
            char midChar = 0; 
            

            for (int i = 0; i < 26; i++) {
                if (alpha[i] % 2 != 0) {
                    oddCount++;
                    midChar = (char) (i + 'A');
                }
            }
            

            if (oddCount > 1) {
                System.out.println("I'm Sorry Hansoo");
            } else {
                StringBuilder half = new StringBuilder();
                

                for (int i = 0; i < 26; i++) {
                    for (int j = 0; j < alpha[i] / 2; j++) {
                        half.append((char) (i + 'A'));
                    }
                }
                

                StringBuilder result = new StringBuilder(half);
                if (oddCount == 1) {
                    result.append(midChar);
                }
                result.append(half.reverse());
                
                System.out.println(result.toString());
            }
        }
        sc.close();
    }
}