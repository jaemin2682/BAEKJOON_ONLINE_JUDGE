package Study;

import java.util.*;

public class Main_17090_미로탈출하기 {
	static int N, M, isPossible[][], ans;
	static char map[][];
	
	static class Arr {
		int n1, n2;
		public Arr(int n1, int n2) {
			this.n1 = n1;
			this.n2 = n2;
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + n1;
			result = prime * result + n2;
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Arr other = (Arr) obj;
			if (n1 != other.n1)
				return false;
			if (n2 != other.n2)
				return false;
			return true;
		}
		
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); M = sc.nextInt(); map = new char[N][M]; isPossible = new int[N][M];
		for(int i=0;i<N;i++) {
			String str = sc.next();
			for(int j=0;j<M;j++) map[i][j] = str.charAt(j);
		}

		Map<Arr, Boolean> route = new HashMap<>();
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				
				if(isPossible[i][j] == -1) continue;
				else if(isPossible[i][j] == 1) { ans++; continue; }
	
				int curY = i, curX = j;
				route.clear(); route.put(new Arr(curY, curX), false);
				
				for(int cnt=0;cnt<N*M;cnt++) {	
					
					if(isPossible[curY][curX] == 1) {
						for(Arr pos : route.keySet()) isPossible[pos.n1][pos.n2] = 1;
						ans++;
						break;
					}
					if(isPossible[curY][curX] == -1) {
						for(Arr pos : route.keySet()) isPossible[pos.n1][pos.n2] = -1;
						break; 
					}
					
					if(map[curY][curX] == 'U') curY--;
					else if(map[curY][curX] == 'R') curX++;
					else if(map[curY][curX] == 'D') curY++;
					else if(map[curY][curX] == 'L') curX--;
					
					if(route.containsKey(new Arr(curY, curX))) { 	//이미 갔던 곳이라면, loop. 즉, 실패
						for(Arr pos : route.keySet()) isPossible[pos.n1][pos.n2] = -1;
						break; 
					}

					if(curY < 0 || curY >= N || curX < 0 || curX >= M) {
						for(Arr pos : route.keySet()) isPossible[pos.n1][pos.n2] = 1;
						ans++;
						break;
					}
					route.put(new Arr(curY, curX), false);	//경로 추가
				}
			}
		}
		System.out.println(ans);		
	}
}