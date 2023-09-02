//Inheritance
//Super class = Base class & Sub class = Derived class

import javax.swing.*;
class Number1
{
	int no;
	Number1(){no=0;}
	Number1(int a){no=a;}
	public String toString()
	{
		String s="\nNo:"+no;
		return s;
	}
	void setData(int a){no=a;}
	void display()
	{
		JOptionPane.showMessageDialog(null,toString());
	}
	void setData()
	{
		try
		{
			no=Integer.parseInt(JOptionPane.showInputDialog(null,"No:"));
		}
		catch(Exception e){}
	}
}
class Name1 extends Number1
{
	String nm;
	Name1()
	{
		super();
		nm=new String();
	}
	Name1(int a,String b)
	{
		super(a);
		nm=b;
	}
	public String toString()
	{
		String s=super.toString()+"\nName:"+nm;
		return s;
	}
	void display()
	{
		JOptionPane.showMessageDialog(null,toString());
	}
	void setData()
	{
		super.setData();
		nm=JOptionPane.showInputDialog(null,"Name:");
	}
	void setData(int a)
	{
		super.setData(a);
		nm=JOptionPane.showInputDialog(null,"Name:");
	}
}
public class Inh1
{
	public static void main(String[] args)
	{
		Number1 a=new Number1();	//Number1 a=address(i.e. referrence)	at address int value
		a.setData();
		a.display();

		Name1 b=new Name1();	//Name1 b=address(i.e. referrence)	at address int value of Number1 & string name of Name1
		b.setData();
		b.display();

		//super class can hold referrence of sub-class
		Number1 c=new Name1();	//Number1 c=address(i.e. referrence)	at address int value of Number1 & string name of Name1
		c.setData();
		c.display();
	}
}