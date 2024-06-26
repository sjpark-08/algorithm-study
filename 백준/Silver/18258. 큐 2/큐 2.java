import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;


public class Main {
    private int[] queue = new int[2000001];
    private int front = -1;
    private int rear = -1;

    public void push(int data){
        queue[++rear] = data;
    }
    public int pop(){
        return queue[++front];
    }

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		Deque<Integer> deque = new ArrayDeque<>();
		
        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String op = st.nextToken();
            if("push".equals(op)){
                int num = Integer.parseInt(st.nextToken());
                push(num);
            }else if("pop".equals(op)){
                bw.write(String.valueOf(front == rear ? -1 : pop()) + '\n');
            }else if("size".equals(op)){
                bw.write(String.valueOf(rear - front) + '\n');
            }else if("empty".equals(op)){
                bw.write(front == rear ? "1\n" : "0\n");
            }else if("front".equals(op)){
                bw.write(String.valueOf(front == rear ? -1 : queue[front + 1]) + '\n');
            }else if("back".equals(op)){
                bw.write(String.valueOf(front == rear ? -1 : queue[rear]) + '\n');
            }
        }

        bw.flush();   
        bw.close();
        br.close();
        
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
