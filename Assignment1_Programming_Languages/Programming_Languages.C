#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//#include<conio.h>

char *language,variables[20][20],functions[50][50];
int varCount=0,funCount=0;
char file_name[15];
int isvalidLine(char line[])
{
	int i;

	for(i=0;line[i]!='\0';i++)
	{
		while(isspace(line[i])&&line[i]!='\0'&&line[i]!='\n')
		{
			i++;
		}
		if('/'!=line[i]&&'\n'!=line[i]&&'\0'!=line[0])
		{
			return 1;
		}
	}
	return 0;
}


char* checkForPHP(char line[])
{
	int i,k=0;
	char word[100];

       for(i=0;line[i]!='\0';i++)
	{
		if(isspace(line[i]))
		{
			word[k]='\0';
			k=0;
		   
			if(!strcmp(word,"<?php"))
			{
			    return "PHP";
			}
			continue;
		}
		else
		{
			word[k++]=line[i];

		}
	}
	return " ";
}
char* checkFile(char line[])
{
	int i,k=0;
	char word[100];

       for(i=0;line[i]!='\0';i++)
	{
		if(isspace(line[i]))
		{
			word[k]='\0';
			k=0;
		     
			if(!strcmp(word,"class"))
			{

			      while(isspace(line[i++]));
			      while(!isspace(line[i++])&&line[i]!='{');
			      while(isspace(line[i++]));
			      i--;
			      if(line[i]=='{')
			      {
				 return "JAVA";
			      }
			      else
			      {
				return "RUBY";
			      }


			}
			continue;
		}
		else
		{

			word[k++]=line[i];

		}
	}
	return " ";

}

void findClasses(char line[])
{
	int i,k=0;
	char word[100];


       for(i=0;line[i]!='\0';i++)
	{
		if(isspace(line[i]))
		{
			word[k]='\0';
			k=0;

		      
			if(!strcmp(word,"class"))
			{

			      while(isspace(line[i++]));
			      i--;
			      do
			      {
				  printf("%c",line[i]);
			      }while(!isspace(line[i++])&&line[i]!='{');
			      break;
			      printf(",");

			}
			continue;
		}
		else
		{

			word[k++]=line[i];

		}
	}


}

int isDataType(char str[])
{
	if(!strcmp(str,"Int")||!strcmp(str,"void")||!strcmp(str,"Float")||!strcmp(str,"Char")||!strcmp(str,"Boolean")||!strcmp(str,"String")||!strcmp(str,"Byte")||!strcmp(str,"Short")||!strcmp(str,"Long")||!strcmp(str,"Double"))
	{
		return 1;
	}
	return 0;
}


void findJAVAVariables(char line[])
{
	int i,k=0;
	char word[100];
	char preStr[100];


       for(i=0;line[i]!='\0';i++)
	{
		if(isspace(line[i])||line[i]==';'||line[i]=='[')
		{
			word[k]='\0';
			k=0;
			if(line[i]==';'||line[i+1]==';')
			{
			     
				//getch();
				if(!isExist(variables,varCount,word)&&isDataType(preStr))
				{
				
					strcpy(variables[varCount++],word);
				}
			}
		      
			strcpy(preStr,word);
			continue;
		}
		else
		{

			word[k++]=line[i];

		}
	}


}

int isKey(char str[])
{
	int i=0;
	if(strcmp(str,"if")==0||strcmp(str,"for")==0||strcmp(str,"while")==0)
	{

		return 1;
	}
	for(i=0;str[i]!='\0';i++)
		{
			if(!(isalnum(str[i])||str[i]=='_'))
			{
				return 1;
			}

		}
	return 0;
}


void findJAVAFunctions(char line[])
{
	int i,k=0;
	char word[100];
	char preStr[100];

       for(i=0;line[i]!='\0';i++)
	{
		if(isspace(line[i])||line[i]=='(')
		{
			word[k]='\0';
			k=0;
			if(line[i]=='('||line[i+1]=='('&&!isKey(word))
			{
			      
			       if(!isExist(functions,funCount,word)&&isDataType(preStr)&&strcmp("main",word))
				{
					strcpy(functions[funCount++],word);
				}

			}
		      
			strcpy(preStr,word);
			continue;
		}
		else
		{

			word[k++]=line[i];

		}
	}


}

void findPHPFunctions(char line[])
{
	int i,k=0,flag=1;
	char word[100];


       for(i=0;line[i]!='\0';i++)
	{
		if(isspace(line[i])||line[i]=='(')
		{
			word[k]='\0';
			k=0;



			if(!flag)
			{
			      
			       if(!isExist(functions,funCount,word))
				{
					strcpy(functions[funCount++],word);
				}
			       flag=1;
			}
		       

		       if(!strcmp(word,"function"))
			{
				flag=0;
			}
			continue;
		}
		else
		{

			word[k++]=line[i];

		}
	}


}

void findRUBYFunctions(char line[])
{
	int i,k=0,flag=1;
	char word[100];


       for(i=0;line[i]!='\0';i++)
	{
		if(isspace(line[i])||line[i]=='(')
		{
			word[k]='\0';
			k=0;



			if(!flag)
			{
			       
			       if(!isExist(functions,funCount,word))
				{
					strcpy(functions[funCount++],word);
				}
			       flag=1;
			}
		      

		       if(!strcmp(word,"def"))
			{
				flag=0;
			}
			continue;
		}
		else
		{

			word[k++]=line[i];

		}
	}


}


int isExist(char var[20][20],int cnt,char nVar[])
{
	int i;
   
	for(i=0;i<cnt;i++)
	{
	      
		if(!strcmp(var[i],nVar))
		{
		      
			return 1;
		}
	}
	return 0;
}


void findPHPVariables(char line[])
{
	int i,k=0,j=0;
	char word[100];


       for(i=0;line[i]!='\0';i++)
	{
		if(isspace(line[i])||line[i]=='-'||line[i]==';')
		{
			word[k]='\0';
			k=0;

		      
		       if(!strcmp(word,"$this"))
		       {
				continue;
		       }
		       if(word[0]=='$')
		       {
			
			   if(!isExist(variables,varCount,word))
			   {
				strcpy(variables[varCount++],word);
			   }
		       }
		      
			continue;
		}
		else
		{

			word[k++]=line[i];

		}
	}



}

void findRUBYVariables(char line[])
{
	int i,k=0,j=0;
	char word[100];


       for(i=0;line[i]!='\0';i++)
	{
		if(isspace(line[i]))
		{
			word[k]='\0';
			k=0;

		     
		       if(word[0]=='@')
		       {
			  
			   if(!isExist(variables,varCount,word))
			   {
				strcpy(variables[varCount++],word);
			   }
		       }
		      
			continue;
		}
		else
		{

			word[k++]=line[i];

		}
	}



}



void parsePHP()
{
	char *str;
	

	char ch,line[100],ln[200];
	
	int i=0,k;
	FILE *fp;
	fp = fopen(file_name, "r");
	while(1)
	{
		str=fgets(ln,100,fp);
		if(!strcmp(str,NULL))
		{
			break;
		}

		if(isvalidLine(str))
		{
		  

			findClasses(str);
			findPHPVariables(str);
			findPHPFunctions(str);
		}

	    


	}

}
void parseJAVA()
{
	char *str;
	

	char ch,line[100],ln[200];
	
	int i=0,k;
	FILE *fp;
	fp = fopen(file_name, "r");
	while(1)
	{
		str=fgets(ln,100,fp);
		if(!strcmp(str,NULL))
		{
			break;
		}

		if(isvalidLine(str))
		{
		   

			findClasses(str);
			findJAVAVariables(str);
			findJAVAFunctions(str);
		}

	    


	}

}


void parseRUBY()
{
	char *str;
	

	char ch,line[100],ln[200];
	
	int i=0,k;
	FILE *fp;
	fp = fopen(file_name, "r");
	while(1)
	{
		str=fgets(ln,100,fp);
		if(!strcmp(str,NULL))
		{
			break;
		}

		if(isvalidLine(str))
		{
		  

			findClasses(str);
			findRUBYVariables(str);
			findRUBYFunctions(str);
		}

	    


	}

}



int main()
{

	char *str;
	

	char ch,line[100],ln[200];
	
	int i=0,k,l=0;
	FILE *fp;
	printf("Enter the filename to be opened \n");
	scanf("%s", file_name);
	fp = fopen(file_name, "r");
	if (fp == NULL)
	{
		printf("file is not present \n");
		getch();
		exit(0);
	}
	while(!feof(fp))
	{
		str=fgets(ln,100,fp);
		if(!strcmp(str,NULL))
		{
			break;
		}

		if(isvalidLine(str))
		{
		  
			language=checkForPHP(str);

			if(!strcmp(language,"PHP"))
			{
				printf("\ language :  PHP");
				printf("\nClasses : ");
				parsePHP();
				printf("\nVariables %d: ",varCount);
				for(l=0;l<varCount;l++)
				{
					printf("%s, ",variables[l]);
				}
				printf("\nFunction : ");
				for(l=0;l<funCount;l++)
				{
					printf("%s, ",functions[l]);
				}

//				getch();
				return 0;
			}
		}

	    


		fclose(fp);


	}

	fp = fopen(file_name, "r");

	while(1)
	{
		str=fgets(ln,100,fp);
	      
		if(!strcmp(str,NULL))
		{
			break;
		}
	      

		     
		if(isvalidLine(str))
		{

//			getch();
			language=checkFile(str);
		    
			if(strcmp(language," "))
			{
				printf("Language : %s",language);
				printf("\nClasses : ");
				if(!strcmp(language,"JAVA"))
				{
					parseJAVA();
					printf("\nVariables : ");
					for(l=0;l<varCount;l++)
					{
						printf("%s, ",variables[l]);
					}
					printf("\nFunction : ");
					for(l=0;l<funCount;l++)
					{
						printf("%s, ",functions[l]);
					}

				}
				else
				{
					parseRUBY();
					printf("\nVariables : ");
					for(l=0;l<varCount;l++)
					{
						printf("%s, ",variables[l]);
					}
					printf("\nFunction : ");
					for(l=0;l<funCount;l++)
					{
						printf("%s, ",functions[l]);
					}
				}
				break;
			}
		}

	   
//		getch();

	}


	fclose(fp);
//	getch();
	return(0);
}


