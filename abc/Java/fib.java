import java.util.Scanner;

class Fibonacci{
	public static void main(String[] args){
	Scanner scan = new Scanner(System.in);
	int first=0, second=1,n,third=0;
	System.out.println("Enter the number to print fibonacci:");
	n = scan.nextInt();	
	System.out.print("Fibonacci series is:");
	System.out.print(first + " "+ second);
	int i=0;
	while(i<n-2){
		third = first+second;
		System.out.print(" "+third);
		first = second;
		second = third;
		i++;	
	}	

	}
}
