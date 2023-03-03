//ESTE ARQUIVO CONTÉM OS MÉTODOS DA CLASSE

/*CABEÇALHO*/
#include"calculadora_basica_qt.h"
#include<QString>
#include<QChar>
#include <QDesktopServices>
//C++ MÓDULOS
#include<cmath>
using namespace std;

//DESTRUIDOR DA CLASSE
Calculator::~Calculator(){
                         };

//CONSTRUTOR DA CLASSE
Calculator::Calculator(){
//CONFIGURAÇÕES GERAIS DA JANELA DO APP
setWindowTitle("Calculadora básica");
resize(600, 350);
setWindowIcon(QIcon("app_symbol.png"));

//INSTANCIADO OS WIDGETS DE LAYOUT DA CLASSE COM OS CONSTRUTORES APROPRIADOS E DEFININDO PROPRIEDADES DOS WIDGETS
//LAYOUT DO APP
main_widget= new QWidget();
main_layout = new QVBoxLayout();
display_layout = new QHBoxLayout();
keyboard_layout = new QHBoxLayout();
numeric_layout = new QGridLayout();
operator_layout = new QGridLayout();
//MENUS (AÇÕES SERÃO INICIALIZADAS NO CONSTRUTOR DA CLASSE)
help_menu = new QMenu();
help_menu=menuBar()->addMenu("Ajuda");
help_action = new QAction("Ajuda", this);
help_action->setShortcut(QKeySequence(Qt::Key_F1)); //ATALHO DE TECLADO
about_action=new QAction("Sobre", this);
about_action->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));//ATALHO DE TECLADO
//ADICIONANDO AÇÕES AOS MENUS
help_menu->addAction(help_action);
help_menu->addAction(about_action);
//DISPLAY
display = new QLabel();
display->setFont(QFont("Times New Roman", 18));
display->setFrameStyle(QFrame::Panel);
//BOTÕES
//TECLADO NÚMERICO
button_0 = new QPushButton("0");
button_1 = new QPushButton("1");
button_2 = new QPushButton("2");
button_3 = new QPushButton("3");
button_4 = new QPushButton("4");
button_5 = new QPushButton("5");
button_6 = new QPushButton("6");
button_7 = new QPushButton("7");
button_8 = new QPushButton("8");
button_9 = new QPushButton("9");
button_00 = new QPushButton("00");
button_00->setToolTip("Os botões que exibem caractéres numéricos inserem os respectivos algarismos no display da calculadora.");
button_point = new QPushButton(".");
button_point->setToolTip("Insere o separador dos dígitos decimais no display da calculadora.");
//TECLADO DE OPERADORES MATEMÁTICOS
button_sum = new QPushButton("+");
button_sum->setToolTip("Calcula a soma de dois valores.");
button_subtract = new QPushButton("-");
button_subtract->setToolTip("Calcula a diferença de dois valores.");
button_multiply = new QPushButton("×");
button_multiply->setToolTip("Calcula o produto de dois valores.");
button_divide = new QPushButton("/");
button_divide->setToolTip("Calcula a razão de dois valores.");
button_square = new QPushButton("x²");
button_square->setToolTip("Eleva um número ao quadrado.");
button_square_root = new QPushButton("√");
button_square_root->setToolTip("Calcula a raíz quadrada de um número.");
button_cube = new QPushButton("x³");
button_cube->setToolTip("Eleva um número ao cubo.");
button_cubic_root = new QPushButton("³√");
button_cubic_root->setToolTip("Calcula a raíz cúbica de um número.");
button_absolute = new QPushButton("|x|");
button_absolute->setToolTip("Retorna o valor absoluto do número exibido no display da calculadora");
button_factorial = new QPushButton("x!");
button_factorial->setToolTip("Retorna o fatorial de um número inteiro.");
button_inverse = new QPushButton("1/x");
button_inverse->setToolTip("Calcula o inverso de um número");
button_percent = new QPushButton("%");
button_percent->setToolTip("Efetua cálculo de porcentagens envolvendo dois valores.\nO primeiro valor correspondendo ao total (100%), e\no segundo representando percentual a ser estimado do total.");
button_memory_register = new QPushButton("MR");
button_memory_register->setToolTip("Registra um valor na memória da calculadora para uso posterior.\nO valor alocado pode ser atualizado múltiplas vezes pelo usuário.");
button_memory_clear = new QPushButton("MC");
button_memory_clear->setToolTip("Exibe o valor atualmente alocado na memória da calculadora.");
button_pi = new QPushButton("π");
button_pi->setToolTip("Exibe o valor de pi no display da calculadora.\n().");
button_plus_minus = new QPushButton("±");
button_plus_minus->setToolTip("Troca o sinal do valor exibido no display da calculadora.");
button_clear = new QPushButton("CE");
button_clear->setStyleSheet("QPushButton { background-color: orange;}");
button_clear->setToolTip("Remove o conteúdo do display da calculadora e\n reajusta o valor das parcelas usadas nos cálculos númericos.");
button_off = new QPushButton("OFF");
button_off->setStyleSheet("QPushButton { background-color: red;}");
button_off->setToolTip("Encerra a aplicação.");
button_backspace = new QPushButton("<-");
button_backspace->setToolTip("Remove o último caractére exibido no display da calculadora.");
button_equal = new QPushButton("=");
button_equal->setToolTip("Exibe o resultado  de operações matemáticas envolvendo duas parcelas.");
//DEFINIÇÃO DO LAYOUT DO APLICATIVO 
//AJUSTE GERAL DE LAYOUTS
setCentralWidget(main_widget);
main_widget->setLayout(main_layout);
main_layout->addLayout(display_layout);
main_layout->addLayout(keyboard_layout);
keyboard_layout->addLayout(numeric_layout);
keyboard_layout->addLayout(operator_layout);
//AJUSTE DO DISPLAY
display_layout->addWidget(display);
//AJUSTE DE TECLADO NÚMERICO
numeric_layout->addWidget(button_7, 0, 0, 1, 1);
numeric_layout->addWidget(button_8, 0, 1, 1, 1);
numeric_layout->addWidget(button_9, 0, 2, 1, 1);
numeric_layout->addWidget(button_4, 1, 0, 1, 1);
numeric_layout->addWidget(button_5, 1, 1, 1, 1);
numeric_layout->addWidget(button_6, 1, 2, 1, 1);
numeric_layout->addWidget(button_1, 2, 0, 1, 1);
numeric_layout->addWidget(button_2, 2, 1, 1, 1);
numeric_layout->addWidget(button_3, 2, 2, 1, 1);
numeric_layout->addWidget(button_0, 3, 0, 1, 1);
numeric_layout->addWidget(button_point, 3, 1, 1, 1);
numeric_layout->addWidget(button_00, 3, 2, 1, 1);
//AJUSTE DE TECLADO DE OPERADORES
operator_layout->addWidget(button_sum, 0, 0, 1, 1);
operator_layout->addWidget(button_subtract, 1, 0, 1, 1);
operator_layout->addWidget(button_multiply, 2, 0, 1, 1);
operator_layout->addWidget(button_divide, 3, 0, 1, 1);
operator_layout->addWidget(button_square,0 , 1, 1, 1);
operator_layout->addWidget(button_square_root,1 , 1, 1, 1);
operator_layout->addWidget(button_cube,2 , 1, 1, 1);
operator_layout->addWidget(button_cubic_root, 3, 1, 1, 1);
operator_layout->addWidget(button_absolute,0 , 2, 1, 1);
operator_layout->addWidget(button_factorial, 1, 2, 1, 1);
operator_layout->addWidget(button_inverse, 2, 2, 1, 1);
operator_layout->addWidget(button_percent, 3, 2, 1, 1);
operator_layout->addWidget(button_memory_register, 0, 3, 1, 1);
operator_layout->addWidget(button_memory_clear, 1, 3, 1, 1);
operator_layout->addWidget(button_pi, 2, 3, 1, 1);
operator_layout->addWidget(button_plus_minus, 3, 3, 1, 1);
operator_layout->addWidget(button_clear, 0, 4, 1, 1);
operator_layout->addWidget(button_off, 1, 4, 1, 1);
operator_layout->addWidget(button_backspace, 2, 4, 1, 1);
operator_layout->addWidget(button_equal, 3, 4, 1, 1);

//AJUSTANDO OS SINAIS E SLOTS
//NOTA: OPERAÇÕES COM STRINGS E QSTRINGS SERÃO INVOCADOS A PARTIR DE OUTROS MÉTODOS (MÉTODOS INTERNOS DA CLASSE)
//NOTA: O MÉTODO zero_division() É APENAS PARA ASSINALAR A TENTATIVA DE SE EXECUTAR UMA OPERAÇÃO INVÁLIDA: A DIVISÃO POR 0

//FUNÇÕES DE USO GERAL (MENU)
connect(help_action, SIGNAL(triggered()), this, SLOT(help()));
connect(about_action, SIGNAL(triggered()), this, SLOT(about()));

//FUNCIONALIDADES BÁSICAS DA CALCULADORA
connect(button_clear, SIGNAL(clicked()), this, SLOT(clear())); 
connect(button_off, SIGNAL(clicked()), this, SLOT(turn_off()));
connect(button_backspace, SIGNAL(clicked()), this, SLOT(backspace()));
connect(button_memory_register, SIGNAL(clicked()), this, SLOT(memory_register()));
connect(button_memory_clear, SIGNAL(clicked()), this, SLOT(memory_clear()));

//ENTRADAS DE DADOS
connect(button_0, SIGNAL(clicked()), this, SLOT(put_0()));
connect(button_point, SIGNAL(clicked()), this, SLOT(put_point()));
connect(button_00, SIGNAL(clicked()), this, SLOT(put_00()));
connect(button_1, SIGNAL(clicked()), this, SLOT(put_1()));
connect(button_2, SIGNAL(clicked()), this, SLOT(put_2()));
connect(button_3, SIGNAL(clicked()), this, SLOT(put_3()));
connect(button_4, SIGNAL(clicked()), this, SLOT(put_4()));
connect(button_5, SIGNAL(clicked()), this, SLOT(put_5()));
connect(button_6, SIGNAL(clicked()), this, SLOT(put_6()));
connect(button_7, SIGNAL(clicked()), this, SLOT(put_7()));
connect(button_8, SIGNAL(clicked()), this, SLOT(put_8()));
connect(button_9, SIGNAL(clicked()), this, SLOT(put_9()));

//OPERADORES MATEMÁTICOS
connect(button_sum, SIGNAL(clicked()), this, SLOT(sum()));
connect(button_subtract, SIGNAL(clicked()), this, SLOT(subtract()));
connect(button_multiply, SIGNAL(clicked()), this, SLOT(multiply()));
connect(button_divide, SIGNAL(clicked()), this, SLOT(divide()));
connect(button_square, SIGNAL(clicked()), this, SLOT(square()));
connect(button_square_root, SIGNAL(clicked()), this, SLOT(square_root()));
connect(button_cube, SIGNAL(clicked()), this, SLOT(cube()));
connect(button_cubic_root, SIGNAL(clicked()), this, SLOT(cubic_root()));
connect(button_absolute, SIGNAL(clicked()), this, SLOT(absolute()));
connect(button_factorial, SIGNAL(clicked()), this, SLOT(factorial()));
connect(button_inverse, SIGNAL(clicked()), this, SLOT(inverse()));
connect(button_percent, SIGNAL(clicked()), this, SLOT(percent()));
connect(button_pi, SIGNAL(clicked()), this, SLOT(show_pi()));
connect(button_plus_minus, SIGNAL(clicked()), this, SLOT(change_signal()));
connect(button_equal, SIGNAL(clicked()), this, SLOT(equal()));

//INICIALIZANDO AS VARIÁVEIS DE BACK-END
//VARIÁVEIS DE BACK-END
parcel1=0.0;
parcel2=0.0;
result=0.0;
memory_value=0.0;
n_value=0;
n_factorial=0;
ad=false;
su=false;
mu=false;
di=false;
pe=false;

                         };

//MÉTODOS DA CLASSE
//FUNÇÕES DE USO GERAL

//FUNÇÃO QUE LIMPA O DISPLAY DA CALCULADORA E RESETA VARIUÁVEIS PARA SEUS VALORES ORIGINAIS
void Calculator::clear(){
QString display_text=" ";
parcel1=0.0;
parcel2=0.0;
result=0.0;
n_value=0;
n_factorial=0;
ad=false;
su=false;
mu=false;
di=false;
pe=false;
display->setText(display_text);
                         };

//FUNÇÃO PARA FINALIZAR A APLICAÇÃO
void Calculator::turn_off(){
exit(0);
                           };

//FUNÇÃO PARA REMOVER UM CARACTÉRE DO DISPLAY DA CALCULADORA
void Calculator::backspace(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.chop(1);
display->setText(display_text);
                            };

//FUNÇÃO PARA REGISTRAR UM VALOR NA MÉMORIA DO CELULAR
void Calculator::memory_register(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
memory_value=display_text.toDouble();
                                  };

//FUNÇÃO QUE EXIBE O VALOR ALOCADO NA MEMÓRIA DO CELULAR
void Calculator::memory_clear(){
QString display_text = QString::number(memory_value);/*VARIÁVEL LOCAL*/
display->setText(display_text);
                               };

//FUNÇÕES DE ENTRADAS DE DADOS NA CALCULADORA (INSERÇÃO DE ALGARISMOS NO DISPLAY DA CALCULADORA)
void Calculator::put_point(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append(".");
display->setText(display_text);
                            };

void Calculator::put_0(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append("0");
display->setText(display_text);
                        };

void Calculator::put_00(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append("00");
display->setText(display_text);
                        };

void Calculator::put_1(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append("1");
display->setText(display_text);
                        };

void Calculator::put_2(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append("2");
display->setText(display_text);
                        };

void Calculator::put_3(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append("3");
display->setText(display_text);
                        };

void Calculator::put_4(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append("4");
display->setText(display_text);
                        };

void Calculator::put_5(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append("5");
display->setText(display_text);
                        };

void Calculator::put_6(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append("6");
display->setText(display_text);
                        };

void Calculator::put_7(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append("7");
display->setText(display_text);
                        };

void Calculator::put_8(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append("8");
display->setText(display_text);
                        };

void Calculator::put_9(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append("9");
display->setText(display_text);
                        };

void Calculator::show_pi(){
parcel1=(4.0)*atan(1.0);
QString display_text = QString::number(parcel1);
display->setText(display_text);
                          };


//FUNÇÕES DE OPERADORES MATEMÁTICOS
//OPERADORES ARITMÉTICOS BÁSICOS
void Calculator::sum(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
ad=true;
su=false;
mu=false;
di=false;
pe=false;
display->setText("");
                      };

void Calculator::subtract(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
ad=false;
su=true;
mu=false;
di=false;
pe=false;
display->setText("");
                      };

void Calculator::multiply(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
ad=false;
su=false;
mu=true;
di=false;
pe=false;
display->setText("");

                      };

void Calculator::divide(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
ad=false;
su=false;
mu=false;
di=true;
pe=false;
display->setText("");
                      };

//OUTROS OPERADORES MATEMÁTICOS
//TROCA DE SINAL
void Calculator::change_signal(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
result=(-1.0)*parcel1;
display_text = QString::number(result);
display->setText(display_text);
                                };

//OPERADORES DE CÁLCULO DE RAÍZES E LOGARITMOS
void Calculator::square(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
result=parcel1*parcel1;
display_text = QString::number(result);
display->setText(display_text);
                         };

void Calculator::square_root(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
result=sqrt(parcel1);
display_text = QString::number(result);
display->setText(display_text);
                         };

void Calculator::cube(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
result=parcel1*parcel1;
result=result*parcel1;
display_text = QString::number(result);
display->setText(display_text);
                       };

void Calculator::cubic_root(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
result=cbrt(parcel1);
display_text = QString::number(result);
display->setText(display_text);
                             };

//VALOR ABSOLUTO DE UM NÚMERO               
void Calculator::absolute(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
if(parcel1>=0)
result=parcel1;
if(parcel1<0)
result=(-1.0)*parcel1;
display_text = QString::number(result);
display->setText(display_text);
                           };

//FATORIAL DE UM NÚMERO INTEIRO
void Calculator::factorial(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
n_value=display_text.toInt();
n_factorial=1;
int i=1; //VARIÁVEL LOCAL

while(i<=n_value){
n_factorial=n_factorial*i;
++i;
                };

display_text = QString::number(n_factorial);
display->setText(display_text);
                            };

//INVERSO DE UM NÚMERO
void Calculator::inverse(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
result=(1.0)/parcel1;
display_text = QString::number(result);
display->setText(display_text);
                          };

//CÁLCULOS DE PORCENTAGEM
void Calculator::percent(){
QString display_text = display->text();/*VARIÁVEL LOCAL*/
parcel1=display_text.toDouble();
ad=false;
su=false;
mu=false;
di=false;
pe=true;
display->setText("");
                          };

//ATIVANDO O OPERADOR '=' PARA EXIBIR RESULTADO DE OPERAÇÕES ENVOLVENDOS DUAS PARCELAS
void Calculator::equal(){
//AJUSTANDO VARIÁVEIS
QString display_text = display->text();/*VARIÁVEL LOCAL*/
display_text.append(".0");
parcel2=display_text.toDouble();

//EXIBINDO MENSAGEM DE ERRO AO TENTAR DIVISÃO POR ZERO
if(di==true && parcel2==0)
zero_division();

//EXECUTANDO A OPERAÇÃO SELECIONADA
if(ad==true && su==false && mu==false && di==false)
result=parcel1+parcel2;
if(ad==false && su==true && mu==false && di==false)
result=parcel1-parcel2;
if(ad==false && su==false && mu==true && di==false)
result=parcel1*parcel2;
if(ad==false && su==false && mu==false && di==true)
result=parcel1/parcel2;

if(pe==true){
result=parcel1*parcel2;
result=result/100.0;
            };

//EXBINDO RESULTADO NO DISPLAY DA CALCULADORA
display_text=QString::number(result);
display->setText(display_text);
                        };

//FUNÇÃO QUE ALERTA A TENTATIVA DE DIVISÃO POR ZERO
void Calculator::zero_division(){
QMessageBox::warning(this, "ERRO CRÍTICO!", "Impossível efetuar a divisão por zero!\n");
                    };
//FUNÇÕES DE USO GERAL
//SOBRE A APLICAÇÃO
void Calculator::about(){
QMessageBox::about(this, "Sobre o Aplicativo Calculadora básica - versão 1.0","Este é um aplicativo básico para performar operações matemáticas elementares.\nPara críticas e sugestões de melhorias entrar em contato com:\ne.r.emidio@yandex.com");
                        };


//AJUDA
void Calculator::help(){
QDesktopServices::openUrl(QUrl::fromLocalFile("ajuda.txt"));
                       };
