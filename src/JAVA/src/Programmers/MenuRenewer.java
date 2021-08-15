import java.util.*;
class MenuRenewer {
    //모든 경우의 수를 담아야함 조합으로
    private static List<String> combination;
    public String[] solution(String[] orders, int[] course) {
        String[] answer = {"a"};
        combination = new ArrayList<>();
        //우선 이거 정렬
        Arrays.sort(orders);

        for(int i = 0; i <orders.length; i++) {
            char [] orders_token = orders[i].toCharArray();
            Arrays.sort(orders_token);
            
            for(int j = 0; j < orders_token.length -1; j++) {
                for(int k = 0; k < course.length; k++) {
                    DFS(orders_token, j, 1, course[k], Character.toString(orders_token[j]));
                }
            }
        }
        //모든 경우의 수를 넣고 이제 map에 넣어서 정렬해아함
        HashMap<String, Integer> map = new HashMap<>();
        for(int i = 0; i < combination.size(); i++) {
            map.put(combination.get(i), map.getOrDefault(combination.get(i),0) +1);
        }
        //이제 value에 맞게 정렬해야함
        ArrayList<String> keyList = new ArrayList<>(map.keySet());
        Collections.sort(keyList, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return map.get(o2) - map.get(o1);
            }
        });
        
        ArrayList<String> result = new ArrayList<>();
        for(int i = 0; i < course.length; i++) {
            int max = 0;
            for(String key : keyList) {
                if(map.get(key) != 1 && key.length() == course[i]) {
                    if(map.get(key) >= max) {
                        result.add(key);
                        max = map.get(key);
                    }
                }
            }
        }
        Collections.sort(result);
        // for(int i = 0; i < result.size(); i++) {
        //     System.out.println(result.get(i));
        // }
        answer = new String[result.size()];
        result.toArray(answer);
        //알파뱃 순으로 정렬 
        return answer;
    }
  
 
    
    public static void DFS(char [] arr, int idx, int currentLen, int endLen, String str) {
        if(currentLen == endLen) {
            combination.add(str);
        }
        for(int i = idx+1; i < arr.length; i++) {
            DFS(arr, i, currentLen+1, endLen, str+arr[i]);
        }
    }
}