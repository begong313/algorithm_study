import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

class Main {
    static ArrayList<Integer>[] graph;
    static int N, M;
    static boolean answer = false;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        graph = new ArrayList[N];
        for (int i = 0; i < N; i++) {
            graph[i] = new ArrayList<>();
        }
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            graph[b].add(a);
        }
        visited = new boolean[N];
        for (int i = 0; i < N; i++) {
            dfs(0, i);
        }
        if (answer) System.out.println(1);
        else System.out.println(0);
    }

    public static void dfs(int depth, int start) {
        if (depth == 4 || answer) {
            answer = true;
            return;
        }
        visited[start] = true;
        for (int i : graph[start]) {
            if (visited[i]) continue;
            dfs(depth + 1, i);
        }
        visited[start] = false;
    }
}