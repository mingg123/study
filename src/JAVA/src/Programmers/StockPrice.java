class StockPrice {
  public static int[] Solution(int[] prices) {
    int answer [] = new int[prices.length];
    for(int i = 0 ; i< prices.length-1; i++) {
    	int target = prices[i];
    	int count = 0;
    	for(int j = i+1; j< prices.length; j++) {
    		if(target <= prices[j]) {
    			count++;
    		} else {
    			count++;
    			break;
    		}
    	}
    	answer[i] = count;
    
    }
    answer[prices.length -1] = 0;
    return answer;
  }

  public static void main(String[] args) {
	  int prices [] = {1,2,4,1,2};
    int n [] = Solution(prices);
    for(int i = 0; i< n.length; i++)
    System.out.println(n[i]);
  }

}