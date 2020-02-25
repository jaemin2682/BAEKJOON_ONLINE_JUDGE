package A_ProblemSolving;

import java.util.Scanner;

public class Main_2630_색종이만들기 {

	private static int N, blue, white;
	private static int[][] arr;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		arr = new int[N][N];
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		getCnt(0, 0, N);
		
		System.out.println(white + "\n" + blue);
	}

	private static void getCnt(int y, int x, int size) {	//시작좌표
		//base_case
		if(full(y, x, size)) {
			if(arr[y][x] == 1) blue++;
			else white++;
			return;
		}
		//recur
		getCnt(y, x, size/2);				//1사
		getCnt(y, x+size/2, size/2);		//2사
		getCnt(y+size/2, x, size/2);		//3사
		getCnt(y+size/2, x+size/2, size/2);	//4사
	}

	private static boolean full(int y, int x, int size) {
		int color = arr[y][x];
		for(int i=y;i<y+size;i++) {
			for(int j=x;j<x+size;j++) {
				if(color != arr[i][j]) return false;
			}
		}
		return true;
	}

}
