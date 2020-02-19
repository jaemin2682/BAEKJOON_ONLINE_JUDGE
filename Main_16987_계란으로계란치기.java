package baekjoon;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main_16987_계란으로계란치기 {

	private static int N, cnt, ans;
	private static ArrayList<Egg> arr;

	public static class Egg {
		int hp;
		int weight;

		public Egg(int hp, int weight) {
			super();
			this.hp = hp;
			this.weight = weight;
		}
	}

	private static void calc() {
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (arr.get(i).hp <= 0) {
				count++;
			}
		}
		ans = Integer.max(count, ans);
	}


	static void calEgg(int cnt) {
		calc();
		if (cnt == N) {	
			return;
		}
				
		if(arr.get(cnt).hp > 0) {
			for(int i=0;i<N;i++) {
				if(i != cnt && arr.get(i).hp > 0) {
					arr.get(cnt).hp -= arr.get(i).weight;
					arr.get(i).hp -= arr.get(cnt).weight;
					calEgg(cnt+1);
					arr.get(cnt).hp += arr.get(i).weight;
					arr.get(i).hp += arr.get(cnt).weight;
				}
			}
		} else calEgg(cnt+1);
	}


	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new ArrayList<Egg>();
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			arr.add(new Egg(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}

		calEgg(0);
		System.out.println(ans);
	}
}
/*
 * 
 * 
 * 
 */