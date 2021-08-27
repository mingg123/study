import java.util.*;
public class Lifeboat {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);
        int min = 0;
        //50 50 70 80 이 존재할경우 50 80 100보다 큼으로 80은 혼자탄다. 그다음 50 70 비교 70 혼자탐 50 50 비교
        for(int max = people.length -1; min<=max; max--) {
            if(people[min]+people[max] <= limit) {
                min++;
            }
            answer++;
        }
        return answer;
    }
}
