import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

import javax.swing.plaf.TreeUI;

public class Main {
    StringBuilder sb = new StringBuilder();
    boolean[][] graph = new boolean[1001][1001];
    boolean[] visited = new boolean[1001];
    int N, M, V;

    public void DFS(int depth, int now){
        if(depth == N) return;
        visited[now] = true;
        sb.append(now).append(" ");

        for(int i = 1; i <= N; i++){
            int next = i;
            if(!graph[now][next] || visited[next]) continue;
            DFS(depth + 1, next);
        }
    }

    public void BFS(int src){
        Deque<Integer> queue = new ArrayDeque<>();
        queue.addLast(src);

        while(!queue.isEmpty()){
            int now = queue.removeFirst();
            if(visited[now]) continue;
            visited[now] = true;
            sb.append(now).append(" ");
            for(int i = 1; i <= N; i++){
                int next = i;
                if(!graph[now][next] || visited[next]) continue;
                queue.addLast(next);
            }
        }
    }
  
    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a][b] = true;
            graph[b][a] = true;
        }

        DFS(0, V);
        sb.append("\n");
        for(int i = 1; i <= N; i++) visited[i] = false;
        BFS(V);
        System.out.println(sb.toString());
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
