package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;


public class Main_9663_NQueen {
static int N, ans;
static boolean visited[][];
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		visited = new boolean[N][N];
		back(0);
		System.out.println(ans);
	}
	
	static void back(int cnt) {
		//base case
		if(cnt == N) {
			ans++;
			return;
		}
		//back
		for(int i=0;i<N;i++) {
			if(check(cnt, i)) {
				visited[cnt][i] = true;
				back(cnt+1);
				visited[cnt][i] = false;
			}
		}
		
		
	}
	
	static boolean check(int y, int x) {
		boolean a = true;
		for(int i=0;i<N;i++)  {	//�¿�/���� check
			if(visited[y][i] || visited[i][x]) {
				a = false;
				return a;
			}
		}
			//�밢�� check
		for(int i=1;i<=N;i++) {
			if(y+i >= N || x+i >= N) break;
			if(visited[y+i][x+i]) {
				a = false;
				return a;
			}
		}
		
		for(int i=1;i<=N;i++) {
			if(y-i < 0 || x+i >= N) break;
			if(visited[y-i][x+i]) {
				a = false;
				return a;
			}
		}
		
		for(int i=1;i<=N;i++) {
			if(y-i <0  || x-i <0 ) break;
			if(visited[y-i][x-i]) {
				a = false;
				return a;
			}
		}
		
		for(int i=1;i<=N;i++) {
			if(y+i >= N || x-i < 0) break;
			if(visited[y+i][x-i]) {
				a = false;
				return a;
			}
		}
		
		return a;
	}

}
