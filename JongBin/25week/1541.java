import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), "-");
        int sum = Integer.MAX_VALUE;
        while (st.hasMoreTokens()) {
            int temp = 0;
            StringTokenizer stt = new StringTokenizer(st.nextToken(), "+");
            while (stt.hasMoreTokens()) {
                temp += Integer.parseInt(stt.nextToken());
            }
            if (sum == Integer.MAX_VALUE) {
                sum = temp;
                continue;
            }
            sum -= temp;
        }
        System.out.println(sum);
    }
}