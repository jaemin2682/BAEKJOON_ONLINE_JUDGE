package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main_14502_연구소 {
	static int N, M, cnt, ans;
	static String str;
	static int map[][];
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
	
	static void bfs() {
		ArrayDeque<Pos> q = new ArrayDeque<>();
		visited = new boolean[N][M];
		cnt = 0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] == 2) {
					q.add(new Pos(i, j));
					visited[i][j] = true;
				}
			}
		}
		
		while(!q.isEmpty()) {
			int y = q.peek().y;
			int x = q.poll().x;
			for(int i=0;i<4;i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny < N && ny >=0 && nx <M && nx >= 0 && !visited[ny][nx] && map[ny][nx] == 0) {
					visited[ny][nx] = true;
					q.add(new Pos(ny, nx));
				}
			}
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] == 0 && !visited[i][j]) cnt++;
			}
		}
		ans = Integer.max(ans,  cnt);
	}
	
	static void wall(int cnt) {
		//base_case
		if(cnt == 3) {
			bfs();
			return;
		}
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(map[i][j] == 0) {
					map[i][j] = 1;
					wall(cnt+1);
					map[i][j] = 0;
				}
			}
		}
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][M];
		for(int i=0;i<N;i++) {
			str = br.readLine();
			for(int j=0, idx=0;j<M;j++, idx+=2) {
				map[i][j] = str.charAt(idx)-'0';
			}
		}
		
		wall(0);
		System.out.println(ans);
	}

}
