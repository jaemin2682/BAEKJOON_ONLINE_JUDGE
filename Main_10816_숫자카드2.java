package A_ProblemSolving;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main_10816_숫자카드2 {

	private static int N, M;
	private static int[] arr;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		HashMap<Integer, Integer> m = new HashMap<>();
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) {
			arr[i] = Integer.parseInt(st.nextToken());
			if(m.containsKey(arr[i])) {				//가지고 있는 값이면
				m.put(arr[i], m.get(arr[i])+1);		//1 더해서 리뉴얼
			}
			else {									//가지고 있지 않은 값이면
				m.put(arr[i], 1);
			}
		}
		
		M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<M;i++) {
			int a = Integer.parseInt(st.nextToken());
			if(m.containsKey(a)) System.out.print(m.get(a) + " ");
			else System.out.print(0 + " ");
			
		}
	}

}
