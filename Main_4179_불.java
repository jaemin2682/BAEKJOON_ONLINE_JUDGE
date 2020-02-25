package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_4179_불 {

	private static int R, C, jY, jX, fY, fX, time;
	private static boolean isFin;
	private static String str;
	private static char[][] map;
	private static Queue<int[]> qF = new LinkedList<int[]>();
	private static Queue<int[]> qJ = new LinkedList<int[]>();
	private static boolean[][] visited;
	private static int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};

	public static void main(String[] args) throws Exception {
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
				if(map[i][j] == 'J') {
					qJ.add(new int[] {i, j});	
					visited[i][j] = true;		
				}
				if(map[i][j] == 'F') {
					qF.add(new int[] {i, j});	
				}
			}
		}	
		bfs();
		if(isFin) System.out.println(time);
		else System.out.println("IMPOSSIBLE");
	}

	private static void bfs() {
		while(qJ.size() != 0) {
			time++;
			for(int i=0, size=qF.size();i<size;i++) {
				fY = qF.peek()[0]; fX = qF.poll()[1];
				for(int j=0;j<4;j++) {			
					int nextfY = fY + dy[j], nextfX = fX + dx[j];
					if(nextfY>=0 && nextfY<R && nextfX>=0 && nextfX<C && map[nextfY][nextfX]!='#' && map[nextfY][nextfX]!='F') {
						map[nextfY][nextfX] = 'F';
						qF.add(new int[] {nextfY, nextfX});
					}
				}
			}
			for(int i=0, size=qJ.size();i<size;i++) {
				jY = qJ.peek()[0]; jX = qJ.poll()[1];
				if(jY==0 || jY==R-1 || jX==0 || jX==C-1) { isFin = true; return; }
				for(int j=0;j<4;j++) {
					int nextjY = jY + dy[j], nextjX = jX + dx[j];
					if(nextjY>=0 && nextjY<R && nextjX>=0 && nextjX<C && map[nextjY][nextjX]=='.' && !visited[nextjY][nextjX]) {
						visited[nextjY][nextjX] = true;
						qJ.add(new int[] {nextjY, nextjX});
					}
				}
			}
		}
	}
}

