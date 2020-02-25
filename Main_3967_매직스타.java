package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main_3967_매직스타 {
	static int arr[], index[];
	static int count;
	static boolean visited[];
	static char tem;
	static char[][] star;
	static String str;
	public static void main(String[] args) throws Exception {	
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		star = new char[5][9];
		visited = new boolean[13];
		arr = new int[12];
		
		for(int i=0;i<5;i++) {
			str = br.readLine();
			for(int j=0;j<9;j++) {
				star[i][j] = str.charAt(j);
			}
		}
		
		if(star[0][4] >='A' && star[0][4] <= 'L') arr[0] = star[0][4]-'A'+1;
		if(star[1][1] >='A' && star[1][1] <= 'L') arr[1] = star[1][1]-'A'+1;
		if(star[1][3] >='A' && star[1][3] <= 'L') arr[2] = star[1][3]-'A'+1;
		if(star[1][5] >='A' && star[1][5] <= 'L') arr[3] = star[1][5]-'A'+1;
		if(star[1][7] >='A' && star[1][7] <= 'L') arr[4] = star[1][7]-'A'+1;
		if(star[2][2] >='A' && star[2][2] <= 'L') arr[5] = star[2][2]-'A'+1;
		if(star[2][6] >='A' && star[2][6] <= 'L') arr[6] = star[2][6]-'A'+1;
		if(star[3][1] >='A' && star[3][1] <= 'L') arr[7] = star[3][1]-'A'+1;
		if(star[3][3] >='A' && star[3][3] <= 'L') arr[8] = star[3][3]-'A'+1;
		if(star[3][5] >='A' && star[3][5] <= 'L') arr[9] = star[3][5]-'A'+1;
		if(star[3][7] >='A' && star[3][7] <= 'L') arr[10] = star[3][7]-'A'+1;
		if(star[4][4] >='A' && star[4][4] <= 'L') arr[11] = star[4][4]-'A'+1;
		
		for(int i=0;i<12;i++) {	//이미 숫자가 들어있는 경우에는 방문처리를 해줌
			if(arr[i] != 0) visited[arr[i]] = true;
			else count++;
		}
		index = new int[count];
		int id = 0;
		for(int i=0;i<12;i++)
			if(arr[i] == 0) index[id++] = i;
			
		dfs(0);
	}
	
	static void dfs(int cnt) {
		//base_case
		if(cnt == count) {
			if(arr[0] == 7) System.exit(0);
			if(arr[0]+arr[2]+arr[5]+arr[7] == 26 &&
					arr[0]+arr[3]+arr[6]+arr[10] == 26 &&
					arr[1]+arr[5]+arr[8]+arr[11] == 26&&
					arr[4]+arr[6]+arr[9]+arr[11] == 26 &&
					arr[1]+arr[2]+arr[3]+arr[4] == 26 &&
					arr[7]+arr[8]+arr[9]+arr[10] == 26) {
				
				star[0][4] = (char)(arr[0] + 'A' - 1);
				star[1][1] = (char)(arr[1] + 'A' - 1);
				star[1][3] = (char)(arr[2] + 'A' - 1);
				star[1][5] = (char)(arr[3] + 'A' - 1);
				star[1][7] = (char)(arr[4] + 'A' - 1);
				star[2][2] = (char)(arr[5] + 'A' - 1);
				star[2][6] = (char)(arr[6] + 'A' - 1);
				star[3][1] = (char)(arr[7] + 'A' - 1);
				star[3][3] = (char)(arr[8] + 'A' - 1);
				star[3][5] = (char)(arr[9] + 'A' - 1);
				star[3][7] = (char)(arr[10] + 'A' - 1);
				star[4][4] = (char)(arr[11] + 'A' - 1);
				
				for(int i=0;i<5;i++) {
					for(int j=0;j<9;j++) {
						System.out.print(star[i][j]);
					}
					System.out.println();
				}
				
				System.exit(0);
			}
		}
		
//		if(arr[0]+arr[2]+arr[5]+arr[7] > 26) return;
//		if(arr[0]+arr[3]+arr[6]+arr[10] > 26) return;
//		if(arr[1]+arr[5]+arr[8]+arr[11] > 26) return;
//		if(arr[4]+arr[6]+arr[9]+arr[11] > 26) return;
//		if(arr[1]+arr[2]+arr[3]+arr[4] > 26) return;
//		if(arr[7]+arr[8]+arr[9]+arr[10] > 26) return;
//		
		
		//back
		for(int i=1;i<=12;i++) {
			if(visited[i]) continue;
			visited[i] = true;
			arr[index[cnt]] = i;
			dfs(cnt+1);
			arr[index[cnt]] = 0;
			visited[i] = false;
		}
	}

}
/*
1차행렬에 1~12가지를 넣는다. (아는 숫자는 숫자 입력, 모르는 자리는 0 입력)
dfs를 돌면서 6가지 경우에 대해 모두 만족하는지 숫자를 하나씩 넣어봄
그 중, 합이 26을 넘어가면, 그냥 return 
6 1 9 4 11 8 5 3 10 2 11 
*/
