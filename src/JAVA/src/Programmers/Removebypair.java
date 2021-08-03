import java.util.*;
class Removebypair
{
    public int solution(String s)
    {
        int answer = 0;
        char [] str = s.toCharArray();
        Stack <Character> stack = new Stack<>();
        for(int i =0; i< str.length; i++) {
            if(stack.empty()) {
                stack.push(str[i]);
                continue;
            } else {
                if(stack.peek() == str[i]) {
                    stack.pop();
                } else {
                    stack.push(str[i]);
                }
            }
        }
        if(stack.size() == 0) answer = 1;
        return answer;
    }
}