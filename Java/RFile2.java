//File Handling
//Program to read a file using byte stream classes.
import java.io.*;
class RFile2

{
	public static void main(String[]args)throws Exception
	{
		FileInputStream fis=new FileInputStream("message.dat");
		int no=0;
		while(true)
		{
			no=fis.read();
			if(no==-1)
				break;
			System.out.print((char)no);
		}
		fis.close();
	}
}