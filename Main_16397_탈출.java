package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_16397_탈출 {

	private static int N, T, G, time;
	private static boolean isFin;
	private static boolean[] visited = new boolean[100000];

	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		T = Integer.parseInt(st.nextToken());
		G = Integer.parseInt(st.nextToken());
		
		bfs();
		
		if(N==G) System.out.println(0);
		else if(!isFin) System.out.println("ANG");
		else System.out.println(time);
	}

	private static void bfs() {
		Queue<Integer> q  = new LinkedList<Integer>();
		q.add(N); 
		while(!q.isEmpty()) {
			time++;
			if(time > T) return;				
			for(int i=0,size=q.size();i<size;i++) {
				int x = q.poll();
				for(int j=0;j<2;j++) {
					int nx = 0;
					if(j==0) nx = x + 1;		
					if(j==1) {					
						if(x*2 > 99999) continue;		
						if(x==0) continue;				
						StringBuilder temp = new StringBuilder(Integer.toString(x*2));
						for(int k=0, size2=temp.length();k<size2;k++) {
							if(temp.charAt(k) != '0') {
								temp.setCharAt(k, (char)(temp.charAt(k)-1));
								break;
							}
						}
						nx = Integer.parseInt(temp.toString());
					}
					if(nx > 99999) continue;
					if(visited[nx]) continue;
					if(nx == G) {
						isFin = true;
						return;
					}
					q.add(nx);
					visited[nx] = true;
				}
			}
		}
		
	}
}
/*
�ټ��ڸ� ������ N, T:����, G:����
��ư A : N++
��ư B : N*2 �Ŀ� 0�� �ƴ� ���� ���� �ڸ����� ���ڰ� 1 �پ��  (N�� 0�̸� �Ⱥ���)
N�� 99,999�� �Ѿ�� ���� Ż�� ����
B�� ���� N�� 2�� ���� ���� 99,999�� �Ѿ ���� �ٷ� ���� 
�ִ� Tȸ ��ư ���� �� ����.
�� Ƚ�� �ȿ� N�� G�� ���� ������ Ż�� ����
�ּ� ��ư Ƚ���� Ż��
1 > 2 > 3 5
*/