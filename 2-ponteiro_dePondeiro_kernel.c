/*
Dada uma matriz N*m alocada dinamicamente.Gere uma nova matriz N*m que é o resultado de uma filtragem por uma matriz chamada de kernel 
que deve possuir  qualque desses tamanhos 3x3 , 5x5 ou 7x7 e a matriz deverá ser preencida com valores de 0 - 255
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int **alocarmatriz(int n, int m);
int **preencher(int **matriz,int n, int m);
void **mostrar(int **matriz,int n, int m);
int **percorrer(int **matriz,int **matriz2,int **kernel,int tam_kernel,int n ,int m);
int media(int **kernel,int tam_kernel);

int main(){
    int n, m,tam_kernel;
    puts("Digite o tamanho da matriz l");
    scanf("%d",&n);
    puts("Digite o valor da matriz C");
    scanf("%d",&m);

    puts("Escolha o tamanho do Kernel");
    puts("[3]Kernel 3 x 3");
    puts("[5]Kernel 5 x 5");
    puts("[7]Kernel 7 x 7");
    scanf("%d",&tam_kernel);

  
    int **kernel = alocarmatriz(tam_kernel,tam_kernel);
    int **matriz = alocarmatriz(n,m);
    int **matriz2 = alocarmatriz(n,m);
    matriz = preencher(matriz,n,m);
    mostrar(matriz,n,m);
    matriz2=percorrer(matriz,matriz2,kernel,tam_kernel,n,m);
    printf("-------------\n");
    mostrar(matriz2,n,m);

    return 0;
}

int **alocarmatriz(int n, int m){

    int **matriz;
    //Alocando a matriz
    matriz=(int**)malloc(sizeof(int*)*n);

    for(int i =0;i<n;i++)
        matriz[i]=(int*)malloc(sizeof(int)*m);
    

    return matriz;
    

}

int **preencher(int **matriz,int n, int m){
    srand(time(NULL));
    for(int i =0;i<n;i++)
        for(int j=0;j<m;j++)
            matriz[i][j] = rand () % 256;

    return matriz;
    

}

void **mostrar(int **matriz,int n, int m){

    for(int i =0;i<n;i++){
        puts("");
        for(int j=0;j<m;j++){
            printf("%d ",matriz[i][j]);
        }
    }
    puts("");

}

int **percorrer(int **matriz,int **matriz2,int **kernel,int tam_kernel,int n ,int m){
    
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                int aux1=0;
                for(int k =i;aux1<tam_kernel;k++){
                    int aux2=0;
                    for(int l=j;aux2<tam_kernel;l++){
                        kernel[aux1][aux2] = matriz[k%n][l%m];
                        
                        aux2++;
                    }
                    aux1++;
                }
                mostrar(kernel,tam_kernel,tam_kernel);
                    
                matriz2[(i+(tam_kernel/2))%n][(j+(tam_kernel/2))%m] = media(kernel,tam_kernel);
            }
        }
    return matriz2;
}

int media(int **kernel,int tam_kernel){
    int soma =0,m=0;
    for(int i =0;i<tam_kernel;i++){
        for(int j = 0;j<tam_kernel;j++){
            soma+=kernel[i][j];
        }
    }
    m=soma/(tam_kernel*tam_kernel);
    return m;
}