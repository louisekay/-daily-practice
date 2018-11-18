class XuanZe
{
   void sortArry(int []arry)
   {
      int i = 0,j = 0,temp = 0;
	  
      for(i = 0;i < 10;i++)
	  {
	      for(j = i+1;j < 10;j++)
		  {
		     if(arry[i] < arry[j])
			 {
			     temp = arry[i];
				 arry[i] = arry[j];
				 arry[j] = temp;
			 }
		  }
	  }
   }

}

class Charu
{
	void sortArry(int [] arry)
	{
		int i = 0,j = 0,temp = 0;
		
		for(i = 1;i < 10;i++)
		{			
			temp = arry[i];
			for(j = i;(j > 0)&&(temp > arry[j-1]);j--)
			{
				arry[j] = arry[j-1];
                arry[j-1] = temp;
			}
 
		}
	}
}

class Maopao
{
	void sortArry(int [] arry)
	{
		int i = 0,j = 0,temp = 0;
		for(i = 0;i < 9;i++)
		{
			//第一种
			/*
			for(j = 0;j <10 - 1 - i;j++)
			{
				if(arry[j] < arry[j+1])
				{
					temp = arry[j+1];
					arry[j+1] = arry[j];
					arry[j] = temp;
				}
			}
			*/
			//第二种
			for(j = 9;j > i;j--)
			{
				if(arry[j] < arry[j-1])
				{
					temp = arry[j-1];
					arry[j-1] = arry[j];
					arry[j] = temp;
				}
			}
		}
	}
}

public class Sort
{
   public static void main(String args[])
   { 
       int arry[] = {12,37,2,78,6,1,99,100,55,1};
	   	   for(int i = 0;i < 10;i++)
	   {
		   System.out.printf("%d ",arry[i]);
	   }
	   System.out.printf("\n");
	   //选择
	    XuanZe xz = new XuanZe();
	   xz.sortArry(arry);
	   for(int i = 0;i < 10;i++)
	   {
		   System.out.printf("%d ",arry[i]);
	   }
	  System.out.printf("\n"); 
	   //插入
	   Charu cr = new Charu();
	   cr.sortArry(arry);
	   for(int i = 0;i < 10;i++)
	   {
		   System.out.printf("%d ",arry[i]);
	   }
	  System.out.printf("\n");
	   //冒泡
 	   Maopao mp = new Maopao();
	   mp.sortArry(arry);
	   for(int i = 0;i < 10;i++)
	   {
		   System.out.printf("%d ",arry[i]);
	   }
	    System.out.printf("\n"); 
   }
}