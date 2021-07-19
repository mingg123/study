import java.util. *;
public class BinaryGame {

    class Solution {
        public String solution(int n, int t, int m, int p) {
            String answer = "";
            String temp = "";
            int num = 0;
            while (temp.length() < t * m) {
                // n진법으로 바꿔줌
                temp = temp + (Integer.toString(num++, n));
            }
            int initIdx = p - 1;

            for (;;) {
                if (answer.length() == t) {
                    break;
                } else {
                    answer = answer + Character.toString(temp.charAt(initIdx));
                    initIdx = initIdx + m;
                }
            }
            return answer.toUpperCase();
        }
    }
}
