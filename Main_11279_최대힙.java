package A_ProblemSolving;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main_11279_최대힙 {

	private static int T, num;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
		T = Integer.parseInt(br.readLine());
		for(int i=0;i<T;i++) {
			num = Integer.parseInt(br.readLine());
			if(num > 0) pq.add(num);
			else {
				if(pq.isEmpty()) System.out.println(0);
				else System.out.println(pq.poll());
			}
		}
	}

}
