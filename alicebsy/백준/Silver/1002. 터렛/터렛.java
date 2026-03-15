import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();

        while (T-- > 0) {
            int x1 = in.nextInt();
            int y1 = in.nextInt();
            int r1 = in.nextInt();
            int x2 = in.nextInt();
            int y2 = in.nextInt();
            int r2 = in.nextInt();

            System.out.println(countPoints(x1, y1, r1, x2, y2, r2));
        }
    }

    public static int countPoints(int x1, int y1, int r1, int x2, int y2, int r2) {
        int distance_pow = (int)(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));

        // 1. 일치하는 경우
        if (x1 == x2 && y1 == y2 && r1 == r2) {
            return -1;
        }
        
        // 2. 중심이 같고 반지름이 다른 경우 
        else if (x1 == x2 && y1 == y2 && r1 != r2) {
            return 0;
        }

        // 3. 외접하는 경우
        else if (distance_pow == Math.pow(r1 + r2, 2)) {
            return 1;
        }

        // 4. 내접하는 경우 
        else if (distance_pow == Math.pow(r1 - r2, 2)) {
            return 1;
        }

        // 5. 두 원이 만나지 않는 경우
        else if (distance_pow > Math.pow(r1 + r2, 2)) {
            return 0;
        }

        // 6. 한 원이 다른 원 안에 포함되어 만나지 않는 경우
        else if (distance_pow < Math.pow(r1 - r2, 2)) {
            return 0;
        }

        // 7. 그 외 두 점에서 만나는 경우
        else {
            return 2;
        }
    }
}