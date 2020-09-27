package Study;

import java.io.*;
import java.util.*;

public class Main_19238_스타트택시 {
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
		// 승객의 위치 Map, 도착지 Map 생성
		for(int i=1;i<N+1;i++) for(int j=1;j<N+1;j++) if(mapS[i][j] == -1) mapE[i][j].add(-1);
		
		st = new StringTokenizer(br.readLine()); curY = Integer.parseInt(st.nextToken()); curX = Integer.parseInt(st.nextToken());
		for(int i=1;i<M+1;i++) {
			st = new StringTokenizer(br.readLine());
			mapS[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = i;
			mapE[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())].add(i);
		}
		
		boolean isFin = true;
		for(int i=0;i<M;i++) {
			// 가장 가까운 승객, 최단거리 찾음
			int dist = findPassenger();		//최단거리
			if(dist < 0) { isFin = false; break; }				//승객이 없을 경우, break
			fuel -= dist;
			if(fuel < 0) { isFin = false; break; }				
			dist = findDisTarget();
			if(dist < 0) { isFin = false; break; }
			fuel -= dist;
			if(fuel < 0) { isFin = false; break; }				//태워주다 연료 소진시, break
			fuel += dist * 2;				//2배 충전
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
		if(mapS[curY][curX] > 0) {	//현재위치일 때
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
벽 : -1, 승객 = 승객번호

-> Logic
1. 현재 위치에서 최단거리가 가장 짧은 승객을 고른다. (여러명이라면 행번호 작은순, 열번호 작은순)  * 택시와 승객이 같은 위치라면, 최단거리는 0
2. 승객이 있는 위치로 택시 이동(한칸당 연료 -1)
3. 승객을 태우고 승객의 목적지로 택시 이동(한칸당 연료 -1, 도착하면 태우고 이동한 연료의 2배 충전)
4. 이동하는 도중에 연료가 바닥나면 로직 종료 (승객을 목적지로 이동시킨 동시에 연료가 바닥나는 경우는 성공으로 인정)

-> Solve
1. 택시의 현재위치에서 bfs를 돌면서, 가장 가까운 승객, 최단거리를 찾음
2. 연료 -= 최단거리 (연료가 0 미만이 된다면, 실패)
3. 택시의 현재위치 == 가장 가까운 승객에서 bfs를 돌면서, 해당 승객의 목적지와의 거리를 찾는다.
4. 연료 -= 최단거리 (연료가 0 미만이 된다면, 실패)    ->   성공한다면 연료 += 최단거리 * 2;
*/