package Study;

import java.util.Scanner;

public class Main_1701_Cubeditor {
	static String str;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		str = sc.next();
		int maxSize = 0;
		for(int i=0;i<str.length();i++) {
			String s = str.substring(i);
			for(int a : getPi(s)) maxSize = Math.max(maxSize, a);
		}
		System.out.println(maxSize);
	}
	
	static int[] getPi(String p) {
		int psize = p.length(), j = 0;
		int[] pi = new int[psize];
		for(int i=1;i<psize;i++) {
			while(j > 0 && p.charAt(i) != p.charAt(j)) j = pi[j-1];
			if(p.charAt(i) == p.charAt(j)) {
				j++;
				pi[i] = j;
			}
		}
		return pi;
	}
	
}
