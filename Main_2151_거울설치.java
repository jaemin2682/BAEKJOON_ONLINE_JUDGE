package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Main_2151_거울설치 {

	private static int N, sy, sx, ey, ex, y, x, vector, ny, nx, ans = Integer.MAX_VALUE;
	private static String str;
	private static char[][] map;
	private static int[][][] visited;
	private static Queue<int[]> q = new LinkedList<int[]>();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new char[N][N];	visited = new int[N][N][4];
		boolean isChecked = false;
		for(int i=0;i<N;i++) {
			str = br.readLine();
			for(int j=0;j<N;j++) {
				map[i][j] = str.charAt(j);
				if(!isChecked && map[i][j] == '#') {sy = i; sx = j; map[i][j] = '*'; isChecked = true;}	//첫 "#"의 위치 저장	
				if(isChecked && map[i][j] == '#') {ey = i; ex = j;};
			}
		}

		bfs();
		
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<N;j++) System.out.print(visited[i][j][2] + " ");
//			System.out.println();
//		}
		
		for(int i=0;i<4;i++) {
			if(visited[ey][ex][i] == 0) continue;
			ans = Math.min(ans, visited[ey][ex][i]);
		}
		if(ans == Integer.MAX_VALUE) ans = 0;
		if(sy == ey) {
			boolean tem = true;
			int min = Math.min(sx, ex), max = Math.max(sx, ex);
			for(int i = min+1; i < max; i++) {
				if(map[sy][i] == '*') tem = false;
			}
			if(tem) ans = 0;
		}
		if(sx == ex) {
			boolean tem = true;
			int min = Math.min(sy, ey), max = Math.max(sy, ey);
			for(int i = min+1; i < max; i++) {
				if(map[i][sx] == '*') tem = false;
			}
			if(tem) ans = 0;
		}
		System.out.println(ans);
		
		

//		System.out.println(visited[ey][ex][0]);
//		System.out.println(visited[ey][ex][1]);
//		System.out.println(visited[ey][ex][2]);
//		System.out.println(visited[ey][ex][3]);
	}

	static int[] dy= {0, 1, 0, -1}, dx = {1, 0, -1, 0};	//오른, 아래, 왼쪽, 위
	
	private static void bfs() {
		for(int i=0;i<4;i++) {	//시작점의 4방향 중, 갈 수 있는 부분만 Queue에 넣는다.(y, x, 방향)
			ny = sy + dy[i]; nx = sx + dx[i];
			if(ny<0 || ny>=N || nx<0 || nx>=N || map[ny][nx] == '*') continue;
			q.add(new int[] {ny, nx, i});
		}
		while(q.size() != 0) {
			y = q.peek()[0]; x = q.peek()[1]; vector = q.poll()[2];
			//성공조건. #
			if(map[y][x] == '#') {
				continue;
			}
			
			if(map[y][x] == '!') {		//거울 설치 가능 장소를 만났을 때
				int newVec = -1;
				for(int i=0;i<3;i++) {
					if(i==0) {	//같은 방향으로 계속 이동
						ny = y + dy[vector]; nx = x + dx[vector];
					}
					else if(i==1) {	//시계방향으로 90도 꺾음
						newVec = (vector+1)%4;
						ny = y + dy[newVec]; nx = x + dx[newVec];
					}
					else if(i==2) {	//반시계방향으로 90도 꺾음
						newVec = vector-1 == -1 ? 3 : vector-1;
						ny = y + dy[newVec]; nx = x + dx[newVec];
					}
					if(ny<0 || ny>=N || nx<0 || nx>=N || map[ny][nx] == '*') continue;
					if(i==0) {
					//	if(visited[ny][nx][vector] != 0) continue;
						if(visited[ny][nx][vector] > visited[y][x][vector] || visited[ny][nx][vector] == 0) {
							visited[ny][nx][vector] = visited[y][x][vector];
							q.add(new int[] {ny, nx, vector});
						}
					}
					else {
					//	if(visited[ny][nx][newVec] != 0) continue;
						if(visited[ny][nx][newVec] > visited[y][x][vector] + 1 || visited[ny][nx][newVec] == 0) {
							visited[ny][nx][newVec] = visited[y][x][vector] + 1;
							q.add(new int[] {ny, nx, newVec});
						}
					}
				}				
			}
			else if(map[y][x] == '.') {
				ny = y + dy[vector]; nx = x + dx[vector];
				if(ny<0 || ny>=N || nx<0 || nx>=N || map[ny][nx] == '*') continue;
				if(visited[ny][nx][vector] > visited[y][x][vector] || visited[ny][nx][vector] == 0) {
				//	if(visited[ny][nx][vector] != 0) continue;
					visited[ny][nx][vector] = visited[y][x][vector];
					q.add(new int[] {ny, nx, vector});
				}
			}
		}
	}
}
/*
한 문에서 시작한다.
계속 같은 방향으로만 이동해야 하고, !를 만났을 때 3가지 경우가 생기게 된다.
1. 같은 방향으로 계속 이동(거울 사용 X)
2. 시계방향으로 90도 꺾음
3. 시계방향으로 -90도 꺾음
*/
