package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_18119_단어암기 {
	static int N, M, oper, state = (1<<26) - 1, words[];
	static String str;
	static char alpha;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken()); words = new int[N];
		for(int i=0;i<N;i++) {
			str = br.readLine();  int flag = 0;
			for(int j=0;j<str.length();j++) flag |= 1 << (str.charAt(j) - 'a');
			words[i] = flag;
		}
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine(), " ");
			oper = Integer.parseInt(st.nextToken()); alpha = st.nextToken().charAt(0);
			if(oper == 2) state |= (1 << alpha - 'a');
			else state &= ~(1 << alpha - 'a');
			System.out.println(getCnt(0));
		}
	}
	static int getCnt(int cnt) {
		for(int i=0;i<N;i++)
			if((words[i] & state) == words[i]) cnt++;
		return cnt;
	}
}