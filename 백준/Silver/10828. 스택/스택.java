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

        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            
            if("push".equals(str)){
                int data = Integer.parseInt(st.nextToken());
                stack.push(data);
            }else if("pop".equals(str)){
                if(stack.size() == 0) bw.write("-1\n"); 
                else{
                    int data = stack.pop();
                    bw.write(String.valueOf(data) + '\n');
                }
            }else if("size".equals(str)){
                int size = stack.size();
                bw.write(String.valueOf(size) + '\n'); 
            }else if("empty".equals(str)){
                boolean isEmpty = stack.isEmpty();
                if(isEmpty) bw.write("1\n");
                else bw.write("0\n");
            }else{
                if(stack.size() == 0) bw.write("-1\n"); 
                else{
                    int data = stack.peek();
                    bw.write(String.valueOf(data) + '\n');
                }
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
