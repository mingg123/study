import java.util. *;
public class ShuttleBus {
    public String solution(int n, int t, int m, String[] timetable) {
        Arrays.sort(timetable);
        Queue<Integer> q = new LinkedList<>();
        int answer = 0;
        int startTime = 9 * 60;
        List<Integer> [] list = new List[n];
        for (int i = 0; i < timetable.length; i++) {
            int hour = Integer.parseInt(timetable[i].split(":")[0]);
            int min = Integer.parseInt(timetable[i].split(":")[1]);
            int total = hour * 60 + min;
            q.add(total);
        }

        for (int i = 0; i < n; i++) {
            list[i] = new ArrayList<>();
            while (!q.isEmpty()) {
                int arrivedTime = q.peek();
                if (arrivedTime <= startTime && list[i].size() < m) {
                    q.remove();
                    list[i].add(arrivedTime);
                } else {
                    break;
                }
                //1초전에도착해야 탐
                answer = arrivedTime - 1;
            }
            startTime = startTime + t;
        }
        //자리가 남았다면
        if (list[n - 1].size() < m) {
            answer = startTime - t;
        }
        String hh = String.format("%02d", answer / 60);
        String mm = String.format("%02d", answer % 60);
        return hh + ":" + mm;
    }
}
