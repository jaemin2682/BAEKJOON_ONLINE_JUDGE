package A_ProblemSolving;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_2003_수들의합2 {

	private static int N, M, sum, ans, idx;
	private static String str;
	private static int[] arr;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		arr = new int[N];
		str= br.readLine();
		for(int i=0;i<N;i++) {
			arr[i] = str.charAt(i*2) - '0';
			sum += arr[i];
			while(sum > M) sum-=arr[idx++];
			if(sum == M) ans++;
		}
		System.out.println(ans);
	}

}
