import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
    static class Node implements Comparable<Node> {
        long val;
        long count;
        
        public Node(long v, long c) {
            this.val = v;
            this.count = c;
        }
        
        @Override
        public int compareTo(Node o) {
            if (this.count != o.count) {
                return Long.compare(this.count, o.count);
            }

            return Long.compare(this.val, o.val);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int L = Integer.parseInt(br.readLine().trim());
        StringTokenizer st = new StringTokenizer(br.readLine().trim());
        List<Long> sList = new ArrayList<>();
        
        for (int i = 0; i < L; i++) {
            sList.add(Long.parseLong(st.nextToken()));
        }
        int n = Integer.parseInt(br.readLine().trim());

        sList.add(0L);
        Collections.sort(sList);

        Map<Long, Long> map = new HashMap<>();

        for (long x : sList) {
            if (x > 0) {
                map.put(x, 0L);
            }
        }

        for (int i = 0; i < sList.size() - 1; i++) {
            long left = sList.get(i);
            long right = sList.get(i + 1);

            for (int k = 1; k <= n; k++) {
                long x = left + k;
                if (x < right) {
                    long count = (x - left) * (right - x) - 1;
                    map.put(x, count);
                } else {
                    break;
                }
            }

            for (int k = 1; k <= n; k++) {
                long x = right - k;
                if (x > left) {
                    long count = (x - left) * (right - x) - 1;
                    map.put(x, count);
                } else {
                    break;
                }
            }
        }

        long maxS = sList.get(sList.size() - 1);
        for (int k = 1; k <= n; k++) {
            long x = maxS + k;
            map.put(x, Long.MAX_VALUE);
        }

        List<Node> candidates = new ArrayList<>();
        for (Map.Entry<Long, Long> entry : map.entrySet()) {
            candidates.add(new Node(entry.getKey(), entry.getValue()));
        }

        Collections.sort(candidates);

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n && i < candidates.size(); i++) {
            sb.append(candidates.get(i).val).append(i == n - 1 ? "" : " ");
        }
        
        System.out.println(sb.toString());
    }
}