import java.util. *;
class Frends4Block {
    public int checkValidation(int m, int n, int[][] visit, String[][] arr) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visit[i][j] == 1) {
                    arr[i][j] = " ";
                    visit[i][j] = 0;
                    count++;
                }
            }

        }
        return count;
    }

    public int solution(int m, int n, String[] board) {
        int[][] visit = new int[m][n];
        String[][] arr = new String[m][n];
        int answer = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = Character.toString(board[i].charAt(j));
            }
        }
        int cnt = 0;
        for (;;) {
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    String temp = arr[i][j];
                    if (temp != " " && (j + 1 < n) && (i + 1 < m) && temp.equals(arr[i][j + 1]) && temp.equals(arr[i + 1][j]) && temp.equals(arr[i + 1][j + 1])) {
                        visit[i][j] = 1;
                        visit[i][j + 1] = 1;
                        visit[i + 1][j] = 1;
                        visit[i + 1][j + 1] = 1;
                    }
                }
            }

            int ans = checkValidation(m, n, visit, arr);
            answer = answer + ans;
            if (ans == 0) 
                break;
            
            for (int c = 0; c < n; c++) {
                for (int r = m - 1; r >= 0; r--) {
                    if (arr[r][c] == " ") {
                        for (int nr = r - 1; nr >= 0; --nr) {
                            if (arr[nr][c] != " ") {
                                arr[r][c] = arr[nr][c];
                                arr[nr][c] = " ";
                                break;
                            }
                        }
                    }
                }
            }

        }

        return answer;
    }

}
