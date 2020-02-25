package A_ProblemSolving;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main_7662_이중우선순위큐 {

	
	private static PriorityQueue<int []> max = new PriorityQueue<>(new Comparator<int[]>() {
		public int compare(int[] o1, int[] o2) {
			return o2[0] - o1[0];
		}
	});
	private static PriorityQueue<int []> min = new PriorityQueue<>(new Comparator<int[]>() {
		public int compare(int[] o1, int[] o2) {
			return o1[0] - o2[0];
		}
	});
	private static int T, k, num;
	private static boolean[] visited;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		for(int tc=0;tc<T;tc++) {
			max.clear();
			min.clear();
			k = Integer.parseInt(br.readLine());
			visited = new boolean[k];
			for(int i=0;i<k;i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				if(st.nextToken().equals("I")) {		//삽입
					num = Integer.parseInt(st.nextToken());
					max.add(new int[] {num, i});
					min.add(new int[] {num, i});
					visited[i] = true;					//사용중인 수
				}
				else {									//삭제
					if(st.nextToken().equals("1")) {	//최대값
						while(!max.isEmpty() && !visited[max.peek()[1]]) {	//남아있지 않은 수들에 대해
							max.poll();
						}
						if(!max.isEmpty()) {	//비어있지 않으면, 남은 수가 들어있다는 것.
							visited[max.poll()[1]] = false;		//pop하고 방문체크 푼다.
						}
					}
					else {								//최소값
						while(!min.isEmpty() && !visited[min.peek()[1]]) {	//남아있지 않은 수들에 대해
							min.poll();
						}
						if(!min.isEmpty()) {	//비어있지 않으면, 남은 수가 들어있다는 것.
							visited[min.poll()[1]] = false;		//pop하고 방문체크 푼다.
						}
					}
				}
			//	System.out.println(list.toString() + " " + max.size() + " " + min.size());
			}
			while(!max.isEmpty() && !visited[max.peek()[1]]) max.poll();		//남은 애들 pop
			while(!min.isEmpty() && !visited[min.peek()[1]]) min.poll();
			
			if(max.isEmpty() && min.isEmpty()) System.out.println("EMPTY");
			else System.out.println(max.peek()[0] + " " + min.peek()[0]);
			
		}
	}

}
/*
최대힙, 최소힙.
둘다 
*/