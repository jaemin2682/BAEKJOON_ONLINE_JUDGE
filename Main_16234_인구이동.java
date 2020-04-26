package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_16234_인구이동 {

	private static int N, L, R, num, ans, cnt, sum;
	private static int[][] map, tempMap;
	private static Queue<int[]> q = new LinkedList<int[]>();
	private static boolean[][] visited;
	private static HashMap<Integer, Integer> m = new HashMap<>();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		L = Integer.parseInt(st.nextToken());
		R = Integer.parseInt(st.nextToken());
		map = new int[N][N];
		tempMap = new int[N][N];
		visited = new boolean[N][N];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) map[i][j] = Integer.parseInt(st.nextToken());
		}
		
		while(true) {	//연합이 지어지지 않을 때 stop
			bfs();
			if(tempMap[N-1][N-1] == N*N) break;
			else ans++;
			moving();
		}
		System.out.println(ans);
	}
	private static void moving() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				map[i][j] = m.get(tempMap[i][j]);	
			}
		}		
	}
	static int dy[] = {0, 0, 1, -1};
	static int dx[] = {1, -1, 0, 0};
	private static void bfs() {
		q.clear();
		for(int i=0;i<N;i++) Arrays.fill(visited[i], false);
		for(int i=0;i<N;i++) Arrays.fill(tempMap[i], 0);
		num = 1;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(visited[i][j]) continue;
				q.add(new int[] {i, j});
				visited[i][j] = true;
				tempMap[i][j] = num;
				cnt = 1;
				sum = map[i][j];
				while(q.size() != 0) {
					int y = q.peek()[0];
					int x = q.poll()[1];
					for(int k=0;k<4;k++) {
						int ny = y + dy[k];
						int nx = x + dx[k];
						if(ny>=0 && ny<N && nx>=0 && nx<N && !visited[ny][nx] && Math.abs(map[y][x] - map[ny][nx]) >= L && Math.abs(map[y][x] - map[ny][nx]) <= R) {
							tempMap[ny][nx] = num;
							sum += map[ny][nx];
							cnt++;
							visited[ny][nx] = true;
							q.add(new int[] {ny, nx});
						}
					}
				}
				m.put(num++, sum/cnt);
			}
		}
		
	}
}
/*
1. 국경선을 공유하는 두 나라의 인구 차이가 L~R이라면, 두 나라가 공유하는 국경선을 하루동안 연다.
--> 모든 나라에 대해 bfs를 실행하며 연합번호를 붙인다. 연합번호가 같은 애들끼리 연합이다. 이러면 연합을 맺지 못한 나라는 없다.
2. 이동할 수 있는 칸들끼리는 연합이다. 인구 이동 시작(각 칸의 인구수는 연합의 인구수 / 연합을 이루는 칸의 개수). 소수점은 버린다
3. 연합 해제, 모든 국경선을 닫음


*/