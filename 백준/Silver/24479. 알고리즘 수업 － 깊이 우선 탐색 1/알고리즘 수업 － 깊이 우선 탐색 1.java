import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import javax.swing.plaf.TreeUI;

public class Main {
    StringBuilder sb = new StringBuilder();
    PriorityQueue<Integer>[] pqList;
    int[] visit;
    int cnt = 0;
    
    public void dfs(int now){
        visit[now] = ++cnt;
        while(!pqList[now].isEmpty()){
            int next = pqList[now].poll();
            if(visit[next] != 0) continue;
            dfs(next);
        }
    }
  
    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        visit = new int[N + 1];
        pqList = new PriorityQueue[N + 1];
        for(int i = 1; i <= N; i++) pqList[i] = new PriorityQueue<>();
        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            pqList[a].add(b);
            pqList[b].add(a);
        }

        dfs(R);
        // Arrays.stream(visit).forEach(i -> sb.append(i).append('\n'));
        for(int i = 1; i <= N; i++) sb.append(visit[i]).append('\n');
        System.out.println(sb.toString());
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
