package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;
import java.util.StringTokenizer;

public class Main_17135_캐슬디펜스 {

	private static int N, M, D, y, x, ny, nx, cnt, size, maxScore;
	private static int[][] map, tempMap;
	private static boolean[][] visited;
	private static int[] arrow = new int[3];
	private static int[] dy = {0, -1, 0, 1};
	private static int[] dx = {-1, 0, 1, 0};		//왼쪽을 먼저 탐색할 수 있게 왼쪽부터 간다.
	private static String str;
	private static Queue<int[]> q = new LinkedList<>();	//한번만 할당
	private static HashSet<int[]> list;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());
		map = new int[N+1][M];
		tempMap = new int[N+1][M];
		visited = new boolean[N+1][M];
		list = new HashSet<>();
		for(int i=0;i<N;i++) {
			str = br.readLine();
			for(int j=0;j<M;j++) {
				map[i][j] = str.charAt(j*2) - '0';			
			}
		}
	
		combination(0, 0);
		System.out.println(maxScore);
				
	}

	private static void combination(int cnt, int start) {
		//base_case
		if(cnt == 3) {						//조합 완성
			int localScore = 0;
			for(int i=0;i<N;i++) tempMap[i] =map[i].clone(); 	////맵 복사
			for(int a=0;a<N;a++) {										//맵을 최대 N번 내린다.
				list.clear();
				for(int i=0;i<3;i++) {										//3명의 궁수에 대해
					for(int j=0;j<N;j++) Arrays.fill(visited[j], false);	//돌기 전에 방문배열 초기화
					bfs(arrow[i]);
				}
				for(int num[] : list) {
					if(tempMap[num[0]][num[1]] == 1) {
						tempMap[num[0]][num[1]] = 0;			//3명 다 돌았으니까, 죽은 적 삭제
						localScore++;
					}
				}
				move();														//적들을 내린다.
			}
			maxScore = Math.max(localScore, maxScore);
			return;
		}
		for(int i=start;i<M;i++) {
			arrow[cnt] = i;
			combination(cnt+1, i+1);
		}
		
	}

	private static void bfs(int pos) {
		cnt=0;
		q.clear();
		q.add(new int[] {N, pos});
		while(!q.isEmpty()) {
			size = q.size();
			cnt++;
			if(cnt > D) return;						//공격 범위가 D를 넘겼을 경우에는 그냥 return;
			for(int i=0;i<size;i++) {
				y = q.peek()[0];
				x = q.poll()[1];
				for(int j=0;j<4;j++) {
					ny = y + dy[j];
					nx = x + dx[j];
					if(ny>=0 && ny<N && nx>=0 && nx<M && !visited[ny][nx]) {
						if(tempMap[ny][nx] == 1) {
							list.add(new int[] {ny, nx});				//잡은 적은 게임에서 제외
							return;
						}
						visited[ny][nx] = true;
						q.add(new int[] {ny, nx});
					}
				}
			}	
		}
	}	
	
	private static void move() {				//적들의 하향 진군
		for(int i=N-2;i>=0;i--) {	//밑부터 내림
			for(int j=0;j<M;j++) {
				tempMap[i+1][j] = tempMap[i][j];
			}
		}
		for(int j=0;j<M;j++) {
			tempMap[0][j] = 0;
		}
	}

}
/*
M(가로의 개수)칸에 대하여 궁수가 3명 있는 모든 경우의 수를 구한다.
0~M-1의 수에 대하여 조합을 구하면 되겠지?

거리는 행의 차이값 + 열의 차이값이므로 bfs로 거리를 잴 수 있다. 그 조합들에 대하여 bfs를 수행한다.(cnt를 늘리면서)
궁수 한 명당 bfs 한번(총 3번).
cnt가 D를 넘겼을 때까지 적(1)을 못찾으면 그 궁수는 실패.
찾았으면, score를 늘려주고 해당 궁수에 대한 bfs 종료.

모든 조합에 대해 가장 큰 score를 출력한다.






*/
