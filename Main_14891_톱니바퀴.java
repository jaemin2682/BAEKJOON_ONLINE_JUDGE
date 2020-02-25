package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main_14891_톱니바퀴 {

	private static LinkedList<Integer>[] arr = new LinkedList[4];
	private static String str;
	private static int K, number, vector, sum;
	private static int check[] = new int[4];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		for(int i=0;i<4;i++) arr[i] = new LinkedList<Integer>();		//linkedList 할당
		
		for(int i=0;i<4;i++) {
			str = br.readLine();
			for(int j=0;j<8;j++) arr[i].add(str.charAt(j) - '0');
		}
		K = Integer.parseInt(br.readLine());
		
		for(int i=0;i<K;i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			number = Integer.parseInt(st.nextToken())-1;
			vector = Integer.parseInt(st.nextToken());
			rotate(number, vector);
		}
		if(arr[0].get(0)==1) sum+=1;
		if(arr[1].get(0)==1) sum+=2;
		if(arr[2].get(0)==1) sum+=4;
		if(arr[3].get(0)==1) sum+=8;
		System.out.println(sum);
	}

	private static void rotate(int num, int vec) {
		Arrays.fill(check, 0);	//check배열 초기화
		vec = vec==1 ? -1 : 1;	//본인의 회전방향과 반대 방향으로 초기화해 놓는다.
				
		int tem = vec;			//실제 회전 시에 초기값을 기억할 수 있도록, 새 변수로 회전방향을 임시저장함 
		//현재 톱니바퀴(6번)부터 0번째까지
		for(int i=num;i>0;i--) {				//num부터 1까지
			if(arr[i].get(6) != arr[i-1].get(2)) {	//현재 톱니바퀴의 6번째가 전 톱니바퀴의 2번째와 다를 때
				if(tem==1) {									//시계 방향
					check[i-1] = tem;
					tem = -1;
				}
				else {											//반시계 방향
					check[i-1] = tem;
					tem = 1;
				}
			}
			else break;									//같을 땐 끝
		}
		tem = vec;										//다시 입력받은 톱니바퀴의 회전상태의 반대로 초기화
		//현재 톱니바퀴(2번)부터 마지막까지
		for(int i=num;i<3;i++) {
			if(arr[i].get(2) != arr[i+1].get(6)) {	//현재 톱니바퀴의 2번째가 다음 톱니바퀴의 6번째와 다를 때
				if(tem==1) {
					check[i+1] = tem;
					tem = -1;
				}
				else {											//반시계 방향
					check[i+1] = tem;
					tem = 1;
				}
			}
			else break;
		}
		
		if(vec==1) {
			arr[num].addLast(arr[num].pollFirst());	 	//반시계방향 : 첫번째꺼 빼서 마지막에 넣음
		}
		else {
			
			arr[num].addFirst(arr[num].pollLast());		//시계방향 : 마지막꺼 빼서 처음에 넣음.
		}
		
		
		for(int i=0;i<4;i++) {
			if(check[i] == 1) arr[i].addFirst(arr[i].pollLast());		//마지막꺼 빼서 처음에 넣음
			else if(check[i] == -1) arr[i].addLast(arr[i].pollFirst());
		}	
	}

}
/*
1번째의 2번째 <-> 2번째의 6번째
2번째의 2번째 <-> 3번째의 6번째
3번째의 2번째 <-> 4번째의 6번째
*/