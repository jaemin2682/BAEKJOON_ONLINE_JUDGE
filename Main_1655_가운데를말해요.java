package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.PriorityQueue;

public class Main_1655_가운데를말해요 {
private static int N, num, maxTemp, minTemp;
	public static void main(String[] args) throws Exception {
		PriorityQueue<Integer> min = new PriorityQueue<>();	//min heap
		PriorityQueue<Integer> max = new PriorityQueue<>(Collections.reverseOrder()); //max heap
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		for(int i=0;i<N;i++) {
			num = Integer.parseInt(br.readLine());
			if(max.size() <= min.size()) max.add(num);
			else min.add(num);
			if(!max.isEmpty() && !min.isEmpty() && max.peek() > min.peek()) {
				maxTemp = max.poll();
				minTemp = min.poll();
				max.add(minTemp);
				min.add(maxTemp);
			}
			System.out.println(max.peek());
		}
	}
}
