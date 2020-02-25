package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main_4485_녹색옷입은애가젤다지 {

	private static int N, y, x, ny, nx, tc=1;
	private static int[] dy = {0, 0, -1, 1};
	private static int[] dx = {1, -1, 0, 0};
	private static String str;
	private static int[][] map;
	private static int[][] weight;
	private static final int inf = Integer.MAX_VALUE;

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while(true) {
			N = Integer.parseInt(br.readLine());
			if(N==0) break;

			map = new int[N][N];		//입력받은 가중치
			weight = new int[N][N];		//누적가중치
			for(int i=0;i<N;i++) Arrays.fill(weight[i], inf);
			for(int i=0;i<N;i++) {
				str = br.readLine();
				for(int j=0;j<N;j++) {
					map[i][j] = str.charAt(j*2) - '0';
				}
			}
			dijkstra();
			System.out.println("Problem "+tc++ + ": " + weight[N-1][N-1]);
		}
	}

	private static void dijkstra() {
		Queue<int[]> q = new LinkedList<>();
		q.add(new int[] {0, 0});
		weight[0][0] = map[0][0];
		while(!q.isEmpty()) {
			y = q.peek()[0];
			x = q.poll()[1];
			for(int i=0;i<4;i++) {
				ny = y + dy[i];
				nx = x + dx[i];
				if(ny>=0 && ny<N && nx>=0 && nx<N) {
					if(weight[y][x] + map[ny][nx] < weight[ny][nx]) {	//나의 누적 가중치 + 다음녀석의 가중치가 다음녀석의 누적가중치보다 작으면
						weight[ny][nx] = weight[y][x] + map[ny][nx];	//바꿔주고
						q.add(new int[] {ny, nx});		//push
					}
				}
			}
		}
		
	}
	
	

}
