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

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        StringBuilder sb = new StringBuilder();

        int[] dx = {0, 0, -1 ,1};
        int[] dy = {-1, 1, 0, 0};

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        boolean[][] visited = new boolean[N][M];
        char[][] map = new char[N][M];
        for(int i = 0; i < N; i++) map[i] = br.readLine().toCharArray();

        Deque<Node> queue = new ArrayDeque<Node>();
        queue.add(new Node(0, 0, 1));
        visited[0][0] = true;
        while(!queue.isEmpty()){
            Node cur = queue.poll();
            int x = cur.x;
            int y = cur.y;
            int d = cur.d;
            if(x == N - 1 && y == M - 1){
                System.out.println(d);
                break;
            }
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx > N - 1 || ny > M - 1) continue;
                if(visited[nx][ny] || map[nx][ny] == '0') continue;
                visited[nx][ny] = true;
                queue.add(new Node(nx, ny, d + 1));
            }
        }
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}