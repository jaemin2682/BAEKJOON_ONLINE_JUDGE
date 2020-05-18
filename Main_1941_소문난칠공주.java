package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main_1941_소문난칠공주 {
	static char[][] arr = new char[5][5];
	static int ans;
	static int[] tempArr = new int[7];
	static int[][] visited = new int[5][5];
	static Queue<int[]> q = new LinkedList<int[]>();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i=0;i<5;i++) {
			String str = br.readLine();
			for(int j=0;j<5;j++)  arr[i][j] = str.charAt(j);
		}
		makeCom(0, 0);
		System.out.println(ans);
	}
	
	private static void makeCom(int start, int cnt) {
		if(cnt == 7) {
			int yNum = 0;
			for(int i=0;i<7;i++) {	//임도연파가 4명 이상이면 return;
				if(arr[tempArr[i]/5][tempArr[i]%5] == 'Y') yNum++;
				if(yNum == 4) return;
			}
			for(int i=0;i<5;i++) Arrays.fill(visited[i], 0);
			for(int i=0;i<7;i++) visited[tempArr[i]/5][tempArr[i]%5] = 1;
			bfs(tempArr[0]/5, tempArr[0]%5);	//다 연결되어있는지 첫놈으로 탐색
		
			for(int i=0;i<7;i++) if(visited[tempArr[i]/5][tempArr[i]%5] != 2) return;
			ans++;
			return;
		}
		for(int i=start;i<25;i++) {
			tempArr[cnt] = i;
			makeCom(i+1, cnt+1);
		}
	}
	static int[] dy = {0, 0, 1, -1}, dx = {1, -1, 0, 0};
	private static void bfs(int y, int x) {
		q.clear();
		visited[y][x] = 2;
		q.add(new int[] {y, x});
		int count = 0;
		while(!q.isEmpty()) {
			count++;
			if(count == 7) return;
			for(int j = 0, size = q.size();j<size;j++) {
				int yy = q.peek()[0], xx = q.poll()[1];
				for(int i=0;i<4;i++) {
					int ny = yy + dy[i], nx = xx + dx[i];
					if(ny<0 || ny>=5 || nx<0 || nx>=5 || visited[ny][nx] != 1) continue;
					visited[ny][nx] = 2;
					q.add(new int[] {ny, nx});
				}
			}
		}
	}

}
/*
S:이다솜파, Y:임도연파
모든 자리에서 탐색 시작. 사방탐색으로 하나씩 이어가고, 7명을 채워야 함. 이다솜파의 학생이 적어도 4명은 있어야함(임도연파가 4명이 되는 순간 return)
25C7 = 25!/7!18! = 480,700
*/