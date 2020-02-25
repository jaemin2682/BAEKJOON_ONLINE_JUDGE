package A_ProblemSolving;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main_1920_수찾기 {

	private static int N, M;
	private static int[] arr;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0;i<N;i++) arr[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(arr);
		M = Integer.parseInt(br.readLine());
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<M;i++) {
			if(binarySearch(0, N-1, Integer.parseInt(st.nextToken()))) System.out.println(1);
			else System.out.println(0);
		}
	}

	private static boolean binarySearch(int left, int right, int target) {
		int mid = 0;
		while(left <= right) {
			mid = (left+right)/2;
			if(arr[mid] == target) return true;
			else if(arr[mid] < target) left = mid+1;
			else right = mid-1;
		}
		return false;
	}

}
