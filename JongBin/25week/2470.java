import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int min = Integer.MAX_VALUE;
        int answer1 = 0;
        int anwer2 = n - 1;

        int left = 0;
        int right = n - 1;
        Arrays.sort(arr);
        while (left < right) {
            int sum = arr[left] + arr[right];
            int currentABS = Math.abs(sum);
            if (currentABS < min) {
                min = currentABS;
                answer1 = arr[left];
                anwer2 = arr[right];
            }
            if (sum > 0) {
                right--;
            } else {
                left++;
            }

        }
        System.out.println(answer1 + " " + anwer2);
    }
}