import java.io.*;
import java.util.*;

public class Main {

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int[] arr;

        int N = Integer.parseInt(br.readLine());
        arr = new int[N];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int left = 0, right = N - 1, ans = 2000000000;
        int L = 0, R = 0;
        while(left < right){
            int tmp = arr[left] + arr[right];
            if(ans > Math.abs(tmp)){
                ans = Math.abs(tmp);
                L = left;
                R = right;
            }
            if(tmp > 0) right--;
            else if(tmp < 0) left++;
            else break;
        }
        System.out.println(arr[L] + " " + arr[R]);
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}