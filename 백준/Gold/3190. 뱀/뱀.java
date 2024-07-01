import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.StringTokenizer;



public class Main {
    
    public class Point {
        private int x;
        private int y;
        public Point(int x, int y){
            this.x = x;
            this.y = y;
        }
    }

    public class Query {
        private int time;
        private char dir;
        public Query(int time, char dir){
            this.time = time;
            this.dir = dir;
        }
    }
  
    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Deque<Point> queue = new ArrayDeque<>();
        Query[] query = new Query[101];
        boolean[][] map = new boolean[101][101];
        boolean[][] apple = new boolean[101][101];
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
   
        int N = Integer.parseInt(br.readLine());
        int K = Integer.parseInt(br.readLine());

        // input (apples' position)
        for(int i = 0; i < K; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            apple[x][y] = true;
        }

        // input (direction queries)
        int L = Integer.parseInt(br.readLine());
        for(int i = 0; i < L; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            char d = st.nextToken().charAt(0);
            query[i] = new Query(t, d);
        }
        
        int direction = 0;
        int time = 0;
        int idx = 0;

        // start at (1, 1)
        map[1][1] = true;
        queue.addLast(new Point(1, 1));

        while(true){
            // expand
            time++;
            int nx = queue.getLast().x + dx[direction];
            int ny = queue.getLast().y + dy[direction];
            if(nx < 1 || ny < 1 || nx > N || ny > N || map[nx][ny]) break;
            
            // next position
            queue.addLast(new Point(nx, ny));
            map[nx][ny] = true;

            // check whether apple exists
            if(apple[nx][ny]) apple[nx][ny] = false;
            else{
                Point out = queue.removeFirst();
                map[out.x][out.y] = false;
            }

            if(idx == L || query[idx].time != time) continue;

            // direction
            if(query[idx].dir == 'D') direction = (direction + 1) % 4;
            else if(query[idx].dir == 'L') direction = (direction - 1 + 4) % 4;
            idx++;
        }
        System.out.println(time);
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
