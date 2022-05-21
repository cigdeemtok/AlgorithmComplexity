#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
 int whilekontrol=0;
  char karakter;
    int counter=0;
    int sayac=0;
    char boyut[10];
    char artis;
    int i=0;
    int icice=0;
   
void forSayaci(FILE *dosya)
{
   
    if((dosya=fopen("kod_blogu.txt","r"))!=NULL)
    {
        karakter=fgetc(dosya);
        while(karakter!=EOF)
        {

            if(karakter=='f')
            {
                karakter=fgetc(dosya);
                if(karakter=='o')
                {
                    karakter=fgetc(dosya);
                    if(karakter=='r')
                    {
                        karakter=fgetc(dosya);
                        counter++;
                        do
                        {
                            karakter=fgetc(dosya);
                            
                            //printf("%c",karakter);
                            if((karakter == '<') || (karakter == '>') || (karakter == '<=') || (karakter == '>=') || (karakter == '==') || (karakter == '!='))
                            {
                                karakter = fgetc(dosya);
                                while(karakter != ';')
                                {
                                    karakter = fgetc(dosya);
                                    boyut[i]=karakter;
                                    i++;
                                    //printf("for icerik %c\n",karakter);

                                }

                            }
                            if((karakter=='+'))
                            {
                                artis = karakter;
                            }
                            else if(karakter == '-')
                            {
                                artis = karakter;
                            }
                            else if( karakter == '*')
                            {
                                artis = karakter;
                            }
                            else if( karakter == '/')
                            {
                                artis= karakter;
                            }

                            //dosyayaYaz(karakter);


                        }
                        
                        
                        while(karakter!=')');
                        
                         karakter=fgetc(dosya);
                        while (karakter !='}'){
                        	
                        	 karakter=fgetc(dosya);
                        	 if(karakter=='f')
            				{
               					karakter=fgetc(dosya);
               					if(karakter=='o')
                				{
                    				karakter=fgetc(dosya);
                    				if(karakter=='r')
                    				{
									icice=1;
									}
									
								}
								
							}
                        	
                        	
                        	
						}
                        
                        
                        
                        
                    }
                }
            }


            karakter=fgetc(dosya);
        }
       // printf("\n%d tane for var.",counter);
        //printf("\nboyut %s",boyut);
       // printf("\nartis %c",artis);
    }
    else
    {
        printf("Dosya bulunamadý.");
    }
 
 	if(icice==1){
 		printf("\nFor karmasikligi O(n^2)dir.");
	 }
	 else{
	 	printf("\nFor karmasikligi O(n)dir.");
	 }
    fclose(dosya);
}

void whileSayaci(FILE* dosya)
{

    char karakter;
    int sayac=0;
    if((dosya=fopen("kod_blogu.txt","r"))!=NULL)
    {
        karakter=fgetc(dosya);
        while(karakter!=EOF)
        {

            if(karakter=='w')
            {
                karakter=fgetc(dosya);
                if(karakter=='h')
                {
                    karakter=fgetc(dosya);
                    if(karakter=='i')
                    {
                        karakter=fgetc(dosya);
                    }
                    if(karakter=='l')
                    {
                        karakter=fgetc(dosya);
                    }
                    if(karakter=='e')
                    {
						sayac++;
                        karakter=fgetc(dosya);
                        while(karakter!=')')
						{
                        	karakter=fgetc(dosya);
                        	if (isdigit(karakter)){
                        	whilekontrol=1;
							}
                        	
						}
                        
                        
                        
                    }
                }
            }


            karakter=fgetc(dosya);
        }
        printf("\n%d tane while var.",sayac);
    }
    else
    {
        printf("Dosya bulunamadý.");
    }

		if(whilekontrol==1){
 		printf("\nWhile karmasikligi O(1)dir.");
	 }
	 else{
	 	printf("\nWhile karmasikligi O(n)dir.");
	 }
    fclose(dosya);


}



int main(int argc, char *argv[])
{
	clock_t baslangic,bitis;
	baslangic=clock();
    FILE *dosya;
    forSayaci(dosya);
    whileSayaci(dosya);
    bitis=clock();
    printf("\nKodun calismasi icin gecen sure: %f saniyedir.",(float)(bitis-baslangic)/CLOCKS_PER_SEC);
    //FILE *dosya2;
    //whileBulma(dosya2);
    


    return 0;
}
