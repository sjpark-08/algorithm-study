import java.io.*;
import java.util.*;

public class Main {

    public class Pair{
        String word;
        int frequency;
        Pair(String word, int frequency){
            this.word = word;
            this.frequency = frequency;
        }
    }

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        HashMap<String, Integer> map = new HashMap<String, Integer>();
        for(int i = 0; i < N; i++){
            String word = br.readLine();
            if(word.length() < M) continue;
            Integer value = map.get(word);
            if(value == null) map.put(word, 1);
            else map.replace(word, value + 1);
        }
        List<Pair> toSort = new ArrayList<Pair>();
        map.forEach((key, value) -> toSort.add(new Pair(key, value)));
        Collections.sort(toSort, (p1, p2) -> {
            if(p1.frequency == p2.frequency && p1.word.length() == p2.word.length()) return p1.word.compareTo(p2.word);
            else if(p1.frequency == p2.frequency) return p2.word.length() - p1.word.length();
            return p2.frequency - p1.frequency;
        });
        toSort.forEach((p) -> sb.append(p.word).append('\n'));

        System.out.print(sb);
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}