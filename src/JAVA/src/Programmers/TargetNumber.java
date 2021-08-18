import java.util.*;
class TargetNumber {
    private static int count;
    public void DFS(int idx, int [] numbers, int target, int sum) {
        if(idx == numbers.length) {
            if(target == sum) {
                count++;
            }
            return;
        }
        int minus = Integer.parseInt("-" + String.valueOf(numbers[idx]));
        DFS(idx+1, numbers, target, sum+ minus);
        DFS(idx+1, numbers, target, sum+ numbers[idx]);
    }
    public int solution(int[] numbers, int target) {
        count = 0;
        DFS(0, numbers, target, 0);
        return count;
    }
}