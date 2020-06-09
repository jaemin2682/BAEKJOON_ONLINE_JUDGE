package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_1939_중량제한 {

	static int N, M, island1, island2, ans;
	static ArrayList<int[]> list[];
	private static boolean[] visited;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());	M = Integer.parseInt(st.nextToken());
		list = new ArrayList[N+1];	visited = new boolean[N+1];
		for(int i=1;i<=N;i++) list[i] = new ArrayList<int[]>();
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			int first = Integer.parseInt(st.nextToken()), last = Integer.parseInt(st.nextToken()), weight = Integer.parseInt(st.nextToken());
			list[first].add(new int[] {last, weight}); list[last].add(new int[] {first, weight});
		}
		st = new StringTokenizer(br.readLine());
		island1 = Integer.parseInt(st.nextToken()); island2 = Integer.parseInt(st.nextToken());
		
		int left = 0, right = 1000000000, mid = 0;
		while(left <= right) {
			mid = (left + right) / 2;
			if(dfs(island1, mid)) {
				ans = mid;
				left = mid + 1;
			}
			else right = mid - 1;
			Arrays.fill(visited, false);
		}
		System.out.println(ans);
	}

	static boolean dfs(int cur, int weight) {
		//base_case
		visited[cur] = true;
		if(cur == island2) {
			return true;
		}		
		for(int i=0;i<list[cur].size();i++) {
			int[] other = list[cur].get(i);
			if(visited[other[0]] || weight > other[1]) continue;
			if(dfs(other[0], weight)) return true;
		}
		return false;
	}
}