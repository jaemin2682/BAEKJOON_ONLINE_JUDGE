package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;

public class Main_2667_단지번호붙이기_dfs {
static int N, ny, nx, cnt;
static int map[][];
static int dy[] = {0, 0, 1, -1};
static int dx[] = {1, -1, 0, 0};
private static String str;
private static boolean[][] visited;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		visited = new boolean[N][N];
		for(int i=0;i<N;i++) {
			str = br.readLine();
			for(int j=0;j<N;j++) {
				map[i][j] = str.charAt(j) - '0';
			}
		}
		LinkedList<Integer> list = new LinkedList<>();
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(map[i][j] == 1 && !visited[i][j]) {
					cnt = 1;
					dfs(i, j);
					if(cnt > 1) cnt--;
					list.add(cnt);
				}
			}
		}
		Collections.sort(list);
		System.out.println(list.size());
		for(int a : list) System.out.println(a);
	}
	private static void dfs(int y, int x) {
		for(int i=0;i<4;i++) {
			ny = y + dy[i];
			nx = x + dx[i];
			if(ny>=0 && ny<N && nx>=0 && nx<N && map[ny][nx]==1 && !visited[ny][nx]) {
				visited[ny][nx] = true;
				cnt++;
				dfs(ny, nx);
			}
		}
	}
}
