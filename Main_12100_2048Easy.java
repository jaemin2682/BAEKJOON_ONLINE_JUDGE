package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_12100_2048Easy {

	private static int N, ans;
	private static int[][] arr;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N][N];
		for(int i=0;i<N;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) arr[i][j] = Integer.parseInt(st.nextToken());
		}

		dfs(0, arr);
		System.out.println(ans);
	}

	private static void dfs(int cnt, int[][] map) {
		int[][] temp = new int[N][N];
		//base_case
		if(cnt==5) {
			int maxVal = 0;
			for(int j=0;j<N;j++) {
				for(int k=0;k<N;k++) {
					maxVal = Math.max(maxVal, map[j][k]);
				}
			}
			ans = Math.max(ans, maxVal);
			return;
		}
		for(int i=0;i<4;i++) {	//left, right, up, down
			
			for(int j=0;j<N;j++) temp[j] = map[j].clone();	//map배열을 복사			
			
			if(i==0) {	//left
				//방향에 맞게 모으기
				for(int j=0;j<N;j++) {
					int idx = 0;
					for(int k=0;k<N;k++) {
						if(temp[j][k] == 0) continue;
						else if(temp[j][k] != 0) {
							int tem = temp[j][k];
							temp[j][k] = 0;
							temp[j][idx++] = tem;
						}
					}
				}
				//합치기
				for(int j=0;j<N;j++) {	//0행 ~ N-1행
					for(int k=0;k<N-1;k++) {	//0열 ~ N-2열
						if(temp[j][k]==0) continue;		//0일때 말고
						if(temp[j][k] == temp[j][k+1]) {	//이번거와 다음거가 같으면
							temp[j][k] *= 2; temp[j][k+1] = 0;
						}
					}
				}
				//방향에 맞게 다시 모으기
				for(int j=0;j<N;j++) {
					int idx = 0;
					for(int k=0;k<N;k++) {
						if(temp[j][k] == 0) continue;
						else if(temp[j][k] != 0) {
							int tem = temp[j][k];
							temp[j][k] = 0;
							temp[j][idx++] = tem;
						}
					}
				}
			}
			else if(i==1) {	//right
				//방향에 맞게 모으기
				for(int j=0;j<N;j++) {
					int idx = N-1;
					for(int k=N-1;k>=0;k--) {
						if(temp[j][k] == 0) continue;
						else if(temp[j][k] != 0) {
							int tem = temp[j][k];
							temp[j][k] = 0;
							temp[j][idx--] = tem;
						}
					}
				}
				//합치기
				for(int j=0;j<N;j++) {	//0행 ~ N-1행
					for(int k=N-1;k>=1;k--) {	//0열 ~ N-2열
						if(temp[j][k]==0) continue;		//0일때 말고
						if(temp[j][k] == temp[j][k-1]) {	//이번거와 다음거가 같으면
							temp[j][k] *= 2; temp[j][k-1] = 0;
						}
					}
				}
				//방향에 맞게 다시 모으기
				for(int j=0;j<N;j++) {
					int idx = N-1;
					for(int k=N-1;k>=0;k--) {
						if(temp[j][k] == 0) continue;
						else if(temp[j][k] != 0) {
							int tem = temp[j][k];
							temp[j][k] = 0;
							temp[j][idx--] = tem;
						}
					}
				}
			}
			else if(i==2) {	//up
				//방향에 맞게 모으기
				for(int j=0;j<N;j++) {	//x
					int idx = 0;
					for(int k=0;k<N;k++) {	//y
						if(temp[k][j] == 0) continue;
						else if(temp[k][j] != 0) {
							int tem = temp[k][j];
							temp[k][j] = 0;
							temp[idx++][j] = tem;
						}
					}
				}
				//합치기
				for(int j=0;j<N;j++) {	//x
					for(int k=0;k<N-1;k++) {	//y
						if(temp[k][j]==0) continue;		//0일때 말고
						if(temp[k][j] == temp[k+1][j]) {	//이번거와 다음거가 같으면
							temp[k][j] *= 2; temp[k+1][j] = 0;
						}
					}
				}
				//방향에 맞게 다시 모으기
				for(int j=0;j<N;j++) {	//x
					int idx = 0;
					for(int k=0;k<N;k++) {	//y
						if(temp[k][j] == 0) continue;
						else if(temp[k][j] != 0) {
							int tem = temp[k][j];
							temp[k][j] = 0;
							temp[idx++][j] = tem;
						}
					}
				}
			}
			else if(i==3) {	//down
				//방향에 맞게 모으기
				for(int j=0;j<N;j++) {	//x
					int idx = N-1;
					for(int k=N-1;k>=0;k--) {	//y
						if(temp[k][j] == 0) continue;
						else if(temp[k][j] != 0) {
							int tem = temp[k][j];
							temp[k][j] = 0;
							temp[idx--][j] = tem;
						}
					}
				}
				//합치기
				for(int j=0;j<N;j++) {	//x
					for(int k=N-1;k>=1;k--) {	//y
						if(temp[k][j]==0) continue;		//0일때 말고
						if(temp[k][j] == temp[k-1][j]) {	//이번거와 다음거가 같으면
							temp[k][j] *= 2; temp[k-1][j] = 0;
						}
					}
				}
				//방향에 맞게 다시 모으기
				for(int j=0;j<N;j++) {	//x
					int idx = N-1;
					for(int k=N-1;k>=0;k--) {	//y
						if(temp[k][j] == 0) continue;
						else if(temp[k][j] != 0) {
							int tem = temp[k][j];
							temp[k][j] = 0;
							temp[idx--][j] = tem;
						}
					}
				}
			}
			
			dfs(cnt+1, temp);
		}
	}

}
/*
최대 5번 이동 -> 4^5번 탐색. 어떤식으로 해먹든 구현만 정확하면 시간초과는 안난다.
*/