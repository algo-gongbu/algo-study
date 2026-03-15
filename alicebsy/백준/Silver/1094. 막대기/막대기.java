import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        if (sc.hasNextInt()) {
            int x = sc.nextInt();
            int count = Integer.bitCount(x);
            
            System.out.println(count);
        }
        
        sc.close();
    }
}