package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_7579_앱 {

	private static int N, M, ans = -1, memory[], cost[], dp[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());  M = Integer.parseInt(st.nextToken());
		memory = new int[N]; cost = new int[N];
		st = new StringTokenizer(br.readLine(), " ");
		for(int i=0;i<N;i++) memory[i] = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine(), " ");
		for(int i=0;i<N;i++) cost[i] = Integer.parseInt(st.nextToken());
		
		dp = new int[11000];	//i 비용으로 dp[i]의 메모리 확보 가능
		Arrays.fill(dp, -1);
		dp[0] = 0;
		
		for(int i=0; i<N; i++){
		    int cur = cost[i];
		    for(int c=10000; c>0; c--){
		        if(c-cur < 0) break;
		        if(dp[c-cur] == -1) continue;
		        dp[c] = Math.max(dp[c], dp[c-cur]+memory[i]);
		    }
		}
		
		for(int i=0; i<=10000; ++i){
		    if(dp[i]==-1) continue;
		    if(dp[i]>=M){
		        ans = i;
		        break;
		    }
		}
		
		System.out.println(ans);
	}

}
