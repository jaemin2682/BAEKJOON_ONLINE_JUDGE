package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_1238_파티 {
	private static int N, M, X, ans;
	private static int[][] road, inverseRoad;
	private static Person[] arr;
	private static int[] time;
	private static final int INF = 2000000;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		X = Integer.parseInt(st.nextToken());
		road = new int[N+1][N+1];	//1 ~ N
		inverseRoad = new int[N+1][N+1];
		arr = new Person[N+1];
		time = new int[N+1];
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken()), e = Integer.parseInt(st.nextToken());
			int dis = Integer.parseInt(st.nextToken());
			if(road[s][e] == 0) road[s][e] = dis;
			else road[s][e] = Math.min(road[s][e], dis);
		}
		for(int i=1;i<=N;i++)	//반대엣지
			for(int j=1;j<=N;j++) inverseRoad[j][i] = road[i][j];

		dijkstra(X, road);	//주어진 엣지의 방향 : X에서 출발
		for(int i=1;i<=N;i++) time[i] += arr[i].time;
		dijkstra(X, inverseRoad);	//주어진 엣지의 반대 방향 : X로 도착
		for(int i=1;i<=N;i++) time[i] += arr[i].time;
		
		for(int i=1;i<=N;i++) ans = Math.max(ans, time[i]);
		System.out.println(ans);
	}

	static class Person {
		int num;
		int time;
		public Person(int num, int time) {
			super();
			this.num = num;
			this.time = time;
		}
	}
	
	private static PriorityQueue<Person> pq = new PriorityQueue<>(new Comparator<Person>() {
		public int compare(Person o1, Person o2) {
			return Integer.compare(o2.time, o1.time);
		}
	});
	
	private static void dijkstra(int start, int[][] roads) {
		pq.clear();
		for(int i=1;i<=N;i++) {
			if(i==start) arr[i] = new Person(i, 0);		//시작점은 0
			else arr[i] = new Person(i, INF);			//나머지는 INF
			pq.add(arr[i]);
		}
		
		while(!pq.isEmpty()) {
			Person cur = pq.poll();
			for(int i=1;i<=N;i++) {
				if(roads[cur.num][i] == 0) continue;	//경로가 없으면 continue
				if(cur.num == i) continue;				//본인 -> 본인은 continue
				Person other = arr[i];
				int dif = cur.time + roads[cur.num][other.num];
				if(other.time > dif) {
					other.time = dif;
					pq.remove(other);
					pq.add(other);
					arr[i] = other;
				}
			}
		}
	}

}
