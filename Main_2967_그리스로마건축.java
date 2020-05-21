package Algorithm;

import java.util.Arrays;
import java.util.Scanner;

public class Main_2967_그리스로마건축 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int R = sc.nextInt(), C = sc.nextInt();
		char[][] map = new char[R][C];
		int[][] visited = new int[R][C], rem = new int[R][C];
		int size = 0;
		for(int i=0;i<R;i++) {
			String str = sc.next();
			for(int j=0;j<C;j++) {
				map[i][j] = str.charAt(j);
				if(map[i][j] == 'x') size++;
			}
		}
		//가능한 최대 정사각형의 size를 구한다.
		int maxSize = 0;
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				if(map[i][j] != 'x') continue;
				int cSize = 0, rSize = 0;
				for(int a=j;a<C;a++) if(map[i][a] == 'x') cSize++;
				for(int a=i;a<R;a++) if(map[a][j] == 'x') rSize++;
				maxSize = Math.max(maxSize, Math.min(cSize, rSize));
			}
		}
		//최대사이즈 ~ 1사이즈를 모든 좌표에 넣어보고, 가능한 case에 대해서 다른 건물을 최대사이즈 ~ 1사이즈를 모두 넣어봄..ㅅㅂ
		for(int s = maxSize ; s > 0 ; s--) {
			for(int i=0;i<R;i++) {
				for(int j=0;j<C;j++) {
					if(map[i][j] != 'x') continue;
					for(int k=0;k<R;k++) Arrays.fill(visited[k], 0);
					boolean isSuccess = true;
					fail:
					for(int k=0;k<s;k++) {
						for(int l=0;l<s;l++) {
							if(i+k >= R || j+l >= C) {isSuccess = false; break fail;}
							if(map[i+k][j+l] != 'x') {isSuccess = false;   break fail;}
							visited[i+k][j+l]++;
						}
					}
					if(!isSuccess) continue;
					
					for(int s2 = maxSize; s2 > 0 ; s2--) {
						for(int i2=0;i2<R;i2++) {
							for(int j2=0;j2<C;j2++) {
								if(map[i2][j2] != 'x') continue;
								for(int a=0;a<R;a++) Arrays.fill(rem[a], 0);
								for(int a=0;a<R;a++) for(int b=0;b<C;b++) rem[a][b] = visited[a][b];
								boolean isSuccess2 = true;
								fail2:
								for(int k2=0;k2<s2;k2++) {
									for(int l2=0;l2<s2;l2++) {
										if(i2+k2 >= R || j2+l2 >= C) {isSuccess2 = false; break fail2;}
										if(map[i2+k2][j2+l2] != 'x') {isSuccess2 = false;  break fail2;}
										rem[i2+k2][j2+l2]++;
									}
								}
								if(!isSuccess2) continue;
								
								boolean isFin = true;
								for(int k2=0;k2<R;k2++) {	//가능한지 check
									for(int l2=0;l2<C;l2++) {
										if(map[k2][l2] == 'x' && rem[k2][l2] == 0) isFin = false;
										if(map[k2][l2] != 'x' && rem[k2][l2] != 0) isFin = false;
									}
								}
								if(isFin) {
									System.out.println((i+1) + " " + (j+1) + " " + s);
									System.out.println((i2+1) + " " + (j2+1) + " " + s2);
									System.exit(0);
								}
							}
						}
					}
				}
			}
		}
	}
}
/*
xx.
xxx
...

xx.
xx.
xx.

xx.
xxx
.xx

x..
.xx
.xx
*/
