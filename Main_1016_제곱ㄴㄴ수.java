package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_1016_제곱ㄴㄴ수 {

	private static long minVal, maxVal, cnt;
	private static boolean check[] = new boolean[1000001];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		minVal = Long.parseLong(st.nextToken());
		maxVal = Long.parseLong(st.nextToken());
		
		for(long i=2l;i*i<=maxVal;i++) {			// 2 ~ maxVal의 제곱근까지
			long val = minVal / (i*i);
			if(minVal % (i*i) != 0) val++;
			while(val*i*i <= maxVal) {
				check[(int) (val*i*i - minVal)] = true;
				val++;
			}
		}
		for(int i=0;i<maxVal-minVal+1;i++)
			if(!check[i]) cnt++;
		System.out.println(cnt);
	}

}
