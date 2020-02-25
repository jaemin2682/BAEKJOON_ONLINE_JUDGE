package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_1175_배달 {

	private static int N, M, time;
	private static boolean isFin, temp;
	private static String str;
	private static char[][] map;
	private static Queue<int[]> q = new LinkedList<>();
	private static boolean[][][][][] visited;
	private static int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new char[N][M];
		visited = new boolean[N][M][5][2][2];
		for(int i=0;i<N;i++) {
			str = br.readLine();
			for(int j=0;j<M;j++) {
				map[i][j] = str.charAt(j);
				if(map[i][j] == 'S') {
					q.add(new int[] {i, j, 4, 0, 0});
				}
				else if(map[i][j]=='C' && !temp) {
					map[i][j] = 'D';
					temp = true;
				}
			}
		}
		bfs();
		if(isFin) System.out.println(time-1);
		else System.out.println(-1);
	}

	private static void bfs() {
		while(q.size() != 0) {
			time++;
			for(int i=0, size=q.size();i<size;i++) {
				int y = q.peek()[0], x=q.peek()[1], vec=q.peek()[2], c=q.peek()[3], d=q.poll()[4];
				if(c==1 && d==1) { 
					isFin = true;
					return;		
				}

				for(int j=0;j<4;j++) {
					if(vec == j) continue;
					int ny = y + dy[j];
					int nx = x + dx[j];
					int temc = c, temd = d;
					if(ny>=0 && ny<N && nx>=0 && nx<M) {
						if(map[ny][nx] == 'C') temc = 1;
						else if(map[ny][nx] == 'D') temd = 1;
						if(map[ny][nx] != '#' && !visited[ny][nx][j][temc][temd]) {
							visited[ny][nx][j][temc][temd] = true;
							q.add(new int[] {ny, nx, j, temc, temd});					
						}
					}
				}
			}
		}
	}

}
