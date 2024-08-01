import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        int[] fibonachi = new int[45];
        fibonachi[0] = 1;
        fibonachi[1] = 1;
        for (int i = 2; i < fibonachi.length; i++) {
            fibonachi[i] = fibonachi[i - 1] + fibonachi[i - 2];
        }

        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] answer = new int[45];
            int cur = 0;
            for (int i = 44; i > 0; i--) {
                int temp = fibonachi[i];
                if (temp <= n) {
                    answer[cur] = temp;
                    n -= temp;
                    cur++;
                }
            }
            Arrays.sort(answer);
            for (int i : answer) {
                if (i != 0) {
                    System.out.print(i + " ");
                }
            }
            System.out.println();
        }
    }
}