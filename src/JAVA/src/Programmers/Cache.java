import java.util. *;
public class Cache {
    public int solution(int cacheSize, String[] cities) {
        int answer = 0;
        for (int i = 0; i < cities.length; i++) {
            cities[i] = cities[i].toUpperCase();
        }

        ArrayList<String> arr = new ArrayList<String>();
        for (int i = 0; i < cities.length; i++) {
            if (cacheSize == 0) 
                return cities.length * 5;
            if (!arr.contains(cities[i])) {
                //포함하지 않으면
                if (arr.size() < cacheSize) {
                    arr.add(cities[i]);
                    answer = answer + 5;
                } else {
                    arr.remove(0);
                    arr.add(cities[i]);
                    answer = answer + 5;
                }
            } else {
                String temp = cities[i];
                arr.remove(temp);
                arr.add(cities[i]);
                answer++;
            }
        }
        return answer;
    }

}
