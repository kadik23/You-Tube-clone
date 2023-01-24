#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//implementation de LLC
typedef struct ADN ADN;
struct ADN{
  unsigned char Car;
  ADN*suivant;
};

typedef  ADN *liste ;

//1- Les fonctions de bases :
//1er function
void insertionEnTete (liste *l, unsigned char nvCar)
   {
        liste p=(liste)(malloc(sizeof(liste)));
        p->Car=nvCar;
        p->suivant=*l;
        *l= p;
   }


    //2em function
void suppressionEnTete(liste *l){
    liste p=*l;
    *l=(*l)->suivant;
    free(p);
                                }

//3em function
void afficherListe(liste *l)
    {
    liste p=*l;
    printf("\n------------------affichage--------------------");
    while(p!=NULL)
    {
        printf("\n %c",p->Car);
        p=p->suivant;
    }
    }

    //4em function
void genere_adn(liste *brin, int n){

  char x[4]={'A','C','G','T'};
  int adn;
  for(int i=0;i<n;i++)
    {
        printf("\n donner un alphabete de quatre bases azotées");
        adn=rand()%4; //random number
        insertionEnTete(brin,x[adn]);
    }

}
//2- Les fonctions de chiffrement consiste à chiffrer un teste claire en code ADN
//1er function
void ASCII (char char_text[32], int code_ascii [255])
{
            int j=0,i=0,pos=0;;
            char tab[8],bin[255];

  while(char_text[i]!='\0')
        {
            itoa(char_text[i],tab, 2);       //convert char_alphabet to char_binaire
            for(int j=0;j<=7;j++)        //affectation contenu de tab en bin_char
                {
                     if(j==0)
                     bin[pos]='0';           //remplir le code obtenue avec un zéro pour obtenir un code multiple de 8 bits
                     pos++;
                     bin[pos]=tab[j];
                }
            i++;
       }

   if(pos!=255)                         //remplir des zeros en fin de tab
    for(int j=pos;j<=255;j++)
        bin[j]='0';

   for(int i=0;i<=255;i++)             //convert bin_char to binaire(code_ascii) en type entier
                if(bin[i]=='1')
                    code_ascii[i]=1;
                else code_ascii[i]=0;





}


//2eme function
void gene_cle(int cle [255])
{
    for(int i=0;i<=255;i++)
      cle[i]=rand()%2;
}


//3eme function
void xor(int cle[255],int code_ascii[255],char text_bin[255] )
{
    for(int i=0;i<=255;i++)
        if(cle[i]!=code_ascii[i])
            text_bin[i]='1';
        else text_bin[i]='0';
text_bin[256]='\0';

}


//4eme function

void gene_code_adn (char text_bin[255],char text_adn[ ])
 { int i=0,j=0;
    while(i<=255)
        {
             if((text_bin[i]=='0')&&(text_bin[i+1]=='0'))
             text_adn[j]='A';
             else if((text_bin[i]=='1')&&(text_bin[i+1]=='0'))
             text_adn[j]='T';
             else if((text_bin[i]=='0')&&(text_bin[i+1]=='1'))
             text_adn[j]='G';
             else if((text_bin[i]=='1')&&(text_bin[i+1]=='1'))
             text_adn[j]='C';
             i=i+2;
             j++;
        }
    text_adn[j] = '\0';

 }


//3- Déchiffrement traduise le texte chiffré (code ADN) en teste claire :
//1er function
void gene_code_bin (char text_adn[ ],char text_bin[255])
{
    int i=0,j=0;
     while(i!='\0')
     {
         if(text_adn[i]=='A')
            {
             text_bin[j]='0';
             text_bin[j+1]='0';
            }
          else if(text_adn[i]=='T')
            {
             text_bin[j]='1';
             text_bin[j+1]='0';
            }
           else if(text_adn[i]=='G')
            {
             text_bin[j]='0';
             text_bin[j+1]='1';
            }
          else
            {
             text_bin[j]='1';
             text_bin[j+1]='1';
            }

          i++;
          j=j+2;
     }
}

 //2em function
 void xoor (int cle[255],char text_bin[255],int code_ascii[255] )
  {
    int binaire;
    for(int i=0;i<=255;i++)
        {  if(text_bin[i]=='0')
             binaire=0;
           else binaire=1;
            code_ascii[i]=cle[i]^binaire;
        }

  }


//3em function
void text_clair (int code_ascii [255], char text[32])
{
   char bin[255],tab[8];

    for(int i=0;i<=255;i++)                  //convert bin_int to bin_char
                if(code_ascii[i]==1)
                   bin[i]='1';
                else bin[i]='0';

   int i=0,k=0;

    while(i<=255)                            // convert bin_char to text
    {
        for(int j=0;j<=7;j++)                //affecter chaque 8bits from bin_char to tab[8]
            {
               tab[j]=bin[i];
               i++;
            }
             tab[8] = '\0';
        text[k] = strtol(tab, NULL, 2);         //converter chaque 8 bits to character
        k++;
    }


}
int main()
{liste l=NULL;
int n,x;
  //printf(" donner longueur n \n");
  //scanf("%d",&n);
    //genere_adn(&l,n);
    //afficherListe(&l);

int code_ascii[255],cle[255],code_ascii_2[255];
char char_text[31];//={'Y','A','O','M','F','R','G','T','N','W','C','C','A','U','B','Q','Z','B','S','G','C','K','L','K','M','G','C','E','C','C','G'};
char text_bin[255];
char text_adn[255];
char text[32];
scanf("%s",&char_text);


ASCII(char_text,code_ascii);
    printf("\n code_ascii obtient:\n");
    for (int i=0;i<=255;i++)
    printf("%d",code_ascii[i]);
    printf("\n\n\n");


gene_cle(cle);
    printf("\n cle obtient:\n");
    for (int i=0;i<=255;i++)
    printf("%d",cle[i]);
    printf("\n\n\n");

xor(cle,code_ascii,text_bin);
    printf("\n xor entre code ascii et cle est:\n%s\n",text_bin);
    gene_code_adn(text_bin,text_adn);
    printf("\n text adn obtient:\n%s\n",text_adn);


gene_code_bin(text_adn,text_bin);

  printf("\n text bin obtient:\n%s\n",text_bin);

xoor(cle,text_bin,code_ascii_2);
    printf(" le xor du text_bin avec la cle de chiffrement:\n");
    for (int i=0;i<=255;i++)
    printf("%d",code_ascii_2[i]);
    printf("\n\n\n");


text_clair(code_ascii,text);
    printf("\n traduire du code ASCII en clair selon codage ASCII:\n");
    printf("%s",text);
return ;
}
