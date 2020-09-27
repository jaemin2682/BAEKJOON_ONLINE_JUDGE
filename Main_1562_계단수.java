package Study;

import java.util.Arrays;
import java.util.Scanner;

public class Main_1562_계단수 {
	static int N, ans, dp[][][];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();	dp = new int[10][N+1][1<<10];
		for(int i=1;i<10;i++) {
			for(int a=0;a<10;a++) for(int b=0;b<N+1;b++) Arrays.fill(dp[a][b], -1);
			ans += dfs(i, 1, 1 << i);
			ans %= 1000000000;
		}
		System.out.println(ans);
	}
	static int dfs(int number, int size, int flag) {
		if(size == N) return flag == (1<<10) - 1 ? 1 : 0;	// 크기가 N일 떄, 모든 수를 사용했으면 존재.
		if(dp[number][size][flag] != -1) return dp[number][size][flag];
		
		int res = 0;
		if(number - 1 >= 0) res += dfs(number-1, size+1, flag | 1 << (number - 1));	// 1 작은 숫자로
		if(number + 1 < 10) res += dfs(number+1, size+1, flag | 1 << (number + 1)); // 1 큰 숫자로
		
		res %= 1000000000;
		dp[number][size][flag] = res;
		return res;
	}
}
