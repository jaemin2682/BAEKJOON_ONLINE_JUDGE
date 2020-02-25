package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_15644_구슬탈출3 {

	private static int N, M, ans, nrY, nrX, nbY, nbX;
	private static String redY, redX, blueY, blueX, path;
	private static boolean red, blue;
	private static String str;
	private static char[][] map;
	private static int dy[] = {0, 0, 1, -1};
	private static int dx[] = {1, -1, 0, 0};
	private static Queue<String[]> q = new LinkedList<>();

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
					redY = Integer.toString(i); redX = Integer.toString(j);
				}
				if(map[i][j] == 'B') {
					blueY = Integer.toString(i); blueX = Integer.toString(j);
				}
			}
		}
		
		q.add(new String[] {redY, redX, blueY, blueX, ""});	//red의 Y, X, blue의 Y, X, 경로
		
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
				blueX = q.peek()[3];
				path = q.poll()[4];
				for(int i=0;i<4;i++) {				//4 direction
					red = false;					//initialize
					blue = false;
					nrY = Integer.parseInt(redY);
					nrX = Integer.parseInt(redX);
					nbY = Integer.parseInt(blueY);
					nbX = Integer.parseInt(blueX);
													//구슬의 이동
					if(i==0) {						//우
						if(Integer.parseInt(redX) < Integer.parseInt(blueX))  firstB(i);	//더 오른쪽에 있는 것부터 이동
						else firstR(i);
					}
					else if(i==1) {					//좌
						if(Integer.parseInt(redX) < Integer.parseInt(blueX))  firstR(i);	//더 좌측에 있는 것부터 이동
						else firstB(i);
					}
					else if(i==2) {					//하
						if(Integer.parseInt(redY) < Integer.parseInt(blueY))  firstB(i);	//더 아래에 있는 것부터 이동
						else firstR(i);
					}
					else if(i==3) {					//상
						if(Integer.parseInt(redY) < Integer.parseInt(blueY))  firstR(i);	//더 위에 있는 것부터 이동
						else firstB(i);	
					}
					if(i==0) str = "R";
					else if(i==1) str = "L";
					else if(i==2) str = "D";
					else if(i==3) str = "U";
					
					if(red && !blue) {		//빨간공은 IN / 파란공은 NOT IN이면 출력
						System.out.println(ans);
						System.out.println(path + str);
						System.exit(0);
					}
					else if(blue) {}		//빨&&파 또는 !빨&&파. 즉, 파란공이 들어간 경우엔 실패이므로 push하지 않음
					else q.add(new String[] {Integer.toString(nrY), Integer.toString(nrX), Integer.toString(nbY), Integer.toString(nbX), path+str});	//나머지는 push
					
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