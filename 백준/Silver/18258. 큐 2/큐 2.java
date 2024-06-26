import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;


public class Main {
    private int[] stack = new int[100001];
    private int top = -1;

    public void push(int data){
        stack[++top] = data;
    }
    public int pop(){
        return stack[top--];
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
                deque.addLast(num);
            }else if("pop".equals(op)){
                bw.write(String.valueOf(deque.isEmpty() ? -1 : deque.pop()) + '\n');
            }else if("size".equals(op)){
                bw.write(String.valueOf(deque.size()) + '\n');
            }else if("empty".equals(op)){
                bw.write(deque.isEmpty() ? "1\n" : "0\n");
            }else if("front".equals(op)){
                bw.write(String.valueOf(deque.isEmpty() ? -1 : deque.getFirst()) + '\n');
            }else if("back".equals(op)){
                bw.write(String.valueOf(deque.isEmpty() ? -1 : deque.getLast()) + '\n');
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
