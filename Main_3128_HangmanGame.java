package Algorithm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main_3128_HangmanGame {

	private static String str;
	static int alphaSize, ans = Integer.MAX_VALUE;
	private static boolean alpha[] = new boolean[26];
	private static int resultArr[], ansArr[];
	private static boolean visited[];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		str = br.readLine();			
		for(int i=0, size=str.length();i<size;i++) 
			if(str.charAt(i) != ' ') {
				alpha[str.charAt(i)-'A'] = true;		
			}
		for(int i=0;i<26;i++) if(alpha[i]) alphaSize++;
		resultArr = new int[alphaSize];
		visited = new boolean[26];
		dfs(0, 0, 0);
		System.out.println(ans + alphaSize);
		for(int a : ansArr) System.out.print((char)(a+'A'));
	}

	private static void dfs(int cnt, int pre, int sum) {
		//base_case
		if(cnt == alphaSize) {	
			if(sum < ans) {
				ans = sum;
				ansArr = resultArr.clone();
			}
			return;
		}
		if(sum >= ans) return;
		//recur
		int idx = pre;
		while(true) {
			if(alpha[idx] && !visited[idx]) {
				visited[idx] = true;
				resultArr[cnt] = idx;
				dfs(cnt+1, idx, sum + Math.min(Math.abs(pre - idx), 26 - Math.abs(pre-idx)));
				visited[idx] = false;
				break;
			}
			idx--;
			if(idx < 0) idx = 25;
			if(idx == pre) break;
		}
		idx = pre;
		while(true) {	
			if(alpha[idx] && !visited[idx]) {
				visited[idx] = true;
				resultArr[cnt] = idx;
				dfs(cnt+1, idx, sum + Math.min(Math.abs(pre - idx), 26 - Math.abs(pre-idx)));
				visited[idx] = false;
				break;
			}
			idx++;
			if(idx > 25) idx = 0;
			if(idx == pre) break;
		}
	}

}
/*
A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

*/