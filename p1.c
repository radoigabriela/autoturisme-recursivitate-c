#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char numar_inmatriculare[100];
    char marca[100];
    char culoare[100];
    int numar_locuri;
    char tip_combustibil[100];
    int capacitate_cilindrica;
    char serie_sasiu[100];
    int vechime;
    int numar_kilometri;
    int id;
} masina;

void creare(char *fn)
{
    FILE* f;
    masina m;
    f=fopen(fn, "wb");
    if(f==NULL)
    {
        printf("Eroare");
        exit(1);
    }
    printf("Introduceti numarul de inmatriculare sau -1 pentru terminare: ");
    scanf("%s", m.numar_inmatriculare);
    while(atoi(m.numar_inmatriculare)!=-1)
    {
        printf("Marca= ");
        scanf("%s", &m.marca);
        printf("Culoare= ");
        scanf("%s", &m.culoare);
        printf("Numarul de locuri= ");
        scanf("%d", &m.numar_locuri);
        printf("Tipul de combustibil= ");
        scanf("%s", &m.tip_combustibil);
        printf("Capacitatea cilindrica a motorului= ");
        scanf("%d", &m.capacitate_cilindrica);
        printf("Serie sasiu= ");
        scanf("%s", &m.serie_sasiu);
        printf("Vechime= ");
        scanf("%d", &m.vechime);
        printf("Numar kilometri= ");
        scanf("%d", &m.numar_kilometri);
        fwrite(&m, sizeof(m),1,f);
        printf("Introduceti numarul de inmatriculare sau -1 pentru terminare: ");
        scanf("%s", &m.numar_inmatriculare);
    }
    fclose(f);
}

void adaugare(char *fn)
{
    FILE* f;
    masina m;
    f=fopen(fn, "ab");
    if(f==NULL)
    {
        printf("Eroare");
        exit(1);
    }
    printf("Introduceti numarul de inmatriculare sau -1 pentru terminare: ");
    scanf("%s", m.numar_inmatriculare);
    while(atoi(m.numar_inmatriculare)!=-1)
    {
        printf("Marca= ");
        scanf("%s", &m.marca);
        printf("Culoare= ");
        scanf("%s", &m.culoare);
        printf("Numarul de locuri= ");
        scanf("%d", &m.numar_locuri);
        printf("Tipul de combustibil= ");
        scanf("%s", &m.tip_combustibil);
        printf("Capacitatea cilindrica a motorului= ");
        scanf("%d", &m.capacitate_cilindrica);
        printf("Serie sasiu= ");
        scanf("%s", &m.serie_sasiu);
        printf("Vechime= ");
        scanf("%d", &m.vechime);
        printf("Numar kilometri= ");
        scanf("%d", &m.numar_kilometri);
        fwrite(&m, sizeof(m),1,f);
        printf("Introduceti numarul de inmatriculare sau -1 pentru terminare: ");
        scanf("%s", &m.numar_inmatriculare);

    }
    fclose(f);
}

void afisare(char *fn)
{
    FILE* f;
    masina m;
    int n;
    f=fopen(fn, "rb");
    if(f==NULL)
    {
        printf("Eroare");
        exit(1);
    }
    n=fread(&m, sizeof(m),1,f);
    while(n==1)
    {
        printf("\n---------------");
        printf("\nNumar de inmatriculare= %s", m.numar_inmatriculare);
        printf("\nMarca= %s", m.marca);
        printf("\nCuloare= %s", m.culoare);
        printf("\nNumarul de locuri= %d", m.numar_locuri);
        printf("\nTip de combustibil= %s", m.tip_combustibil);
        printf("\nCapacitatea cilindrica a motorului= %d", m.capacitate_cilindrica);
        printf("\nSerie sasiu= %s", m.serie_sasiu);
        printf("\nVechime= %d", m.vechime);
        printf("\nNumar kilometri= %d", m.numar_kilometri);
        printf("\n---------------");
        n=fread(&m,sizeof(m),1,f);
    }
    fclose(f);
}

void modificare(char *fn)
{
    masina m;
    char numar_inmatriculare[100];
    FILE* f;
    int ok=0;
    f=fopen(fn, "rb+");
    if(f==NULL)
    {
        printf("Eroare\n");
        return 0;
    }
    printf("Introduceti numarul de inmatriculare sau -1 pentru terminare: ");
    scanf("%s", numar_inmatriculare);
    while(fread(&m, sizeof(m),1,f)==1)
    {
        if(strcmp(m.numar_inmatriculare, numar_inmatriculare)==0)
        {
            ok=1;
            break;
        }
    }
    if(ok)
    {
        printf("Introduceti noua vechime= ");
        scanf("%d", &m.vechime);
        printf("Introduceti noul numar de kilometri= ");
        scanf("%d", &m.numar_kilometri);
        fseek(f, -sizeof(m), SEEK_CUR);
        fwrite(&m, sizeof(m),1,f);
    }
    else
    {
        printf("Masina nu a fost gasita!\n");
    }
    fclose(f);
}
int main()
{
    char f1[100];
    printf("Introduceti nume pentru fisier: ");
    scanf("%s", &f1);
    creare(f1);
    printf("\Afisare masini: \n");
    afisare(f1);
    printf("\nModificare numarul de kilometri si vechime: \n");
    modificare(f1);
    printf("\nAfisare masini: \n");
    afisare(f1);
    printf("\nAdaugare masini noi: \n");
    adaugare(f1);
    printf("\nAfisare masini: \n");
    afisare(f1);
    return 0;
}
