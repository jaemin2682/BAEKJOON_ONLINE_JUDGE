package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_2234_성곽 {

	private static int W, H, roomNum, maxCnt, maxSize, breakMaxSize;
	private static int[][] map, room;
	private static int[] sum;
	private static Queue<int[]> q = new LinkedList<int[]>();
	private static boolean[][] visited;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		W = Integer.parseInt(st.nextToken()); H = Integer.parseInt(st.nextToken());
		map = new int[H][W]; visited = new boolean[H][W]; room = new int[H][W];
		sum = new int[2501];
		for(int i=0;i<H;i++) {		//map input
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<W;j++) map[i][j] = Integer.parseInt(st.nextToken());
		}
		bfs();	//방의 개수와 가장 넓은 방의 넓이를 구하기 위한 bfs
		System.out.println(maxCnt);
		System.out.println(maxSize);
		for(int i=0;i<H;i++) {
			for(int j=0;j<W;j++) {
				for(int k=0;k<4;k++) {	//다른방이고 상하좌우로 인접해있으면, 모든 경우의 두 방의 크기를 더해준다.(벽 있는게 무조건 높음)
					int ny = i + dy[k];
					int nx = j + dx[k];
					if(ny>=0 && ny<H && nx>=0 && nx<W) {
						if(room[i][j] != room[ny][nx])		//해당 방번호의 합끼리 더해준 것의 최대치를 구함.
							breakMaxSize = Math.max(breakMaxSize, sum[room[i][j]] + sum[room[ny][nx]]);
					}
				}
			}
		}
		System.out.println(breakMaxSize);
	}

	static int dy[] = {0, -1, 0, 1}, dx[] = {-1, 0, 1, 0};
	private static void bfs() {
		for(int i=0;i<H;i++) {		//H*W에 대해 모두 진행
			for(int j=0;j<W;j++) {
				if(visited[i][j]) continue;		//방문했던 곳이면 넘김
				int sz = 1;
				roomNum++;
				maxCnt++;	//와보지 않은 방이니 방의 개수 증가
				q.add(new int[] {i, j});		//시작점 출발, 방의 넓이 1로 시작
				visited[i][j] = true;
				room[i][j] = roomNum;
				while(q.size() != 0) {
					int y = q.peek()[0], x = q.poll()[1];
					room[y][x] = roomNum;
					for(int k=0;k<4;k++) {
						int ny = y + dy[k], nx = x + dx[k];
						if(ny<0 || ny>=H || nx<0 || nx>=W) continue;	//범위넘기면 넘김
						if(visited[ny][nx]) continue;	//방문한 곳이면 넘김
						if((map[y][x] & 1 << k) == 0) {	//해당 map의 숫자의 2진수의 자릿수가 0이면(해당 방향의 벽이 없으면)
							sz++;
							q.add(new int[] {ny, nx});	//새 좌표와 ++된 사이즈를 넘김
							visited[ny][nx] = true;				//방문표시
						}
					}
				}
				sum[roomNum] = sz;
				maxSize = Math.max(maxSize, sz);		//최대 size 갱신
			}
		}
	}
}
/*

7 4
11 6  11 6  3  10 6
7  9  6  13 5  15 5
1  10 12 7  13 7  5
13 11 10 8  10 12 13

4방향으로 이동하는데, 해당 칸의 숫자의 (왼쪽에서) 0번째가 1이면 왼쪽이동 X, 1번째가 1이면 위쪽이동 X, 2번째가 1이면 오른쪽이동 X, 3번쨰가 1이면 아래쪽이동 X

왼쪽 벽 : 1, 위쪽 벽 : 2, 동쪽 벽 : 4, 남쪽 벽 : 8
*/