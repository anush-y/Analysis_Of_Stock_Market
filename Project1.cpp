#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define size 10 //no. of companies
//# define first_date 1
//# define last_date 3
//# define s_d 2
//# define e_d 3
struct sol{
		 	char name1[50];
			 };
			 struct sol b[size];

struct sensex
  {
      	  	 float Open;
       		 float High;
      		 float Low;
       		 float Cp_stock;
       		 double Volume;
   	      };
typedef struct cmp
	{
	   char name[50]; 
	   struct sensex att[30];
   		 
	}cmp;
	
	void perchange(int s_d,int e_d,  cmp cmp_name[10])   //printing percentage change for every stock 
	{
		int i,flag=0;
		float diff,per_change1;
		for(i=0;i<size;i++)
	  		{
	  			diff=cmp_name[i].att[e_d].Cp_stock-cmp_name[i].att[s_d].Open;
	  			if(diff<0)
	  			{
	  				diff=-diff;
	  				flag=0;
				 }
				  else
				  {
				  	flag=1;
				  }
	  			per_change1= (diff/cmp_name[i].att[s_d].Open)*100;
	  			if(flag==0)
	  			{
				printf("The decrease percentage in the stock price is %f of %s \n ",per_change1,cmp_name[i].name);
		     	}
		    	else
		     	{
		     	printf("The increase percentage in the stock price is %f of %s \n ",per_change1,cmp_name[i].name);
		     	}
			}
	}
	
	void sort(struct cmp cmp1_name[size], int date)
	{
		printf("Hii \n");
		 for(int i=0;i<size-1;i++)
		   {
		   printf("Hii \n");
		   		int min=i;
		   		char q[50];
		   		for(int j=i+1;j<9;j++)
		   		{
		   			if(cmp1_name[i].att[date].Volume>cmp1_name[j].att[date].Volume)
		   			{
		   				struct sensex t;
		   				t=cmp1_name[i].att[date];
		   				cmp1_name[i].att[date]=cmp1_name[j].att[date];
		   				cmp1_name[j].att[date]=t;
		   				
					
		   				
		   				strcpy(q,cmp1_name[i].name);
		   				strcpy(cmp1_name[i].name,cmp1_name[j].name);
		   				strcpy(cmp1_name[j].name,q);
		   				
					}
					else if (cmp1_name[i].att[date].Volume==cmp1_name[j].att[date].Volume)
					{
						if(cmp1_name[i].att[date].Cp_stock>cmp1_name[j].att[date].Cp_stock)
						{
							struct sensex t;
							char q[50];
							
							t=cmp1_name[i].att[date];
			   				cmp1_name[i].att[date]=cmp1_name[j].att[date];
			   				cmp1_name[j].att[date]=t;
		   					
		   					strcpy(q,cmp1_name[i].name);
		   				strcpy(cmp1_name[i].name,cmp1_name[j].name);
		   				strcpy(cmp1_name[j].name,q);
						}
					}
				}
			 }
		   printf("This is the sorted list of the stocks \n");
		   for(int i=0;i<size;i++)
		   {
		   		printf ("%s\n",cmp1_name[i].name);
		   }
	}
	void profit_loss(struct cmp cmp_name[size],char Cmp[50], int d_b, int d_s, int n)
	{
		float profit,loss;
			int i=0;
			int s=0;
		
			while(s==0)
			{
				if(strcmp (cmp_name[i].name,Cmp))
				{
					s=i;
				}
				else
				{
					i++;
				}
			}
			if(cmp_name[s].att[d_s].Cp_stock>cmp_name[s].att[d_b].Cp_stock)
			{
				profit=n*(cmp_name[s].att[d_s].Cp_stock-cmp_name[s].att[d_b].Open);
				printf("Total profit earned is %f",profit);
			}
			else
			{
				loss=n*(cmp_name[s].att[d_b].Open-cmp_name[s].att[d_s].Cp_stock);
				printf("Total losses is %f",loss);
			}
	}
	
	void high_performance(struct cmp cmp_name[size],int s_d, int e_d)
	{
		int loc;
			float max,per_change2,diff;
			for(int i=0;i<size;i++)
			{
				diff=cmp_name[i].att[e_d].Cp_stock-cmp_name[i].att[s_d].Open;
				if(diff>0)
				{
					per_change2=(diff/cmp_name[i].att[s_d].Open)*100;
					float max=0.0;
					if(per_change2>max)
					{
						max=per_change2;
						loc=i;
					}
			    }
			}
			printf("%f",max);
			printf("The highest performing stock is %s \n",cmp_name[loc].name);
	}
	
	void lowest_performing(struct cmp cmp_name[size],int s_d, int e_d)
	{
		int loc1;
			float diff,min=INT_MAX,per_change3;
			for(int i=0;i<size;i++)
			{
				diff=cmp_name[i].att[e_d].Cp_stock-cmp_name[i].att[s_d].Open;
				if(diff>0)
				{
					per_change3=(diff/cmp_name[i].att[s_d].Open)*100;
					if(per_change3<min)
					{
						min=per_change3;
						loc1=i;
					}
			    }
			}
			printf("The lowest performing stock is %s \n",cmp_name[loc1].name);
	}
	
	void avg(struct cmp cmp_name[size],int s_d, int e_d)
	{
		float avg1,sum=0,avg;
		for(int i=0;i<size;i++)
		{
			for(int j=s_d;j<=e_d;j++)
			{
				avg1=(cmp_name[i].att[j].Cp_stock+cmp_name[i].att[j].Volume)/2;
				sum=sum+avg1;
			}
			avg=avg1/((e_d)+(s_d)-1);
			printf("The average of all average values is %f for %s stock\n",avg,cmp_name[i].name);
		}
	}
	
	void per_change(struct cmp cmp_name[size], int s_d, int e_d)
	{
		float sum1=0.0,per_change,diff1;
         float a[size];
         int i;
	
		 
		 for(i=0;i<size;i++)
		 {
		 	int j=s_d;
		 	while(j<=e_d)
		 	{
		 		diff1=(cmp_name[i].att[s_d].Open-cmp_name[i].att[s_d-1].Cp_stock);
		 		if(diff1<0)
		 		{
		 			diff1=-diff1;
				 }
				per_change=(diff1/cmp_name[i].att[s_d-1].Cp_stock)*100*cmp_name[i].att[s_d].Volume;
				sum1=sum1+per_change;
				j++;
			 }
			 a[i]=sum1;
			 strcpy(b[i].name1,cmp_name[i].name);
			 
			 
		 }  
		   
		char p[50];
		for(i=1;i<size-1;i++)
		{
			 int loc=i;
			for(int j=i+1;j<size;j++)
			{
				 if(a[j]<a[loc])
				{
		
					strcpy(p,b[j].name1);
					strcpy(b[j].name1,b[loc].name1);
					strcpy(b[loc].name1,p);	
				}
			}
		}
		   for(i=0;i<size;i++)
			{
				printf("%s",b[i].name1);
			}
	}
int main()
{
	 struct cmp cmp_name[size];
	 	int i,j,days,line;
	 	float diff,per_change1;
	 	FILE* ptr;
	 	ptr=fopen("data.csv","r");
	
	printf("Give the no. of days \n");
	scanf("%d",&days);
	char n[size][50] = {"SBIN", "TATAMOTORS","PNB","YESBANK","TECHM", "INFY", "TCS", "TITAN","ONGC", "IOC"};
    

	
	
	if(ptr==NULL)
	{
		printf("ERROR \n");
	}
	int count=1;
	for(i=0;i<size;i++)
	{
	
		for(int j=1;j<=days;j++)
		{
			
			fscanf(ptr, "%f,%f, %f, %f, %lf",&cmp_name[i].att[j].Open,&cmp_name[i].att[j].High,&cmp_name[i].att[j].Low,&cmp_name[i].att[j].Cp_stock,&cmp_name[i].att[j].Volume);
			
//			printf("%d \n", i);
		}
		
	}      
	fclose(ptr);
	
	for(int i=0;i<size;i++)
	{
//		printf("%s \n",n[i]);
		strcpy(cmp_name[i].name,n[i]);
	}
	
printf("%lf \n",cmp_name[0].att[1].Cp_stock);
	int l=1;
	
	while(l==1)
	{
		int choice;
        printf("\n");
        printf("1. Percentage change in stock price :\n");
        printf("2. Sort given data :\n");
        printf("3. Profit/Loss on two days :\n");
        printf("4. Highest performing stock :\n");
        printf("5. Lowest performing stock :\n");
        printf("6. Stocks acording to increasing overall performance :\n");
        printf("7. Average value of stocks :\n");
        printf("8. Exit :\n");
        printf("\nEnter Your Choice :\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
        	case 1: 
	        	{
	        		int s_d,e_d;
				
					printf("Enter the starting day \n");
					scanf("%d",&s_d);
					printf("Enter the ending day \n");
					scanf("%d",&e_d);
					

					perchange(s_d,e_d,cmp_name);
					
					printf("Enter 1 if you want to continue else press 0\n");
					scanf("%d",&l);
					
					if(l==0)
					{
						printf("Thank you for using our program \n");
						
					}
					break;
					
				}
			
			case 2:
				{
					int date;
				   float t;
				    struct cmp cmp1_name[size];
				    for(int i=0;i<size;i++)
				    {
				    	strcpy(cmp1_name[i].name,cmp_name[i].name);
				    	for(int j=1;j<=days;j++)
				    	{
				    		cmp1_name[i].att[j].Cp_stock=cmp_name[i].att[j].Cp_stock;
				    		cmp1_name[i].att[j].High=cmp_name[i].att[j].High;
				    		cmp1_name[i].att[j].Low=cmp_name[i].att[j].Low;
				    		cmp1_name[i].att[j].Open=cmp_name[i].att[j].Open;
				    		cmp1_name[i].att[j].Volume=cmp_name[i].att[j].Volume;	
						}
					}
					printf("%f \n",cmp1_name[1].att[1].Cp_stock);
					
				  
				   printf("Give the date on which you have to sort \n");
				   scanf("%d",&date);
				   
				   sort(cmp1_name,date);
				   
				   printf("Enter 1 if you want to continue else press 0\n");
					scanf("%d",&l);
					
					if(l==0)
					{
						printf("Thank you for using our program \n");
						
					}
					break;
				}
				
			case 3:
				{
					int d_b,d_s,n,s=0;
					char Cmp[50];
					printf("Give the company name \n");
					scanf("%19s",&Cmp);
					printf("Give the date on which the stock was bought \n");
					scanf("%d",&d_b);
					printf("Give the date on which the stock was sold \n");
					scanf("%d",&d_s);
					printf("Give the no. of stocks which were sold \n");
					scanf("%d",&n);
					
					profit_loss(cmp_name,Cmp,d_b,d_s,n);
					
					printf("Enter 1 if you want to continue else press 0\n");
					scanf("%d",&l);
					
					if(l==0)
					{
						printf("Thank you for using our program \n");
						
					}
					break;
				}
				
			case 4:
				{
					int s_d,e_d;
				
					printf("Enter the starting day \n");
					scanf("%d",&s_d);
					printf("Enter the ending day \n");
					scanf("%d",&e_d);
					
					high_performance(cmp_name,s_d,e_d);
					
					printf("Enter 1 if you want to continue else press 0\n");
					scanf("%d",&l);
					
					if(l==0)
					{
						printf("Thank you for using our program \n");
						
					}
					break;
				}
				
			case 5:
				{
					int s_d,e_d;
				
					printf("Enter the starting day \n");
					scanf("%d",&s_d);
					printf("Enter the ending day \n");
					scanf("%d",&e_d);
					
					lowest_performing(cmp_name,s_d,e_d);
					
					printf("Enter 1 if you want to continue else press 0\n");
					scanf("%d",&l);
					
					if(l==0)
					{
						printf("Thank you for using our program \n");
						
					}
					break;
				}
				
			case 6:
				{
					int s_d,e_d;
				
					printf("Enter the starting day \n");
					scanf("%d",&s_d);
					printf("Enter the ending day \n");
					scanf("%d",&e_d);
					
					per_change(cmp_name,s_d,e_d);
					
					printf("Enter 1 if you want to continue else press 0\n");
					scanf("%d",&l);
					
					if(l==0)
					{
						printf("Thank you for using our program \n");
						
					}
					break;
				}
				
			case 7:
				{
					int s_d,e_d;
				
					printf("Enter the starting day \n");
					scanf("%d",&s_d);
					printf("Enter the ending day \n");
					scanf("%d",&e_d);
					
					avg(cmp_name,s_d,e_d);
					
					printf("Enter 1 if you want to continue else press 0\n");
					scanf("%d",&l);
					
					if(l==0)
					{
						printf("Thank you for using our program \n");
						
					}
					break;
				}
				
			default:
				{
					printf("Thank you for using my program \n");
					break;
				}
		}
	}
	
	return 0;		  
		   
}




