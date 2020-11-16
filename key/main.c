#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char PD[30];
    char PG[30];

} DFs;
int Ferm1(char Ferm[],int,DFs DF[]);


int main()
{
    char  T[50],bj9[4000],occ_Ferm[4000],occ_TR[4000],All_Attr[4000],Ferm[4000];
    int occ0=0,occ1=0,bj=0;
    int a=0,i=0,j,k,nbDF=0,nbAF;
    DFs DF[30];





    //Saisie des attributs
    printf (" \tENTER THE ATTRIBUTES : \n" );

    do {
        scanf("%s",T);


        if((strcmp(T,"0"))==0)
            break;

        strcat(All_Attr,T);

    } while(1);




    //Saisie des dependeces fonctionnelles


    printf("\n\n\tENTER YOUR FUNCTIONAL DEPENDENCES :\n ");

    i=0;
    do {

        do {
            printf("\nENTER LEFT :");
            scanf("%s",T);
            if((strcmp(T,"00"))==0) {
                break;

            }
            if((strcmp(T,"->"))==0  ) {
                break;
            }
            if(strstr(All_Attr,T)==NULL)
                printf("!! ATTENTION !! THIS ATTRIBUTES DOES NOT EXIST IN THIS RELATION !! TRY AGAIN!!\n");
            else {

                strcat(DF[i].PG,T);

            }
        } while(1);
  if((strcmp(T,"00"))==0) {

                break;

            }
        do {
            printf("\nENTER RIGHT :");
            scanf("%s",T);
            if((strcmp(T,"00"))==0) {
                nbDF++;
                break;

            }
            if((strcmp(T,"0"))==0) {
                nbDF++;
                break;

            }
            if(strstr(All_Attr,T)==NULL)
                printf("!! ATTENTION !! THIS ATTRIBUTES DOES NOT EXIST IN THIS RELATION !! TRY AGAIN!!\n");
            else {

                strcat(DF[i].PD,T);


            }

        } while(1);
        if((strcmp(T,"00"))==0)
            break;
        i++;

    } while(1);


    //Traitement des dependeces fonctionnelles




    for(i=0; i<nbDF; i++)
        for(j=0; j<strlen(DF[i].PD); j++)
            if(strchr(bj9,DF[i].PD[j])==NULL)
                bj9[strlen(bj9)]=DF[i].PD[j];


    for(i=0; i<strlen(All_Attr); i++) {
        a=0;
        for(j=0; j<strlen(bj9); j++)
            if(All_Attr[i]!= bj9[j])
                a++;
        if(a==strlen(bj9))
            Ferm[strlen(Ferm)]=All_Attr[i];
    }


    //Determination de la cle

    if(strlen(Ferm)!=0) {
        nbAF=Ferm1(Ferm,nbDF,DF);
        if(nbAF==strlen(All_Attr)) {
            printf("\n\n\t%s IS A (LUCKY) KEY \n\n",Ferm);
            exit(0);
        }
    }




    do {

        j=0;
        do {

            for (i=0; i<nbDF; i++) {
                if(strchr(occ_TR,All_Attr[j])!=NULL)
                    continue ;
                else if(strchr(DF[i].PG,All_Attr[j])!=NULL)
                    occ0++;

            }
            if(occ0>=occ1) {
                occ1=occ0;

                occ_TR[bj]=All_Attr[j];
            }
            occ0=0;
            j++;

        } while(j<strlen(All_Attr));
        bj++;
        occ1=0;
    } while(bj<strlen(All_Attr));

    i=0;
    j=0;
    k=strlen(Ferm);

    do {




        Ferm[k]=occ_TR[i];
        nbAF=Ferm1(Ferm,nbDF,DF);
        if(nbAF==strlen(All_Attr)) {
            printf("\n\n\t%s IS A (LUCKY) KEY \n\n",Ferm);
            exit(0);
        }

        if(nbAF==strlen(Ferm))
            i++;
        else
            break;

        if(i==strlen(occ_TR)) {
            Ferm[k]=occ_TR[j];
            k++;
            j++;
            i=0;
        }
    } while(1);

    for(i=0; i<strlen(occ_TR); i++) {
        a=0;
        for(j=0; j<strlen(Ferm); j++)
            if(occ_TR[i]!= Ferm[j])
                a++;
        if(a==strlen(Ferm))
            occ_Ferm[strlen(occ_Ferm)]=occ_TR[i];
    }


    for(i=0; i<strlen(occ_Ferm); i++)
        for(j=0; j<nbDF; j++)
            if(strchr(DF[j].PD,occ_Ferm[i])!=NULL) {
                for(k=0; k<strlen(DF[j].PG); k++)
                    if(strchr(Ferm,DF[j].PG[k])==NULL)
                        Ferm[strlen(Ferm)]=DF[j].PG[k];

                nbAF=Ferm1(Ferm,nbDF,DF);
                if(nbAF==strlen(All_Attr)) {
                printf("\n\n\t%s IS A (LUCKY) KEY \n\n",Ferm);
                    exit(0);
                }

            }


    return 0;
}

int Ferm1( char Ferm[4000],int nbDF,DFs DF[50])
{
    int m,i,j,a=0,s;
    char T[500];
    strcpy(T,Ferm);
    do {

        s=a;
        for(i=0; i<nbDF; i++) {
            m=1;
            for(j=0; j<strlen(DF[i].PG); j++)
                if(strchr(Ferm,DF[i].PG[j])==NULL )
                    m=0;
            if(m!=0)
                for(j=0; j<strlen(DF[i].PD); j++)
                    if(strchr(Ferm,DF[i].PD[j])==NULL ) {

                        Ferm[strlen(Ferm)]=DF[i].PD[j];
                        a++;
                    }
        }

        if(s==a)
            break;
    } while(1);
    a=strlen(Ferm);
    strcpy(Ferm,T);


    return a;
}

