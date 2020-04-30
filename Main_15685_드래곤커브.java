package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main_15685_드래곤커브 {

	private static int N, ans;
	private static boolean[][] map = new boolean[101][101];
	private static ArrayList<Integer> list = new ArrayList<>();
	private static int dy[] = {0, -1, 0, 1}, dx[] = {1, 0, -1, 0};

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		StringTokenizer st;
		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken()), g = Integer.parseInt(st.nextToken());
			list.clear();	//시작점부터의 이동방향을 담을 list
			list.add(d);	//0세대 : 시작방향
			
			while(g-- != 0) nextGeneration();	//입력으로 주어진 세대의 이동경로를 구함.
			draw(y, x);
		}
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				if(map[i][j] && map[i][j+1] && map[i+1][j] && map[i+1][j+1]) ans++;
		System.out.println(ans);
	}
	
	private static void draw(int y, int x) {	//입력으로 주어지는 드래곤커브는 격자 밖으로 안벗어남. 경계검사 필요 X
		int curY = y, curX = x, size = list.size();
		for(int i=0;i<size;i++) {				//list에 기록된 방향 순서로 그린다.
			map[curY][curX] = true;
			curY += dy[list.get(i)];
			curX += dx[list.get(i)];
		}
 		map[curY][curX] = true;					//마지막 좌표도
	}
	// 0:오른쪽, 1:위쪽, 2:왼쪽, 3:아래쪽
	private static void nextGeneration() {
		int size = list.size();
		for(int i=size-1;i>=0;i--) list.add((list.get(i)+1)%4); //역순으로 탐색
	}

}
/*
100*100개의 격자 위에 드래곤 커브가 N개 있는데, N개를 입력받아 입력에서 주어진 세대의 드래곤 커브를 전부 그려둔다.
100*100을 돌면서, 1*1의 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 정사각형 개수를 센다.

세대가 늘어가며 이동한 방향을 저장해주고, 다음세대로 넘어갈 때에는 역순서로 시계방향으로 돌린 반대방향의 방향으로 이동한다.
실제 이동방향 -> 시계방향 <-> 반대방향
오른쪽 -> 아래쪽 <-> 위쪽
아래쪽 -> 왼쪽 <-> 오른쪽
왼쪽 -> 위쪽 <-> 아래쪽
위쪽 -> 오른쪽 <-> 왼쪽
*/