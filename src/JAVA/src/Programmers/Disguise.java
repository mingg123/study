import java.util.*;
public class Disguise {

    public int solution(String[][] clothes) {
        int answer = 0;
        HashMap<String, ArrayList<String>> map = new HashMap();

        for (int i = 0; i < clothes.length; i++) {
            if (map.containsKey(clothes[i][1])) {
                ArrayList<String> temp = map.get(clothes[i][1]);
                temp.add(clothes[i][0]);
                map.put(clothes[i][1], temp);
            } else {
                ArrayList<String> temp = new ArrayList();
                temp.add(clothes[i][0]);
                map.put(clothes[i][1], temp);
            }
        }

        Iterator<String> keys = map
            .keySet()
            .iterator();
        int count = 1;
        while (keys.hasNext()) {
            String key = keys.next();
            int mapSize = map
                .get(key)
                .size();
            //상의를 두개입을순 없음. 안입는경우도 포함해서 +1
            count = count * (mapSize + 1);
        }

        // System.out.println(multiply); 모든 옷을 안입는 경우는 없음 -1
        return count - 1;
    }

}
