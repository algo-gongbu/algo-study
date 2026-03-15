import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNext()) {
            String A = sc.next();
            String B = sc.next();
            
            int minDiff = Integer.MAX_VALUE;
            
            // A를 B 위에서 움직일 수 있는 모든 횟수 반복
            for (int i = 0; i <= B.length() - A.length(); i++) {
                int currentDiff = 0;
                
                // 겹치는 부분의 알파벳 차이 계산
                for (int j = 0; j < A.length(); j++) {
                    if (A.charAt(j) != B.charAt(i + j)) {
                        currentDiff++;
                    }
                }
                
                // 최솟값 갱신
                if (currentDiff < minDiff) {
                    minDiff = currentDiff;
                }
            }
            
            System.out.println(minDiff);
        }
        
        sc.close();
    }
}