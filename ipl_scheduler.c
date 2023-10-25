#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Date Structure
struct ddt_str
{
	int day;
	int month;
	int year;
	char days[10];
	char _time[10];
}*ddt_arr;

//To Proceed After The Input Date
int next_date(int d,int m,int y)
{
	int nd,nm,ny;
    
    if (m%2!=0 && m>=1 && m<=7 && d==31)
    {
        nd=1;
        nm=m+1;
        ny=y;
    }
    
    else if (m%2==0 && m>=8 && m<=10 && d==31)
    {
        nd=1;
        nm=m+1;
        ny=y;
    }
    
    else if (m%2==0 && m>=4 && m<=6 && d==30)
    {
        nd=1;
        nm=m+1;
        ny=y;
    }
    
    else if (m%2!=0 && m>=9 && m<=11 && d==30)
    {
        nd=1;
        nm=m+1;
        ny=y;
    }
    
    else if (m==2 && (d==29 || d==28))
    {
    	if (y%4==0 && d == 28)
    	{
    		if (y%100==0)
    		{
    		    nd=1;
		        nm=m+1;
		        ny=y;
    			
			}
			
			else
			{
				nd=d+1;
		        nm=m;
		        ny=y;
			}
		}
		
		else
		{
			nd=1;
        	nm=m+1;
        	ny=y;
		}
    }
    
    else if (m==12 && d==31)
    {
        nd=1;
        nm=1;
        ny=y+1;
    }
    
    else
    {
        nd=d+1;
        nm=m;
        ny=y;
    }
    
    int ndate = (nd*1000000)+(nm*10000)+(ny);
    return ndate;
}

//To Calculate Which Date Index
int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return( y + (int)(y/4)- (int)(y/100)+ (int)(y/400)+ t[m-1] + d) % 7;
}

//To Process The Given Date
void get_Data(struct ddt_str *c,int n,int date)
{
	int d,m,y,di,i;
	i = 0;
	while(i<n*(n-1))
	{
	    y = date % 10000;
		date = date/10000;
		m = date%100;
		date = date/100;
		d = date;
		di = dayofweek(d,m,y);
	    
	    switch(di)
	    {
        case 1: 
            strcpy((c+i)->days,"Monday");
            strcpy((c+i)->_time,"7:30 PM");
            (c + i)->day = d;
    	    (c + i)->month = m;
    	    (c + i)->year= y;
            break;
        
        case 2: 
            strcpy((c+i)->days,"Tuesday");
            strcpy((c+i)->_time,"7:30 PM");
            (c + i)->day = d;
    	    (c + i)->month = m;
    	    (c + i)->year= y;
            break;
        
        case 3: 
            strcpy((c+i)->days,"Wednesday");
            strcpy((c+i)->_time,"7:30 PM");
            (c + i)->day = d;
    	    (c + i)->month = m;
    	    (c + i)->year= y;
            break;
        
        case 4: 
            strcpy((c+i)->days,"Thursday");
            strcpy((c+i)->_time,"7:30 PM");
            (c + i)->day = d;
    	    (c + i)->month = m;
    	    (c + i)->year= y;
            break;
        
        case 5: 
            strcpy((c+i)->days,"Friday");
            strcpy((c+i)->_time,"7:30 PM");
            (c + i)->day = d;
    	    (c + i)->month = m;
    	    (c + i)->year= y;
            break;
        
        case 6: 
            strcpy((c+i)->days,"Saturday");
            strcpy((c+i)->_time,"3:30 PM");
            (c + i)->day = d;
    	    (c + i)->month = m;
    	    (c + i)->year= y;
    	    ++i;
    	    if (i != n*(n-1)){
	            strcpy((c+i)->days,"Saturday");
	            strcpy((c+i)->_time,"7:30 PM");
	            (c + i)->day = d;
	    	    (c + i)->month = m;
	    	    (c + i)->year= y;
    		}
            break;
        
        case 0: 
            strcpy((c+i)->days,"Sunday");
            strcpy((c+i)->_time,"3:30 PM");
            (c + i)->day = d;
    	    (c + i)->month = m;
    	    (c + i)->year= y;
    	    ++i;
    	    
    	    if (i != n*(n-1))
    	    {
	            strcpy((c+i)->days,"Sunday");
	            strcpy((c+i)->_time,"7:30 PM");
	            (c + i)->day = d;
	    	    (c + i)->month = m;
	    	    (c + i)->year= y;
    		}	
            break;
    	}
	    
	    date = next_date(d,m,y);
	    ++i;
	}
}

//Circular Shifting Of Batches
void circular_shift(int n,char arr[][100],char w_arr[][100])
{
    int i,j;
    
    for(i=0;i<100;i++)
    {
        w_arr[0][i] = arr[0][i];
    }
    
    for(i=0;i<100;i++)
    {
        w_arr[1][i] = arr[n-1][i];
    }
    
    for (i=2;i<n;i++)
    {
        for(j=0;j<100;j++)
        {
            w_arr[i][j] = arr[i-1][j];  
        }
    }
}

//Creating The Fixture
int create_fixture(int n,char l[][100],int b,int f,struct ddt_str *c)
{
    int i;
    for (i=0;i<n/2;i++)
    {
        if (b<n-1)
        {
            printf("Match No : %d | %s v/s %s | Venue : Home Stadium Of %s | Date : %d/%d/%d | Day : %s | Time : %s\n",f+1,(l+i),(l+n-i-1),*(l+i),(ddt_arr + f)->day,(ddt_arr + f)->month,(ddt_arr + f)->year,(ddt_arr + f)->days,(ddt_arr+f)->_time);
        }
        
        else
        {
            printf("Match No : %d | %s v/s %s | Venue : Home Stadium Of %s | Date : %d/%d/%d | Day : %s | Time : %s\n",f+1,(l+i),(l+n-i-1),*(l+n-i-1),(ddt_arr + f)->day,(ddt_arr + f)->month,(ddt_arr + f)->year,(ddt_arr + f)->days,(ddt_arr+f)->_time);
        }
        f = f+1;
    }
    return f;
}

//Main Function
int main()
{
    //Topic Name
    printf("\n\n------------------------------------------------------------------------------------\n\n");
    printf("TOPIC");
    printf("\n-----");
    printf("\nIPL SCHEDULAR");
    printf("\n\n------------------------------------------------------------------------------------\n");
    
    //Group Members Info
    printf("\nGROUP MEMBERS");
    printf("\n----- -------");
    printf("\nDeeban Kumar M - CB.EN.U4CSE21613");
    printf("\nNeranjan M  - CB.EN.U4CSE21642");
    printf("\nNila Sangamitra Arul - CB.EN.U4CSE21643");
    printf("\nNithish Reddy C  - CB.EN.U4CSE21644");
    printf("\nPanchumarthi Mohithi - CB.EN.U4CSE21645\n");
    printf("\n------------------------------------------------------------------------------------\n");
    
    //Main Code
    printf("\nOUTPUT");
    printf("\n------");
    int n, fixture_count, batch_num, i,j,date;
    printf ("\nEnter Even Number Of Teams : ");
    scanf ("%d",&n);
    char (*start_arr)[100] = calloc(n, sizeof *start_arr);  
    char (*new_arr)[100] = calloc(n, sizeof *new_arr);
    ddt_arr = (struct ddt_str *)malloc(sizeof(struct ddt_str));
    printf("Enter The Starting Date Of The Tournament (Enter As DDMMYYYY) : ");
	scanf("%d",&date);
    get_Data(ddt_arr,n,date);
    char op1[4],op2[4];
    printf("Enter 'yes' If You Want To Enter Team Names"); 
    printf("\n\t\t\t(or)"); 
    printf("\nEnter 'no' If You Want Default Team Names : ");
    scanf("%s",op1);
    printf("\n\n------------------------------------------------------------------------------------\n");
    
    if (strcmp(op1,"yes") == 0)
    {
        for (i = 0; i < n; i++)
        {
            printf("Enter Team %d Name : ",i+1);
            scanf(" %[^\n]s",start_arr[i]);
        }
    }
    
    else 
    {
        for(i = 0; i < n; i++)
        {
            start_arr[i][0] = 'T';
            start_arr[i][1] = 'e';
            start_arr[i][2] = 'a';
            start_arr[i][3] = 'm';
            start_arr[i][4] = ' ';
            start_arr[i][5] = (char)(i+65);
        }
    }
    
    do
    {
        fixture_count = 0;
        batch_num = 0;
        printf("\nSCHEDULE");
        printf("\n--------\n");
        fixture_count = create_fixture(n,start_arr,batch_num,fixture_count,ddt_arr);
        for (batch_num=1;batch_num<2*(n-1);batch_num++)
        {
            circular_shift(n,start_arr,new_arr);
            for (i=0;i<n;i++)
            {
                for(j=0;j<100;j++)
                {
                    start_arr[i][j] = new_arr[i][j];
                }
            }
            fixture_count = create_fixture(n,new_arr,batch_num,fixture_count,ddt_arr);
        }
       
        if(strcmp(op1,"yes")==0)
        {
            printf("\nEnter 'yes' To Create A New Schedule");
            printf("\n\t\t\t(or)");
            printf("Enter 'no' To End The Program : ");
            scanf("%s",op2);
        }
        
        else
        {
            strcpy(op2,"no");
        }
    }while(strcmp(op2,"yes")==0);
    
    return 0;
}