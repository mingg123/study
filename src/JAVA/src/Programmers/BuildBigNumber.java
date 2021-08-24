import java.util.*;

class BuildBigNumber {
    public String solution(String number, int k) {
        String answer = "";
        // numLen : 뽑아야하는 문자열 갯수 
        // 1924면 192/4 를 기준으로 1 9 2 중 가장 큰 수 9를 뽑음
        // 그다음 24중 큰 수인 4를 뽑음 
        // 핵심은 뽑아야하는 문자길이 -1 만큼 뒤에서 제외해주고 가장 큰수를 찾는것
        int numLen = number.length() - k;
        StringBuilder sb = new StringBuilder();
        int index = 0;
        int max = 0;
        for(int i = 0; i < numLen; i++){
            max = 0;
            for(int j = index; j <= k+i; j++) {
                if(max < number.charAt(j)-'0') {
                    max = number.charAt(j)-'0';
                    index = j+1;
                }
            }
            sb.append(max);
        }
        return sb.toString();
    }
}

