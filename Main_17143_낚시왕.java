package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main_17143_낚시왕 {

	private static int R, C, M, r, c, s, d, z, sum;
	private static int map[][];
	private static ArrayList<Shark> list = new ArrayList<>();	//상어의 이동을 편하게 하기 위해 만든 리스트
	
	static class Shark {
		int r, c, s, d, z, num;
		public Shark(int r, int c, int s, int d, int z, int num) {
			this.r = r;
			this.c = c;
			this.s = s;
			this.d = d;
			this.z = z;
			this.num = num;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		map = new int[R+1][C+1];
		
		for(int i=1;i<=M;i++) {	
			st = new StringTokenizer(br.readLine());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			s = Integer.parseInt(st.nextToken());
			d = Integer.parseInt(st.nextToken());
			z = Integer.parseInt(st.nextToken());
			
			if(d==1 || d==2) s %= (2*(R-1));		//필요없는 이동회수 줄여주기
			else s %= (2*(C-1));
			
			map[r][c] = i;
			list.add(new Shark(r, c, s, d, z, i));
		}	//r, c, s(속력), d(이동방향), z(크기), num(상어 번호)
		
		for(int i=1;i<=C;i++) {	//1열 ~ C열에 대해
			
			for(int j=1;j<=R;j++) {						//상어잡이
				if(map[j][i] != 0) {					//가장 먼저보는 상어를 0(잡는다)
					sum += list.get(map[j][i]-1).z;
					list.get(map[j][i]-1).z = -1;		//잡힌놈은 크기가 -1
					map[j][i] = 0;
					break;
				}
			}
			
			for(int j=0;j<M;j++) {	//상어의 이동	
				move(list.get(j));
			}
			
			for(int j=0;j<M;j++) {					//맵에 상어 기록/누가 있다면 작은놈 삭제
				Shark shark = list.get(j);
				if(shark.z == -1) continue;
				if(map[shark.r][shark.c] != 0) {						//0이 아닐 때, 기존의 상어보다 크기가 크다면 덮어쓴다.
					if(list.get(map[shark.r][shark.c]-1).z < shark.z) {
						list.get(map[shark.r][shark.c]-1).z = -1;
						map[shark.r][shark.c] = shark.num;
					}
				}
				else map[shark.r][shark.c] = shark.num;					//0이면 그냥 채워넣어줌
			}
			
//			for(int a=1;a<=R;a++) {
//				for(int b=1;b<=C;b++) {
//					if(map[a][b] == null) System.out.print(0 + " ");
//					else System.out.print(1 + " ");
//				}
//				System.out.println();
//			}
//			System.out.println("============");
		}
	
		System.out.println(sum);
	}
	private static void move(Shark shark) {	
		map[shark.r][shark.c] = 0;
		if(shark.d == 1 && shark.r - shark.s > 0) {
			shark.r -= shark.s;
			return;
		}
		else if(shark.d == 2 && shark.r + shark.s <= R) {
			shark.r += shark.s;
			return;
		}
		else if(shark.d == 3 && shark.c + shark.s <= R) {
			shark.c += shark.s;
			return;	
		}
		else if(shark.d == 4 && shark.c - shark.s > 0) {
			shark.c -= shark.s;
			return;
		}
//		
		for(int i=0;i<shark.s;i++) {
			if(shark.d==1) {	//위
				if(shark.r == 1) {
					shark.d = 2;
					shark.r++;
				}
				else shark.r--;
			}
			else if(shark.d==2)	{	//아래
				if(shark.r == R) {
					shark.d = 1;
					shark.r--;
				}
				else shark.r++;
			}
			else if(shark.d==3) {	//오른쪽
				if(shark.c == C) {
					shark.d = 4;
					shark.c--;
				}
				else shark.c++;
			}
			else if(shark.d==4) {	//왼쪽
				if(shark.c == 1) {
					shark.d = 3;
					shark.c++;
				}
				else shark.c--;
			}
		}
		
		
	}
}
/*
C*(R + R*C + R*C + R + R*C*s)  => O(C*C*R*s) -> 100*100*100*200  10억 -> 2억...
r, c, s(속력), d(이동방향), z(크기)를 가진 클래스 선언
1~C열에 대해서 같은 열에 있는 상어를 검사해, 가장 가까운 상어를 지운다.(배열에 그릴지? 클래스 리스트를 쓸지? 맵을 쓸지?)
모든 상어에 대해, 이동을 실시한다.
r, c가 겹치는 상어가 있다면 가장 큰 상어 빼고 다 지운다.
*/