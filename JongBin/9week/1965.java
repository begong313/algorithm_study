import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] arr = new int[N];
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int[] dp = new int[N];
        dp[0] = 1;
        for (int i = 1; i < N; i++) {
            dp[i]=1;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] < arr[i] && dp[i]<=dp[j]) {
                    dp[i] = dp[j]+1;

                }
            }
        }
        System.out.println(Arrays.stream(dp).max().orElse(0));
    }
}