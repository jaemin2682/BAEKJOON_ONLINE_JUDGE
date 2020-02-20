package A_ProblemSolving;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main_1259_팰린드롬수 {
	private static String str;
	private static int size;
	private static boolean check;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		while(true) {
			str = br.readLine();
			if(str.equals("0")) break;
			size = str.length();
			check = true;
			for(int i=0;i<size/2;i++) {
				if(str.charAt(i) != str.charAt(size-1-i)) {
					check = false;
					break;
				}
			}
			if(check) System.out.println("yes");
			else System.out.println("no");
		}
	}

}
