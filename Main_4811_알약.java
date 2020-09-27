package Study;

import java.util.Scanner;

public class Main_4811_알약 {
	static long peel[][] = new long[31][31];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int num = sc.nextInt();
			if(num == 0) break;
			System.out.println(dfs(num, 0));
		}
	}
	// 가능 문자열(w, h) : 반 조각을 먹었을 경우(w, h-1) + 한 조각을 먹었을 경우(w-1, h+1)
	static long dfs(int w, int h) {
		long result = peel[w][h];
		if(result != 0) return result;
		
		result = 0;
		if(h > 0) result += dfs(w, h-1);	// 반 조각을 먹었을 경우
		if(w > 0) result += dfs(w-1, h+1);	// 한 조각을 먹었을 경우
		else return 1;
	
		peel[w][h] = result;
		return result;
	}

}
