
import java.util.*;
class AddTowByTo {
    public int[] solution(int[] numbers) {
        int[] answer;
        Arrays.sort(numbers);
        HashSet <Integer> set = new HashSet<>();
        for(int i = 0; i <numbers.length; i++) {
            for(int j =0; j < numbers.length; j++) {
                if(i!=j) {
                    set.add(numbers[i]+numbers[j]);
                }
            }
        }
        //주석처리한 부분 같은거임
        return set.stream().sorted().mapToInt(Integer::intValue).toArray();
//         ArrayList<Integer> arr = new ArrayList<>(set);
//         Collections.sort(arr);

//         answer = new int[arr.size()];
//         for(int i = 0; i < arr.size(); i++) {
//             answer[i] = arr.get(i);
//         }
//         return answer;
    }
}

