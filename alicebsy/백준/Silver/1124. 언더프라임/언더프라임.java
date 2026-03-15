import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNextInt()) {
            int A = sc.nextInt();
            int B = sc.nextInt();
            
            boolean[] isPrime = new boolean[B + 1];
            int[] minFactor = new int[B + 1];
            int[] count = new int[B + 1]; // 소인수의 개수
            
            for (int i = 2; i <= B; i++) {
                isPrime[i] = true;
                minFactor[i] = i;
            }
            
            // 체 및 최소 소인수 기록
            for (int i = 2; i * i <= B; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j <= B; j += i) {
                        isPrime[j] = false;
                        if (minFactor[j] == j) {
                            minFactor[j] = i;
                        }
                    }
                }
            }
            
            // 모든 수의 소인수 개수 구하기
            int underprimeCount = 0;
            for (int i = 2; i <= B; i++) {
                count[i] = count[i / minFactor[i]] + 1;
            }
            
            // 4. A부터 B까지 언더프라임 개수
            for (int i = A; i <= B; i++) {
                if (isPrime[count[i]]) {
                    underprimeCount++;
                }
            }
            
            System.out.println(underprimeCount);
        }
        
        sc.close();
    }
}