import java.util.*;
class ParentalTranslation {
    public static String swap(String u) {
        char left = '(';
        char right = ')';
        String temp = "";
        for (int i = 0; i < u.length(); i++) {
            if (u.charAt(i) == left) {
                temp = temp + Character.toString(right);
            } else {
                temp = temp + Character.toString(left);
            }
        }
        return temp;
    }
    public static boolean validation(String p) {
        int left = 0;
        int right = 0;
        boolean flag = true;
        for (int i = 0; i < p.length(); i++) {
            if (p.charAt(i) == '(') 
                left++;
            else 
                right++;
            if (left < right) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    public String solution(String p) {
        if (p.equals("")) 
            return "";
        String answer = "";
        String u = "";
        String v = "";
        int left = 0;
        int right = 0;
        for (int i = 0; i < p.length(); i++) {
            if (p.charAt(i) == '(') 
                left++;
            else 
                right++;
            if (left == right) {
                u = p.substring(0, i + 1);
                v = p.substring(i + 1);
                break;
            }
        }

        //올바른 문자열이면 v 처음부터 다시
        if (validation(u)) {
            return u + solution(v);
        }
        answer = answer + "(" + solution(v) + ")";
        u = u.substring(1, u.length() - 1);
        u = swap(u);
        answer = answer + u;
        return answer;
    }
}