import java.io.*;
import java.util.*;

public class Main {

    public int N, total, budget;
    public int budgets[];

    public boolean isPossible(int limit){
        int sum = 0;
        for(int i = 0; i < N; i++){
            if(budgets[i] <= limit) sum += budgets[i];
            else sum += limit;
        }
        return sum <= total;
    }

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        budgets = new int[N];

        int maxBudget = 0;
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < N; i++){
            budgets[i] = Integer.parseInt(st.nextToken());
            maxBudget = Math.max(maxBudget, budgets[i]);
        }
        total = Integer.parseInt(br.readLine());

        int left = 0, right = maxBudget + 1;
        int mid;
        int ans = 0;
        while(left < right){
            mid = left + right >> 1;
            if(isPossible(mid)){
                left = mid + 1;
                ans = mid;
            }
            else right = mid;
        }
        System.out.println(ans);
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}