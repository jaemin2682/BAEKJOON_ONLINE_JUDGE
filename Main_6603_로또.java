package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_6603_로또{
static int k;
static int arr[];
static int temp[];
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while(true) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			k = Integer.parseInt(st.nextToken());
			if(k == 0) break;
			arr = new int[k];
			temp = new int[6];
			for(int i=0;i<k;i++) arr[i] = Integer.parseInt(st.nextToken());
			dfs(0, 0);
			System.out.println();
			
		}
	}
	static void dfs(int cnt, int start) {
		if(cnt == 6) {
			for(int i=0;i<6;i++) System.out.print(temp[i] + " ");
			System.out.println();
			return;
		}
		for(int i = start;i<k;i++) {
			temp[cnt] = arr[i];
			dfs(cnt+1, i+1);
		}
	}

}

/*

*/