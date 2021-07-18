import java.util.*;
public class Tuple {

    class Solution {
        public int[] solution(String s) {
            //가장 앞, 뒤 { , } 제거
            s = s.substring(1, s.length() - 1);
            String[] str = s.split("},");
            String[] token = new String[1000000];

            HashSet<Integer> set = new LinkedHashSet<Integer>();
            Arrays.sort(str, Comparator.comparing(String::length));
            for (int i = 0; i < str.length; i++) {
                // 다음은  가장 앞에 { 제거
                str[i] = str[i].replace("{", "");
                str[i] = str[i].replace("}", "");
   
                token = str[i].split(",");
                for (int j = 0; j < token.length; j++) {
                    if (!set.contains(Integer.parseInt(token[j]))) {
                        set.add(Integer.parseInt(token[j]));
                    }
                }

            }
            int[] answer = new int[set.size()];
            return set
                .stream()
                .mapToInt(Integer::intValue)
                .toArray();
        }
    }
}
