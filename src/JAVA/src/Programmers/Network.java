public class Network {
    static int [] visited = new int[201];

    public static void DFS(int startx, int n, int [][]computers) {
        visited[startx] = 1;
        for(int i = 0 ; i < n; i++ ) {
            if(visited[i] == 0 && computers[startx][i] == 1) {
                DFS(i, n, computers);
            }
        }
    }
    public static int solution(int n, int[][] computers) {
        int answer = 0;
        for(int i = 0; i<n; i++) {
                //computers[i][j] 는 항상 1이기 떄문에 0부터 시작해도 된다.
                if(visited[i]== 0) {
                    DFS(i,n, computers);
                    answer ++;
                }           
        }
        return answer;
    }

    public static void main(String[] args) {
        int [][] test = {{1,1,0}, {1,1,1}, {0,0,1}};
        int ans = solution(3, test);
    }
}
