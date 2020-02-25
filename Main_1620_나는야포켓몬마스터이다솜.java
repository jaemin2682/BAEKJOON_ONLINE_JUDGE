package A_ProblemSolving;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class Main_1620_나는야포켓몬마스터이다솜 {

	private static int N, M;
	private static HashMap<String, Integer> m = new HashMap<>();
	private static HashMap<Integer, String> m2 = new HashMap<>();
	private static String str;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		for(int i=1;i<=N;i++) {
			str = br.readLine();
			m.put(str, i);		//Key가 포켓몬 이름
			m2.put(i, str);		//Key가 포켓몬 번호
		}
		for(int i=0;i<M;i++) {
			str = br.readLine();
			if(str.charAt(0) >= '0' && str.charAt(0) <= '9') {	//숫자일 때
				System.out.println(m2.get(Integer.parseInt(str)));
			}
			else {	//문자일 때
				System.out.println(m.get(str));
			}
		}
	}
}
