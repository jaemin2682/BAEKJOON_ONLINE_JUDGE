package Algorithm;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main_17071_숨바꼭질5 {

	private static int N, K, preMoveValue=1;
	private static boolean check;
	private static boolean visited[][] = new boolean[500001][2];

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		if(N==K) System.out.println(0);
		else {
			bfs();
			if(check) System.out.println(preMoveValue);
			else System.out.println(-1);
		}
	}

	private static void bfs() {
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(N);
		
		while(q.size() != 0) {
			K += preMoveValue;
			if(K>500000) return;
			if(visited[K][preMoveValue%2]) {
				check = true;
				return;
			}
			for(int i=0,size=q.size();i<size;i++) {		//qsize
				int pos = q.poll();
				for(int j=0;j<3;j++) {
					int next = 0;
					if(j==0) next = pos+1;				//X+1
					else if(j==1) next = pos-1; 		//X-1
					else if(j==2) next = pos*2;			//X*2
					//System.out.println(next + " " + K);
					
					if(next < 0 || next > 500000) continue;
					if(next == K) {check = true;  return;}
					if(visited[next][preMoveValue%2]) continue;
					
					visited[next][preMoveValue%2] = true;		
					q.add(next);
				}
			}
			preMoveValue++;
		}
	}
}