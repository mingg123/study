import java.util.*;
public class Steppingstone {
class Solution {
    public boolean validation(int m, int k, int [] stones) {
        int cnt = 0;
        for(int i = 0; i < stones.length; i++) {
            if(stones[i] < m) {
                cnt++;
                if(cnt >= k) return false;
            } else {
                cnt = 0;
            }
        }
        return true;
    }
    public int solution(int[] stones, int k) {
        int answer = 0;
        int min = 0;
        int max = 200000000;
        while(min <= max) {
            int mid = (min + max) / 2;
            if(validation(mid, k, stones)) {
                //멈춰야 하기 때문
                min = mid + 1;
                answer = mid;
            } else {
                max = mid - 1;
            }
        }
        return answer;
    }
       
}

}
