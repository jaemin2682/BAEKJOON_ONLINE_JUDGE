package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main_1799_비숍 {
	static int N;
	static int map[][];
	static int ans[] = new int[2];
	static int l[] = new int[20];
	static int r[] = new int[20];
	static String str;

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		map = new int[N][N];
		l = new int[20];
		r = new int[20];
		for (int i = 0; i < N; i++) {
			str = br.readLine();
			for (int j = 0, idx = 0; j < N; j++, idx += 2) {
				map[i][j] = str.charAt(idx) - '0';
			}
		}
		
		dfs(0, 0, 0, 0);
		dfs(0, 1, 0, 1);

		System.out.println(ans[0] + ans[1]);
	}

	static void dfs(int row, int col, int count, int color)
	{
	    if (col >= N) {	//�� ������ ����
	        row++;		//�� ++
	        if(col%2 == 0) col = 1;		//¦������ ���� ���� ���� ���� Ȧ������ ���� ��
	        else col = 0;				//Ȧ������ ���� ���� ���� ���� ¦������ ���� ��
	    }
	    if (row >= N) {	//�� ������ ����
	        ans[color] = Integer.max(ans[color], count);	//�ִ밪 ����
	        return;
	    }
	 
	    if (map[row][col] == 1 && l[col - row + N - 1] == 0 && r[row + col] == 0)
	    {	//���� �� ���� + �밢�� �˻�
	        l[col - row + N - 1] = r[row + col] = 1;
	        dfs(row, col+2, count + 1, color);
	        l[col - row + N - 1] = r[row + col] = 0;
	    }
	    dfs(row, col+2, count, color);
	}


}
