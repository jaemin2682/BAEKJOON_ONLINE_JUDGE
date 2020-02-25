package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_3109_빵집_오재민 {

	private static int R, C, ans;
	private static char[][] map;
	private static int[] dy = {-1, 0, 1};
	private static int[] dx = {1, 1, 1};
	private static String str;
	private static boolean check;
	private static boolean[][] visited;

	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		map = new char[R][C];
		visited = new boolean[R][C];
		for(int i=0;i<R;i++) {
			str = br.readLine();
			for(int j=0;j<C;j++) {
				map[i][j] = str.charAt(j);
			}	
		}
		
		for(int i=0;i<R;i++) {
			check = false;
			dfs(i, 0);
		}
		System.out.println(ans);
	}
	
	private static void dfs(int y, int x) {	//y좌표, x좌표, 몇번째 행, 얻은 점수
		//base_case
		if(x == C-1) {	//마지막 열에 다다르면 return
			ans++;
			check = true;
			return;
		}
		
		//dfs
		for(int i=0;i<3;i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if(ny>=0 && ny<R && nx>=0 && nx<C && map[ny][nx]=='.' && !visited[ny][nx]) {
				visited[ny][nx] = true;
				dfs(ny, nx);
				if(check) return;
				
			}
		}
		
	}

}
