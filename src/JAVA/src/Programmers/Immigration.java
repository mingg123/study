import java.util.*;
class Immigration {
    public long solution(int n, int[] times) {
        long answer = Long.MAX_VALUE;
        Arrays.sort(times);
        long start, mid, end;
        start = 0;
        end = Long.MAX_VALUE;
        mid = 0;
        //sum은 횟수를 셀 수 있음. n 과 같은 몇명까지 검사할 수 있는지 
        long sum = 0;
        while(start<=end) {
            mid = (start+end)/2;
            sum = 0;
            for(int i = 0; i < times.length; i++) {
                sum = sum+ (mid/times[i]);
                if(sum >=n) break;
            }
            if(sum < n) {
                start = mid+1;
            } else {
                end = mid -1;
                answer = Math.min(mid, answer);
            }
        }
        return answer;
    }
}

