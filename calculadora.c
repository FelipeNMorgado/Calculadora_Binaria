#include<stdio.h>
#include<strings.h>
#include <stdlib.h>
//Felipe Nunes Morgado - fnm - Turma B
//30/08 - 14h 55m - 20h 40min - Realizando terciera questão e ajustes no código

void transformar_hexa(int n , int d){
    int  i = 0, array[36];
    
    while(n != 0){
        array[i] = n%d;
        printf("Numerador: %d Resto: %d", &n , &array[i]);
        n = n/d;
        i++;
    }
    for(int j = i-1;j>=0;j--){
        if(array[j] < 10){
            printf("%d", array[j]);
        }else if(array[j] == 10){
            printf("A");
        }else if(array[j] == 11){
            printf("B");
        }else if(array[j] == 12){
            printf("C");
        }else if(array[j] == 13){
            printf("D");
        }else if(array[j] == 14){
            printf("E");
        }else if(array[j] == 15){
            printf("F");
        }
        
        
    }

}

void transformar(int n, int d){
    int  i = 0, array[36];
        
        while(n != 0){
            array[i] = n%d;
            printf("Numerador: %d Resto: %d", &n , &array[i]);
            n = n/d;
            i++;
        }
        for(int j = i-1;j>=0;j--){
            printf("%d", array[j]);
        }
}

void transformar_bcd(int n) {
    int index = 0;
    int bcd[10];  

    
    while (n > 0) {
        int digit = n % 10;
        bcd[index] = digit;
        n /= 10;
        index++;
    }

    
    for (int j = index - 1; j >= 0; j--) {
        int digit = bcd[j];
        int array[4] = {0};  
        int k = 0;

        
        while (digit > 0) {
            array[3 - k] = digit % 2;
            digit /= 2;
            k++;
        }

        
        for (int l = 0; l < 4; l++) {
            printf("%d", array[l]);
        }
        printf(" ");
    }
    printf("\n");
}

void decimal_para_binario(int decimal) {
    if (decimal == 0) {
        printf("0");
        return;
    }
    
    // Encontrar o número de bits necessários
    int bits = sizeof(decimal) * 8;
    char binario[bits + 1];
    int i = bits - 1;
    
    // Inicializa o array com '0'
    for (int j = 0; j < bits; j++) {
        binario[j] = '0';
    }
    
    // Converte o número decimal para binário
    while (decimal > 0) {
        binario[i--] = (decimal % 2) ? '1' : '0';
        decimal = decimal / 2;
    }
    
    // Imprime o resultado
    int start = i + 1;
    for (int j = start; j < bits; j++) {
        putchar(binario[j]);
    }
}

int main(){
    int opc;
    printf("DIgite:\n(1)-tranformar numero de base 10\n(2)-tranformar numero de base 10 com sinal\n(3)-Converter real e decimal para double e float\n");
    scanf("%d" , &opc);

    if(opc == 1){
        int var, num;
        printf("DIgite:\n(1)-Tranformar numero para binario\n(2)-Tranformar numero para octal\n(3)-Transformar numero para hexadecimal\n(4)-Tranforamar numero para BCD\n");
        scanf("%d",&var);
        printf("Digite o numero que deseja tranformar:\n");
        scanf("%d" , &num);
        if(var == 1){
            transformar(num , 2);
        }else if(var == 2){
            transformar(num , 8);
        }else if(var == 3){
            transformar_hexa(num , 16);
        }else if(var == 4){
            transformar_bcd(num);

        }
    }else if(opc == 2){
        int num;
    printf("Digite o numero que deseja transformar:\n");
    scanf("%d", &num);

    
    int largura = 8;
    int array[largura];
    int i = 0;

    
    int temp_num = num;
    if (temp_num < 0) {
        temp_num = -temp_num; 
    }

    
    while (temp_num > 0) {
        array[i] = temp_num % 2;
        temp_num = temp_num / 2;
        i++;
    }

    
    while (i < largura) {
        array[i] = 0;
        i++;
    }

    
    if (num < 0) {
        
        printf("Complemento a 1:\n");
        for (int j = largura - 1; j >= 0; j--) {
            array[j] = 1 - array[j];
        }

        
        for (int j = largura - 1; j >= 0; j--) {
            printf("%d", array[j]);
        }
        printf("\n");

        
        int resto = 1;
        for (int j = 0; j <largura; j++) {
            int soma = array[j] + resto;
            array[j] = soma % 2;
            resto = soma / 2;
        }

        
        printf("Complemento a 2:\n");
        for (int j = largura - 1; j >= 0; j--) {
            printf("%d", array[j]);
        }
        printf("\n");
    } else {
        
        printf("Binário:\n");
        for (int j = largura - 1; j >= 0; j--) {
            printf("%d", array[j]);
        }
        printf("\n");
    }

    }else if(opc == 3){
        int full, dec,i=0, array[36],notacao,sinal = 0,decimal[36],p=0;
        printf("Digite o numero que deseja transformar:\n");
        scanf("%d,%d", &full,&dec);
        if(full<0){
            sinal= 1;
        }
        while (full != 0) {
        array[i] = full%2;
            full = full/2;
            i++;
        }
        for(int j = i-1;j>=0;j--){
            if(array[j] == 1){
                break;
            }else{
                notacao ++;
                array[j] = 0;
            }
        }
        notacao = i - notacao;
        notacao = 127 - notacao;


        printf("Numero em float:\n");
        printf("%d",sinal);
        while(notacao != 0){
            decimal[p] = notacao%2;            
            notacao = notacao/2;
            p++;
        }
        for(int j = p-1;j>=0;j--){
            printf("%d", decimal[j]);
        }
        for(int j = i-1;j>=0;j--){
        printf("%d", array[j]);
        }
        decimal_para_binario(dec);     
    }else{
        printf("opcao invalida");
    }
    return 0;
} 