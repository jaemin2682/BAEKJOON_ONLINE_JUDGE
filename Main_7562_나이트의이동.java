package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main_7562_나이트의이동 {
	static int t, L, startY, startX, targetY, targetX, size, cnt;
	static boolean visited[][];
	static ArrayDeque<Pos> q;
	static int dy[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
	static int dx[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

	static class Pos {
		int y;
		int x;

		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}
	
	static void bfs() {
		q = new ArrayDeque<>();
		q.add(new Pos(startY, startX));
		visited[startY][startX] = true;

		while (!q.isEmpty()) {
			size = q.size();
			cnt++;
			for (int j = 0; j < size; j++) {
				int x = q.peek().x;
				int y = q.poll().y;
				if(y == targetY && x == targetX) return;
				for (int i = 0; i < 8; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny < L && ny >= 0 && nx < L && nx >= 0 && !visited[ny][nx]) {
						visited[ny][nx] = true;
						q.add(new Pos(ny, nx));
					}
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		t = Integer.parseInt(br.readLine());
		for (int tc = 0; tc < t; tc++) {
			L = Integer.parseInt(br.readLine());
			cnt = -1;
			visited = new boolean[L][L];
			StringTokenizer st = new StringTokenizer(br.readLine());
			startY = Integer.parseInt(st.nextToken());
			startX = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			targetY = Integer.parseInt(st.nextToken());
			targetX = Integer.parseInt(st.nextToken());

			bfs();
			
			System.out.println(cnt);
		}
	}
}
