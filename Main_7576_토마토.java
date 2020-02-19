package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main_7576_토마토 {

	private static int M;
	private static int N;
	private static int cnt;
	private static int[] dy = {0, 0, 1, -1};
	private static int[] dx = {1, -1, 0, 0};
	
	private static int[][] tomato;
	private static ArrayDeque<int[]> q;
	private static boolean[][] visited;

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		q = new ArrayDeque<>();
		visited = new boolean[N][M];
		tomato = new int[N][M];
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<M;j++) {
				tomato[i][j]  = Integer.parseInt(st.nextToken());
				if(tomato[i][j]==1) {
					q.add(new int[] {i, j});	//익은 토마토를 전부 큐에 넣어줌.
					visited[i][j] = true;
				}
			}
		}
		bfs();
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				if(tomato[i][j] == 0) {
					System.out.println(-1);
					System.exit(0);
				}
			}
		}
		System.out.println(cnt-1);
	}

	private static void bfs() {
		while(!q.isEmpty()) {
			int size = q.size();
			cnt++;
			for(int j=0;j<size;j++) {
				int y = q.peek()[0];
				int x = q.poll()[1];
				for(int i=0;i<4;i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if(ny>=0 && ny<N && nx>=0 && nx<M && !visited[ny][nx] && tomato[ny][nx] == 0) {
						q.add(new int[] {ny, nx});
						tomato[ny][nx] = 1;
						visited[ny][nx] = true;
					}
				}
			}
		}
	}

}
