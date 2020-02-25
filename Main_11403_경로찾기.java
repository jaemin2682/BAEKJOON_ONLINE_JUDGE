package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main_11403_경로찾기 {
static int N, ver;
static boolean check;
static ArrayList<Integer>[] vertex;
static boolean visited[];
static String str;
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		vertex = new ArrayList[N+1];							//ArrayList �迭 �Ҵ�
		visited = new boolean[N+1];
		for(int i=0;i<N;i++) vertex[i+1] = new ArrayList<>();	//ArrayList �Ҵ�
		for(int i=1;i<=N;i++) {
			str = br.readLine();
			for(int j=1, idx=0;j<=N;idx+=2,j++) {
				ver = str.charAt(idx) - '0';
				if(ver == 1) {
					vertex[i].add(j);
				}
			}
		}
		
		for(int i=1;i<=N;i++) {	//��� ������ ���� i>j�� �� �� �ִ��� �˻�
			Arrays.fill(visited, false);
			dfs(i);
			for(int j=1;j<=N;j++) {
				if(visited[j]) System.out.print(1 + " ");
				else System.out.print(0 + " ");
			}
			System.out.println();
		}
		
	}
	
	static void dfs(int start) {
		int size = vertex[start].size();
		for(int i=0;i<size;i++) {
			ver = vertex[start].get(i);
			if(!visited[ver]) {
				visited[ver] = true;
				dfs(ver);
			}
		}
	}
// 4. 1. 5 6 7 2
}
