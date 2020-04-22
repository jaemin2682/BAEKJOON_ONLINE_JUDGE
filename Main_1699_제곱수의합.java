package Algorithm;

import java.util.Scanner;

public class Main_1699_제곱수의합 {

	private static int N;
	private static int[] arr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		arr = new int[N+1];
		for(int i=1;i<=N;i++) arr[i] = i;	//수 i를 모두 1의 합으로 나타냈을 때, 즉 최대값으로 초기화해준다.
		for(int i=2;i<=N;i++) {				//i번째 인덱스, 즉 i를 제곱수로 나타냈을 때, 항의 최소개수
			for(int j=2;j*j<=i;j++)			//i보다 작은 j*j에 대해, 한번씩 수행해 최소값을 구해본다.
				arr[i] = Math.min(arr[i], arr[i-j*j] + 1);
		}
		System.out.println(arr[N]);
	}
}
