package Study;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main_6087_레이저통신 {
	static int W, H, map[][], num = 1, sy, sx, ey, ex, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};	
	static PriorityQueue<int[]> q = new PriorityQueue<>(new Comparator<int[]>() {
		@Override
		public int compare(int[] o1, int[] o2) {
			return Integer.compare(o1[3], o2[3]);
		}
	});
	static int visited[][];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		W = sc.nextInt(); H = sc.nextInt();	map = new int[H][W]; visited = new int[H][W];
		for(int i=0;i<H;i++) {
			String str = sc.next();
			for(int j=0;j<W;j++) {
				if(str.charAt(j) == '.') map[i][j] = 0;
				else if(str.charAt(j) == '*') map[i][j] = -1;
				else {
					map[i][j] = num++;
					if(map[i][j] == 1) { sy = i; sx = j; }
					else { ey = i; ex = j; }
				}
			}
		}
		for(int i=0;i<H;i++) Arrays.fill(visited[i], Integer.MAX_VALUE);
		bfs();
		System.out.println(visited[ey][ex]);
	}
	//아래, 위, 오른, 왼 (0, 1, 2, 3)
	static void bfs() {
		for(int i=0;i<4;i++) {
			int y = sy + dy[i], x = sx + dx[i];
			if(y < 0 || y >= H || x < 0 || x >= W || map[y][x] == -1) continue;
			q.add(new int[] {y, x, i, 0});	//y, x, vec, cnt
		}
		while(!q.isEmpty()) {
			int y = q.peek()[0], x = q.peek()[1], vec = q.peek()[2], cnt = q.poll()[3];

			for(int i=0;i<4;i++) {
				int ny = y + dy[i], nx = x + dx[i];
				if(ny < 0 || ny >= H || nx < 0 || nx >= W || map[ny][nx] == -1) continue;
				if((vec == 0 && i == 1) || (vec == 1 && i == 0) || (vec == 2 && i == 3) || (vec == 3 && i == 2)) continue;	
				if(vec == i && visited[ny][nx] >= cnt) {
					visited[ny][nx] = cnt;
					q.add(new int[] {ny, nx, i, cnt});
				}
				else if(vec != i && visited[ny][nx] >= cnt + 1) {
					visited[ny][nx] = cnt + 1;
					q.add(new int[] {ny, nx, i, cnt+1});
				}
			}		
		}
	}
}
