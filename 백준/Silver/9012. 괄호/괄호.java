import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        int T = scanner.nextInt();
        scanner.nextLine();

        String str;
        for(int i = 0; i < T; i++){
            str = scanner.nextLine();
            int len = str.length();
            int left = 0;
            boolean fail = false;

            for(int k = 0; k < len; k++){
                if(str.charAt(k) == '(') left++;
                else{
                    if(left == 0) {
                        fail = true;
                        break;
                    }else left--;
                }
            }
            if(left > 0) fail = true;
            System.out.println(fail ? "NO" : "YES");
        }
    }
}
