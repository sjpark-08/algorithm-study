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
        
        int k = 1;
        int N = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < N; i++){
            int num = Integer.parseInt(br.readLine());
            while(num >= k){
                push(k++);
                sb.append('+');
                sb.append('\n');
            }
            if(top != -1 && stack[top] == num){
                pop();
                sb.append('-');
                sb.append('\n');
            }
        }    
        if(top != -1) {
            System.out.println("NO");
            return;
        } else bw.write(sb.toString());
        
        bw.flush();   
        bw.close();
        br.close();
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
