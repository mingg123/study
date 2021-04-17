import java.util.Scanner;

public class GCD {
	public static void main(String args[])
	{
		Scanner input= new Scanner(System.in);
		int maxnum, minnum, a, b;
		int answer=0;
		System.out.print("숫자 두개를 입력하세요: ");
		a=input.nextInt();
		b=input.nextInt();
		if(a>=b)
		{
			maxnum=a;
			minnum=b;
		}
		else
		{
			maxnum=b;
			minnum=a;
		}
		// 두 수 가운데 큰수를 maxnum, 작은수를 minnum이라 한다.
		while(minnum!=0) //minnum이 0이면 공약수는 maxnum과 같다
		{
			answer=maxnum%minnum;
			maxnum=minnum;
			minnum=answer;
		}
		System.out.print(maxnum);
		
	}
}
