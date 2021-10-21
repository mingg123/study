import java.util.*;
public class PressingKeyboard {
public String solution(int[] numbers, String hand) {
    String answer = "";
    int Lnow = 10;
    int Rnow = 12;
    for(int i = 0; i < numbers.length; i++) {
        int target = numbers[i];
        if(target == 0) target = 11;
        if(target == 1 || target == 4 || target == 7) {
            answer = answer + "L";
            Lnow = target;
        } else if(target ==3 || target == 6 || target == 9) {
            answer = answer + "R";
            Rnow = target;
        } else {
            int leftLen = Math.abs(Lnow-target)/3 + Math.abs(Lnow-target)%3;
            int rightLen = Math.abs(Rnow-target)/3 + Math.abs(Rnow-target)%3;
        
            if(leftLen == rightLen) {
                if(hand.equals("right")) {
                    answer = answer + "R";
                    Rnow = target;
                } else {
                    answer = answer + "L";
                    Lnow = target;
                }
            } else if(leftLen > rightLen) {
                    answer = answer + "R";
                    Rnow = target;
            } else {
                answer = answer + "L";
                Lnow = target;
            }  
        }
    }
    return answer;
}

}
