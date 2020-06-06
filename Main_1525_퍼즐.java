package Algorithm;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main_1525_퍼즐 {

	static int ind[][] = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4, 6}, {1, 3, 5, 7}, {2, 4, 8}, {3, 7}, {4, 6, 8}, {5, 7}};
	static HashMap<String, Boolean> map = new HashMap<>();
	static Queue<Object[]> q = new LinkedList<Object[]>();
	static final String FinStr = "123456780";
	
	public static void main(String[] args) {
		Scanner sc =  new Scanner(System.in);
		String str = "";
		for(int i=0;i<9;i++) {
			String s = sc.next();
			str += s;
		}
		System.out.println(bfs(str, 0));
	}
	
	static int bfs(String str, int cnt) {
		q.add(new Object[] {str, 0});
		map.put(str, false);
		if(str.equals(FinStr)) return 0;
		while(!q.isEmpty()) {
			String curStr = (String) q.peek()[0];
			int curCnt = (int) q.poll()[1], curPos = curStr.indexOf("0");
			StringBuilder sb;
			for(int in : ind[curPos]) {
				sb = new StringBuilder(curStr);
				sb.setCharAt(curPos, curStr.charAt(in));
				sb.setCharAt(in, '0');
				if(map.containsKey(sb.toString())) continue;
				if(sb.toString().equals(FinStr)) return curCnt+1;
				q.add(new Object[] {sb.toString(), curCnt+1});
				map.put(sb.toString(),false);
			}
		}
		return -1;
	}
}