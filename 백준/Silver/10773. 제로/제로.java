import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        Stack<Integer> stack = new Stack<>();

        int K = Integer.parseInt(br.readLine());
        for(int i = 0; i < K; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int data = Integer.parseInt(st.nextToken());

            if(data == 0) stack.pop();
            else stack.push(data);
        }

        int sum = 0;
        while(!stack.isEmpty()){
            sum += stack.pop();
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
