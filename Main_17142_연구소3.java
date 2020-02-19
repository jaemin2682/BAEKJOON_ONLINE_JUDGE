package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_17142_연구소3 {
	static int N, M, size, res, ans = Integer.MAX_VALUE;
	static int virus[][];
	static boolean visited[][];
	static String str;
	static ArrayList<Pos> list;
	static Pos arr[];
	static int dy[] = { 0, 0, 1, -1 };
	static int dx[] = { 1, -1, 0, 0 };
	static boolean check = true, localCheck;

	public static class Pos {	//좌표 클래스
		int y;
		int x;
		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}

	}

	public static void makeArr(int cnt, int start) {	//조합 만드는 메소드(DFS)
		if (cnt == M) { // 바이러스 조합 완성 시
			res = -1; // 결과값 초기화
			localCheck = true;
			bfs();
			back: for (int i = 0; i < N; i++) { // 바이러스를 다 퍼뜨리지 못한 경우
				for (int j = 0; j < N; j++) {
					if (!visited[i][j] && virus[i][j] == 0) {
						localCheck = false;
						break back;
					}
				}
			}
			if (localCheck)
				ans = Integer.min(res, ans);
			
			
			res = -1; // 결과값 초기화
			localCheck = true;
			bfs2();	
			back: for (int i = 0; i < N; i++) { // 바이러스를 다 퍼뜨리지 못한 경우
				for (int j = 0; j < N; j++) {
					if (!visited[i][j] && virus[i][j] == 0) {
						localCheck = false;
						break back;
					}
				}
			}
			if (localCheck)
				ans = Integer.min(res, ans);
			return;
		}
		for (int i = start; i < list.size(); i++) {
			arr[cnt] = list.get(i);
			makeArr(cnt + 1, i + 1);
		}

	}

	public static void bfs() {
		Queue<Pos> q = new LinkedList<Pos>();
		for (int i = 0; i < N; i++)
			Arrays.fill(visited[i], false); // 방문배열 초기화
		size = arr.length;
		for (int i = 0; i < size; i++) {
			visited[arr[i].y][arr[i].x] = true;
			q.add(arr[i]); // 큐에 2가 든 좌표들을 넣는다.
		}

		while (!q.isEmpty()) {
			int size = q.size();
			res++;
			for (int j = 0; j < size; j++) {
				int y = q.peek().y;
				int x = q.poll().x;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
						if (!visited[ny][nx] && virus[ny][nx] == 0) {
							visited[ny][nx] = true;
							q.add(new Pos(ny, nx));	
						} 
					}
				}
			}
		}
	}
	
	public static void bfs2() {
		Queue<Pos> q = new LinkedList<Pos>();
		for (int i = 0; i < N; i++)
			Arrays.fill(visited[i], false); // 방문배열 초기화
		size = arr.length;
		for (int i = 0; i < size; i++) {
			visited[arr[i].y][arr[i].x] = true;
			q.add(arr[i]); // 큐에 2가 든 좌표들을 넣는다.
		}

		while (!q.isEmpty()) {
			int size = q.size();
			res++;
			for (int j = 0; j < size; j++) {
				int y = q.peek().y;
				int x = q.poll().x;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny >= 0 && ny < N && nx >= 0 && nx < N) {
						if (!visited[ny][nx] && virus[ny][nx] != 1) {
							visited[ny][nx] = true;
							q.add(new Pos(ny, nx));	
						} 
					}
				}
			}
		}
	}

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());

		list = new ArrayList<Pos>();
		virus = new int[N][N];
		visited = new boolean[N][N];
		arr = new Pos[M];
		for (int i = 0; i < N; i++) {
			str = br.readLine();
			for (int j = 0, index = 0; j < N; j++, index += 2) {
				virus[i][j] = str.charAt(index) - '0';
				if (virus[i][j] == 2) list.add(new Pos(i, j)); // 바이러스가 있는 좌표를 list에 넣는다.
			}
		}

		makeArr(0, 0);

		if (ans == Integer.MAX_VALUE)
			System.out.println(-1);
		else
			System.out.println(ans);
	}

}
/*
 * 2가 있는 좌표들을 모두 배열에 저장한다. 그 배열에 가능한 조합들에 대해 모두 BFS를 실행한다. BFS를 실행한 결과 중 가장 작은
 * 시간을 출력한다.
 */