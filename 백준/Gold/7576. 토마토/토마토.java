import java.io.*;
import java.util.*;

public class Main {

    public class Node{
        int x, y, t;
        Node(int x, int y, int t){
            this.x = x;
            this.y = y;
            this.t = t;
        }
    }

    int M, N, ans;
    int[] dx = {0, 0, -1, 1};
    int[] dy = {-1, 1, 0, 0};
    int[][] map;
    boolean[][] visited;
    Deque<Node> queue = new ArrayDeque<Node>();

    public void bfs(){
        while(!queue.isEmpty()){
            Node cur = queue.poll();
            int x = cur.x;
            int y = cur.y;
            int t = cur.t;
            ans = t;
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1) continue;
                if(visited[nx][ny] || map[nx][ny] == -1) continue;
                visited[nx][ny] = true;
                queue.add(new Node(nx, ny, t + 1));
            }
        }
    }

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        visited = new boolean[N][M];

        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < M; j++){
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] == 1){
                    queue.add(new Node(i, j, 0));
                    visited[i][j] = true;
                }
            }
        }
        bfs();
        boolean suc = true;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 0 && !visited[i][j]){
                    suc = false;
                    break;
                }
            }
        }
        if(suc) System.out.println(ans);
        else System.out.println(-1);
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}