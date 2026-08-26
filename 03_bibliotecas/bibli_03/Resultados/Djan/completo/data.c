#include "data.h"

/**
 * @file data.h
 * @brief Biblioteca para manipulação de datas.
 * 
 * Esta biblioteca contém funções para verificar a validade de uma data, imprimir uma data por extenso,
 * verificar se um ano é bissexto, calcular o número de dias de um mês, comparar duas datas e calcular a
 * diferença em dias entre duas datas.
 * 
 */


/**
 * @brief Verifica se uma data é válida.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 * @return int Retorna 1 se a data é válida e 0 caso contrário.
 */
int verificaDataValida(int dia, int mes, int ano){
    if(dia <= 30 && (mes==04||mes==06||mes==10||mes==12)){
        return 1;
    }else if(dia <= 31 && (mes==01||mes==02||mes==03||mes==05||mes==07||mes=="08"||mes=="09"||mes==11)){
        return 1;
    }else if(verificaBissexto(ano) == 1 && dia <= 30 && (mes==04||mes==06||mes==10||mes==12)){
        return 1;
    }

    return 0;
}

/**
 * @brief Imprime o nome do mês por extenso.
 * 
 * @param mes Mês a ser impresso.
 */
void imprimeMesExtenso(int mes){
        switch (mes) {
            case 1:  printf("Janeiro");   
            break;
            case 2:  printf("Fevereiro"); 
            break;
            case 3:  printf("Março");     
            break;
            case 4:  printf("Abril");     
            break;
            case 5:  printf("Maio");      
            break;
            case 6:  printf("Junho");     
            break;
            case 7:  printf("Julho");     
            break;
            case 8:  printf("Agosto");    
            break;
            case 9:  printf("Setembro");  
            break;
            case 10: printf("Outubro");   
            break;
            case 11: printf("Novembro");  
            break;
            case 12: printf("Dezembro");  
            break;
    }
}

/**
 * @brief Imprime a data por extenso.
 * 
 * @param dia Dia da data.
 * @param mes Mês da data.
 * @param ano Ano da data.
 */
void imprimeDataExtenso(int dia, int mes, int ano){
    imprimeMesExtenso(mes);

    printf("%d de %s de %d\n", dia, mes, ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 * 
 * @param ano Ano a ser verificado.
 * @return int Retorna 1 se o ano é bissexto e 0 caso contrário.
 */
int verificaBissexto(int ano){

    if((ano%4 == 0 && ano%100 != 0) || (ano%400 == 0)){
        return 1;
    }else{
        return 0;
    }
}

/**
 * @brief Calcula o número de dias de um mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias do mês.
 */
int numeroDiasMes(int mes, int ano){
        switch (mes){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            if(verificaBissexto(ano)) {
                return 29;
            }
            return 28;
        default:
            return 0;
    }
}

/**
 * @brief Compara duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna 1 se a primeira data é maior que a segunda, -1 se a primeira data é menor que a segunda
 * e 0 se as datas são iguais.
 * A data ser "maior" significa que ela está mais no futuro.
 */
int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    
    if(ano1 > ano2){
        return 1;
    }else if(ano1 < ano2){
        return -1;
    }
    
    if(mes1 > mes2){ 
        return 1;
    }
    if(mes1 < mes2){
        return -1;
    }
    
    if(dia1 > dia2){
        return 1;
    }else if(dia1 < dia2){ 
        return -1;
    }

    return 0;
}


/**
 * @brief Calcula o número de dias até o mês.
 * 
 * @param mes Mês a ser verificado.
 * @param ano Ano da data.
 * @return int Retorna o número de dias até o mês.
*/
int calculaDiasAteMes(int mes, int ano){
    int dias_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, total = 0, i;

    if(verificaBissexto(ano)){
        dias_mes[2] = 29;
    }

    for(i = 1; i < mes; i++){
        total += dias_mes[i];
    }

    return total;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 * 
 * @param dia1 Dia da primeira data.
 * @param mes1 Mês da primeira data.
 * @param ano1 Ano da primeira data.
 * @param dia2 Dia da segunda data.
 * @param mes2 Mês da segunda data.
 * @param ano2 Ano da segunda data.
 * @return int Retorna o número de dias de diferença entre as datas.
 */
int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

    int diasAcumulados1 = calculaDiasAteMes(mes1, ano1) + dia1;
    int diasAcumulados2 = calculaDiasAteMes(mes2, ano2) + dia2;
    int totalDias = 0, i, diasAno1;

    // Caso 1: As datas são do mesmo ano
    if (ano1 == ano2) {
        totalDias = diasAcumulados2 - diasAcumulados1;
    }
    // Caso 2: A data 1 é de um ano anterior ao da data 2
    else if (ano1 < ano2) {
        if (verificaBissexto(ano1)) {
            diasAno1 = 366;
        } else {
            diasAno1 = 365;
        }
        totalDias += (diasAno1 - diasAcumulados1);
        
        // Soma os dias dos anos inteiros que estão no meio
        for (i = ano1 + 1; i < ano2; i++) {
            // Substituído o condicional por if/else dentro do loop
            if(verificaBissexto(i)){
                totalDias += 366;
            }else{
                totalDias += 365;
            }
        }
        totalDias += diasAcumulados2;
    }else{
        return calculaDiferencaDias(dia2, mes2, ano2, dia1, mes1, ano1);
    }

    if(totalDias < 0){
        return - totalDias;
    }
    return totalDias;

}