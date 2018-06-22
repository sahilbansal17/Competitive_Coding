import java.util.Scanner;
import java.math.BigInteger;
import java.util.ArrayList;


public class Main {
	public static void main(String[] args) {
		
		ArrayList<BigInteger> seq_list = new ArrayList<BigInteger>();
		BigInteger end, seq_num, product, maxResult;
		
		end = new BigInteger("-999999");		// used to find the sequence end
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){ 			        //Scanning till file is ended
			seq_num = sc.nextBigInteger();

			if(seq_num.compareTo(end)!=0){     //Checking if the number is not equal to the sequence end number
				seq_list.add(seq_num);		   //If not adding it to the sequence list
			}
			else{
				maxResult = seq_list.get(0);   //Initializing the maxResult with first element of the sequence
				
				for(int i = 0; i < seq_list.size(); i++){
					product = BigInteger.ONE;  //Initializing product as one
					
					for(int j = i; j < seq_list.size(); j++){      //Looping through all possible sub sequences
						product = product.multiply(seq_list.get(j));
						maxResult = maxResult.max(product);        //If there product is maximum then assigning it to maxResult
					}
				}
				System.out.println(maxResult); //Printing the result
				seq_list.clear();              //Clearing the sequence list so that it doesn't append to the new sequence 
			}
		}
	}
}