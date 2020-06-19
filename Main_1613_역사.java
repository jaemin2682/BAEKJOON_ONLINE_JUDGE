package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_1613_역사 {

	private static int n, k, s, prev, post;
	private static boolean[][] dist;
	private static boolean[] visited;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		dist = new boolean[n+1][n+1];
		visited = new boolean[n+1];
 		for(int i = 0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			dist[Integer.parseInt(st.nextToken())][Integer.parseInt(st.nextToken())] = true;
		}
 		
 		for(int k=1;k<n+1;k++) {		//floyd
 			for(int i=1;i<n+1;i++) {
 				for(int j=1;j<n+1;j++) {
 					if(dist[i][k] && dist[k][j]) dist[i][j] = true;	//i>k, k>j로 가는 경로가 있으면, i>j도 있음.
 				}
 			}
 		}
		s = Integer.parseInt(br.readLine());
		for(int i = 0; i < s; i++) {
			st = new StringTokenizer(br.readLine());
			prev = Integer.parseInt(st.nextToken());
			post = Integer.parseInt(st.nextToken());
			if(dist[prev][post]) System.out.println(-1);
			else if(dist[post][prev]) System.out.println(1);
			else System.out.println(0);
		}
	}
}
/*
floyd로 a > b로 갈 수 있는 경로들에 대해 모두 구함.
a > b로 갈 수 있으면, a가 시간적으로 먼저 일어난 일임
b > a로 갈 수 있으면, b가 시간적으로 먼저.
둘다 아니면, 갈 수 없음(0)
*/