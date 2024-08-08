import java.io.*;
import java.util.*;

public class Main {

    boolean[][] map = new boolean[1001][1001];
    int[][] visited = new int[1001][1001];
    int[] dx = {0, 0, -1, 1};
    int[] dy = {-1, 1, 0, 0};
    int N, M;

    public class Point{
        int x;
        int y;
        int dis;
        public Point(int x, int y, int dis){
            this.x = x;
            this.y = y;
            this.dis = dis;
        }
    }

    public void bfs(int x, int y){
        for(int i = 1; i <= N; i++) Arrays.fill(visited[i], -1);
        ArrayDeque<Point> queue = new ArrayDeque<>();
        queue.addLast(new Point(x, y, 0));

        while(!queue.isEmpty()){
            Point now = queue.removeFirst();
            if(visited[now.x][now.y] != -1) continue;
            visited[now.x][now.y] = now.dis;

            for(int i = 0; i < 4; i++){
                int nx = now.x + dx[i];
                int ny = now.y + dy[i];
                if(nx < 1 || ny < 1 || nx > N || ny > M || visited[nx][ny] != -1 || !map[nx][ny]) continue;
                queue.addLast(new Point(nx, ny, now.dis + 1));
            }
        }
    }

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int srcX = 0, srcY = 0;
        for(int i = 1; i <= N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j <= M; j++){
                int num = Integer.parseInt(st.nextToken());
                if(num == 2){
                    srcX = i;
                    srcY = j;
                }else if(num == 1) map[i][j] = true;
            }
        }
        bfs(srcX, srcY);
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if(visited[i][j] == -1 && !map[i][j]) sb.append("0 ");
                else sb.append(visited[i][j]).append(' ');
            }
            sb.append('\n');
        }
        System.out.print(sb);
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}