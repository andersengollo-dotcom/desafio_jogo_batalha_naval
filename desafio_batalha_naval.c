#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define TAM_NAVIOS 3
#define LINHA_PODER 3
#define COLUNA_PODER 5
 
int main() {
    int ind_navio_vert = 0;
    int ind_navio_hori = 0;
    int ind_navio_diag_dir = 0;
    int ind_navio_diag_esq = 0;

    int cod_coluna[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //código das colunas com o índice - para facilitar codagem
    //char cod_coluna[COLUNAS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //código das colunas com as letras
    int navio_hori[TAM_NAVIOS] = {3, 3, 3};
    int navio_vert[TAM_NAVIOS] = {3, 3, 3};
    int navio_diag_dir [TAM_NAVIOS] = {3, 3, 3};
    int navio_diag_esq [TAM_NAVIOS] = {3, 3, 3};
    
    int lin_navio_vert = 0; //coor inicial vertical (linha)
    int col_navio_vert = 1; //coor inicial vertical (coluna)

    int lin_navio_hori = 0; //coor inicial horizontal (linha)
    int col_navio_hori = 3; //coor inicial horizontal (coluna)

    int lin_navio_diag_dir = 2; // coor inicial diagonal direita (linha)
    int col_navio_diag_dir = 5; // coor inicial diagonal direita (coluna)

    int lin_navio_diag_esq = 7; // coor inicial diagonal esquerda (linha)
    int col_navio_diag_esq = 8; // coor inicial diagonal esquerda (coluna)
    
    int tabuleiro[LINHAS][COLUNAS]; //valores de zero indicando ÁGUA

    //formando a matriz vazia
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }
    
    printf("\n");
    //#### VALIDAÇÃO SE OS ÍNDICES ESTÃO CABENDO NO TABULEIRO ####

    //validando índice navio VERTICAL
    if (lin_navio_vert <= 7 && lin_navio_vert >= 0){ //linha pode ser de 0 a 7
        printf("Coordenadas válidas LNV\n");
    } else
    {
        printf("Coordenadas INVÁLIDAS LNV\n");
    }
    
    if (col_navio_vert <= 9 && col_navio_vert >= 0){ //coluna pode ser de 0 a 9
        printf("Coordenadas válidas CNV\n");
    } else
    {
        printf("Coordenadas INVÁLIDAS CNV\n");
    }
    
    //validando índice navio HORIZONTAL
    if (lin_navio_hori <= 9 && lin_navio_hori >= 0){ //linha pode ser de 0 a 9
        printf("Coordenadas válidas LNH\n");
    } else
    {
        printf("Coordenadas INVÁLIDAS LNH\n");
    }
    
    if (col_navio_hori <= 7 && col_navio_hori >= 0){ //coluna pode ser de 0 a 7
        printf("Coordenadas válidas CNH\n");
    } else
    {
        printf("Coordenadas INVÁLIDAS CNH\n");
    }

    //validando índice navio DIAGONAL DIREITA
    if (lin_navio_diag_dir <= 7 && lin_navio_diag_dir >= 0){ //linha pode ser de 0 a 7
        printf("Coordenadas válidas LDD\n");
    } else
    {
        printf("Coordenadas INVÁLIDAS LDD\n");
    }
    
    if (col_navio_diag_dir <= 7 && col_navio_diag_dir >= 0){ //coluna pode ser de 0 a 7
        printf("Coordenadas válidas CDD\n");
    } else
    {
        printf("Coordenadas INVÁLIDAS CDD\n");
    }

    //validando índice navio DIAGONAL ESQUERDA
    if (lin_navio_diag_esq <= 7 && lin_navio_diag_esq >= 0){ //linha pode ser de 0 a 7
        printf("Coordenadas válidas LDE\n");
    } else
    {
        printf("Coordenadas INVÁLIDAS LDE\n");
    }
    
    if (col_navio_diag_esq <= 9 && col_navio_diag_esq >= 2){ //coluna pode ser de 0 a 7
        printf("Coordenadas válidas CDE\n");
    } else
    {
        printf("Coordenadas INVÁLIDAS CDE\n");
    }
    
    // ##### POSICIONANDO OS NAVIOS NA MATRIZ #####

    //posicionando navio VERTICAL com do-while (NÃO VALIDA PORQUE É O PRIMEIRO)
    do{
        tabuleiro[lin_navio_vert][col_navio_vert] = navio_vert[ind_navio_vert];
        lin_navio_vert++;
        ind_navio_vert++;
    } while (ind_navio_vert < 3);

    //posicionando navio HORIZONTAL com do-while (VALIDANDO COM IF-ELSE)
    if (tabuleiro[lin_navio_hori][col_navio_hori] || tabuleiro[lin_navio_hori][col_navio_hori+1] || tabuleiro[lin_navio_hori][col_navio_hori+2] == 3)
    {
        printf("### ERRO ###\n--> O navio HORIZONTAL está sobreposto <--\n");
    } else {
        do {
        tabuleiro[lin_navio_hori][col_navio_hori] = navio_hori[ind_navio_hori];
        col_navio_hori++;
        ind_navio_hori++;
    } while (ind_navio_hori < 3);
    }
     
    //posicionando navio DIAGONAL DIREITA com do-while (VALIDANDO COM IF-ELSE)
    if (tabuleiro[lin_navio_diag_dir][col_navio_diag_dir] || tabuleiro[lin_navio_diag_dir+1][col_navio_diag_dir+1] || tabuleiro[lin_navio_diag_dir+2][col_navio_diag_dir+2] == 3)
    {
        printf("### ERRO ###\n--> O navio DIAGONAL DIREITA está sobreposto <--\n");
    } else {
        do {
        tabuleiro[lin_navio_diag_dir][col_navio_diag_dir] = navio_diag_dir[ind_navio_diag_dir];
        lin_navio_diag_dir++;
        col_navio_diag_dir++;
        ind_navio_diag_dir++;
    } while (ind_navio_diag_dir < 3);
    }
    
    //posicionando navio DIAGONAL ESQUERDA com do-while (VALIDANDO COM IF-ELSE)
    if (tabuleiro[lin_navio_diag_esq][col_navio_diag_esq] || tabuleiro[lin_navio_diag_esq+1][col_navio_diag_esq-1] || tabuleiro[lin_navio_diag_esq+2][col_navio_diag_esq-2] == 3)
    {
        printf("### ERRO ###\n--> O navio DIAGONAL ESQUERDA está sobreposto <--\n");
    } else {
        do {
        tabuleiro[lin_navio_diag_esq][col_navio_diag_esq] = navio_diag_esq[ind_navio_diag_esq];
        lin_navio_diag_esq++;
        col_navio_diag_esq--;
        ind_navio_diag_esq++;
    } while (ind_navio_diag_esq < 3);
    }

    //inserindo os poderes especiais

    int cone[2] = {8, 8}; //coordenadas poder cone
    int cruz[2] = {0, 4}; //coordenadas poder cruz
    int octa[2] = {7, 7}; //coordenadas poder octaedro

    // CONE   
    
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (i == cone[0] && j == cone[1] || 
                i == cone[0] && j == cone[1]-1 || 
                i == cone[0] && j == cone[1]+1)
            {
                tabuleiro[i][j] = 1;
            } else if (i == cone[0]-1 && j == cone[1])
            {
                tabuleiro[i][j] = 1;
            } else if (i == cone[0]+1 && j == cone[1]+1 ||
                       i == cone[0]+1 && j == cone[1]+2 ||
                       i == cone[0]+1 && j == cone[1] ||
                       i == cone[0]+1 && j == cone[1]-1 ||
                       i == cone[0]+1 && j == cone[1]-2)
            {
                tabuleiro[i][j] = 1;
            } else
            {
                continue;
            }
        }   
    };

    // CRUZ
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (i == cruz[0]+1 && j == cruz[1])
            {
                tabuleiro[i][j] = 1;
            } else if (i == cruz[0]-1 && j == cruz[1])
            {
                tabuleiro[i][j] = 1;
            } else if (i == cruz[0] && j == cruz[1]+1 ||
                       i == cruz[0] && j == cruz[1]+2 ||
                       i == cruz[0] && j == cruz[1] ||
                       i == cruz[0] && j == cruz[1]-1 ||
                       i == cruz[0] && j == cruz[1]-2)
            {
                tabuleiro[i][j] = 1;
            } else
            {
                continue;
            }
        }   
    }

    // OCTAEDRO
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (i == octa[0]+1 && j == octa[1])
            {
                tabuleiro[i][j] = 1;
            } else if (i == octa[0]-1 && j == octa[1])
            {
                tabuleiro[i][j] = 1;
            } else if (i == octa[0] && j == octa[1]+1 ||
                       i == octa[0] && j == octa[1] ||
                       i == octa[0] && j == octa[1]-1)
            {
                tabuleiro[i][j] = 1;
            } else
            {
                continue;
            }
        
        }   
    }

    //##### VALIDANDO COORDENADAS DO PODER
    
    //VALIDANDO PODER CONE
    if (cone[0] <= 8 && cone[0] >= 0){ //linha pode ser de 0 a 8
        printf("Coordenadas válidas do CONE (linha)\n");
    } else
    {
        printf("Disperdiçando poder do CONE fora do tabuleiro (linha)\n");
    }
    
    if (cone[1] <= 7 && cone[1] >= 0){ //coluna pode ser de 0 a 7
        printf("Coordenadas válidas do CONE (coluna)\n");
    } else
    {
        printf("Disperdiçando poder do CONE fora do tabuleiro (coluna)\n");
    }

    //VALIDANDO PODER CRUZ
     if (cruz[0] <= 8 && cruz[0] >= 1){ //linha pode ser de 1 a 8
        printf("Coordenadas válidas do CRUZ (linha)\n");
    } else
    {
        printf("Disperdiçando poder do CRUZ fora do tabuleiro (linha)\n");
    }
    
    if (cruz[1] <= 7 && cruz[1] >= 2){ //coluna pode ser de 2 a 7
        printf("Coordenadas válidas da CRUZ (coluna)\n");
    } else
    {
        printf("Disperdiçando poder do CRUZ fora do tabuleiro (coluna)\n");
    }

    //VALIDANDO PODER OCTAEDRO
    if (octa[0] <= 8 && octa[0] >= 1){ //linha pode ser de 1 a 8
        printf("Coordenadas válidas do OCTAEDRO (linha)\n");
    } else
    {
        printf("Disperdiçando poder do OCTAEDRO fora do tabuleiro (linha)\n");
    }
    
    if (octa[1] <= 8 && octa[1] >= 1){ //coluna pode ser de 1 a 8
        printf("Coordenadas válidas do OCTAEDRO (coluna)\n");
    } else
    {
        printf("Disperdiçando poder do OCTAEDRO fora do tabuleiro (coluna)\n");
    }


    // #### IMPRIMINDO A MATRIZ ####

    //cabeçalho dos Código das Colunas
    printf("\n");
    printf(" ########### TABULEIRO ###########\n");
    printf("     ");
    for (int i = 0; i < 10; i++)
    {
    printf("%d  ", cod_coluna[i]);
    }

    printf("\n");//espaçamento

    //imprimindo a matriz COM NAVIOS/PODERES
    for (int i = 0; i < 10; i++)
    {
    printf("%2d -", i); //para o número da linha
    for (int j = 0; j < 10; j++)
    {
    printf("%2d ", tabuleiro[i][j]); //para o valor dos índices
    }
    printf("\n");
    }

    return 0;
}

