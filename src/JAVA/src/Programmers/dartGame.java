import java.util. *;
public class dartGame {

    public int solution(String dartResult) {
        int answer = 0;
        int idx = 0;
        int arr[] = new int[3];
        String preVal = "";
        for (int i = 0; i < dartResult.length(); i++) {
            switch (dartResult.charAt(i)) {
                case 'S':
                    arr[idx] = Integer.parseInt(preVal);
                    idx++;
                    preVal = "";
                    System
                        .out
                        .println(preVal);
                    break;
                case 'D':
                    arr[idx] = (int)Math.pow(Integer.parseInt(preVal), 2);
                    idx++;
                    preVal = "";
                    System
                        .out
                        .println(preVal);
                    break;
                case 'T':
                    arr[idx] = (int)Math.pow(Integer.parseInt(preVal), 3);
                    idx++;
                    preVal = "";
                    System
                        .out
                        .println(preVal);
                    break;
                case '*':
                    arr[idx - 1] = arr[idx - 1] * 2;
                    //안써주면 index Error 발생
                    if (idx > 1) 
                        arr[idx - 2] = arr[idx - 2] * 2;
                    break;
                case '#':
                    arr[idx - 1] = arr[idx - 1] * -1;
                    break;
                default:
                    preVal = preVal + Character.toString(dartResult.charAt(i));
                    break;

            }
        }
        for (int i = 0; i < 3; i++) {
            answer = answer + arr[i];
        }
        return answer;
    }

}
