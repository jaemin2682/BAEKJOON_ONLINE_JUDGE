package Algorithm;

import java.io.*;
import java.util.*;

public class Main_1113_수영장만들기 {

	static int N, M, ans, min = 10, max, map[][], dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
	static Queue<int[]> q = new LinkedList<int[]>();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken()); map = new int[N][M];
		for(int i=0;i<N;i++) {
			String str = br.readLine();
			for(int j=0;j<M;j++) {
				map[i][j] = str.charAt(j) - '0';
				min = Math.min(min, map[i][j]); max = Math.max(max, map[i][j]);
			}
		}
		for(int i=min;i<max;i++) for(int j=1;j<N-1;j++) for(int k=1;k<M-1;k++) if(map[j][k] == i) ans += bfs(i, j, k, 1);
		System.out.println(ans);
	}

	static int bfs(int depth, int sy, int sx, int cnt) {
		q.clear();
		boolean isPossible = true;	//개수에 포함 시킬 건지
		map[sy][sx] = depth+1;
		q.add(new int[] {sy, sx});
		while(!q.isEmpty()) {
			int y = q.peek()[0], x = q.poll()[1];
			for(int i=0;i<4;i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if(ny < 0 || ny >= N || nx < 0 || nx >= M || map[ny][nx] < depth) { isPossible = false; continue; }	//탐색중 경계가 인접 || 목표깊이 미만이면, 이 영역들은 노쓸모
				if(map[ny][nx] != depth) continue;	//depth인 칸으로만 갈거임
				map[ny][nx] = depth + 1;
				cnt++;
				q.add(new int[] {ny, nx});
			}
		}
		if(isPossible) return cnt;
		return 0;
	}
}
