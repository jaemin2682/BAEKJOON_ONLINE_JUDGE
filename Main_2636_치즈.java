package baekjoon;

import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.BufferedReader;

public class Main_2636_치즈 {
	static int N, M, x, y, nx, ny, num=3, cnt, totCnt = -1, temCnt;
	static String str;
	static int cheese[][];
	static ArrayDeque<Pos> q;
	static boolean visited[][];
	static int dy[] = {0, 0, 1, -1};
	static int dx[] = {1, -1, 0, 0};
	
	static class Pos {
		int y;
		int x;
		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		cheese = new int[N][M];
		visited = new boolean[N][M];
		for(int i=0;i<N;i++) {
			str = br.readLine();
			for(int j=0, idx=0;j<M;j++, idx+=2) {
				cheese[i][j] = str.charAt(idx) - '0';
				if(cheese[i][j] == 1) cnt++;
			}
		}
		
		temCnt = cnt;
		
		while(totCnt!=0) {
			for(int i=0;i<N;i++) Arrays.fill(visited[i], false);
			cnt = 0;
			bfs();
		}
		System.out.println(num - 3);
		System.out.println(temCnt);
		
		
		
	}
	
	static void bfs() {
		q = new ArrayDeque<>();
		q.add(new Pos(0, 0));
		visited[0][0] = true;
		cheese[0][0] = num;
		while(!q.isEmpty()) {
			y = q.peek().y;
			x = q.poll().x;
			for(int i=0;i<4;i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if(ny < N && ny >= 0 && nx < M && nx >= 0 && !visited[ny][nx] && cheese[ny][nx] != 1) {
					visited[ny][nx] = true;
					cheese[ny][nx] = num;
					q.add(new Pos(ny, nx));
				}
			}
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(cheese[i][j] == num) {
					for(int k=0;k<4;k++) {
						ny = i+dy[k];
						nx = j+dx[k];
						if(ny < N && ny >= 0 && nx < M && nx >= 0 && cheese[ny][nx] == 1) {
							cheese[ny][nx] = num+1;
						}
					}
				}
			}
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(cheese[i][j] == 1) cnt++;
			}
		}
		totCnt = cnt;
		if(cnt != 0) temCnt = cnt;
		num++;
	}

}
/*
�ݺ� : 
�����ڸ�(0, 0)���� bfs�� �����ؼ� 0�� ���� 3���� �ٲ۴�. 3�� ����
N*M�� ���鼭, 3�� ���� �ִ� 1�� ���� 3���� �ٲ۴�.

*/
