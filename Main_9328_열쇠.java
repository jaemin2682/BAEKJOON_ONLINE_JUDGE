package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_9328_열쇠 {

	private static int T, h, w, doc;
	private static char[][] map;
	private static boolean keys[] = new boolean[26];
	private static boolean[][] visited;
	private static Queue<int[]> q = new LinkedList<int[]>();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		T = Integer.parseInt(br.readLine());
		for(int tc=0;tc<T;tc++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			h = Integer.parseInt(st.nextToken()); w = Integer.parseInt(st.nextToken());
			map = new char[h+2][w+2];
			visited = new boolean[h+2][w+2];
			for(int i=0;i<w+2;i++) map[0][i] = '.';		//첫째 줄 .로 채움
			for(int i=0;i<w+2;i++) map[h+1][i] = '.';	//마지막 줄 .로 채움
			for(int i=1;i<h+1;i++) {
				String str = br.readLine();
				for(int j=1;j<w+1;j++) map[i][j] = str.charAt(j-1);
				map[i][0] = '.'; map[i][w+1] = '.';		//각 줄의 처음, 마지막을 .로 채움
			}
			String key = br.readLine();
			Arrays.fill(keys, false);					//가진 열쇠 초기화
			doc = 0;	//찾은 문서 초기화
			if(!key.equals("0")) {	//0이 아닐 때에만 수행
				for(int i=0, size=key.length();i<size;i++) {
					for(int j=1;j<h+1;j++)
						for(int k=1;k<w+1;k++)
							if(key.charAt(i) - 32 == map[j][k]) map[j][k] = '.';	//가진 열쇠의 문을 지운다.
					keys[key.charAt(i)-'a'] = true;										//가지고 있는 열쇠 표시
				}
			}
			bfs();
			System.out.println(doc);
		}
	}

	static int dy[] = {0, 0, 1, -1}, dx[] = {1, -1, 0, 0};
	private static void bfs() {
		q.clear();
		q.add(new int[] {0, 0});	//첫 칸에서 시작
		visited[0][0] = true;
		
		while(q.size() != 0) {
			int y = q.peek()[0];
			int x = q.poll()[1];
			for(int i=0;i<4;i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if(ny>=0 && ny<h+2 && nx>=0 && nx<w+2 && !visited[ny][nx] && map[ny][nx] != '*') {
					if(map[ny][nx] >= 'A' && map[ny][nx] <= 'Z') continue;	//문을 만났을 때. 갈 수 없음(아직 안열었잖아)
					
					if(map[ny][nx] >= 'a' && map[ny][nx] <= 'z') {		//열쇠를 만났을 때
						if(keys[map[ny][nx]-'a']) {		//이미 열쇠를 발견했을 때(열쇠는 여러 개가 가능하므로)
							visited[ny][nx] = true;
							map[ny][nx] = '.';
							q.add(new int[] {ny, nx});	//그냥 이동
						}
						else {		//열쇠를 처음 발견했을 때
							keys[map[ny][nx]-'a'] = true;
							for(int j=0;j<h+2;j++)
								for(int k=0;k<w+2;k++)
									if(map[j][k] == map[ny][nx]-32) map[j][k] = '.';	//해당 문을 모두 연다.
							for(int j=0;j<h+2;j++) Arrays.fill(visited[j], false);				//방문배열 다시 초기화하고
							q.clear(); 					//큐도 비운다.
							q.add(new int[] {ny, nx});	//해당 위치부터 다시 시작
						}
					}
					else if(map[ny][nx] == '$') {		//문서 발견시
						doc++;
						map[ny][nx] = '.';				//중복 발견 방지
						visited[ny][nx] = true;
						q.add(new int[] {ny, nx});
					}
					else {	//빈칸일 때
						visited[ny][nx] = true;
						q.add(new int[] {ny, nx});
					}
				}
			}
		}
	}
}
