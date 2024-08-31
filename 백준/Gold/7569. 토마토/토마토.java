import java.io.*;
import java.util.*;

public class Main {

    public class Node{
        int x, y, z, t;
        Node(int x, int y, int z, int t){
            this.x = x;
            this.y = y;
            this.z = z;
            this.t = t;
        }
    }

    int M, N, H, ans;
    int[] dx = {0, 0, -1, 1, 0, 0};
    int[] dy = {-1, 1, 0, 0, 0, 0};
    int[] dz = {0, 0, 0, 0, -1, 1};
    int[][][] map;
    boolean[][][] visited;
    Deque<Node> queue = new ArrayDeque<Node>();

    public void bfs(){
        while(!queue.isEmpty()){
            Node cur = queue.poll();
            int x = cur.x;
            int y = cur.y;
            int z = cur.z;
            int t = cur.t;
            ans = t;
            for(int i = 0; i < 6; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                int nz = z + dz[i];
                if(nx < 0 || ny < 0 || nz < 0 || nx > N - 1 || ny > M - 1 || nz > H - 1) continue;
                if(visited[nz][nx][ny] || map[nz][nx][ny] == -1) continue;
                visited[nz][nx][ny] = true;
                queue.add(new Node(nx, ny, nz, t + 1));
            }
        }
    }

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());

        map = new int[H][N][M];
        visited = new boolean[H][N][M];

        for(int k = 0; k < H; k++){
            for(int i = 0; i < N; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < M; j++){
                    map[k][i][j] = Integer.parseInt(st.nextToken());
                    if(map[k][i][j] == 1){
                        queue.add(new Node(i, j, k, 0));
                        visited[k][i][j] = true;
                    }
                }
            }
        }
        bfs();
        boolean suc = true;
        for(int k = 0; k < H; k++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < M; j++){
                    if(map[k][i][j] == 0 && !visited[k][i][j]){
                        suc = false;
                        break;
                    }
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