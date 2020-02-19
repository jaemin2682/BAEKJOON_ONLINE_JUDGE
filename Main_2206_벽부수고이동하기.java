package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_2206_벽부수고이동하기 {
static int n, m, res=-1;
static String str;
static int map[][];
static boolean visited[][][];
static int[] dy = {0, 0, 1, -1};
static int[] dx = {1, -1, 0, 0};
	static class Pos {
		int y;
		int x;
		int cnt;
		int hasBomb;
		
		public Pos(int y, int x, int cnt, int hasBomb) {
			super();
			this.y = y;
			this.x = x;
			this.cnt = cnt;
			this.hasBomb = hasBomb;	//1이면 이미 사용, 0이면 미사용
		}
	}
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][m];
		visited = new boolean[n][m][2];
		for(int i=0;i<n;i++) {
			str = br.readLine();
			for(int j=0;j<m;j++) {
				map[i][j] = str.charAt(j)-48;
			}
		}
		
		Queue<Pos> q = new LinkedList<Pos>();
		q.add(new Pos(0,0,0,0));
		while(!q.isEmpty()) {
			int x=q.peek().x, y=q.peek().y, cnt=q.peek().cnt, bomb = q.peek().hasBomb;
			q.poll();
			
			if(y==n-1 && x==m-1) {
				res = cnt+1;
				break;
			}
			
			for(int i=0;i<4;i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny >= 0 && ny < n && nx >= 0 && nx < m) {
					if(bomb==0) {	//아직 안박살냈을 때
						if(map[ny][nx] == 1 && !visited[ny][nx][bomb+1]) {	//벽이 있을 때 + 부쉈을 경우 그 위치 방문 안했을 때 > 박살
							visited[ny][nx][bomb+1] = true;
							q.add(new Pos(ny, nx, cnt+1, bomb+1));
						}
						else if(map[ny][nx] == 0 && !visited[ny][nx][bomb]){	//벽이 없을 때 + 부수지 않았을 경우 그 위치 방문 안했을 때
							visited[ny][nx][bomb] = true;
							q.add(new Pos(ny, nx, cnt+1, bomb));
						}
					}
					else {		//이미 박살낸 벽이 있음
						if(map[ny][nx] == 0 && !visited[ny][nx][bomb]) {	//벽이 없을 때만 + 부쉈을 경우 그 위치 방문 안했을 때
							visited[ny][nx][bomb] = true;
							q.add(new Pos(ny, nx, cnt+1, bomb));
						}
						
					}
				
				}
			}
		}
		System.out.println(res);
		
	}

}