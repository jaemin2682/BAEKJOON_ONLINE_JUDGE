package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;

public class Main_11559_PuyoPuyo {
	static char puyo[][];
	static int stackArr[][];
	static ArrayList<Pos> delList;
	static ArrayList<Character> temArr;
	static int y, x, ny, nx, stack, ans;
	static int dy[] = { 0, 0, 1, -1 };
	static int dx[] = { 1, -1, 0, 0 };
	static String str;
	static boolean visited[][];
	static boolean isFin;
	static ArrayDeque<Pos> q;

	static class Pos {
		int y;
		int x;

		public Pos(int y, int x) {
			super();
			this.y = y;
			this.x = x;
		}
	}

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		puyo = new char[12][6];
		stackArr = new int[12][6];
		visited = new boolean[12][6];
		q = new ArrayDeque<>();
		for (int i = 0; i < 12; i++) {
			str = br.readLine();
			for (int j = 0; j < 6; j++) {
				puyo[i][j] = str.charAt(j);
			}
		}
		while(!isFin) {
			bfs();
			ans++;
		}
		
		System.out.println(ans-1);
	}

	static void bfs() {
		isFin = true;
		q = new ArrayDeque<Pos>();
		for(int k=0;k<12;k++) Arrays.fill(visited[k], false);	//방문배열 초기화
		for(int i=0;i<12;i++) {	// bfs를 상하좌우로 돌면서 같은 색 연결된 뿌요들 좌표를 찾아, 리스트에 넣어준다.
			for(int j=0;j<6;j++) {
				if(puyo[i][j] != '.' && !visited[i][j]) {
					delList = new ArrayList<Pos>();	//삭제할 뿌요 list
					q.add(new Pos(i, j));
					delList.add(new Pos(i, j));
					visited[i][j] = true;
					while(!q.isEmpty()) {
						y = q.peek().y;
						x = q.poll().x;
						for(int k=0;k<4;k++) {
							ny = y + dy[k];
							nx = x + dx[k];
							if(ny<12&&ny>=0&&nx<6&&nx>=0&&!visited[ny][nx] && puyo[ny][nx] != '.' && puyo[ny][nx] == puyo[y][x]) {
								delList.add(new Pos(ny, nx));
								visited[ny][nx] = true;
								q.push(new Pos(ny, nx));
							}
						}
					}
					//해당 뿌요의 delList 다 찾은 상태
					if(delList.size() >= 4) {
						isFin = false;
						for(int k=0;k<delList.size();k++) {
								puyo[delList.get(k).y][delList.get(k).x] = '.';	//.로 바꿔(지워) 준다.
						}
					
					
						//뿌요들을 전부 내려준다
						//각 열을 전부 뽑아서, 한바퀴 돌면서 .이 나오면 뒤로 뺀다
						for(int a=0;a<6;a++) {
							temArr = new ArrayList<Character>();
							for(int b=11;b>=0;b--) temArr.add(puyo[b][a]);	//한 열의 정보 저장
							int idx = 0;
							for(int b=0;b<12;b++) {							//.을 뒤로 빼기
								if(temArr.get(idx) == '.') {
									temArr.remove(idx);
									temArr.add('.');
								}
								else idx++;
							}
							for(int b=11;b>=0;b--) puyo[b][a] = temArr.get(11-b);	//puyo 갱신
						}
					}
				}
			}
		}
	}
}

