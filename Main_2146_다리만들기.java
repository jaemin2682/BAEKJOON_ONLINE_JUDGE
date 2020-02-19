package A_ProblemSolving;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

public class Main_2146_다리만들기 {

	private static int N, cnt, number=1, ans = Integer.MAX_VALUE;
	private static int[][] map;
	private static boolean[][] visited;
	private static int dy[] = {0, 0, 1, -1};
	private static int dx[] = {1, -1, 0, 0};
	
	private static String str;
	private static Queue<int[]> q = new LinkedList<int[]>();

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		visited = new boolean[N][N];
		for(int i=0;i<N;i++) {
			str = br.readLine();
			for(int j=0;j<N;j++) map[i][j] = str.charAt(j*2) - '0';
		}
		numbering();		//섬 번호 붙여주기
		mkBridge();
		
//		for(int i=0;i<N;i++) {
//			for(int j=0;j<N;j++) {
//				System.out.print(map[i][j] + " ");
//			}
//			System.out.println();
//		}
		
		System.out.println(ans-1);
	}

	private static void mkBridge() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(map[i][j] != 0)  {		//육지에 대해서만
					cnt = 0;				//이동거리 초기화
					for(int k=0;k<N;k++) Arrays.fill(visited[k], false);
					q.clear();
					q.add(new int[] {i, j});
					turn : 
					while(!q.isEmpty()) {
						cnt++;				//이동거리 증가
						for(int k=0, size=q.size();k<size;k++) {
							int y = q.peek()[0];
							int x = q.poll()[1];
							for(int l=0;l<4;l++) {
								int ny = y + dy[l];
								int nx = x + dx[l];
								if(ny>=0 && ny<N && nx>=0 && nx<N && !visited[ny][nx] && map[ny][nx] != map[i][j]) {
									if(cnt >= ans) {
										break turn;				//이동회수가 답안보다 크게나오면 break;
									}
									if(map[ny][nx] != 0) {		//다른 섬을 만났을 때
										ans = Integer.min(ans, cnt);
										break turn;
									}
									visited[ny][nx] = true;
									q.add(new int[] {ny, nx});
								}
							}
						}
					}
				}
			}
		}
	}

	private static void numbering() {
		q.clear();
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(map[i][j] == 1) {		// 육지에 대해서만
					number++;
					map[i][j] = number;
					visited[i][j] = true;
					q.add(new int[] {i, j});
					while(!q.isEmpty()) {
						int y = q.peek()[0];
						int x = q.poll()[1];
						for(int k=0;k<4;k++) {
							int ny = y + dy[k];
							int nx = x + dx[k];
							if(ny>=0 && ny<N && nx>=0 && nx<N && !visited[ny][nx] && map[ny][nx] == 1) {
								visited[ny][nx] = true;
								q.add(new int[] {ny, nx});
								map[ny][nx] = number;
							}
						}
					}
				}
			}
		}
		
	}

}
/*
각 섬뭉치의 번호를 붙여준다.
N*N을 돌며 모든 육지칸에 대해 bfs를 수행한다.
4면에 대해 바다인 부분에 대해서 뻗어나가며, 다른 번호의 섬을 만나면 종료.
지금까지 구한 최솟값보다 값이 커지면 종료

*/