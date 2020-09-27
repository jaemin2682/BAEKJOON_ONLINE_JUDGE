package Study;

import java.util.*;

public class Main_17244_아맞다우산 {
	static int R, C, flag, y, x, time, ny, nx, nFlag, cnt, dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
	static char map[][];
	static boolean visited[][][];
	static Queue<int[]> q = new LinkedList<>();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		C = sc.nextInt(); R = sc.nextInt(); map = new char[R][C]; visited = new boolean[R][C][1<<5];
		for(int i=0;i<R;i++) {
			String str = sc.next();
			for(int j=0;j<C;j++) {
				char cur = str.charAt(j);
				map[i][j] = cur;
				if(cur == 'S') q.add(new int[] {i, j, 0, 0});
				else if(cur == 'X') map[i][j] = (char)(cnt++ + '0');
			}
		}
		while(!q.isEmpty()) {
			y=q.peek()[0]; x=q.peek()[1]; time=q.peek()[2]; flag=q.poll()[3];
			if(map[y][x] == 'E' && flag == (1<<cnt) - 1) {
				System.out.println(time);
				System.exit(0);
			}
			for(int i=0;i<4;i++) {
				ny = y + dy[i]; nx = x + dx[i];
				if(ny < 0 || ny >= R || nx < 0 || nx >= C || map[ny][nx] == '#' || visited[ny][nx][flag]) continue;
				if(map[ny][nx] >= '0' && map[ny][nx] <= '4') {
					nFlag = flag | (1 << (map[ny][nx] - '0'));
					q.add(new int[] {ny, nx, time+1, nFlag});
					visited[ny][nx][nFlag] = true;
				}
				else {
					q.add(new int[] {ny, nx, time+1, flag});
					visited[ny][nx][flag] = true;
				}
			}
		}
	}
}