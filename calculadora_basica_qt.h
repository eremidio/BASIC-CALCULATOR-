//ESTE ARQUIVO CONTERÁ AS CLASSES DO APLICATIVOP DA CALCULADORA

/*
REFAZER (INICIALIZAR OS WIDGETS NO CONSTRUTOR DA CLASSE NA DEFINIÇÃO DA  CLASSE USAR RAW POINTERS)

*/

/*CABEÇALHO*/
#pragma once
//Qt MÓDULOS
#include<QApplication>
#include<QWidget>
#include<QMainWindow>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGridLayout>
#include<QLabel>
#include<QPushButton>
#include<Qt>
#include<QtGui>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QMessageBox>
#include<QString>
#include<QChar>

//C++ MÓDULOS
using namespace std;

//DEFINIÇÃO DA CLASSE DO APP
class Calculator: public QMainWindow{

//MACRO PARA USO DE SINAIS E SLOTS
Q_OBJECT

public:
//CONSTRUTOR E DESTRUIDOR DA CLASSE
Calculator();
~Calculator();

//WIDGETS
//LAYOUT DO APP
QWidget* main_widget;
QVBoxLayout* main_layout;
QHBoxLayout* display_layout;
QHBoxLayout* keyboard_layout;
QGridLayout* numeric_layout;
QGridLayout* operator_layout;
//MENUS (AÇÕES SERÃO INICIALIZADASNO CONSTRUTOR DA CLASSE)
QMenu* help_menu;
QAction* help_action;
QAction* about_action;
//DISPLAY
QLabel* display;
//BOTÕES
//TECLADO NÚMERICO
QPushButton* button_0;
QPushButton* button_1;
QPushButton* button_2;
QPushButton* button_3;
QPushButton* button_4;
QPushButton* button_5;
QPushButton* button_6;
QPushButton* button_7;
QPushButton* button_8;
QPushButton* button_9;
QPushButton* button_00;
QPushButton* button_point;
//TECLADO DE OPERADORES MATEMÁTICOS
QPushButton* button_sum;
QPushButton* button_subtract;
QPushButton* button_multiply;
QPushButton* button_divide;
QPushButton* button_square;
QPushButton* button_square_root;
QPushButton* button_cube;
QPushButton* button_cubic_root;
QPushButton* button_absolute;
QPushButton* button_factorial;
QPushButton* button_inverse;
QPushButton* button_percent;
QPushButton* button_memory_register;
QPushButton* button_memory_clear;
QPushButton* button_pi;
QPushButton* button_plus_minus;
QPushButton* button_clear;
QPushButton* button_off;
QPushButton* button_backspace;
QPushButton* button_equal;

public:
//VARIÁVEIS DE BACK-END
double parcel1, parcel2, result, memory_value, display_double;
float di_result;
int n_value;
uint64_t n_factorial;
bool ad, su, mu, di, pe;

//MÉTODOS DA CLASSE
public slots:
//FUNÇÕES DE USO GERAL
void about();
void help();
//FUNCIONALIDADES BÁSICAS DA CALCULADORA
void clear();
void turn_off();
void memory_register();
void memory_clear();
void backspace();

//ENTRADAS DE DADOS
void put_00();
void put_0();
void put_1();
void put_2();
void put_3();
void put_4();
void put_5();
void put_6();
void put_7();
void put_8();
void put_9();
void put_point();
//OPERADORES MATEMÁTICOS
void zero_division();
void sum();
void subtract();
void multiply();
void divide();
void square();
void square_root();
void cube();
void cubic_root();
void absolute();
void factorial();
void inverse();
void percent();
void show_pi();
void change_signal();
void equal();

                                    };
