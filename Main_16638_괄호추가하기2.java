package Study;
import java.util.Scanner;
import java.util.Stack;
public class Main_16638_°ýÈ£Ãß°¡ÇÏ±â2 {
	static int N, n1, n2, res, ans = Integer.MIN_VALUE;
	static String exp, op, cur;
	static Stack<String> s = new Stack<>(), cal = new Stack<>();
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt(); exp = sc.next();
		
		for(int i=0;i<1<<N/2;i++) {
			boolean isValid = true;
			for(int j=0;j<N/2;j++) if((i & 1<<j) != 0 && ((i & 1<<(j+1)) != 0)) {isValid = false;  break;}
			if(isValid) calc(i);
		}
		System.out.println(ans);
	}

	static void calc(int flag) {
		s.clear(); cal.clear();
		for(int i=0;i<exp.length();i++) {	// °ýÈ£ ¿¬»ê
			if(i%2 == 0 && (1 << (i/2) & flag) != 0) {
				n1 = exp.charAt(i) - '0'; n2 = exp.charAt(i+2) - '0';
				res = exp.charAt(i+1) == '*' ? n1 * n2 : exp.charAt(i+1) == '+' ? n1 + n2 : n1 - n2;
				i+=2;
				s.add(Integer.toString(res));
			}
			else s.add(exp.charAt(i)+"");
		}
		while(!s.isEmpty()) cal.add(s.pop());	//¿Å±â°í

		while(!cal.isEmpty()) {					//°ö ¿¬»ê
			cur = cal.pop();
			if(!cal.isEmpty() && cal.peek().equals("*")) {
				res = 0;
				while(!cal.isEmpty() && cal.peek().equals("*")) {
					cal.pop();
					res =res == 0 ? Integer.parseInt(cur) * Integer.parseInt(cal.pop()) : res * Integer.parseInt(cal.pop());
				}
				s.add(Integer.toString(res));
			}
			else s.add(cur);
		}
		while(!s.isEmpty()) cal.add(s.pop());	//¿Å±â°íd

		res = Integer.parseInt(cal.pop());
		while(!cal.isEmpty()) {					// µ¡¼À, »¬¼À ¿¬»ê
			op = cal.pop(); n1 = Integer.parseInt(cal.pop());
			res = op.equals("+") ? res + n1 : res - n1; 
		}
		ans = Integer.max(ans, res);
	}
}