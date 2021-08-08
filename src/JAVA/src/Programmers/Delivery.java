import java.util.*;
class Delivery {
    public int solution(int N, int[][] road, int K) {
        int answer = 0;

        int len =  road.length;
        int [][] map = new int[N][N];
        for (int i = 0; i < map.length; i++) {
            for (int j = 0; j < map[0].length; j++) {
                if (i == j) {                                               
                    map[i][j] = 0;
                } else 
                map[i][j] = 500001;                                           
            }
        }

        for(int i = 0; i < len; i++) {
            int x = road[i][0] -1;
            int y = road[i][1] -1;
            int cnt = road[i][2];
            
            if(cnt < map[x][y]) {
                map[x][y] = map[y][x] = cnt;
            }
        } 
 
        
         for (int k = 0; k < N; k++) {                                         
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if(i == j) continue;
                    if (map[i][j] > map[i][k] + map[k][j]) {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }
        for(int i = 0; i < map[0].length; i++) {
            if(map[0][i] <= K) {
                answer ++;
            }
        }
        return answer;
    }
}

