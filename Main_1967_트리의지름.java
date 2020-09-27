package Study;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main_1967_Ʈ�������� {

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
		for(int[] child : nodeList[d]) {	//�ش� ����Ʈ������ ���� ū dist�� �ڽĳ��, �ι�°�� ū dist�� �ڽĳ�� ����
			second = Math.max(second, child[1] + dfs(child[0]));
			if(first < second) { int tem = first; first = second; second = tem; }
		}
		ans = Math.max(ans, first + second);	//�� �ڽ� ��� dist�� ������ �ֽ�ȭ
		return first;
	}

}