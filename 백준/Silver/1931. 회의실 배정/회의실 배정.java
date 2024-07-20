import java.io.*;
import java.util.*;

public class Main {
    class Meeting {
        public int start;
        public int end;
        public Meeting(int start, int end){
            this.start = start;
            this.end = end;
        }
    }
  
    public void solution() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        Comparator<Meeting> comparator = new Comparator<Meeting>() {
            @Override
            public int compare(Meeting m1, Meeting m2){
                return m1.end == m2.end ? m1.start - m2.start : m1.end - m2.end;
            }
        };
        
        int N = Integer.parseInt(st.nextToken());
        Meeting[] meetings = new Meeting[N];
        for(int i = 0; i < N; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            meetings[i] = new Meeting(start, end);
        }

        Arrays.sort(meetings, comparator);
        
        int ans = 1;
        int prev = meetings[0].end;
        for(int i = 1; i < N; i++){
            if(prev > meetings[i].start) continue;
            prev = meetings[i].end;
            ans++;
        }
        
        System.out.println(ans);
    }
    public static void main(String[] args) throws Exception {
        new Main().solution();
    }
}