import java.io.*;
import java.util.*;

public class Main {

    public class Pair{
        String student;
        int index;
        Pair(String student, int index){
            this.student = student;
            this.index = index;
        }
    }

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int K = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        HashMap<String, Integer> map = new HashMap<String, Integer>();
        for(int i = 0; i < L; i++){
            String student = br.readLine();
            map.put(student, i);
        }
        // List<Pair> toSort = new ArrayList<Pair>();
        // map.forEach((key, value) -> toSort.add(new Pair(key, value)));
        // Collections.sort(toSort, (p1, p2) -> p1.index - p2.index);

        // int T = Math.min(K, st.size());
        // for(int i = 0; i < T; i++) bw.write(toSort.get(i).student + '\n');

        String[] students = new String[L];
        map.forEach((key, value) -> students[value] = key);
        int T = Math.min(K, map.size());
        int cnt = 0;
        for(int i = 0; i < L; i++){
            if(students[i] == null) continue;
            bw.write(students[i] + '\n');
            cnt++;
            if(cnt == T) break;
        }
        
        bw.flush();
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}