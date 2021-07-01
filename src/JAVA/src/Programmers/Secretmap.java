import java.util.*;
public class Secretmap {
    static public int len = 0;
    public String checkValidation(String str) {
        String zero = "";
        if(str.length() > len) {
            str = str.substring(str.length() - len, str.length());
            return str;
        } else {     
            //n 자리수 보다 적을경우 
            for(int i = 0; i< len- str.length(); i++) {
                zero = zero + "0";
            }
        }
        return zero + str;
    }
    public String[] solution(int n, int[] arr1, int[] arr2) {
        len = n;
        String[] answer = new String[n];
        for(int i = 0; i<n; i++) {
             String binary1 = Integer.toBinaryString(arr1[i]);
             String binary2 = Integer.toBinaryString(arr2[i]);
             binary1 = checkValidation(binary1);
             binary2 = checkValidation(binary2);
         
            String temp = "";
            for(int j =0; j<n; j++) {
                if(binary1.charAt(j) == '1' || binary2.charAt(j) == '1') {
                    temp = temp + "#";
                } else {
                    temp = temp + " ";
                }
            }
            answer[i] = (temp);
        }
        return answer;
    }
}

