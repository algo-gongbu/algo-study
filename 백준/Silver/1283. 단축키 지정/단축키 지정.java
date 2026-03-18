import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        
        boolean[] used = new boolean[26];
        StringBuilder result = new StringBuilder();

        for (int i = 0; i < N; i++) {
            String line = br.readLine();
            String[] words = line.split(" ");
            boolean isAssigned = false;

            // 1순위 : 각 단어의 첫 글자 확인
            for (int j = 0; j < words.length; j++) {
                char firstChar = words[j].charAt(0);
                int charIdx = Character.toLowerCase(firstChar) - 'a';
                
                // 단축키로 지정되지 않은 알파벳
                if (!used[charIdx]) {
                    used[charIdx] = true; 
                    
                    // 해당 단어의 첫 글자에만 []를 씌워서 다시 조립
                    for (int k = 0; k < words.length; k++) {
                        if (k == j) {
                            result.append("[").append(words[k].charAt(0)).append("]").append(words[k].substring(1));
                        } else {
                            result.append(words[k]);
                        }
                        if (k < words.length - 1) result.append(" ");
                    }
                    result.append("\n");
                    isAssigned = true;
                    break;
                }
            }

            // 2순위: 1순위에서 지정되지 않았다면, 왼쪽부터 모든 알파벳 확인
            if (!isAssigned) {
                for (int j = 0; j < line.length(); j++) {
                    char c = line.charAt(j);
                    if (c == ' ') continue; // 공백은 건너뜀
                    
                    int charIdx = Character.toLowerCase(c) - 'a';
                    if (!used[charIdx]) {
                        used[charIdx] = true; // 사용 처리
                        
                        // 해당 글자에만 []를 씌워서 조립
                        result.append(line.substring(0, j))
                              .append("[").append(c).append("]")
                              .append(line.substring(j + 1))
                              .append("\n");
                        isAssigned = true;
                        break;
                    }
                }
            }

            // 3순위: 어떤 것도 단축키로 지정할 수 없다면 원본 그대로 출력
            if (!isAssigned) {
                result.append(line).append("\n");
            }
        }

        // 최종 결과 출력
        System.out.print(result.toString());
    }
}