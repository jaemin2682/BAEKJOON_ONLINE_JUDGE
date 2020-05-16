package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_4991_로봇청소기 {

	private static int H, W, sy, sx, targetCnt, y, x, ny, nx, flag, success;
	private static String str;
	private static int[][] map;
	private static int[][][] dist;
	private static Queue<int[]> q = new LinkedList<int[]>();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			W = Integer.parseInt(st.nextToken()); H = Integer.parseInt(st.nextToken());
			if(W == 0 && H == 0) break;
			map = new int[H][W]; q.clear(); targetCnt=0;//initialize
			for(int i=0;i<H;i++) {
				str = br.readLine();
				for(int j=0;j<W;j++) {
					char cur = str.charAt(j);
					if(cur == 'o') { sy = i; sx = j; }	//시작위치 좌표 저장
					else if(cur == '*') map[i][j] = ++targetCnt;	//더러운칸의 Numbering, 개수 세기
					else if(cur == 'x') map[i][j] = -1;		//가구는 -1
				}	//나머지 깨끗한칸은 0
			}
			success = (1 << targetCnt) - 1;				//모든 더러운 칸을 청소했을 때 bitMask가 가지는 숫자
			dist = new int[H][W][(1 << (targetCnt))+1];	//(i, j, k) : (i,j)칸에서 청소한 더러운 칸의 정보를 가지는 배열
			System.out.println(bfs());
		}
	}
	static int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
	private static int bfs() {
		q.add(new int[] {sy, sx, 0});	//'o'칸 0개 청소상태로 시작
		while(q.size() != 0) {
			y = q.peek()[0]; x = q.peek()[1]; flag = q.poll()[2];
			if(flag == success) return dist[y][x][flag];
			for(int i=0;i<4;i++) {
				ny = y + dy[i]; nx = x + dx[i];
				if(ny<0 || ny >= H || nx<0 || nx>=W || map[ny][nx] == -1) continue;	//경계검사, 가구인지 검사
				if(map[ny][nx] > 0 && dist[ny][nx][flag | (1 << (map[ny][nx]-1))] == 0) {	//더러운 방이고 돌아오는게 아닐 때
					q.add(new int[] {ny, nx, flag | (1 << (map[ny][nx]-1))});
					dist[ny][nx][flag | (1 << (map[ny][nx]-1))] = dist[y][x][flag] + 1;
				
				}
				else if(map[ny][nx] == 0 && dist[ny][nx][flag] == 0) {	//깨끗한 방일 때, 돌아오는거 아닐 때
					q.add(new int[] {ny, nx, flag});
					dist[ny][nx][flag] = dist[y][x][flag]+1;
				}
			}
		}
		return -1;
	}
}
/*
BFS로 가구를 피해 더러운 칸을 모두 깨끗한 칸으로 만드는 최소 이동 횟수를 구하는 문제.
간 장소를 다시 갈 수 있기 때문에, 같은 상태로 다시 가면 안되는걸 기록.
*/