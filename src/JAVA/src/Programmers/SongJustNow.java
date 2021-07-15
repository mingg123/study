import java.util. *;
public class SongJustNow {
    class Solution {
        public String changeShap(String str) {
            str = str.replace("A#", "a");
            // str = str.replace("B#", "b");
            str = str.replace("C#", "c");
            str = str.replace("D#", "d");
            // str = str.replace("E#", "e");
            str = str.replace("F#", "f");
            str = str.replace("G#", "g");
            return str;
        }
        public String solution(String m, String[] musicinfos) {
            String answer = "";
            int max = -1;
            for (int i = 0; i < musicinfos.length; i++) {
                String info[] = musicinfos[i].split(",");

                String startTime[] = info[0].split(":");
                String endTime[] = info[1].split(":");
                int start = (Integer.parseInt(startTime[0]) * 60) + Integer.parseInt(
                    startTime[1]
                );
                int end = (Integer.parseInt(endTime[0]) * 60) + Integer.parseInt(endTime[1]);

                m = changeShap(m);
                info[3] = changeShap(info[3]);

                int totalLen = end - start;
                // 길이를 이어붙여줘야함 아오
                String Change = "";

                int repeat = (totalLen / info[3].length());
                int add = (totalLen % info[3].length());

                for (int k = 0; k < repeat; k++) {
                    Change = Change + info[3];
                }
                Change = Change + info[3].substring(0, add);

                if (Change.contains(m)) {
                    if (max < totalLen) {
                        answer = info[2];
                        max = totalLen;
                    }
                }
            }

            return max == -1
                ? "(None)"
                : answer;
        }
    }
}
