import java.io.*;
import java.util.*;

public class Main {

    public class Node{
        int x, y, d;
        Node(int x, int y, int d){
            this.x = x;
            this.y = y;
            this.d = d;
        }
    }

    int N, srcX, srcY, destX, destY;
    int[] dx = {-1, -2, -2, -1, 1, 2, 2, 1};
    int[] dy = {-2, -1, 1, 2, 2, 1, -1, -2};

    public int bfs(){
        boolean[][] visited = new boolean[N][N];
        Deque<Node> queue = new ArrayDeque<Node>();
        queue.add(new Node(srcX, srcY, 0));
        visited[srcX][srcY] = true;

        while(!queue.isEmpty()){
            Node cur = queue.poll();
            int x = cur.x;
            int y = cur.y;
            int d = cur.d;
            if(x == destX && y == destY) return d;
            for(int i = 0; i < 8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1 || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                queue.add(new Node(nx, ny, d + 1));
            }
        }
        return 0;
    }

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        StringBuilder sb = new StringBuilder();

        int TC = Integer.parseInt(br.readLine());
        for(int t = 0; t < TC; t++){
            N = Integer.parseInt(br.readLine());
            st = new StringTokenizer(br.readLine());
            srcX = Integer.parseInt(st.nextToken());
            srcY = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            destX = Integer.parseInt(st.nextToken());
            destY = Integer.parseInt(st.nextToken());
            int result = bfs();
            sb.append(result).append('\n');
        }
        System.out.println(sb);
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}