package Study;

import java.util.Scanner;

public class Main_9944_NM보드완주하기 {
	static int N, M, ans, map[][], dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
	public static void main(String[] args) {	
		Scanner sc = new Scanner(System.in);
		int rnd = 0;
		while(sc.hasNext()) {
			N = sc.nextInt(); M = sc.nextInt(); ans = Integer.MAX_VALUE; rnd++; map = new int[N][M];
			for(int i=0;i<N;i++) {
				String str = sc.next();
				for(int j=0;j<M;j++) {
					char cur = str.charAt(j);
					if(cur == '*') map[i][j] = -1;
					else map[i][j] = 0;
				}
			}
			
			for(int i=0;i<N;i++) {
				for(int j=0;j<M;j++) {
					if(map[i][j] == -1) continue;
					for(int k=0;k<4;k++) {
						map[i][j] = 1;
						dfs(i, j, k, 1);	//현재 위치, 방향, cnt
						map[i][j] = 0;
					}
				}
			}
			int cnt = 0;
			if(ans == 1) for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(map[i][j] == 0) cnt++;
			
			if(cnt == 1) System.out.println("Case " + rnd + ": 0");
			else if(ans == Integer.MAX_VALUE) System.out.println("Case " + rnd + ": -1");
			else System.out.println("Case " + rnd + ": " + ans);
		}
	}
	
	static void dfs(int y, int x, int vec, int cnt) {
		int ny = y + dy[vec], nx = x + dx[vec];
		boolean isFin = true;
		
		end:
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(map[i][j] == 0) { isFin = false; break end; }
		if(isFin) {
			ans = Integer.min(ans, cnt);
			return;
		}
		
		if(ny < 0 || ny >= N || nx < 0 || nx >= M || map[ny][nx] == -1 || map[ny][nx] == 1) {	//방향 수정
			for(int i=0;i<4;i++) {
				if(i == vec) continue;
				ny = y + dy[i]; nx = x + dx[i];
				if(ny < 0 || ny >= N || nx < 0 || nx >= N || map[ny][nx] == -1 || map[ny][nx] == 1) continue;
				map[ny][nx] = 1;
				dfs(ny, nx, i, cnt+1);
				map[ny][nx] = 0;
			}
		}
		else {	//기존 방향
			map[ny][nx] = 1;
			dfs(ny, nx, vec, cnt);
			map[ny][nx] = 0;
		}	
	}
}