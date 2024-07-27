import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while (T-- > 0) {

            PriorityQueue<Long> pq = new PriorityQueue<>();
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                pq.add(Long.valueOf(st.nextToken()));
            }
            long answer = 1L;

            while (pq.size() > 1) {
                Long a = pq.poll();
                Long b = pq.poll();
                Long temp = a * b;
                answer = (answer % 1000000007) * (temp % 1000000007);
                pq.add(temp);
            }
            System.out.println(answer % (1000000007));
        }


    }
}


