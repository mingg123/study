import java.util.*;

class CheckDistance {
    public static Character [][] newMap;
    public static int[] idx = {0,0,-1,0};
    public static int[] idy = {-1,1,0,0};
    public int[] solution(String[][] places) {
        int len = places.length;
        int[] answer = new int[len];
        for(int i =0; i< 5; i++) {
            answer[i] = 1;
        }
        for(int i = 0; i < places.length; i++) {
            newMap = new Character[5][5];
            //메인은 여기부터 시작 
            for(int j = 0; j < 5; j++) {
                String str = places[i][j];
                for(int k = 0; k < 5; k++) {
                    newMap[j][k] = (str.charAt(k));
                }
            }
            for(int a = 0; a <5; a++){
                for(int b= 0; b<5; b++) {
                    if(newMap[a][b] == 'P') {
                        if(!bfs(newMap, a,b)) {
                            answer[i] = 0;
                        }
                    }
                }
            }
         
        }
        return answer;
    }
    public boolean bfs(Character[][] board, int x, int y) {
        Queue<Node> q = new LinkedList<>();
        boolean [][]visited = new boolean[5][5];
        q.offer(new Node(x,y));
        visited[x][y] = true;
        
        while(!q.isEmpty()) {
            Node current = q.poll();
            for(int i = 0; i<4; i++) {
                int nx = current.x + idx[i];
                int ny = current.y + idy[i];
                int manhattan = Math.abs(nx-x) + Math.abs(ny-y);
                if(nx<0 || ny <0 || nx>= board.length || ny >= board.length || visited[nx][ny] || manhattan >2|| board[nx][ny] == 'X') continue;
                visited[nx][ny] = true;
                if(board[nx][ny] == 'P') return false;
                else q.offer(new Node(nx, ny));
            }
        }
        return true;
    }
    public class Node {
        int x;
        int y;
        public Node(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}