package Study;

import java.util.Scanner;

public class Main_2140_Áö·ÚÃ£±â {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt(), ny=0 ,nx=0 ,ans = 0, map[][] = new int[N][N], dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
		for(int i=0;i<N;i++) {
			String str = sc.next();
			for(int j=0;j<N;j++) {
				if(str.charAt(j) == '#') map[i][j] = -1;
				else map[i][j] = str.charAt(j) - '0';
			}
		}
		for(int i=1;i<N-1;i++) {
			for(int j=1;j<N-1;j++) {
				boolean isBomb = true; int cnt = 0;
				for(int k=0;k<8;k++) {
					ny = i + dy[k]; nx = j + dx[k];
					if(map[ny][nx] == 0) { isBomb = false; break; }
					if(map[ny][nx] == -1) cnt++;
				}
				if(!isBomb) continue;
				if(cnt == 8) { ans++; continue; }
				for(int k=0;k<8;k++) {
					ny = i + dy[k]; nx = j + dx[k];
					if(map[ny][nx] > 0) map[ny][nx]--;
				}
				ans++;
			}
		}
		System.out.println(ans);
	}	
}
