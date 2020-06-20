package Algorithm;

import java.util.Scanner;

public class Main_11066_파일합치기 {

	static int K, arr[], sum[], dp[][];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int tc=0;tc<T;tc++) {
			K = sc.nextInt();
			arr = new int[K+1]; sum = new int[K+1]; dp = new int[K+2][K+2];
			for(int i=1;i<=K;i++) {
				arr[i] = sc.nextInt();		//40 30 30 50
				sum[i] = sum[i-1] + arr[i];	//40 70 100 150
			}
			for (int i = 2; i <= K; ++i) {
				for (int j = i - 1; j > 0; --j)	{
					dp[j][i] = 987654321;
					for (int k = j; k <= i; k++) dp[j][i] = Math.min(dp[j][i], dp[j][k] + dp[k + 1][i]);
					dp[j][i] += sum[i] - sum[j - 1];
				}
			}
			System.out.println(dp[1][K]);
		}
	}
}
/*
dp[j][i] : j~i의 파일을 합칠 때의 최소비용
min(j~i) = min(j~k) + min(k+1, i)
dp[j][i] = dp[j][k] + dp[k+1][i]
*/