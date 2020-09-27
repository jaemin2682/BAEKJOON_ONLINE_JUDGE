package Study;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main_1967_트리의지름 {

	static ArrayList<int[]> nodeList[];
	static int ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int n = Integer.parseInt(br.readLine());
		nodeList = new ArrayList[n+1];
		for(int i=1;i<=n;i++) nodeList[i] = new ArrayList<>();
		for(int i=0;i<n-1;i++) {
			st = new StringTokenizer(br.readLine());
			nodeList[Integer.parseInt(st.nextToken())].add(new int[] {Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())});
		}
		dfs(1);
		System.out.println(ans);
	}
	
	static int dfs(int d) {
		int first = 0, second = 0;
		for(int[] child : nodeList[d]) {	//해당 서브트리에서 가장 큰 dist의 자식노드, 두번째로 큰 dist의 자식노드 구함
			second = Math.max(second, child[1] + dfs(child[0]));
			if(first < second) { int tem = first; first = second; second = tem; }
		}
		ans = Math.max(ans, first + second);	//두 자식 노드 dist의 합으로 최신화
		return first;
	}

}