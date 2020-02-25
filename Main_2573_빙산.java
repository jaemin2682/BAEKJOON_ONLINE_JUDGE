package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_2573_빙산 {

	private static int N, M, ny, nx, y, x, cnt, ans;
	private static boolean isFin;
	private static int[][] map;
	private static boolean[][] visited;
	private static int[] dy = {0, 0, 1, -1};
	private static int[] dx = {1, -1, 0, 0};
	private static Queue<int[]> q = new LinkedList<int[]>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		visited = new boolean[N][M];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++) map[i][j] = Integer.parseInt(st.nextToken());
		}
		
		while(!isFin) {
			if(isEmpty()) {
				ans = 0;
				break;
			}
			ans++;
			check();		//0이 아닌 셀 체크
			melt();			//얼음 녹이기
			bfs();			//몇덩어리인지 체크
		}
		System.out.println(ans);
	}
	
	private static boolean isEmpty() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] != 0) return false;
			}
		}
		return true;
	}

	private static void bfs() {
		q.clear();
		for(int i=0;i<N;i++) Arrays.fill(visited[i], false);
		cnt = 0;
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j]!=0 && !visited[i][j]) {			//0이 아닌 방문하지 않은 셀
					cnt++;
					if(cnt >= 2) {
						isFin = true;
						return;
					}
					q.add(new int[] {i, j});
					visited[i][j] = true;
					while(!q.isEmpty()) {
						y = q.peek()[0];
						x = q.poll()[1];
						for(int l=0;l<4;l++) {
							ny = y + dy[l];
							nx = x + dx[l];
							if(ny>=0 && ny<N && nx>=0 && nx<M && !visited[ny][nx] && map[ny][nx]!=0) {
								visited[ny][nx] = true;
								q.add(new int[] {ny, nx});
							}
						}
					}
				}
			}
		}
	}

	private static void check() {
		for(int i=0;i<N;i++) Arrays.fill(visited[i], false);		//방문배열 초기화
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] != 0) visited[i][j] = true;			//0이 아닌 셀 체크
			}
		}
	}

	private static void melt() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(!visited[i][j]) {									//(체크하지 않은)0인 칸에 대해서
					for(int k=0;k<4;k++) {
						ny = i+dy[k];
						nx = j+dx[k];
						if(ny>=0 && ny<N && nx>=0 && nx<M && map[ny][nx] != 0) map[ny][nx]--;		//0이 아니면 --
					}
				}
			}
		}
	}

}
/*
모든 0인 칸을 돌면서, 사방에 0이 아닌 칸이 있을 때 -1을 시킨다. (녹이기)
bfs로 0이 아닌 모든 칸을 돌면서, 한 칸에 대해 bfs를 돌 때마다 cnt를 증가시키는데 cnt가 2가 되는 순간의 답을 도출 
300*300*4 = 36만 + 9만 = 45만.

*/