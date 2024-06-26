import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
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
        // Stack<Integer> stack = new Stack<>();
        
        int K = Integer.parseInt(br.readLine());
        for(int i = 0; i < K; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int data = Integer.parseInt(st.nextToken());

            if(data == 0) pop();
            else push(data);
        }

        int sum = 0;
        while(top != -1){
            sum += pop();
        }
        System.out.println(sum);

        bw.flush();
        bw.close();
        br.close();
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
