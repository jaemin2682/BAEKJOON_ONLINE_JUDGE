package Study;

import java.util.Scanner;

public class Main_16917_양념반후라이드반 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt(), B = sc.nextInt(), C = sc.nextInt(), X = sc.nextInt(), Y = sc.nextInt(), min = Math.min(X, Y), mid = (A+B) <= C*2 ? (A+B)*min : C*2*min;
		System.out.println(mid + Math.min(A, C*2) * (X - min) + Math.min(B, C*2) * (Y - min));
	}

}
