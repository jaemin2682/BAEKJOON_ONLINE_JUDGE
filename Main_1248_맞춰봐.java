package Algorithm;

import java.util.Scanner;

public class Main_1248_맞춰봐 {

	static int N, res[];
	static char arr[][];
	static String str;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); arr = new char[N][N]; res = new int[N];	str = sc.next();
		for(int i=0, idx = 0;i<N;i++) for(int j=i;j<N;j++) arr[i][j] = str.charAt(idx++);
		dfs(0);	
	}

	static void dfs(int cur) {
		if(cur == N) {
			for(int i=0;i<N;i++) System.out.print(res[i] + " ");
			System.exit(0);;
		}
		for(int i=-10;i<=10;i++) {
			res[cur] = i;
			if(check(cur)) dfs(cur+1);
		}
	}

	static boolean check(int cur) {	//현재까지 다 만족하는지 확인
		for(int i=0;i<=cur;i++) {
			int sum = 0;
			for(int j=i;j<=cur;j++) {
				sum += res[j];
				char oper = sum > 0 ? '+' : sum < 0 ? '-' : '0';
				if(oper != arr[i][j]) return false;
			}
		}
		return true;
	}
}