
public class Triangle {
	
	public static void main (String[] args){
		int side1 = 7;
		int side2 = 8;
		int side3 = 9;
		
		if ((side1 + side2) > side3 && (side2 + side3) > side1 && (side1 + side3) > side2 )
		{
			System.out.println("This is a valid triangle");
		}
		else
		{
			System.out.println("This is not a valid triangle");
		}
			
		if (side1 == side2 || side1 == side3 || side2 == side3)
		{
			System.out.println("This is an isosceles triangle");
		}
		
		if (side1 == side2 && side2 == side3 && side1 == side3)
		{
			System.out.println("This is an equilateral triangle");
		}
		
		else
		{
			System.out.println("This is a scalene triangle");
		}
		
		
	}

}
