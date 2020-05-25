package Algorithm;

import java.util.Scanner;

public class Main_12025_장난꾸러기영훈 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();	long k = sc.nextLong(); int size = 0; StringBuilder sb = new StringBuilder(str);
		for(int i=0;i<str.length();i++) if(str.charAt(i) == '1' || str.charAt(i) == '6' || str.charAt(i) == '2' || str.charAt(i) == '7') size++;
		if(size == 0) System.out.println(str);
		else if(k > (long) Math.pow(2, size)) System.out.println(-1);
		else {
			for(int i=0;i<sb.length();i++) {
				if(sb.charAt(i) == '1' || sb.charAt(i) == '6' || sb.charAt(i) == '2' || sb.charAt(i) == '7') {
					if(((k-1) % (long) Math.pow(2, size)) >= (long) Math.pow(2, size) / 2) {
						if(sb.charAt(i) == '1' || sb.charAt(i) == '6') sb.setCharAt(i, '6');
						else if(sb.charAt(i) == '2' || sb.charAt(i) == '7') sb.setCharAt(i, '7');
					}
					else {
						if(sb.charAt(i) == '1' || sb.charAt(i) == '6') sb.setCharAt(i, '1');
						else if(sb.charAt(i) == '2' || sb.charAt(i) == '7') sb.setCharAt(i, '2');
					}
					size--;
				}
			}
			System.out.println(sb);
		}
	}
}