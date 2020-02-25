package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main_16235_나무재테크 {

	private static int N, M, K;
	private static String str;
	private static int[][] winter, energy;
	private static ArrayList<Integer> map[][];

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		winter = new int[N][N];
		energy = new int[N][N];
		map = new ArrayList[N][N];
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) map[i][j] = new ArrayList<>();
		}
		for(int i=0;i<N;i++) Arrays.fill(energy[i], 5);

		for(int i=0;i<N;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<N;j++) winter[i][j] = Integer.parseInt(st.nextToken());
		}

		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			map[Integer.parseInt(st.nextToken())-1][Integer.parseInt(st.nextToken())-1].add(Integer.parseInt(st.nextToken()));	//���������� �� ��ǥ�� ArrayList�� ����
		}
		
		for(int i=0;i<K;i++) {
			spring();
			fall();
			winter();			
		}		
		System.out.println(howTreeNumber());
	}

	

	private static void spring() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(map[i][j].isEmpty()) continue;
				if(map[i][j].size()>=2) Collections.sort(map[i][j]);
				int curEnergy = energy[i][j], idx=-1;
				for(int k=0, size=map[i][j].size();k<size;k++) {
					if(curEnergy >= map[i][j].get(k)) {		
						curEnergy -= map[i][j].get(k);		
						map[i][j].set(k, map[i][j].get(k)+1);
					}
					else {
						idx = k;
						break;
					}
				}
				if(idx != -1) {
					for(int k=0, size=map[i][j].size()-idx;k<size;k++) {	
						curEnergy += map[i][j].get(idx)/2;
						map[i][j].remove(idx);
					}
				}
				energy[i][j] = curEnergy;
			} 
		}
	}
	static int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};
	static int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
	private static void fall() {
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				if(map[i][j].size() == 0) continue;
				for(int k=0, size=map[i][j].size();k<size;k++) {
					if(map[i][j].get(k) % 5 == 0) {				
						for(int l=0;l<8;l++) {
							int ny = i+dy[l], nx=j+dx[l];
							if(ny<0 || ny>=N || nx<0 || nx>=N) continue;	
							map[ny][nx].add(1);							
						}
					}
				}
			}
		}
	}
	
	private static void winter() {
		for(int i=0;i<N;i++) 
			for(int j=0;j<N;j++) 
				energy[i][j] += winter[i][j];
	}
	
	private static int howTreeNumber() {
		int number = 0;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				number += map[i][j].size();
		return number;
	}
}