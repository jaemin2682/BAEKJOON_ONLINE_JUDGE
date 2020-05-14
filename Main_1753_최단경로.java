package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_1753_최단경로 {
	static class Edge{
		int num, weight;
		public Edge(int num, int weight) {
			this.num = num;
			this.weight = weight;
		}
	}
	private static int V, E, K;
	private static boolean[] visited;
	private static ArrayList<Edge>[] list;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st= new StringTokenizer(br.readLine());
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(br.readLine());
		list = new ArrayList[V+1];
		for(int i=1;i<=V;i++) list[i] = new ArrayList<Edge>();
		for(int i=0;i<E;i++) {
			st = new StringTokenizer(br.readLine());
			list[Integer.parseInt(st.nextToken())].add(new Edge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		
		PriorityQueue<Edge> pq = new PriorityQueue<>(new Comparator<Edge>() {
			public int compare(Edge o1, Edge o2) {
				return Integer.compare(o1.weight, o2.weight);
			}
		});
		Edge arr[] = new Edge[V+1];
		for(int i=1;i<=V;i++) {
			if(i==K) arr[i] = new Edge(i, 0);
			else arr[i] = new Edge(i, 987654321);
			pq.add(arr[i]);
		}
		
		visited = new boolean[V+1];
		while(!pq.isEmpty()) {
			Edge cur = pq.poll();
			for(Edge other : list[cur.num]) {
				if(!visited[other.num] && arr[cur.num].weight + other.weight < arr[other.num].weight) {
					arr[other.num].weight = arr[cur.num].weight + other.weight;
					pq.remove(arr[other.num]);
					pq.add(arr[other.num]);
				}
			}
			visited[cur.num] = true;
		}
		for(int i=1;i<=V;i++) {
			if(arr[i].weight == 987654321) System.out.println("INF");
			else System.out.println(arr[i].weight);
		}
	}

}
