package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main_1786_찾기 {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String T = br.readLine();
		String P = br.readLine();
		ArrayList<Integer> list = kmp(T, P);
		System.out.println(list.size());
		for(int num : list) System.out.print(num + " ");
	}
	
	public static int[] getPi(String p) {
		int m = p.length(), j = 0;
		int[] pi = new int[m];
		for(int i=1;i<m;i++) {
			while(j>0 && p.charAt(i) != p.charAt(j)) j = pi[j-1];
			if(p.charAt(i) == p.charAt(j)) pi[i] = ++j;
		}
		return pi;
	}
	
	public static ArrayList<Integer> kmp(String s, String p) {
		int n = s.length(), m = p.length(), j = 0;
		ArrayList<Integer> list = new ArrayList<>();
		int[] pi = getPi(p);
		for(int i = 0;i<n;i++) {
			while(j > 0 && s.charAt(i) != p.charAt(j)) j = pi[j-1];
			if(s.charAt(i) == p.charAt(j)) {
				if(j == m-1) {
					list.add(i-j+1);
					j = pi[j];
				}
				else j++;
			}
		}
		return list;
	}

}
