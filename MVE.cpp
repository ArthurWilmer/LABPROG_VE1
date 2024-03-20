/*
prazo 14/04 domingo
Confeccione um sistema de matrículas em disciplinas de uma faculdade:
Entidades mais importantes: Aluno e Disciplina
Aluno: código (5 dígitos), nome, CPF
Disciplina: código (4 dígitos), nome, professor, quatidade de créditos
O sistema deve ser capaz de armazenar uma lista de alunos e uma lista de disciplinas por periodo (2018.2)
Estruturas alocadas dinamicamente
Opções: Inserção, remoção (através de um menu de opções)
        Consultas das disciplinas de um aluno em um determinado periodo
        Consultas dos alunos que estão matriculados em uma disciplina em um determinado periodo
        Salvamento e recuperação dos dados entre sessão
*/

#include <iostream>
using std::cin;
using std::cout;
using std::ios;
using std::endl;
using std::cerr;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;

#include <cstdlib>
using std::exit;

#include <iomanip>
using std::setw;

//#include <vector>

#include <windows.h>

#define PRESENT "SISTEMA DE CADASTRO UNIVERSITARIO"

//#include "MVE.h" // funções de verificação

/* Estruturas - 3 - Aluno, Disciplina, Matrícula ::  Listas encadeadas */

/* Aluno : 4 Campos*/
struct data_Aluno
{
    string cod;
    string nome;
    string CPF;
    data_Aluno *next;
};

/* Disciplina : 5 Campos*/
struct data_Disciplina
{
    string cod;
    string nome;
    string professor;
    int credito;
    data_Disciplina *next;
};

/* Relações de Matrícula por período : 5 Campos*/
struct data_Matricula
{
    int periodo;
    string cod1;
    string cod2;
    data_Matricula *next;
};

/* Tipos a serem verificados na abertura do arquivo a fim de carregamentos dos dados existentes*/
enum tipo {aluno=0, disciplina, matricula};

/* Mostra o dia no sistema */
void show_time()
{
    SYSTEMTIME time;
    GetSystemTime(&time);
    cout << time.wDay << "/" << time.wMonth << "/" << time.wYear << endl;
}

/* Classe de funções de inserção de dados com sobrecarga de funções*/
class Data_In
{
    public:
        data_Aluno* line(data_Aluno* aluno, string cod, string nome, string CPF)
        {
    
            data_Aluno* node = new data_Aluno;

            node->next=NULL;
            node->cod=cod;
            node->nome=nome;
            node->CPF=CPF;

            if(aluno)
            {
                aluno->next=node;
            }

            return aluno ? aluno : node; 
        }

        void newline(data_Aluno* lista)
        {
            system("cls");
            cout << "Cadastro de Alunos" << endl;
            cout << "Insira abaixo o Codigo, Nome e o CPF." << endl;
            string codigo, nome, CPF;
            cout << "Codigo: " << endl;
            getline(cin,codigo);
            cout << "Nome: " << endl;
            getline(cin,nome);
            cout << "CPF: " << endl;
            getline(cin,CPF);

            line(lista, codigo, nome, CPF);

            cout << endl << "aluno inserido com sucesso!";
            getchar();
            system ("cls");
        }

        void chargelines (string nome_arquivo)
        {
            ofstream arquivo(nome_arquivo, ios::out | ios:: binary);
        }
};

/* Classe de funções de remoção de dados com sobrecarga de funções*/

/*Classe menu de opções*/
class Menu
{
    public:
    void display()
    {
        cout << PRESENT << " "; show_time();
        cout << "[1] - Cadastrar aluno" << endl;
        cout << "[2] - Salvar" << endl;
        cout << "[3] - Sair" << endl << endl;
        cout << "Digite a opcao acima: ";
    }

    /*Obtém a opção do switch*/
    int get_op()
    {
        display();
        cin >> operador; fflush(stdin);
        return operador;
    }

    private:
    int operador;
};

int main()
{   
    /*Classe de funções*/
    Data_In insert;
    Menu menu;
    
    /*Alocação dinâmica das listas encadeadas*/
    data_Aluno *lista = insert.line(NULL, "", "", "");
       
    /*carregando arquivos*/
    
    /*Menu*/
    while (1)
    {           
        switch (menu.get_op())
        {
        case 1: //inserir aluno
            insert.newline(lista);
            break;

        case 2: //salvar aluno
            
            break;
        
        default:
            break;
        }
    }
    return 0;
}