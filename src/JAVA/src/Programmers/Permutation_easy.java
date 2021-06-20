public class Permutation_easy {
    static void print(int [] result, int length) {
        for(int i = 0 ; i< length; i++) {
            System.out.print(result[i] + " ");
        }
        System.out.println(" ");
    }
    
    static void perm(int[] arr, int[] output, boolean[] visitied, int depth, int r, int n) {
        if(depth == r) {
            print(output, r);
            return;
        }
        for(int i = 0; i<n; i++) {
            if(visitied [i] != true) {
                visitied[i] = true;
                output[depth] = arr[i];
                perm(arr, output, visitied, depth+1, n, r);
                visitied[i] = false;
            }
        }
    }
  
     public static void main(String[] args) {
        int arr[] = {1,2,3};
        int result[] = new int [100];
        boolean visitied[] = new boolean[100];

        perm(arr, result, visitied, 0, 3, 3);
    }
}
