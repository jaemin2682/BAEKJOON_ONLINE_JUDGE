package Study;

import java.util.Scanner;

public class Main_4811_�˾� {
	static long peel[][] = new long[31][31];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			int num = sc.nextInt();
			if(num == 0) break;
			System.out.println(dfs(num, 0));
		}
	}
	// ���� ���ڿ�(w, h) : �� ������ �Ծ��� ���(w, h-1) + �� ������ �Ծ��� ���(w-1, h+1)
	static long dfs(int w, int h) {
		long result = peel[w][h];
		if(result != 0) return result;
		
		result = 0;
		if(h > 0) result += dfs(w, h-1);	// �� ������ �Ծ��� ���
		if(w > 0) result += dfs(w-1, h+1);	// �� ������ �Ծ��� ���
		else return 1;
	
		peel[w][h] = result;
		return result;
	}

}
