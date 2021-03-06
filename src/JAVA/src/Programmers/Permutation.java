import java.util.*;


public class Permutation {
    static LinkedList<String>strList = new LinkedList<>();
    static LinkedList<String> resultList = new LinkedList<>();
    static LinkedList<String> answerList = new LinkedList<>();

    public static void permutation( LinkedList<String> arr,  LinkedList<String> result, int n, int r) {

        if(r == 0) {
            String tempAns = "";
            //01, 1 은 모두 1로 간주하기 때문에 앞자리가 1은 제외 시켜야함 
            if(!result.get(0).equals("0")) {
                for(int i = 0; i < result.size(); i++) {            
                    tempAns = tempAns + result.get(i);
                }
                answerList.push(tempAns);
            }
           return;
        } 
        for(int i = 0 ; i < n; i++) {
            result.add(arr.remove(i).toString());
            permutation(arr, result, n-1, r-1);
            arr.add(i, result.remove(result.size() -1));
        }
    }
    public static int solution(String numbers) {
        int answer = 0;
        //strList에 numbers를 넣어줌
        for(int i = 0; i < numbers.length(); i++) {
            strList.add(Character.toString(numbers.charAt(i)));
        }

   
        for(int i = 0; i < numbers.length(); i++) {
            permutation(strList, resultList, strList.size(), i + 1);
        }

        //중복 제거를 위해 List -> Set -> List로 변환함 
        HashSet <String> set =  new HashSet<>(answerList);
        ArrayList <String> realanswer = new ArrayList<String>(set);
   
        for(int i = 0; i< realanswer.size(); i++) {
            boolean isPrime = false;
            int num = Integer.parseInt(realanswer.get(i));
            int sqrt = (int) Math.sqrt(num);
            if(num == 1) {
                isPrime = false;
            }
            else if(num == 2) isPrime = true;
            else {
                isPrime = true;
                for(int j = 2; j <= sqrt; j++) {
                    if(num % j == 0) {
                        isPrime = false;
                        break;
                    }
                }
            }
            if(isPrime) answer++;
        }
        return answer;
    }
 
    public static void main(String [] args){

        int tet = solution("011");
        System.out.println(tet);
    }
}

