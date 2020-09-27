package Study;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_2917_�����ɲ� {
	static int N, M, dist[][], sy, sx, ey, ex, y, x, ny, nx, dis, maxDis, dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
	static boolean[][] visited;
	static Queue<int[]> q = new LinkedList<int[]>();
	static PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
		@Override
		public int compare(int[] o1, int[] o2) {
			return Integer.compare(o2[0], o1[0]);
		}
	});
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken()); dist = new int[N][M]; visited = new boolean[N][M];
		// �� �Է¹���, �������� �ּҰŸ� set
		for(int i=0;i<N;i++) {
			String str = br.readLine();
			for(int j=0;j<M;j++) {
				char cur = str.charAt(j);
				if(cur == '+') {
					dist[i][j] = 0;
					q.add(new int[] {i, j});
				}
				else dist[i][j] = -1;
				
				if(cur == 'V') { sy = i; sx = j; }
				else if(cur == 'J') {ey = i; ex = j; }
			}
		}
		// �������� �ּҰŸ� ���ϱ�
		while(q.size() != 0) {
			y = q.peek()[0]; x = q.poll()[1];
			for(int i=0;i<4;i++) {
				ny = y + dy[i]; nx = x + dx[i];
				if(ny < 0 || ny >= N || nx < 0 || nx >= M || dist[ny][nx] != -1) continue;
				dist[ny][nx] = dist[y][x] + 1;
				q.add(new int[] {ny, nx});
			}
		}
		// ������ �Ÿ��� �ּڰ��� ���� ū ��� ���ϱ�
		pq.add(new int[] {dist[sy][sx], sy, sx});
		visited[sy][sx] = true;
		while(pq.size() != 0) {
			maxDis = pq.peek()[0]; y = pq.peek()[1]; x = pq.poll()[2];
			for(int i=0;i<4;i++) {
				ny = y + dy[i]; nx = x + dx[i];
				if(ny < 0 || ny >= N || nx < 0 || nx >= M || visited[ny][nx]) continue;
				if(ny == ey && nx == ex) {
					System.out.println(Math.min(dist[ny][nx], maxDis));
					System.exit(0);
				}
				visited[ny][nx] = true;
				pq.add(new int[] {Math.min(dist[ny][nx], maxDis), ny, nx});
			}
		}
	}

}
