#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>

using namespace std;

string abecedario="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
string numeros="1234567890";
string aux[] = {"vector","for","while","escalar","print","verdadero","falso","else"};
vector<string> palabras_reservadas (aux, aux + sizeof(aux) / sizeof(string) );



char getchar(const char* &pointer)
{
  char rpta=*pointer;
  pointer++;
  return rpta;
}
char peekchar(const char* &pointer)
{
  char rpta=*pointer;
  return rpta;
}

bool is_something(string abecedario,char actual)
{
  return abecedario.find(actual) < abecedario.length() && abecedario.find(actual) >= 0;
}

string all_the_token(const char* &pointer, string abecedario, string salida, char actual)
{
  salida.push_back(actual);
  while(abecedario.find(peekchar(pointer)) < abecedario.length() || abecedario.find(peekchar(pointer)) < 0)
    {
      char actual=getchar(pointer);
      salida.push_back(actual);
    }
  return salida;
}


void scanner(string cadena, int conteo_filas)
{
  string salida="";
  const char* pointer = cadena.c_str();
  char actual;
  int contador_debug=1;
  
  while(contador_debug<=cadena.length())
    {   
      actual=getchar(pointer);
      if(is_something(abecedario,actual)) //es una letra
      {
        salida=all_the_token(pointer,abecedario,salida, actual);
        if(find(palabras_reservadas.begin(), palabras_reservadas.end(), salida) != palabras_reservadas.end())
        {
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - "<<salida<<" [ "<<salida<<" ] encontrado en (1:"<<contador_debug<<")"<<endl;
          
        }
        else
        {
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - ID [ "<<salida<<" ] encontrado en (1:"<<contador_debug<<")"<<endl;
        
        }
        salida="";
        
      }
      else if(is_something(numeros,actual)) //es un numero
      {
        salida=all_the_token(pointer,numeros,salida, actual);
        contador_debug=contador_debug+salida.length();
        cout<<"DEBUG SCAN - NUMBER [ "<<salida<<" ] encontrado en (1:"<<contador_debug<<")"<<endl;
        salida="";
      }
      else if(actual==':')
      {
        salida.push_back(actual);
        if(peekchar(pointer)=='=')
        {
          actual=getchar(pointer);
          salida.push_back(actual);
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - ASSIGN OP [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
        else
        {
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - ERROR [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
      }
      else if(actual=='/')
      {
        salida.push_back(actual);
        if(peekchar(pointer)=='/')
        {
          actual=getchar(pointer);
          salida.push_back(actual);
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - COMMENT [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
        else
        {
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - DIVISION [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
      }
      else if(actual=='+')
      {

        salida.push_back(actual);
        if(peekchar(pointer)=='+')
        {
          actual=getchar(pointer);
          salida.push_back(actual);
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - ADITTION IN ONE [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
        else
        {
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - ADITTION [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
        
      }
      else if(actual=='.')
      {
        salida.push_back(actual);
        contador_debug=contador_debug+salida.length();
        cout<<"DEBUG SCAN - POINT PRODUCT OP [ "<<salida<<" ] encontrado en (1:"<<contador_debug<<")"<<endl;
        salida="";
        
      }
      else if(actual=='-')
      {
        salida.push_back(actual);
        contador_debug=contador_debug+salida.length();
        cout<<"DEBUG SCAN - SUBTRACTION OP [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
        salida="";
        
      }
      else if(actual=='{')
      {
        salida.push_back(actual);
        contador_debug=contador_debug+salida.length();
        cout<<"DEBUG SCAN - OPEN BLOCK [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
        salida="";
        
      }
      else if(actual=='}')
      {
        salida.push_back(actual);
        contador_debug=contador_debug+salida.length();
        cout<<"DEBUG SCAN - CLOSE BLOCK [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
        salida="";
        
      }
      else if(actual=='(')
      {

        salida.push_back(actual);
        contador_debug=contador_debug+salida.length();
        cout<<"DEBUG SCAN - OPEN PARENTHESIS [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
        salida="";
        
      }
      else if(actual==')')
      {
        salida.push_back(actual);
        contador_debug=contador_debug+salida.length();
        cout<<"DEBUG SCAN - CLOSE PARENTHESIS [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
        salida="";
        
      }
      else if(actual==';')
      {
        salida.push_back(actual);
        contador_debug=contador_debug+salida.length();
        cout<<"DEBUG SCAN - SEMICOLON [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
        salida="";
        
      }
      else if(actual=='<')
      {
        salida.push_back(actual);
        contador_debug=contador_debug+salida.length();
        if(peekchar(pointer)=='=')
        {
          actual=getchar(pointer);
          salida.push_back(actual);
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - LESS THAN OR EQUAL TO [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
        else
        {
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - LESS THAN OP [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
        
        
      }
      else if(actual=='>')
      {
        salida.push_back(actual);
        contador_debug=contador_debug+salida.length();
        if(peekchar(pointer)=='=')
        {
          actual=getchar(pointer);
          salida.push_back(actual);
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - GREATER THAN OR EQUAL TO [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
        else
        {
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - GREATER THAN OP [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
        
        
      }
       else if(actual=='=')
      {
        salida.push_back(actual);
        if(peekchar(pointer)=='=')
        {
          actual=getchar(pointer);
          salida.push_back(actual);
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - EQUAL OP [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
        else
        {
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - ERROR [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
      
      }
      else if(actual=='!')
      {
        salida.push_back(actual);
        if(peekchar(pointer)=='=')
        {
          actual=getchar(pointer);
          salida.push_back(actual);
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - NOT EQUAL OP [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
        else
        {
          contador_debug=contador_debug+salida.length();
          cout<<"DEBUG SCAN - NOT OP [ "<<salida<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
          salida="";
        }
      
      }
        else if(actual==' ')
      {

        contador_debug++;
      }
      else
      {
        cout<<"DEBUG SCAN - ERROR [ "<<actual<<" ] encontrado en ("<<conteo_filas<<":"<<contador_debug<<")"<<endl;
        contador_debug++;
      }
    }
    
  
  
}
void gettoken(string filename)
{
  vector<string> lines;
  string line;
  string entrada;

  ifstream input_file(filename);
  if (!input_file.is_open()) {
      cerr << "Could not open the file - '"
           << filename << "'" << endl;
  }
  int contador=1;
  while (getline(input_file, line)){
      scanner(line,contador);
    contador++;
  }
}
int main() {
  gettoken("test.txt");
  

  
}