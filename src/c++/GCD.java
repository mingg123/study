import java.util.Scanner;

public class GCD {
	public static void main(String args[])
	{
		Scanner input= new Scanner(System.in);
		int maxnum, minnum, a, b;
		int answer=0;
		System.out.print("���� �ΰ��� �Է��ϼ���: ");
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
		// �� �� ��� ū���� maxnum, �������� minnum�̶� �Ѵ�.
		while(minnum!=0) //minnum�� 0�̸� ������� maxnum�� ����
		{
			answer=maxnum%minnum;
			maxnum=minnum;
			minnum=answer;
		}
		System.out.print(maxnum);
		
	}
}
