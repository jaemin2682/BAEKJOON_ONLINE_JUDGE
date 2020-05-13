package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_12736_Fireworks {
	private static PriorityQueue<Long> pq[];
	private static int N, M;
	private static int P[], C[], D[];
	private static long E[];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		pq = new PriorityQueue[300004];
		P = new int[300004];
		C = new int[300004];
		D = new int[300004];
		E = new long[300004];
		
		for(int i=2;i<=N+M;i++) {
			st = new StringTokenizer(br.readLine());
			P[i] = Integer.parseInt(st.nextToken());	//연결점의 번호
			C[i] = Integer.parseInt(st.nextToken());	//도환선의 길이
		}

		for(int i=1;i<=N+M;i++) {						//최대힙
			pq[i] = new PriorityQueue<Long>(Collections.reverseOrder());
		}
		
		for(int i=N+M;i>=2;i--) {
			long l = 0, r = 0;
			
			if(D[i]!=0) {
				for(int j=1;j<D[i];j++) if(!pq[i].isEmpty()) E[i] += pq[i].poll();
				if(!pq[i].isEmpty()) l = pq[i].poll();
				if(!pq[i].isEmpty()) r = pq[i].poll();
			}
			
			pq[i].add(l+(long)C[i]);
			pq[i].add(r+(long)C[i]);
			E[i] -= (long)C[i];
		
			if(pq[i].size() > pq[P[i]].size()) {			//사이즈가 작은 pq의 원소를 큰 pq의 원소에 모두 넣어준다.
				while(!pq[P[i]].isEmpty())	pq[i].add(pq[P[i]].poll());
			}
			else {
				while(!pq[i].isEmpty())	pq[P[i]].add(pq[i].poll());
			}
				
			E[P[i]] += E[i];
			D[P[i]]++;
		}
		long ans = E[1];
		for(int i=0;i<D[1];i++)  ans += pq[1].poll();
		System.out.println(ans);
	}

}
