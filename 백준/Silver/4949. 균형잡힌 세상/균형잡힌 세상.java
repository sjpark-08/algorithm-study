import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    private char[] stack = new char[100001];
    private int top = -1;

    public void push(char data){
        stack[++top] = data;
    }
    public char pop(){
        return stack[top--];
    }

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        // Stack<Integer> stack = new Stack<>();
        
        while(true){
            String line = br.readLine();
            if(".".equals(line)) break;

            char[] str = new char[102];
            str = line.toCharArray();
            
            top = -1;
            boolean fail = false;
            int length = line.length();
            for(int i = 0; i < length; i++){
                if(fail) break;
                char c = str[i];

                if(c == '(' || c == '[') push(c);
                else if(c == ')' || c == ']'){
                    if(top == -1) fail = true;
                    else{
                        if(stack[top] == '(' && c == ')') pop();
                        else if(stack[top] == '[' && c == ']') pop();
                        else fail = true;
                    }
                }
            }
            if(top != -1 || fail) bw.write("no" + '\n');
            else bw.write("yes" + '\n');
        }

        bw.flush();
        bw.close();
        br.close();
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}
