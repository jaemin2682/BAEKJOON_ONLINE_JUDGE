package Algorithm;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main_1043_거짓말 {

	private static int N, M, knowNum, partyNum, ans;
	private static ArrayList<Integer> know = new ArrayList<>();
	private static ArrayList<Integer>[] adjList, partyList;
	private static boolean[] visited;
	private static Queue<Integer> q = new LinkedList<Integer>();

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		adjList = new ArrayList[N+1];		//인접리스트. 1 ~ N 인덱스 사용
		partyList = new ArrayList[M];		//파티의 참여자 리스트(저장)
		visited = new boolean[N+1];			//진실을 알 수 있는 사람인지
		
		for(int i=1;i<N+1;i++) adjList[i] = new ArrayList<>();
		for(int i=0;i<M;i++) partyList[i] = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		knowNum = Integer.parseInt(st.nextToken());
		for(int i=0;i<knowNum;i++) know.add(Integer.parseInt(st.nextToken()));	//진실을 아는 사람의 리스트
		for(int i=0;i<M;i++) {
			st = new StringTokenizer(br.readLine());
			partyNum = Integer.parseInt(st.nextToken());
			for(int j=0;j<partyNum;j++) partyList[i].add(Integer.parseInt(st.nextToken()));
			for(int j=0, size=partyList[i].size();j<size;j++) {	//인접리스트 만들어줌
				for(int k=0;k<size;k++) {
					if(j==k) continue;
					adjList[partyList[i].get(j)].add(partyList[i].get(k));
				}
			}
		}
		
		for(int i=0, size=know.size();i<size;i++) {
			if(!visited[know.get(i)]) bfs(know.get(i));
		}
		for(int i=0;i<M;i++) {
			boolean isLie = true;
			for(int j=0, size=partyList[i].size();j<size;j++) {
				if(visited[partyList[i].get(j)]) {isLie = false; break; }
			}
			if(isLie) ans++;
		}
		System.out.println(ans);
	}
	

	private static void bfs(int start) {
		q.clear();
		q.add(start);
		visited[start] = true;
		while(q.size() != 0) {
			int node = q.poll();
			for(int i=0, size=adjList[node].size();i<size;i++) {	//인접노드들에 대해
				int nNode = adjList[node].get(i);
				if(visited[nNode]) continue;
				visited[nNode] = true;
				q.add(nNode);
			}
		}
	}

}
/*
과장 or 진실.  과장을 더 좋아함 but 몇몇은 진실을 안다. / 거짓말쟁이 되기 싫어
진실을 아는 사람이 파티에 왔을때 -> 진실
어떤 사람이 한 파티에서는 진실, 한 파티에서는 과장으로 들어도 거짓말쟁이가 됌.

1. 진실을 아는 사람이 있는 파티? -> 진실을 말해야 함.
2. 그 파티에 있는 사람들이 있는 파티? -> 진실을 말해야 함.
꼬리에 꼬리를 물 수 있음. -> 그래프로 표현하면 편할 듯.
한 파티에 참석중인 사람들은, 서로 연결된 사람들이다. -> 진실을 아는 사람과 어떤식으로든 연결이 되어있으면, 그  사람도 진실을 알게 된다.

구현
1. 매 파티를 입력받아서, 같은 파티에 있는 사람들은 서로 연결되있는 인접리스트(ArrayList)를 만듬.
2. 진실을 아는 사람부터 bfs 출발, visited배열로 진실을 알게 되는 사람들을 표시.
3. 각 파티를 확인해보며, 진실을 알게 되는 사람이 없으면 가장을 할 수 있는 파티.

*/