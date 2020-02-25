package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.Collections;
import java.util.Queue;

public class Main_1260_DFS와BFS {
	static int N, M, V, num1, num2;
	static ArrayList<Integer> edge[];
	static boolean visited[];
	static boolean visited2[];

	int arr[] = new int[5];

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		V = Integer.parseInt(st.nextToken());
		visited = new boolean[N + 1];
		visited2 = new boolean[N + 1];
		edge = new ArrayList[N + 1];
		for (int i = 1; i <= N; i++) edge[i] = new ArrayList<>();

		for (int i = 0; i < M; i++) { // edge �Է¹ޱ�
			st = new StringTokenizer(br.readLine());
			num1 = Integer.parseInt(st.nextToken());
			num2 = Integer.parseInt(st.nextToken());
			edge[num1].add(num2);
			edge[num2].add(num1);
		}
		for (int i = 1; i <= N; i++) { // �� ������ ���� ������ ����
			Collections.sort(edge[i]);
		}
		
		visited[V] = true;			//���� ������ �湮
		dfs(V, 0);					//dfs
		
		System.out.println();
		bfs(V);						//bfs

	}

	static void dfs(int start, int cnt) {
		// base case
		System.out.print(start + " ");
		// dfs
		int size = edge[start].size();
		for(int i=0;i<size;i++) {
			if(!visited[edge[start].get(i)]) {
				visited[edge[start].get(i)] = true;
				dfs(edge[start].get(i), cnt+1);
			}
		}
	}
	
	static void bfs(int start) {
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.add(start);
		visited2[start] = true;
		while(!q.isEmpty()) {
			int ver = q.poll();
			System.out.print(ver + " ");
			int size = edge[ver].size();
			for(int i=0;i<size;i++) {
				if(!visited2[edge[ver].get(i)]) {
					visited2[edge[ver].get(i)] = true;
					q.add(edge[ver].get(i));
				}
			}
		}
	}

}
