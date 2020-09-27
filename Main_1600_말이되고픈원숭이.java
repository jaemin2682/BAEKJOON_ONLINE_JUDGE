package Study;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_1600_¸»ÀÌµÇ°íÇÂ¿ø¼þÀÌ {
	static int K, W, H, map[][], dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0}, ky[] = {-2, -2, -1, 1, 2, 2, 1, -1}, kx[] = {-1, 1, 2, 2, 1, -1, -2, -2};
	static boolean visited[][][];
	static Queue<int[]> q = new LinkedList();
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		K = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken()); H = Integer.parseInt(st.nextToken()); map = new int[H][W]; visited = new boolean[H][W][K+1];
		for(int i=0;i<H;i++) {
			String str = br.readLine();
			for(int j=0;j<W;j++) map[i][j] = str.charAt(j*2) - '0';
		}
		move();
	}
	static void move() {
		q.add(new int[] {0, 0, 0, 0});
		visited[0][0][0] = true;
		
		while(q.size() != 0) {
			int y = q.peek()[0], x = q.peek()[1], kcnt = q.peek()[2], rnd = q.poll()[3];
			if(y == H-1 && x == W-1) {
				System.out.println(rnd);
				return;
			}
	
			if(kcnt < K) {
				for(int i=0;i<8;i++) {
					int ny = y + ky[i], nx = x + kx[i];
					if(ny < 0 || ny >= H || nx < 0 || nx >= W || visited[ny][nx][kcnt+1] || map[ny][nx] == 1) continue;
					q.add(new int[] {ny, nx, kcnt+1, rnd+1});
					visited[ny][nx][kcnt+1] = true;
				}
			}
			
			for(int i=0;i<4;i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if(ny < 0 || ny >= H || nx < 0 || nx >= W || visited[ny][nx][kcnt] || map[ny][nx] == 1) continue;
				q.add(new int[] {ny, nx, kcnt, rnd+1});
				visited[ny][nx][kcnt] = true;
			}
		}
		System.out.println(-1);
	}
}
	