import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Queue;
import java.util.Stack;
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
        
        for (int i = 1; i <= N; i++) {
            deque.addLast(i);
        }

        while(true) {
            if(deque.size() == 1) break;
            deque.removeFirst();
            deque.addLast(deque.removeFirst());
        }
        
        System.out.println(deque.removeFirst());
        
        bw.flush();   
        bw.close();
        br.close();
        
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
