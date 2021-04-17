package Programmers;

public class StringCompress {
	public static int solution(String s) {
		if(s.length() == 1) return 1;
		int answer = 1001;
		for(int i = 1; i <= (s.length()/2) ; i++) {
			String result = "";
			int prefix = 1;
			String now, next = "";
			for(int j = 0; j<= s.length() /i; j++) {
				int start, end = 0;
				start = i * j;
//				런타임 에러 발생
//				end = i * (j+1);
//				if(end > s.length()) end = s.length();
				end = i * (j + 1) > s.length() ? s.length() : i * (j + 1);
				now = next;
				next = s.substring(start, end);
				if (now.equals(next)) {
					prefix++;
				} else {
					if (prefix <= 1) {
						result = result + now;
					} else {
						result = result + (prefix) + now;
					}
					prefix = 1;
				}
			}
			result = result + (prefix) + next;
//			result = result.replaceAll("1", "");   // 10a10b 를 0a0b로 바꾸어 반례
			answer = (Math.min(answer, result.length()));
		}
		return answer;
	}

	public static void main(String args[]) {
		solution("abcabcdede");
	}
}
