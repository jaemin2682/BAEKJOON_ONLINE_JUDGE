package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main_1697_숨바꼭질 {

	private static int N;
	private static int K;
	private static int cnt;
	private static boolean[] visited;

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		visited = new boolean[Math.max(N, K)*2+1];
		bfs();
		
		System.out.println(cnt-1);
	}

	private static void bfs() {
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.offer(N);
		while(!q.isEmpty()) {
			int size = q.size();
			cnt++;
			if(visited[K] == true) return;
			for(int j=0;j<size;j++) {
				int cur = q.poll();
				if(cur == K) return;
				
				for(int i=0;i<3;i++) {
					int next = 0;
					if(i==0) next = cur + 1;
					else if(i==1) next = cur - 1;
					else if(i==2) next = cur * 2;
					
					if(next >= 0 && next <= Math.max(N,  K)*2 && !visited[next]) {
						q.offer(next);
						visited[next] = true;
					}
				}
			}
		}
	}
	
	

}
