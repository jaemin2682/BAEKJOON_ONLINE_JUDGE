package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main_16916_부분문자열 {
	static boolean isContain = false;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String S = br.readLine();
		String P = br.readLine();
		kmp(S, P);
		if(isContain) System.out.println(1);
		else System.out.println(0);
	}
	
	public static int[] getPi(String p) {
		int m = p.length(), j = 0;
		int[] pi = new int[m];
		for(int i=1;i<m;i++) {
			while(j>0 && p.charAt(i) != p.charAt(j))
				j = pi[j-1];
			if(p.charAt(i) == p.charAt(j)) pi[i] = ++j;
		}
		return pi;
	}
	
	public static void kmp(String s, String p) {
		int n = s.length(), m = p.length(), j = 0;
		int[] pi = getPi(p);
		for(int i=0;i<n;i++) {
			while(j > 0 && s.charAt(i) != p.charAt(j))
				j = pi[j-1];
			if(s.charAt(i) == p.charAt(j)) {
				if(j == m-1) {
					isContain = true;
					return;
				}
				else j++;
			}
		}
	}

}
