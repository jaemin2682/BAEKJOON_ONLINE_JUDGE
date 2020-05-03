package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_15686_치킨배달 {

	private static int N, M, count, ans = Integer.MAX_VALUE;
	private static int[][] map, tempMap;
	private static String str;
	private static ArrayList<Pos> list = new ArrayList<>();
	private static Pos[] comArr;
	private static Queue<Pos> q = new LinkedList<Pos>();
	private static boolean[][] visited;

	public static class Pos {
		int y; int x;
		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[N][N];
		tempMap = new int[N][N];
		visited = new boolean[N][N];
		for(int i=0;i<N;i++) {
			str = br.readLine();
			for(int j=0;j<N;j++) {
				map[i][j] = str.charAt(j*2) - '0';
				if(map[i][j] == 2) {
					list.add(new Pos(i, j));
					map[i][j] = 0;
				}
			}
		}
		comArr = new Pos[list.size()];
		combi(0, 0);
		System.out.println(ans);
	}
	private static void combi(int cnt, int start) {
		//base_case
		if(cnt == M) {
			mkMap();
			ans = Math.min(ans, chickenDis());
			return;
		}
		for(int i = start;i<list.size();i++) {
			comArr[cnt] = list.get(i);
			combi(cnt+1, i+1);
		}
	}
	
	private static void mkMap() {
		for(int i=0;i<N;i++) tempMap[i] = map[i].clone();
		for(int i=0;i<M;i++) {
			tempMap[comArr[i].y][comArr[i].x] = 2;
		}
	}
	
	private static int chickenDis() {
		int res = 0;
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(map[i][j] == 1) {
					res += bfs(i, j);
				}
			}
		}
		return res;
	}
	
	private static int dy[] = {0, 0, 1, -1};
	private static int dx[] = {1, -1, 0, 0};
	private static int bfs(int y, int x) {
		int sum = 0, cnt = 0;
		for(int i=0;i<N;i++) Arrays.fill(visited[i], false);
		q.clear();
		q.add(new Pos(y, x));
		visited[y][x] = true;
		while(q.size() != 0) {
			cnt++;
			for(int i=0,size=q.size();i<size;i++) {
				int yy = q.peek().y;
				int xx = q.poll().x;
				for(int j=0;j<4;j++) {
					int ny = yy + dy[j];
					int nx = xx + dx[j];
					if(ny>=0 && ny<N && nx>=0 && nx<N && !visited[ny][nx]) {
						if(tempMap[ny][nx] == 2) return cnt;
						q.add(new Pos(ny, nx));
						visited[ny][nx] = true;
					}
				}
			}
		}	
		return -99999999;
	}

}
/*
치킨 거리 : 각 집에서 집과 가장 가까운 치킨집 사이의 거리
도시의 치킨 거리 : 모든 집의 치킨 거리의 합
0:빈칸, 1:집, 2:치킨집
M개의 치킨집을 고르고, 나머지 치킨집은 모두 폐업시켜야 함.
그냥 고르는거니까 조합 가능. 최대 13C6 = 13!/6!/7! = 13 2 11 2 3 > 충분함
모든 조합에 대해서 도시의 치킨 거리를 구하면 된다.
도시의 치킨 거리 구하기 : 최대 2N * N2 = n^3 = 충분(75000)

*/