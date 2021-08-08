import java.util.*;
class ShortestDistinct {
    int [] dx = {0,0,1,-1};
    int [] dy = {1,-1,0,0};
    int [][]visit;
    int n, m;
    class Node{
        int x;
        int y;
        int count;
        public Node(int x, int y, int count) {
            this.x = x;
            this.y = y;
            this.count = count;
        }
    }
    public int bfs(int x, int y, int[][]maps) {
        Queue<Node> q = new LinkedList<>();
        q.offer(new Node(x,y,1));
        visit[x][y] = 1;
        while(!q.isEmpty()) {
            Node node = q.poll();
            if(node.x == n-1 && node.y == m-1) return node.count;
            for(int i = 0; i < 4; i++) {
                int nx = node.x + dx[i];
                int ny = node.y + dy[i];
                if(nx >= 0 && ny >= 0 && nx < n && ny < m && maps[nx][ny] == 1 && visit[nx][ny]==0) {
                    visit[nx][ny] = 1;
                    q.offer(new Node(nx, ny, node.count + 1));
                }
            }
        }
        return -1;
    }
    public int solution(int[][] maps) {
        int answer = 0;
        n = maps.length;
        m = maps[0].length;
        visit = new int[n][m];
        return bfs(0,0,maps);
    }
}
