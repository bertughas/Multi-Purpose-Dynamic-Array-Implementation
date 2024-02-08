#include <stdio.h>
#include <stdlib.h>

struct diziElemanlari{
int boyut;
int indis;
int *veri;


};
typedef struct diziElemanlari Dizim;
//dizi olusturacaz
void diziOlustur(Dizim *d,int boyut){
d->boyut=boyut;
d->veri=(int*)malloc(boyut*sizeof(int));
d->indis=0;


}

void genislet(Dizim *d,int eklenenBoyut){
d->boyut+=eklenenBoyut;
d->veri=(int*)realloc(d->veri,d->boyut*sizeof(int));





}
void diziyeElemanEkle(Dizim *d,int v){
if(d->indis==d->boyut-1){
    printf("Dizinin boyutunu genisletmek ister misiniz?(Cikis -1):");
    int eklenenBoyut;
    if(eklenenBoyut==-1){
        return 0;
    }
    scanf("%d",&eklenenBoyut);
    genislet(d,eklenenBoyut);
}
d->veri[d->indis]=v;
d->indis++;




}









int main() {
int sayi;
printf("dizininzde kac eleman olacak:");
scanf("%d",&sayi);

Dizim dizi;
diziOlustur(&dizi,sayi);


for(int i=0;i<sayi;i++){
printf("\nDizinin %d. elemanini ekrana girin:",i+1);
int eleman;
scanf("%d",&eleman);
diziyeElemanEkle(&dizi,eleman);
}

printf("Dizinin elemanlari:\n");
for(int i=0;i<dizi.indis;i++){
    printf("%d ",dizi.veri[i]);
}
free(dizi.veri);








return 0;
}
