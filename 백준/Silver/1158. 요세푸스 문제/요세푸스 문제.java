import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int x =0;
        int count = 0;

        Queue<Integer> que = new LinkedList();

        for(int i = 1; i <= n ; i++){
            que.offer(i);

        }
        bw.write("<");

        while(!que.isEmpty()){
            count++;

            x = que.poll();
            if(count == k){
                bw.write(String.valueOf(x));

                // 마지막이 아니면 쉼표 출력 
                if (!que.isEmpty()) {
                    bw.write(", ");
                }
                count = 0;
            }else{
                que.offer(x);
            }

        }


        bw.write(">");
        bw.flush();


    }

}




