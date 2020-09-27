package Study;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_2533_��ȸ������SNS {
	
	static int N, par, chil, dp[][];
	static ArrayList<Integer> rel[]; 
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		N = Integer.parseInt(br.readLine());	dp = new int[N+1][2];
		rel = new ArrayList[N+1];	for(int i=1;i<N+1;i++) rel[i] = new ArrayList<>();
		
		for(int i=0;i<N-1;i++) {
			st = new StringTokenizer(br.readLine(), " ");  par = Integer.parseInt(st.nextToken());	chil = Integer.parseInt(st.nextToken());
			rel[par].add(chil);	rel[chil].add(par);
		}
		
		for(int i=1;i<=N;i++) Arrays.fill(dp[i], -1);
		//��Ʈ�� ������ 1?
		System.out.println(Math.min(dfs(1, 0, 1) + 1, dfs(1, 0, 0)));
	}
	
	static int dfs(int cur, int prev, int chk) {
		if(dp[cur][chk] != -1) return dp[cur][chk];
		else dp[cur][chk] = 0;
		
		for(int i = 0, size = rel[cur].size();i<size;i++) {
			int next = rel[cur].get(i);
			if(next == prev) continue;
			if(chk == 1) dp[cur][chk] += Math.min(dfs(next, cur, 0), dfs(next, cur, 1) + 1);	//�󸮾������ �� : ���� ���� �󸮾���� or Not
			else dp[cur][chk] += dfs(next, cur, 1) + 1;	//�ƴ� �� : �����ִ� ������ �󸮾����
		}
		return dp[cur][chk];
	}

}
