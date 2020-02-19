package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main_13460_구슬탈출2 {

	private static int N, M, ans, nrY, nrX, nbY, nbX, redY, redX, blueY, blueX;
	private static boolean red, blue;
	private static String str;
	private static char[][] map;
	private static int dy[] = {0, 0, 1, -1};
	private static int dx[] = {1, -1, 0, 0};
	private static Queue<int[]> q = new LinkedList<>();

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new char[N][M];
		for(int i=0;i<N;i++) {
			str = br.readLine();
			for(int j=0;j<M;j++) {map[i][j] = str.charAt(j);
				if(map[i][j] == 'R') {
					redY = i; redX = j;
				}
				if(map[i][j] == 'B') {
					blueY = i; blueX = j;
				}
			}
		}
		
		q.add(new  int[] {redY, redX, blueY, blueX});	//red의 Y, X, blue의 Y, X, 경로
		
		bfs();
		
		System.out.println(-1);  			//bfs에서 exit이 안나는 경우 -1 출력(R이 갇힌 경우)
	}
	
	private static void bfs() {
		while(!q.isEmpty()) {
			int size = q.size();
			ans++;
			for(int j=0;j<size;j++) {
				redY = q.peek()[0];					//pop
				redX = q.peek()[1];
				blueY = q.peek()[2];
				blueX = q.poll()[3];
				for(int i=0;i<4;i++) {				//4 direction
					red = false;					//initialize
					blue = false;
					nrY = redY;
					nrX = redX;
					nbY = blueY;
					nbX = blueX;
													//구슬의 이동
					if(i==0) {						//우
						if(redX < blueX)  firstB(i);	//더 오른쪽에 있는 것부터 이동
						else firstR(i);
					}
					else if(i==1) {					//좌
						if(redX < blueX)  firstR(i);	//더 좌측에 있는 것부터 이동
						else firstB(i);
					}
					else if(i==2) {					//하
						if(redY < blueY)  firstB(i);	//더 아래에 있는 것부터 이동
						else firstR(i);
					}
					else if(i==3) {					//상
						if(redY < blueY)  firstR(i);	//더 위에 있는 것부터 이동
						else firstB(i);	
					}
					
					if(red && !blue) {		//빨간공은 IN / 파란공은 NOT IN이면 출력
						System.out.println(ans);
						System.exit(0);
					}
					else if(blue) {}		//빨&&파 또는 !빨&&파. 즉, 파란공이 들어간 경우엔 실패이므로 push하지 않음
					else q.add(new int[] {nrY, nrX, nbY, nbX});	//나머지는 push
					
					if(ans>10) {
						System.out.println(-1);
						System.exit(0);
					}
				}
			}
		}
	}
	private static void firstR(int i) {
		while(true) {					//Red Ball
			nrY += dy[i];
			nrX += dx[i];
			if(map[nrY][nrX]=='O') red = true;
			if(map[nrY][nrX]=='#') {
				nrY -= dy[i];
				nrX -= dx[i];
				break;
			}
		}
		while(true) {					//Blue Ball		
			nbY += dy[i];
			nbX += dx[i];
			if(map[nbY][nbX]=='O') blue = true;
			if(map[nbY][nbX]=='#' || (nbY==nrY && nbX==nrX)) {
				nbY -= dy[i];
				nbX -= dx[i];
				break;
			}
		}
	}

	private static void firstB(int i) {
		while(true) {					//Blue Ball
			nbY += dy[i];
			nbX += dx[i];
			if(map[nbY][nbX]=='O') blue = true;
			if(map[nbY][nbX]=='#') {
				nbY -= dy[i];
				nbX -= dx[i];
				break;
			}
		}
		while(true) {					//Red Ball
			nrY += dy[i];
			nrX += dx[i];
			if(map[nrY][nrX]=='O') red = true;
			if(map[nrY][nrX]=='#' || (nbY==nrY && nbX==nrX)) {
				nrY -= dy[i];
				nrX -= dx[i];
				break;
			}
		}
	}

}

