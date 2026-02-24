import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNextLong()) {
            long x = sc.nextLong();
            long y = sc.nextLong();
            
            // 기존 승률 계산 
            long z = (y * 100) / x;
            

            if (z >= 99) {
                System.out.println(-1);
            } else {
                long left = 1;
                long right = 2_000_000_000L; 
                long ans = -1;
                
                // 이분 탐색
                while (left <= right) {
                    long mid = left + (right - left) / 2;
                    
                    long newZ = ((y + mid) * 100) / (x + mid);
                    
                    // 승률이 변했을 때 확인하기 위해 범위를 절반으로 줄임
                    if (newZ > z) {
                        ans = mid;
                        right = mid - 1;
                    } else {
                        // 승률이 변하지 않았다면 게임을 더
                        left = mid + 1;
                    }
                }
                
                System.out.println(ans);
            }
        }
        sc.close();
    }
}