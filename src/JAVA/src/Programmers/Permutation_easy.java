public class Permutation_easy {

    static  int arr[] = {1,2,3};
    static int result[] = new int [100];
    static boolean visitied[] = new boolean[100];

    static void print(int [] result, int length) {
        for(int i = 0 ; i< length; i++) {
            System.out.print(result[i] + " ");
        }
        System.out.println(" ");
    }

    // static void perm(int[] arr, int[] output, boolean[] visitied, int depth, int r, int n) {
    static void perm( int depth, int r, int n) {
        if(r == depth) {
            print(result, r);
        } 

        for(int i = 0; i<n; i++) {
            if(!visitied[i]) {
                visitied[i] = true;
                result[depth] = arr[i];
                perm( depth+1, r, n);
                visitied[i] = false;
            }
        }
        
    
    }
  
     public static void main(String[] args) {
        // int arr[] = {1,2,3};
        // int result[] = new int [100];
        // boolean visitied[] = new boolean[100];

        // perm(arr, result, visitied, 0, 3, 3);
        perm(0,3,3);
    }
}
