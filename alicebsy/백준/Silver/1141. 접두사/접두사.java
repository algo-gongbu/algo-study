import java.util.Scanner;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNextInt()) {
            int n = sc.nextInt();
            
            // 중복된 단어 제거
            HashSet<String> set = new HashSet<>();
            for (int i = 0; i < n; i++) {
                set.add(sc.next());
            }
            
            int count = 0;
            
            // 다른 단어의 접두사인지 확인
            for (String s1 : set) {
                boolean isPrefix = false;
                
                for (String s2 : set) {
                    if (!s1.equals(s2) && s2.startsWith(s1)) {
                        isPrefix = true;
                        break;
                    }
                }
                
                if (!isPrefix) {
                    count++;
                }
            }
            
            System.out.println(count);
        }
        
        sc.close();
    }
}