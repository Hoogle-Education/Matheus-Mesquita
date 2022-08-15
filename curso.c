#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// VALORES DO PROBLEMA
// ALTERAR PARA TESTES
const int quantidade_cursos = 3;
const int quantidade_alunos = 3;
const double CR_min = 6.0;

struct curso
{
  char codigo_do_curso[50];
  int atingiu_CR;
  int nao_atingiu_CR;
};

struct curso *inicializa();
void leitura(struct curso *cursos);
void leitura_alunos(struct curso *cursos);
int busca(struct curso *cursos, const char *codigo);
void exibe(struct curso cursos[]);

int main(int argc, char const *argv[])
{
  struct curso *cursos = inicializa(cursos);

  leitura(cursos);
  leitura_alunos(cursos);
  exibe(cursos);

  return 0;
}

struct curso *inicializa()
{
  struct curso *cursos = (struct curso *)malloc(quantidade_cursos * sizeof(struct curso));
  return cursos;
}

void leitura(struct curso *cursos)
{
  printf("# Digite os codigos dos cursos\n");
  for (int i = 0; i < quantidade_cursos; i++)
  {
    printf("> Curso #%d - Codigo: ", i + 1);
    scanf(" %s", cursos[i].codigo_do_curso);
  }
}

void leitura_alunos(struct curso *cursos)
{

  printf("INSIRA OS DADOS DOS ALUNOS\n");

  for (int i = 0; i < quantidade_alunos; i++)
  {
    char codigo[50];
    double CR;

    printf("Insira os dados do aluno #%d\n", i + 1);

    printf("codigo do curso: ");
    scanf(" %s", codigo);

    printf("CR: ");
    scanf(" %lf", &CR);

    int pos = busca(cursos, codigo);

    if (pos == -1)
      continue;

    if (CR > CR_min)
    {
      cursos[pos].atingiu_CR++;
    }
    else
    {
      cursos[pos].nao_atingiu_CR++;
    }
  }
}

int busca(struct curso *cursos, const char *codigo)
{
  int pos = -1;

  for (int i = 0; i < quantidade_cursos; i++)
  {
    if (strcmp(cursos[i].codigo_do_curso, codigo) == 0)
    {
      pos = i;
      break;
    }
  }

  return pos;
}

void exibe(struct curso cursos[])
{
  printf("------------------------\n");
  printf("--------RELACAO DE CURSOS--------");
  printf("------------------------\n");

  for (int i = 0; i < quantidade_cursos; i++)
  {
    printf("| CURSO #%s |\n", cursos[i].codigo_do_curso);
    printf("| Com CR minimo = %d\n", cursos[i].atingiu_CR);
    printf("| Sem CR minimo = %d\n\n", cursos[i].nao_atingiu_CR);
    printf("------------------------\n");
  }
}