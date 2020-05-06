package Algorithm;

import java.util.Scanner;

public class Main_6987_월드컵 {

	private static int[][] arr;
	private static int[][] resultArr;
	private static int[][] daejin = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}};
	private static boolean isPossible;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);		
		for(int i=0;i<4;i++)  {
			arr = new int[6][3];
			resultArr = new int[6][3];		//0:승리, 1:무승부, 2:패배
			for(int j=0;j<18;j++) arr[j/3][j%3] = sc.nextInt();
			isPossible = false;
			dfs(0);
			if(isPossible) System.out.print(1 + " ");
			else System.out.print(0 + " ");
		}
		
	}

	private static void dfs(int cnt) {
		//base_case
		if(cnt == 15) {
			boolean isFin = true;
			end:
			for(int i=0;i<6;i++) {
				for(int j=0;j<3;j++) {
					if(resultArr[i][j] != arr[i][j]) {
						isFin = false;
						break end;
					}
				}
			}
			if(isFin) isPossible = true;
			return;
		}
		int team1 = daejin[cnt][0], team2 = daejin[cnt][1];
		
		//승리 시
		resultArr[team1][0]++;
		resultArr[team2][2]++;
		dfs(cnt+1);
		resultArr[team1][0]--;
		resultArr[team2][2]--;
		//무승부 시
		resultArr[team1][1]++;
		resultArr[team2][1]++;
		dfs(cnt+1);
		resultArr[team1][1]--;
		resultArr[team2][1]--;
		//패배 시
		resultArr[team1][2]++;
		resultArr[team2][0]++;
		dfs(cnt+1);
		resultArr[team1][2]--;
		resultArr[team2][0]--;
	}

}

/*
A B C D E F
A vs {B, C, D, E, F}
B VS {C, D, E, F}
C VS {D, E, F}
D VS {E, F}
E VS {F}
= 15가지

각 팀은 이기거나 지거나 무승부가 가능

*/