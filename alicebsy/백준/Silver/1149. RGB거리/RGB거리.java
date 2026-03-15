import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNextInt()) {
            int N = sc.nextInt();
            int[][] cost = new int[N][3];
            
            for (int i = 0; i < N; i++) {
                cost[i][0] = sc.nextInt(); // 빨
                cost[i][1] = sc.nextInt(); // 초
                cost[i][2] = sc.nextInt(); // 파
            }
            


            for (int i = 1; i < N; i++) {
                cost[i][0] += Math.min(cost[i-1][1], cost[i-1][2]); // 빨
                cost[i][1] += Math.min(cost[i-1][0], cost[i-1][2]); // 초
                cost[i][2] += Math.min(cost[i-1][0], cost[i-1][1]); // 파
            }
            
            // 가장 작은 값을 출력
            int minCost = Math.min(cost[N-1][0], Math.min(cost[N-1][1], cost[N-1][2]));
            System.out.println(minCost);
        }
        
        sc.close();
    }
}