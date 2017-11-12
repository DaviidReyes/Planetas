#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void ExtremosFijos(void);
void ExtremoLibre(void);
double** Tambor();

void main()
{
	ExtremosFijos();
	ExtremoLibre();
	Tambor();
	return 0;	
}

void ExtremosFijos(void)
{
	int n=129;
	float *x=malloc(n*sizeof(float));
	float *y=malloc(n*sizeof(float));    
	float dx=0.0050;
    	float dt = 0.00001;
	float c=250;
    	float *up=malloc(n*sizeof(float));	
	float *up1=malloc(n*sizeof(float));	
	float *um1=malloc(n*sizeof(float));
	float r= c*dt/dx;
	float t = 1000000;	
	FILE *fp1= fopen("cond_ini_cuerda.dat", "r");
	int i;
	int j;  
	for(i=0;i<n;i++)                                   
        {
	        fscanf(fp1, "%f %f\n", &x[i],&y[i] );            
	                
        }
    	fclose(fp1);

 	FILE* myfile=fopen("archivo1.txt","w");
	FILE* myfile1=fopen("archivo3.txt","w");
	// Condiciones iniciales
	for(i=1;i<(n-1);i++){
	um1[i]=y[i];
	up[i]=y[i]+(r*r/2)*(y[i+1]-2*y[i]+y[i-1]);
	}
	
	for(j=1;j<t;j++)
		{
		for(i=1;i<(n-1);i++)
		{
			up1[i]=2*(1-r*r)*up[i]-um1[i]+r*r*(up[i+1]+up[i-1]);
		}	

		for(i=1;i<(n-1);i++)
		{
			um1[i]=up[i];
			up[i]=up1[i];
		}				
	//}

	// FILE* myfile=fopen("archivo1.txt","w");
		if(j == 2 |j == (t/2) | j == (t/4) | j == (t/8)| j == (t-1))
		{
	         	for (i=0; i<n; i++)
			{
				//fprintf("%f ", up[i]);
				
				
				fprintf(myfile, "%f ", up[i]);
				//printf("u[%d][%d] = %f\n", i,j, up[i][j]);
		        }
			fprintf(myfile, "\n");
		}
		
		
		  
		if( j%100==0)
{
		fprintf(myfile1, "%f ", up[n/2]);
}				
		
	}

}
void ExtremoLibre(void)
{
	int n=129;
	float *x=malloc(n*sizeof(float));
	float *y=malloc(n*sizeof(float));    
	float dx=0.00500;
    	float dt = 0.00001;
	float L = 0.64;
	float c=250;
	float pi=3.1416;
    	float *up=malloc(n*sizeof(float));	
	float *up1=malloc(n*sizeof(float));	
	float *um1=malloc(n*sizeof(float));
	float r= c*dt/dx;
	float t = 100000;	
	FILE *fp1= fopen("cond_ini_cuerda.dat", "r");
	int i;
	int j;  
	for(i=0;i<n;i++)                                   
        {
	        fscanf(fp1, "%f %f\n", &x[i],&y[i] );            
	                
        }
    	fclose(fp1);

 	FILE* myfile=fopen("archivo2.txt","w");
	for(i=1;i<(n-1);i++){
	um1[i]=y[i];
	up[i]=y[i]+(r*r/2)*(y[i+1]-2*y[i]+y[i-1]);
	}
	
	for(j=1;j<t;j++)
		{
		for(i=1;i<(n-1);i++)
		{
			up1[i]=2*(1-r*r)*up[i]-um1[i]+r*r*(up[i+1]+up[i-1]);
			
			
		}	
			up1[n-1]=sin((2*pi*c/L)*j*dt);
		for(i=1;i<(n);i++)
		{
			um1[i]=up[i];
			up[i]=up1[i];
		
		}
						
	
	// FILE* myfile=fopen("archivo1.txt","w");
		if(j == 2 |j == (t/2) | j == (t/4) | j == (t/8)| j == (t-1))
		{
	         	for (i=0; i<n; i++)
			{
				//fprintf("%f ", up[i]);
				
				
				fprintf(myfile, "%f ", up[i]);
				//printf("u[%d][%d] = %f\n", i,j, up[i][j]);
		        }
			fprintf(myfile, "\n");
		}
	}

}

double** Tambor()
{	float dx=0.00500;
	float dy=0.00500;
    	float dt = 0.00001;
	float c=250;
	float rx=c*dt/dx;
	float ry=c*dt/dy;
	float t = 100000;

	//Cargar la matriz inicial
    FILE *fp;
    int n=101;
    fp = fopen("cond_ini_tambor.dat","r");
    int i,j,k;
    /*reopen the file to reset the pointer*/
    fclose(fp);
    fp = fopen("cond_ini_tambor.dat","r");
    double inicial[n][n];

    /*Load file into array*/
   
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf( fp, "%lf", &(inicial[i][j]));
        }
        fscanf(fp, "\n", NULL);
    }
FILE* myfile4=fopen("archivo4.txt","w");
double ** past=malloc(n*sizeof(double*));
	for(i=0;i<=n;i++)
{ 
	past[i]=malloc(n*sizeof(double));
}
double ** present=malloc(n*sizeof(double*));
	for(i=0;i<=n;i++)
{ 
	present[i]=malloc(n*sizeof(double));
}
double ** future=malloc(n*sizeof(double*));
	for(i=0;i<=n;i++)
{ 
	future[i]=malloc(n*sizeof(double));
}
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           past[i][j]=present[i][j]=inicial[i][j];
		//printf("%lf ",inicial[i][j]);	 
        }
        
    }

for(k=1;k<t;k++)
{
	for(i=1;i<(n-1);i++)
    {
        	for(j=1;j<(n-1);j++)
        	{
           	future[i][j]=pow(rx,2)*(present[i+1][j]-2*present[i][j]+present[i-1][j])+pow(ry,2)*(present[i][j+1]-2*present  [i][j]+present[i][j-1])+2*present[i][j]-past[i][j];
        	}
        
    }

	for(i=1;i<(n-1);i++)
    {
        	for(j=1;j<(n-1);j++)
        	{
           	past[i][j]=present[i][j];
		present[i][j]=future[i][j];
        	}
        
    }

	if(k == 2 |k == (t/2) | k == (t/4) | k == (t/8)| k == (t-1))
		{
	         	for (i=0; i<n; i++)
			{
			for(j=0;j<n;j++)
				{
				
					fprintf(myfile4, "%f ", present[i][j]);
				
		        	}
			
		fprintf(myfile4, "\n");	
			}
		}	

	}


}
