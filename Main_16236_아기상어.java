package Algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main_16236_아기상어 {

	private static int N, sharkSize = 2, sharkY, sharkX, levelStack, ans;
	private static int[][] map;
	private static ArrayList<Fish> list = new ArrayList<>();
	private static boolean[][] visited;
	
	static class Fish {
		int y, x, dis;
		public Fish(int y, int x, int dis) {
			this.y = y;
			this.x = x;
			this.dis = dis;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		map = new int[N][N]; visited = new boolean[N][N];
		for(int i=0;i<N;i++) for(int j=0;j<N;j++) {
			map[i][j] = sc.nextInt();
			if(map[i][j] == 9) {sharkY = i; sharkX = j; map[i][j] = 0;}
		}
		
		while(true) {
			list.clear();
			for(int i=0;i<N;i++) for(int j=0;j<N;j++) if(map[i][j] < sharkSize && map[i][j] != 0) {	//상어크기보다 작은 모든 물고기들에 대해
				int dis = bfs2(i, j);	//현재 상어위치에서 접근 가능한 것만 add.
				if(dis != -1) list.add(new Fish(i, j, dis));
			}
			if(list.size() == 0) break;
			for(int i=0, size=list.size();i<size;i++) {
				Collections.sort(list, new Comparator<Fish>() {	//거리, y좌표, x좌표 순으로 정렬
					public int compare(Fish o1, Fish o2) {
						if(o1.dis == o2.dis) {
							if(o1.y == o2.y) return Integer.compare(o1.x, o2.x);
							return Integer.compare(o1.y, o2.y);
						}
						return Integer.compare(o1.dis, o2.dis);
					}
				});
				if(bfs(list.get(0).y, list.get(0).x)) {
					levelStack++;
					if(levelStack == sharkSize) {
						sharkSize++;
						levelStack = 0;
					}
				}
			}	
		}
		System.out.println(ans);
		
	}
	
	private static int bfs2(int targetY, int targetX) {
		q.clear();
		for(int i=0;i<N;i++) Arrays.fill(visited[i], false);
		q.add(new int[] {sharkY, sharkX});	//상어 출발!
		visited[sharkY][sharkX] = true;
		int cnt = 0;
		while(!q.isEmpty()) {
			int size = q.size();
			cnt++;
			for(int j=0;j<size;j++) {
				int y = q.peek()[0], x = q.poll()[1];
				for(int i=0;i<4;i++) {
					int ny = y + dy[i], nx = x + dx[i];
					if(ny<0 || ny>=N || nx<0 || nx>=N || visited[ny][nx] || map[ny][nx] > sharkSize) continue;
					if(ny == targetY && nx == targetX) {
						return cnt;
					}
					q.add(new int[] {ny, nx});
					visited[ny][nx] = true;
				}
			}
		}
		return -1;
	}

	private static Queue<int[]> q = new LinkedList<int[]>();
	private static int[] dy = {0, 0, 1, -1}, dx = {1, -1, 0, 0};
	private static boolean bfs(int targetY, int targetX) {
		q.clear();
		for(int i=0;i<N;i++) Arrays.fill(visited[i], false);
		q.add(new int[] {sharkY, sharkX});	//상어 출발!
		visited[sharkY][sharkX] = true;
		int cnt = 0;
		while(!q.isEmpty()) {
			int size = q.size();
			cnt++;
			for(int j=0;j<size;j++) {
				int y = q.peek()[0], x = q.poll()[1];
				for(int i=0;i<4;i++) {
					int ny = y + dy[i], nx = x + dx[i];
					if(ny<0 || ny>=N || nx<0 || nx>=N || visited[ny][nx] || map[ny][nx] > sharkSize) continue;
					if(ny == targetY && nx == targetX) {
						ans += cnt;
						map[ny][nx] = 0;
						sharkY = ny; sharkX = nx;
						return true;
					}
					q.add(new int[] {ny, nx});
					visited[ny][nx] = true;
				}
			}
		}
		return false;
	}

}
/*
0 : 빈 칸, 1 ~ 6 : 물고기의 크기, 9 : 아기상어 위치
*/