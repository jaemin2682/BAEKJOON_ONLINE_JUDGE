package Algorithm;

import java.util.Scanner;

public class Main_17825_주사위윷놀이 {
	private static int[] arr;
	private static int ans;
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		arr = new int[10];
		for(int i=0;i<10;i++) arr[i] = sc.nextInt();
		dfs(0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		System.out.println(ans);
	}
	
	
	static int pos[][] = {{0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
			{10, 13, 16, 19, 25, 30, 35, 40},
			{20, 22, 24, 25, 30, 35, 40},
			{30, 28, 27, 26, 25, 30, 35, 40}};
	private static void dfs(int cnt, int oneType, int oneIdx, int twoType, int twoIdx, int threeType, int threeIdx, int fourType, int fourIdx, int sum) {
		//base_case
		if(cnt == 10) {
			ans = Math.max(sum, ans);
			return;
		}
		for(int i=1;i<=4;i++) {
			if(i==1) {	//첫째 말
				int type = oneType, idx = oneIdx;		//i번째 말의 이동Type, 현재 idx
				if(type == -1) continue;				//도착한 말이라면 continue
				
				if(type==0 && idx==5) {type = 1; idx = arr[cnt];}		//10에서 시작할 경우
				else if(type==0 && idx==10) {type = 2; idx = arr[cnt];}	//20에서 시작할 경우	
				else if(type==0 && idx==15) {type = 3; idx = arr[cnt];}	//30에서 시작할 경우
				else idx += arr[cnt];
				
				if((type==twoType && idx==twoIdx) || (type==threeType && idx==threeIdx) || (type==fourType && idx==fourIdx)) continue;	//다른 말이 있을 경우 다른 말 사용
				if(idx >= pos[type].length) type = -1;		 //도착했을경우 앞으로 제외시킬거임
				
				if(type != -1 && pos[type][idx] == 25) {	//모든 경로에 25가 존재하므로, 다른 말이 25에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==25) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==25) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==25) continue;
				}
				else if(type != -1 && pos[type][idx] == 30 && type != 0) {	//모든 경로에 30이 존재하므로, 다른 말이 30에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==30 && twoType!=0) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==30 && threeType!=0) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==30 && fourType!=0) continue;
				}
				else if(type != -1 && pos[type][idx] == 35) {	//모든 경로에 35이 존재하므로, 다른 말이 35에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==35) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==35) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==35) continue;
				}
				else if(type != -1 && pos[type][idx] == 40) {	//모든 경로에 40이 존재하므로, 다른 말이 40에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==40) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==40) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==40) continue;
				}				
				
				if(type==-1) dfs(cnt+1, type, idx, twoType, twoIdx, threeType, threeIdx, fourType, fourIdx, sum);
				else dfs(cnt+1, type, idx, twoType, twoIdx, threeType, threeIdx, fourType, fourIdx, sum+pos[type][idx]);
			}
			else if(i==2) {
				int type = twoType, idx = twoIdx;
				if(type == -1) continue;

				if(type==0 && idx==5) {type = 1; idx = arr[cnt];}	//10에서 시작할 경우
				else if(type==0 && idx==10) {type = 2; idx = arr[cnt];}	//20에서 시작할 경우	
				else if(type==0 && idx==15) {type = 3; idx = arr[cnt];}	//30에서 시작할 경우
				else idx += arr[cnt];
				
				if((type==oneType && idx==oneIdx) || (type==threeType && idx==threeIdx) || (type==fourType && idx==fourIdx)) continue;	//다른 말이 있을 경우 다른 말 사용
				if(idx >= pos[type].length) type = -1;					//도착했을경우 앞으로 논외
				
				if(type != -1 && pos[type][idx] == 25) {	//모든 경로에 25가 존재하므로, 다른 말이 25에 있으면 위와같이 다른놈 이동
					if(oneType != -1 && pos[oneType][oneIdx]==25) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==25) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==25) continue;
				}
				else if(type != -1 && pos[type][idx] == 30 && type != 0) {	//모든 경로에 30이 존재하므로, 다른 말이 30에 있으면 위와같이 다른놈 이동
					if(oneType != -1 && pos[oneType][oneIdx]==30 && oneType!=0) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==30 && threeType!=0) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==30 && fourType!=0) continue;
				}
				else if(type != -1 && pos[type][idx] == 35) {	//모든 경로에 35이 존재하므로, 다른 말이 35에 있으면 위와같이 다른놈 이동
					if(oneType != -1 && pos[oneType][oneIdx]==35) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==35) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==35) continue;
				}
				else if(type != -1 && pos[type][idx] == 40) {	//모든 경로에 40이 존재하므로, 다른 말이 40에 있으면 위와같이 다른놈 이동
					if(oneType != -1 && pos[oneType][oneIdx]==40) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==40) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==40) continue;
				}	
				
				if(type == -1) dfs(cnt+1, oneType, oneIdx, type, idx, threeType, threeIdx, fourType, fourIdx, sum);
				else dfs(cnt+1, oneType, oneIdx, type, idx, threeType, threeIdx, fourType, fourIdx, sum+pos[type][idx]);
			}
			else if(i==3) {
				int type = threeType, idx = threeIdx;
				if(type == -1) continue;
				
				if(type==0 && idx==5) {type = 1; idx = arr[cnt];}	//10에서 시작할 경우
				else if(type==0 && idx==10) {type = 2; idx = arr[cnt];}	//20에서 시작할 경우	
				else if(type==0 && idx==15) {type = 3; idx = arr[cnt];}	//30에서 시작할 경우(30이 2개라 type==0조건 넣음)
				else idx += arr[cnt];
				
				if((type==twoType && idx==twoIdx) || (type==oneType && idx==oneIdx) || (type==fourType && idx==fourIdx)) continue;	//다른 말이 있을 경우 다른 말 사용
				if(idx >= pos[type].length) type = -1;					//도착했을경우 앞으로 논외 
				
				if(type != -1 && pos[type][idx] == 25) {	//모든 경로에 25가 존재하므로, 다른 말이 25에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==25) continue;
					if(oneType != -1 && pos[oneType][oneIdx]==25) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==25) continue;
				}
				else if(type != -1 && pos[type][idx] == 30 && type != 0) {	//모든 경로에 30이 존재하므로, 다른 말이 30에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==30 && twoType!=0) continue;
					if(oneType != -1 && pos[oneType][oneIdx]==30 && oneType!=0) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==30 && fourType!=0) continue;
				}
				else if(type != -1 && pos[type][idx] == 35) {	//모든 경로에 35이 존재하므로, 다른 말이 35에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==35) continue;
					if(oneType != -1 && pos[oneType][oneIdx]==35) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==35) continue;
				}
				else if(type != -1 && pos[type][idx] == 40) {	//모든 경로에 40이 존재하므로, 다른 말이 40에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==40) continue;
					if(oneType != -1 && pos[oneType][oneIdx]==40) continue;
					if(fourType != -1  && pos[fourType][fourIdx]==40) continue;
				}	
				
				
				if(type==-1) dfs(cnt+1, oneType, oneIdx, twoType, twoIdx, type, idx, fourType, fourIdx, sum);
				else dfs(cnt+1, oneType, oneIdx, twoType, twoIdx, type, idx, fourType, fourIdx, sum+pos[type][idx]);
			}
			else if(i==4) {
				int type = fourType, idx = fourIdx;
				if(type == -1) continue;
				
				if(type==0 && idx==5) {type = 1; idx = arr[cnt];}	//10에서 시작할 경우
				else if(type==0 && idx==10) {type = 2; idx = arr[cnt];}	//20에서 시작할 경우	
				else if(type==0 && idx==15) {type = 3; idx = arr[cnt];}	//30에서 시작할 경우(30이 2개라 type==0조건 넣음)
				else idx += arr[cnt];
				
				if((type==twoType && idx==twoIdx) || (type==threeType && idx==threeIdx) || (type==oneType && idx==oneIdx)) continue;	//다른 말이 있을 경우 다른 말 사용
				if(idx >= pos[type].length) type = -1;					//도착했을경우 앞으로 논외 
				
				if(type != -1 && pos[type][idx] == 25) {	//모든 경로에 25가 존재하므로, 다른 말이 25에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==25) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==25) continue;
					if(oneType != -1  && pos[oneType][oneIdx]==25) continue;
				}
				else if(type != -1 && pos[type][idx] == 30 && type != 0) {	//모든 경로에 30이 존재하므로, 다른 말이 30에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==30 && twoType!=0) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==30 && threeType!=0) continue;
					if(oneType != -1  && pos[oneType][oneIdx]==30 && oneType!=0) continue;
				}
				else if(type != -1 && pos[type][idx] == 35) {	//모든 경로에 35이 존재하므로, 다른 말이 35에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==35) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==35) continue;
					if(oneType != -1  && pos[oneType][oneIdx]==35) continue;
				}
				else if(type != -1 && pos[type][idx] == 40) {	//모든 경로에 40이 존재하므로, 다른 말이 40에 있으면 위와같이 다른놈 이동
					if(twoType != -1 && pos[twoType][twoIdx]==40) continue;
					if(threeType != -1 && pos[threeType][threeIdx]==40) continue;
					if(oneType != -1  && pos[oneType][oneIdx]==40) continue;
				}	
				
				if(type == -1) dfs(cnt+1, oneType, oneIdx, twoType, twoIdx, threeType, threeIdx, type, idx, sum);
				else dfs(cnt+1, oneType, oneIdx, twoType, twoIdx, threeType, threeIdx, type, idx, sum+pos[type][idx]);
			}
			
		}
	}
}