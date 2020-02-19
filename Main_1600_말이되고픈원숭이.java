package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main_1600_말이되고픈원숭이 {
	static int Dy[] = {-2,-1,1,2,2,1,-1,-2};
	static int Dx[] = {1,2,2,1,-1,-2,-2,-1};
	static int dy[] = {0, 0, 1, -1};
	static int dx[] = {1, -1, 0, 0};
	static int K, W, H, y, x, knight, ny, nx, cnt;
	static int map[][];
	static boolean visited[][][];
	static String str;
	
	static class Pos {
		int y;
		int x;
		int knight;
		int cnt;
		public Pos(int y, int x, int knight, int cnt) {
			super();
			this.y = y;
			this.x = x;
			this.knight = knight;
			this.cnt = cnt;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		K  = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken());
		H = Integer.parseInt(st.nextToken());
		map = new int[H][W];
		visited = new boolean[H][W][K+1];
		
		for(int i=0;i<H;i++) {
			str = br.readLine();
			for(int j=0, idx=0;j<W;j++, idx+=2) {
				map[i][j] = str.charAt(idx) - '0';
			}
		}
		
		int count = bfs();
		System.out.println(count);
	}
	
	static int bfs() {
		ArrayDeque<Pos> q = new ArrayDeque<>();
		q.add(new Pos(0, 0, 0, 0));
		while(!q.isEmpty()) {
			y = q.peek().y;
			x = q.peek().x;
			knight = q.peek().knight;
			cnt = q.poll().cnt;
			
			if(y==H-1 && x==W-1) return cnt;
			
			if(knight < K) {
				for(int i=0;i<8;i++) {
					ny = y + Dy[i];
					nx = x + Dx[i];
					if(ny<H && ny>=0 && nx<W && nx>=0 && !visited[ny][nx][knight+1] && map[ny][nx]==0) {
						visited[ny][nx][knight+1] =  true;
						q.add(new Pos(ny, nx, knight+1, cnt+1));
					}
				}
			}
			for(int i=0;i<4;i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if(ny<H && ny>=0 && nx<W && nx>=0 && !visited[ny][nx][knight]&& map[ny][nx] ==0) {
					visited[ny][nx][knight] = true;
					q.add(new Pos(ny, nx, knight, cnt+1));
				}
			}
		}
		return -1;
	}
}

/*
k번 말처럼 움직일 수 있다.
bfs는 무조건 처음 도착하는 시점이 최단시간임.
말처럼 움직이는 것에 우선순위를 둔다.
*/