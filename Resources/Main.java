import java.util.*;
import java.io.*;
import java.math.*;
import java.text.*;
public class Main
{
	static FastScanner in = new FastScanner(System.in);
	static StringBuilder sb = new StringBuilder();
	public static void main(String[] args)
	{
		// Never sort array of primitive type
		System.out.print(sb.toString());
	}
	static BigInteger b(long n) { return BigInteger.valueOf(n);}
	static BigInteger b(String s) { return new BigInteger(s); }
}
class FastScanner
{
	BufferedReader reader;
	StringTokenizer tokenizer;
	FastScanner (InputStream inputStream)
	{
		reader = new BufferedReader(new InputStreamReader(inputStream));
	}
	String nextToken()
	{
		while (tokenizer == null || ! tokenizer.hasMoreTokens())
		{
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (Exception e){}
		}
		return tokenizer.nextToken();
	}
	boolean hasNext()
	{
		if (tokenizer == null || ! tokenizer.hasMoreTokens())
		{
			try {
				tokenizer = new StringTokenizer(reader.readLine());
			} catch (Exception e){ return false; }
		}
		return true;
	}
	int nextInt()
	{
		return Integer.parseInt(nextToken());
	}
}
