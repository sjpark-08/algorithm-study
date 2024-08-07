import java.io.*;
import java.util.*;

public class Main {

    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        char[] str = new char[N];
        str = br.readLine().toCharArray();

        ArrayList<Integer> person = new ArrayList<>();
        ArrayList<Integer> hamburger = new ArrayList<>();
        for(int i = 0; i < N; i++){
            if(str[i] == 'P') person.add(i);
            else hamburger.add(i);
        }

        int pIdx = 0, hIdx = 0, ans = 0;
        while(pIdx < person.size() && hIdx < hamburger.size()){
            if(Math.abs(person.get(pIdx) - hamburger.get(hIdx)) <= K){
                pIdx++; hIdx++;
                ans++;
            }else{
                if(person.get(pIdx) < hamburger.get(hIdx)) pIdx++;
                else hIdx++;
            }
        }
        System.out.println(ans);
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}