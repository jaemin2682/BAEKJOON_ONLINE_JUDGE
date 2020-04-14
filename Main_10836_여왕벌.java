package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_10836_여왕벌 {

	private static int M, N;
	private static int arr[];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		M = Integer.parseInt(st.nextToken()); N = Integer.parseInt(st.nextToken());
		arr = new int[2*M-1];	//밑~위~오 저장할 배열
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			int idx = 0;
			int zero=Integer.parseInt(st.nextToken()), one=Integer.parseInt(st.nextToken()), two=Integer.parseInt(st.nextToken());
			for(int j=0;j<zero;j++)	arr[idx++] += 0;
			for(int j=0;j<one;j++) arr[idx++] += 1;
			for(int j=0;j<two;j++) arr[idx++] += 2;
		}
		for(int i=0;i<M;i++) {
			for(int j=0;j<M;j++) {
				if(j==0) System.out.print(arr[M-i-1]+1 + " ");
				else System.out.print(arr[j+M-1]+1 + " ");
			}
			System.out.println();
		}
	}

}
	
/*
700 * 700 = 49만 * 100만 = 
*/