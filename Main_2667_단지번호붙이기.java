package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;

public class Main_2667_단지번호붙이기 {
	static int N, size, num, cnt;
	static int map[][];
	static boolean visited[][];
	static String str;
	static int dy[] = {0, 0, 1, -1};
	static int dx[] = {1, -1, 0, 0};
	
	static class Pos {
		int y;
		int x;
		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}
	
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		visited = new boolean[N][N];
		for(int i=0;i<N;i++) {
			str = br.readLine();
			for(int j=0;j<N;j++) {
				map[i][j] = str.charAt(j) - '0';
			}
		}
		
		ArrayDeque<Pos> q = new ArrayDeque<>();
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(map[i][j] != 0 && !visited[i][j]) {
					q.add(new Pos(i, j));
					num++;
					visited[i][j] = true;
					map[i][j] = num;
					while(!q.isEmpty()) {
						int y = q.peek().y;
						int x = q.poll().x;
						for(int k=0;k<4;k++) {
							int ny = y + dy[k];
							int nx = x + dx[k];
							if(ny < N && ny >=0 && nx < N && nx >= 0 && !visited[ny][nx] && map[ny][nx] != 0) {
								map[ny][nx] = num;
								cnt++;
								visited[ny][nx] = true;
								q.push(new Pos(ny, nx));
							}
						}
					}
				}
			}
		}
		
		System.out.println(num);
		int arr[] = new int[num];
		for(int i=1;i<=num;i++) {
			cnt = 0;
			for(int j=0;j<N;j++) {
				for(int k=0;k<N;k++) {
					if(map[j][k] == i) cnt++;
				}
			}
			arr[i-1] = cnt;
		}
		Arrays.sort(arr);
		for(int i=0;i<num;i++) {
			System.out.println(arr[i]);
		}
	}

}
