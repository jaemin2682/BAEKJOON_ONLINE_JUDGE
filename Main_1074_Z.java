package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Main_1074_Z {
	static int N, r, c, num;
	static int[][] arr;
 
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		arr = new int[(int)Math.pow(2, N)][(int)Math.pow(2, N)];
		search(0, 0, (int)Math.pow(2, N));
		for(int i=0;i<(int)Math.pow(2, N);i++) {
			for(int j=0;j<(int)Math.pow(2, N);j++) {
				System.out.printf("%3d ",arr[i][j]);
			}
			System.out.println();
		}	
	}

	private static void search(int height, int width, int size) {
		if(size==2) {
			arr[height][width] = num++;
			arr[height][width+1] = num++;
			arr[height+1][width] = num++;
			arr[height+1][width+1] = num++;
			return;
		}
//		if(size == 2) {
//			if(r>=height && r<=height+1 && c>=width && c<=width+1) {
//				if(r==height && c==width) {System.out.println(num); System.exit(0);} num++;
//				if(r==height && c==width+1) {System.out.println(num); System.exit(0);} num++;
//				if(r==height+1 && c==width) {System.out.println(num); System.exit(0);} num++;
//				if(r==height+1 && c==width+1) {System.out.println(num++); System.exit(0);}
//			}
//			else num+=4;
//			return;
//		}
		search(height, width, size/2); 
		search(height, width+size/2, size/2);
		search(height+size/2, width, size/2);
		search(height+size/2, width+size/2, size/2);

	}

}