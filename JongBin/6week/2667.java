import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int map[][];
    static boolean visit[][];
    static int N;// 지도 최대크기
    static int count = 1;
    static int x[] = {-1, 1, 0, 0};
    static int y[] = {0, 0, -1, 1};

    public static void dfs(int i, int j) {
        map[i][j] = count;
        visit[i][j] = true;

        for (int k = 0; k < x.length; k++) {
            int ix = i + x[k];
            int jy = j + y[k];

            if (ix >= 0 && ix < N && jy >= 0 && jy < N) {
                if (map[ix][jy] == 1 && !visit[ix][jy]) {
                    dfs(ix, jy);
                }
            }
        }
    }
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new int [N][N];
        for(int i=0; i<N; i++){
            String[] input = br.readLine().split("");
            for(int j =0;j<N;j++){
                map[i][j] = Integer.parseInt(input[j]);
            }
        }
        visit = new boolean[N][N];
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(map[i][j] ==1 && !visit[i][j]){
                    dfs(i,j);
                    count++;
                }
            }
        }
        System.out.println(count-1);
        int result[] = new int[count];
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(map[i][j] != 0)
                    result[map[i][j]]++;
            }
        }
        Arrays.sort(result);
        for(int i=1; i<result.length; i++) {
            System.out.println(result[i]);
        }
    }
}