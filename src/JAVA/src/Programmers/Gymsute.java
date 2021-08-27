 import java.util.*;
public class Gymsute {
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = n-lost.length;
        Arrays.sort(lost);
        Arrays.sort(reserve);
        for(int i = 0; i < lost.length; i++) {
            for(int j = 0; j < reserve.length; j++) {
                if(lost[i] == reserve[j]) {
                    lost[i] = -1;
                    reserve[j] = -1;
                    answer++;
                    break;
                }
            }
        }
        for(int i = 0; i < reserve.length; i++) {
            int temp = reserve[i];
            for(int j = 0; j < lost.length; j++) {
                if(lost[j] != -1 && ((temp-1) == lost[j] || (temp+1) == lost[j])){
                    lost[j] = -1;
                    answer++;
                    break;
                }
            }
        }
        return answer;
    }

}
