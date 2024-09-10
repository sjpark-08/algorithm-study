import java.io.*;
import java.util.*;

public class Main {

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());
        for(int t = 0; t < T; t++){
            List<List<Integer>> charIndex = new ArrayList<List<Integer>>();
            for(int i = 0; i < 26; i++) charIndex.add(new ArrayList<Integer>());
            char[] charArr = br.readLine().toCharArray();
            int K = Integer.parseInt(br.readLine());

            int ansMax = 0, ansMin = 10001;
            for(int i = 0; i < charArr.length; i++) charIndex.get(charArr[i] - 'a').add(i);
            for(int i = 0; i < 26; i++){
                List<Integer> charIdx = charIndex.get(i);
                if(charIdx.size() < K) continue;
                for(int k = 0; k < charIdx.size() - K + 1; k++){
                    ansMax = Math.max(ansMax, charIdx.get(k + K - 1) - charIdx.get(k) + 1);
                    ansMin = Math.min(ansMin, charIdx.get(k + K - 1) - charIdx.get(k) + 1);
                }
            }
            if(ansMax > 0) sb.append(ansMin).append(' ').append(ansMax).append('\n');
            else sb.append("-1\n");
        }
        System.out.println(sb);
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}