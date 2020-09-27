package Study;

import java.io.*;
import java.util.*;

public class Main_19238_��ŸƮ�ý� {
	static int N, M, fuel, curY, curX, curP, mapS[][];
	static ArrayList<Integer> mapE[][];
	static int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
	static boolean visited[][];
	static Queue<int[]> q = new LinkedList<int[]>();
	static PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
		@Override
		public int compare(int[] o1, int[] o2) {
			if(o1[0] == o2[0]) return Integer.compare(o1[1], o2[1]);
			return Integer.compare(o1[0], o2[0]);
		}
	});
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken()); fuel = Integer.parseInt(st.nextToken());
		mapS = new int[N+1][N+1]; mapE = new ArrayList[N+1][N+1]; visited = new boolean[N+1][N+1];
		for(int i=1;i<N+1;i++) for(int j=1;j<N+1;j++) mapE[i][j] = new ArrayList<Integer>();
		for(int i=1;i<N+1;i++) {
			String str = br.readLine();
			for(int j=1;j<N+1;j++) {
				char cur = str.charAt(j*2-2);
				if(cur =='0') mapS[i][j] = 0;
				else mapS[i][j] = -1;
			}
		}
		// �°��� ��ġ Map, ������ Map ����
		for(int i=1;i<N+1;i++) for(int j=1;j<N+1;j++) if(mapS[i][j] == -1) mapE[i][j].add(-1);
		
		st = new StringTokenizer(br.readLine()); curY = Integer.parseInt(st.nextToken()); curX = Integer.parseInt(st.nextToken());
		for(int i=1;i<M+1;i++) {
			st = new StringTokenizer(br.readLine());
			mapS[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = i;
			mapE[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())].add(i);
		}
		
		boolean isFin = true;
		for(int i=0;i<M;i++) {
			// ���� ����� �°�, �ִܰŸ� ã��
			int dist = findPassenger();		//�ִܰŸ�
			if(dist < 0) { isFin = false; break; }				//�°��� ���� ���, break
			fuel -= dist;
			if(fuel < 0) { isFin = false; break; }				
			dist = findDisTarget();
			if(dist < 0) { isFin = false; break; }
			fuel -= dist;
			if(fuel < 0) { isFin = false; break; }				//�¿��ִ� ���� ������, break
			fuel += dist * 2;				//2�� ����
		}
		if(isFin) System.out.println(fuel);
		else System.out.println(-1);
	}
	
	static int findPassenger() {
		q.clear(); pq.clear();
		for(int i=1;i<N+1;i++) Arrays.fill(visited[i], false);
		q.add(new int[] {curY, curX});
		visited[curY][curX] = true;
		int cnt = 0;
		if(mapS[curY][curX] > 0) {	//������ġ�� ��
			curP = mapS[curY][curX];
			mapS[curY][curX] = 0;
			return cnt;	
		}
		while(q.size() != 0) {
			cnt++;
			for(int c=0, size = q.size();c<size;c++) {
				int y = q.peek()[0], x = q.poll()[1];
				for(int i=0;i<4;i++) {
					int ny = y + dy[i], nx = x + dx[i];
					if(ny < 1 || ny > N || nx < 1 || nx > N || visited[ny][nx] || mapS[ny][nx] == -1) continue;
					if(mapS[ny][nx] > 0) pq.add(new int[] {ny, nx});
					visited[ny][nx] = true;
					q.add(new int[] {ny, nx});
				}
			}
			if(pq.size() != 0) {
				curY = pq.peek()[0]; curX = pq.peek()[1];
				curP = mapS[curY][curX];
				mapS[curY][curX] = 0;
				return cnt;
			}
		}
		return Integer.MIN_VALUE;
	}
	
	static int findDisTarget() {
		q.clear();
		for(int i=1;i<N+1;i++) Arrays.fill(visited[i], false);
		q.add(new int[] {curY, curX});
		visited[curY][curX] = true;
		int cnt = 0;
		while(q.size() != 0) {
			cnt++;
			for(int c=0, size = q.size();c<size;c++) {
				int y = q.peek()[0], x = q.poll()[1];
				for(int i=0;i<4;i++) {
					int ny = y + dy[i], nx = x + dx[i];
					if(ny < 1 || ny > N || nx < 1 || nx > N || visited[ny][nx] || (mapE[ny][nx].size() != 0 && mapE[ny][nx].get(0) == -1)) continue;
					if(mapE[ny][nx].size() != 0) {
						for(int j=0;j<mapE[ny][nx].size();j++) {
							if(mapE[ny][nx].get(j) == curP) {
								curY = ny; curX = nx;
								mapE[curY][curX].set(j, 0);
								return cnt;
							}
							
						}
					}
					visited[ny][nx] = true;
					q.add(new int[] {ny, nx});
				}
			}
		}
		return Integer.MIN_VALUE;
	}

}
/*
N : 2 ~ 20, M : 1 ~ 400
�� : -1, �°� = �°���ȣ

-> Logic
1. ���� ��ġ���� �ִܰŸ��� ���� ª�� �°��� ����. (�������̶�� ���ȣ ������, ����ȣ ������)  * �ýÿ� �°��� ���� ��ġ���, �ִܰŸ��� 0
2. �°��� �ִ� ��ġ�� �ý� �̵�(��ĭ�� ���� -1)
3. �°��� �¿�� �°��� �������� �ý� �̵�(��ĭ�� ���� -1, �����ϸ� �¿�� �̵��� ������ 2�� ����)
4. �̵��ϴ� ���߿� ���ᰡ �ٴڳ��� ���� ���� (�°��� �������� �̵���Ų ���ÿ� ���ᰡ �ٴڳ��� ���� �������� ����)

-> Solve
1. �ý��� ������ġ���� bfs�� ���鼭, ���� ����� �°�, �ִܰŸ��� ã��
2. ���� -= �ִܰŸ� (���ᰡ 0 �̸��� �ȴٸ�, ����)
3. �ý��� ������ġ == ���� ����� �°����� bfs�� ���鼭, �ش� �°��� ���������� �Ÿ��� ã�´�.
4. ���� -= �ִܰŸ� (���ᰡ 0 �̸��� �ȴٸ�, ����)    ->   �����Ѵٸ� ���� += �ִܰŸ� * 2;
*/