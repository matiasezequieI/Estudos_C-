/*
7- Realizar uma consulta qualquer em banco de dados MySQL e mostrar o resultado na tela, se possível a saída deve estar em formato JSON. (veja sobre a library jsonCPP).
*/

#include <stdio.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASS "132567"
#define DB "db"

int main(void)
{
    MYSQL conexao;
    MYSQL_RES *resp;
    MYSQL_ROW linhas;
    MYSQL_FIELD *campos;
    char query[] = "SELECT * FROM musicas;";
    int contador; 

    mysql_init(&conexao);
    if (mysql_real_connect(&conexao, HOST, USER, PASS, DB, 0, NULL, 0)) //realiza conexao
    {
        printf("Conectado com Sucesso!\n");
        if (mysql_query(&conexao, query)) //consulta
            printf("Erro: %s\n", mysql_error(&conexao));
        else
        {
            resp = mysql_store_result(&conexao); 
            if (resp)
            {

                campos = mysql_fetch_fields(resp);
                for (contador = 0; contador < mysql_num_fields(resp); contador++)
                {
                    printf("%s", (campos[contador]).name);
                    if (mysql_num_fields(resp) > 1)
                        printf("\t");
                }

                printf("\n");

                while ((linhas = mysql_fetch_row(resp)) != NULL)
                {
                    for (contador = 0; contador < mysql_num_fields(resp); contador++)
                        printf("%s\t", linhas[contador]);
                    printf("\n");
                }
            }
            mysql_free_result(resp);
        }
        mysql_close(&conexao);
    }
    else
    {
        printf("Conexao Falhou\n");
        if (mysql_errno(&conexao))
            printf("Erro %d : %s\n", mysql_errno(&conexao), mysql_error(&conexao));
    }

    return 0;
}
