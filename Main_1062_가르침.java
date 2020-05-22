package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main_1062_가르침 {

	static int K, N, ans;
	static String[] words;
	static int[] tempArr; 
	static HashMap<Integer, Boolean> m = new HashMap<>();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken()); K = Integer.parseInt(st.nextToken());
		words = new String[N]; tempArr = new int[26];
		for(int i=0;i<N;i++) words[i] = br.readLine();
		//최소 필요 글자 : 5(a, n, t, i, c)
		if(K >= 5) combi(0, 0);
		System.out.println(ans);
	}

	static void combi(int cnt, int start) {
		//base_case
		if(cnt == K-5) {
			ans = Math.max(ans, check());
			return;
		}
		for(int i=start;i<26;i++) {
			if(i == 0 || i == 2 || i == 8 || i == 13 || i == 19) continue;
			tempArr[cnt] = i;
			combi(cnt+1, i+1);
		}
	}

	static int check() {
		int cnt = 0;
		m.clear(); m.put(0, false); m.put(2, false); m.put(8, false); m.put(13, false); m.put(19, false);
		for(int i=0;i<K-5;i++) m.put(tempArr[i], false);
		for(int i=0;i<N;i++) {	//word
			boolean isGood = true;
			for(int j=0;j<words[i].length();j++) if(!m.containsKey(words[i].charAt(j) - 'a')) {isGood = false; break;}
			if(isGood) cnt++;
		}
		return cnt;
	}
}