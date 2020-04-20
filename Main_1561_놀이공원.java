package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_1561_놀이공원 {

	private static int N, M;
	private static int[] roundTime;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());  M = Integer.parseInt(st.nextToken());
		roundTime = new int[M];
		st = new StringTokenizer(br.readLine());
		for(int i=0;i<M;i++) roundTime[i] = Integer.parseInt(st.nextToken());
		
		if(N <= M) {System.out.println(N); System.exit(0);}		//놀이기구가 더 많으면 마지막 아이 번호 바로 출력
		long left = 0, right = 2000000000*30l, time=0;			//최소, 최대 시간 기준으로 이분탐색
		while(left <= right) {
			long mid = (left+right)/2;
			long num = M;
			for(int i=0;i<M;i++) num += mid / roundTime[i];	//mid 시간 때 몇명까지 타는지
			if(num >= N) {time = mid; right = mid-1;}		//N을 넘기는 최소시간을 구한다. 즉, 마지막 아이가 탄 시간
			else left = mid+1;
		}
		long number = M;	//0초 때 M명이 탈거임
		for(int i=0;i<M;i++) number += (time-1) / roundTime[i];	//구한 시간 1분 전에 탄 아이들의 수(=탄 아이의 넘버)를 구함.
		for(int i=0;i<M;i++) {		//이제 time초에 아이 번호를 1씩 늘려주면서 N번째 아이가 어떤걸 탔는지 구함
			if(time % roundTime[i] == 0) number++; //시간이 배수일 때 타니까
			if(number == N) {					   //N번째면
				System.out.println(i+1);
				break;
			}
		}
	}

}
/*
N명(1 ~ 20억), M종류(1~1만)
즉 ,N이 아닌 logN or MlogN으로 풀어야 한다. (log면 이분탐색?)

특정 시간 x에 애들을 지금까지 몇명 태웠는지 계산한다.
이분탐색으로 지금까지 태운 아이들의 명수와 N이 가장 가까운 시간을 뽑아내, 정확히 N명을 태웠을 경우 어떤걸 타는지 확인한다.

*/