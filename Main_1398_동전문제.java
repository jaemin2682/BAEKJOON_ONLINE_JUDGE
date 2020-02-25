package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main_1398_동전문제 {
static long K, first, second, cnt = Integer.MAX_VALUE;
static String str;
static int T;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		for(int tc=0;tc<T;tc++) {
			str = br.readLine();
			K = Long.parseLong(str);
			cnt = Integer.MAX_VALUE;
			first = (long) Math.pow(10, str.length());
			second = (long) Math.pow(100, str.length()/2) * 25;
			
			dfs(first, second, K, 0);
			
			System.out.println(cnt);
		}
	}
	
	static void dfs(long first, long second, long k, int num) {	//10^k 나눗셈 factor, 25*100^K 나눗셈 factor, 나머지 K, 사용한 동전 개수
		//base_case
		if(k == 0) {
			cnt = Math.min(cnt, num);	//cnt값 갱신
			return;
		}
		if(num >= cnt) return;	// 최소값을 넘어갈 경우 return(가지치기);
		
		//first값이 K와 같거나 작아질 때까지 10으로 나눠준다.
		while(k < first && first > 0) first /= 10;
		//second값이 K와 같거나 작아질 때까지 100으로 나눠준다.
		while(k < second && second > 0) second /= 100;
		
		dfs(first, second, k-(k/first)*first, num+(int)(k/first));	//10^k
		if(size(k)%2 == 0 && k-second >= 0) dfs(first, second, k - second, num+1);	//25*100^k : 숫자의 길이가 짝수일 경우에만
	
	}
	
	static int size(long n) {
		int s = 0;
		while(n > 0) {
			n/=10;
			s++;
		}
		return s;
	}
}
/* 
47
100000000000000
999999999999999
*/
