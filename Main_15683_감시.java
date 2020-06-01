package Algorithm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main_15683_감시 {

	static int N, M, ans = Integer.MAX_VALUE;
	static int[][] arr;
	static int[] dy = {-1, 0, 1, 0}, dx = {0, 1, 0, -1};	//0:위, 1:오른쪽, 2:아래, 3:왼쪽
	private static ArrayList<Camera> list;
	private static int[] temp;
	private static Queue<Camera> q = new LinkedList<Camera>();
	private static boolean[][] visited;
	
	static class Camera {
		int y, x, type, vec;
		boolean visited[][];
		
		public Camera(int y, int x, int type, int vec) {
			this.y = y;
			this.x = x;
			this.type = type;
			this.vec = vec;
		}
		public Camera(int y, int x, int type, int vec, boolean[][] visited) {
			this.y = y;
			this.x = x;
			this.type = type;
			this.vec = vec;
			this.visited = visited;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); M = sc.nextInt(); arr = new int[N][M]; visited = new boolean[N][M];
		list = new ArrayList<Camera>();
		for(int i=0;i<N;i++) for(int j=0;j<M;j++) {
			arr[i][j] = sc.nextInt();
			if(arr[i][j] >= 1 && arr[i][j] <= 5) list.add(new Camera(i, j, arr[i][j], -1));
		}
		temp = new int[list.size()];
		makeCom(0);
		
		if(ans == Integer.MAX_VALUE) {
			int cnt = 0;
			for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(arr[i][j] == 0) cnt++;
			System.out.println(cnt);
		}
		else System.out.println(ans);
		
		
	}
	private static void makeCom(int cnt) {
		if(cnt == list.size()) {
			bfs(temp.clone());
			return;
		}
		if(list.get(cnt).type == 1) {
			for(int i=0;i<4;i++) {
				temp[cnt] = i;
				makeCom(cnt+1);
			}
		} else if(list.get(cnt).type == 2) {
			for(int i=0;i<2;i++) {
				temp[cnt] = i;
				makeCom(cnt+1);
			}
		} else if(list.get(cnt).type == 3) {
			for(int i=0;i<4;i++) {
				temp[cnt] = i;
				makeCom(cnt+1);
			}
		}  else if(list.get(cnt).type == 4) {
			for(int i=0;i<4;i++) {
				temp[cnt] = i;
				makeCom(cnt+1);
			}
		}  else if(list.get(cnt).type == 5) {
			temp[cnt] = 0;
			makeCom(cnt+1);
		}
		
		
	}
	//0:위, 1:오른쪽, 2:아래, 3:왼쪽
	private static void bfs(int[] com) {
		q.clear();
		for(int i=0;i<N;i++) Arrays.fill(visited[i], false);
		for(int i=0;i<list.size();i++) {
			Camera cur = list.get(i);
			if(cur.type == 1) {
				if(com[i] == 0) q.add(new Camera(cur.y, cur.x, cur.type, 0, visited.clone()));
				else if(com[i] == 1) q.add(new Camera(cur.y, cur.x, cur.type, 1, visited.clone()));
				else if(com[i] == 2) q.add(new Camera(cur.y, cur.x, cur.type, 2, visited.clone()));
				else if(com[i] == 3) q.add(new Camera(cur.y, cur.x, cur.type, 3, visited.clone()));
			}
			else if(cur.type == 2) {
				if(com[i] == 0) {
					q.add(new Camera(cur.y, cur.x, cur.type, 1, visited.clone()));	//2번카메라 0번 : 좌우
					q.add(new Camera(cur.y, cur.x, cur.type, 3, visited.clone()));
				} else if(com[i] == 1) {
					q.add(new Camera(cur.y, cur.x, cur.type, 0, visited.clone()));	//2번카메라 1번 : 상하
					q.add(new Camera(cur.y, cur.x, cur.type, 2, visited.clone()));
				}
			}
			else if(cur.type == 3) {
				if(com[i] == 0) {
					q.add(new Camera(cur.y, cur.x, cur.type, 0, visited.clone()));	//3번카메라 0번 : 위부터
					q.add(new Camera(cur.y, cur.x, cur.type, 1, visited.clone()));
				} else if(com[i] == 1) {
					q.add(new Camera(cur.y, cur.x, cur.type, 1, visited.clone()));
					q.add(new Camera(cur.y, cur.x, cur.type, 2, visited.clone()));
				} else if(com[i] == 2) {
					q.add(new Camera(cur.y, cur.x, cur.type, 2, visited.clone()));
					q.add(new Camera(cur.y, cur.x, cur.type, 3, visited.clone()));
				} else if(com[i] == 3) {
					q.add(new Camera(cur.y, cur.x, cur.type, 3, visited.clone()));
					q.add(new Camera(cur.y, cur.x, cur.type, 0, visited.clone()));
				}
			}
			else if(cur.type == 4) {
				if(com[i] == 0) {
					q.add(new Camera(cur.y, cur.x, cur.type, 3, visited.clone()));
					q.add(new Camera(cur.y, cur.x, cur.type, 0, visited.clone()));
					q.add(new Camera(cur.y, cur.x, cur.type, 1, visited.clone()));
				} else if(com[i] == 1) {
					q.add(new Camera(cur.y, cur.x, cur.type, 0, visited.clone()));
					q.add(new Camera(cur.y, cur.x, cur.type, 1, visited.clone()));
					q.add(new Camera(cur.y, cur.x, cur.type, 2, visited.clone()));
				} else if(com[i] == 2) {
					q.add(new Camera(cur.y, cur.x, cur.type, 1, visited.clone()));
					q.add(new Camera(cur.y, cur.x, cur.type, 2, visited.clone()));
					q.add(new Camera(cur.y, cur.x, cur.type, 3, visited.clone()));
				} else if(com[i] == 3) {
					q.add(new Camera(cur.y, cur.x, cur.type, 2, visited.clone()));
					q.add(new Camera(cur.y, cur.x, cur.type, 3, visited.clone()));
					q.add(new Camera(cur.y, cur.x, cur.type, 0, visited.clone()));
				}
			}
			else if(cur.type == 5) {
				q.add(new Camera(cur.y, cur.x, cur.type, 0, visited.clone()));
				q.add(new Camera(cur.y, cur.x, cur.type, 1, visited.clone()));
				q.add(new Camera(cur.y, cur.x, cur.type, 2, visited.clone()));
				q.add(new Camera(cur.y, cur.x, cur.type, 3, visited.clone()));
			}
		}
		
		while(!q.isEmpty()) {
			Camera cur = q.poll();
			int ny = cur.y + dy[cur.vec], nx = cur.x + dx[cur.vec];
			boolean[][] checked = cur.visited;
			if(ny < 0 || ny >= N || nx < 0 || nx >= M || arr[ny][nx] == 6) continue;
			visited[ny][nx] = true;
			q.add(new Camera(ny, nx, cur.type, cur.vec, checked));
			int cnt = 0;
			for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(arr[i][j] == 0 && !checked[i][j]) cnt++;
			ans = Math.min(ans, cnt);
		}
		
	}

}
/*
1번 : 4가지
2번 : 2가지
3번 : 4가지
4번 : 4가지
5번 : 1가지
사각지대 : (벽, 카메라, 감시 가능한 지역 제외) 즉, 0 && visited 의 크기
Class : y, x좌표, 카메라 종류, 가능한 상태, 방향
*/