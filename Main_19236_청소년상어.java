package Study;

import java.util.Scanner;

public class Main_19236_청소년상어 {
	static int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};	//위부터 반시계 45도씩(index 0부터)
	static int dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
	static Fish map[][] = new Fish[4][4];
	static int ans;
	
	static class Fish {
		int num, vec;
		public Fish(int num, int vec) {
			this.num = num;
			this.vec = vec;
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		for(int i=0;i<4;i++) for(int j=0;j<4;j++) map[i][j] = new Fish(sc.nextInt(), sc.nextInt()-1);
		
		int start = map[0][0].num;
		map[0][0].num = -1;
		
		sharkMove(start);
		System.out.println(ans);
	}

	static void sharkMove(int res) {
		ans = Math.max(ans, res);		
		int y=-1, x=-1;
		find: for(int i=0;i<4;i++) for(int j=0;j<4;j++) if(map[i][j].num == -1) { y = i; x = j; break find; }	//shark find
		
		int vec = map[y][x].vec;
		
		for(int i=1;i<4;i++) {
			int ny = dy[vec]*i + y, nx = dx[vec]*i + x;	// 이동할 위치
			
			if(ny < 0 || ny > 3 || nx < 0 || nx > 3) break;		//경계검사
			
			Fish[][] tempMap = new Fish[4][4];		//map 저장
			for(int j=0;j<4;j++) for(int k=0;k<4;k++) {
				int num = map[j][k].num, vect = map[j][k].vec;
				tempMap[j][k] = new Fish(num, vect);
			}
			
			fishMove();	//물고기 이동
			
			if(map[ny][nx].num == 0) {
				for(int j=0;j<4;j++) for(int k=0;k<4;k++) map[j][k] = tempMap[j][k];
				continue;		//상어는 물고기가 없는 칸으로 이동 X
			}
			
			int fishVec = map[ny][nx].vec, fishNum = map[ny][nx].num;	//먹힌 물고기의 num은 0, 상어의 위치 이동과 방향 조정
			map[y][x].num = 0; map[y][x].vec = -111;
			map[ny][nx] = new Fish(-1, fishVec);			

			sharkMove(res + fishNum);
			
			for(int j=0;j<4;j++) for(int k=0;k<4;k++) {
				int num = tempMap[j][k].num, vect = tempMap[j][k].vec;
				map[j][k] = new Fish(num, vect);
			}
		}
	}
	
	static void fishMove() {
		for(int i=1;i<17;i++) {	//1부터 16까지 순서대로 이동
			int x=-1, y=-1;		//현재 위치
			find: for(int j=0;j<4;j++) for(int k=0;k<4;k++) if(map[j][k].num == i) { y = j; x = k; break find; }	//현재 위치 찾기
			if(x == -1) continue;	//현재 없는 물고기면 continue
			for(int j=0;j<8;j++) {
				int ny = dy[(map[y][x].vec + j)%8] + y, nx = dx[(map[y][x].vec + j)%8] + x;	// 이동할 위치
				if(ny < 0 || ny > 3 || nx < 0 || nx > 3 || map[ny][nx].num == -1) continue;	// 경계검사, 상어체크
				int num = map[ny][nx].num, vec = map[ny][nx].vec;
				map[ny][nx] = new Fish(map[y][x].num, (map[y][x].vec + j)%8);
				map[y][x] = new Fish(num, vec);
				break;
			}
		}
	}
}