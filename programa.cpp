#include "programa.h"

QString Programa::getNome() const
{
    return nome;
}

bool Programa::setNome(const QString &value)
{
    if(value.size()>=3){
        nome = value;
        return true;
    }else return false;
}

float Programa::getTamanho() const
{
    return tamanho;
}

bool Programa::setTamanho(float value)
{
    if(value>0){
    tamanho = value;
    return true;
    }else return false;
}

QString Programa::getFuncao() const
{
    return funcao;
}

bool Programa::setFuncao(const QString &value)
{
    if(value.size()>=3){
        funcao = value;
        return true;
    }else return false;
}

QString Programa::getVersao() const
{
    return versao;
}

bool Programa::setVersao(const QString &value)
{
    versao = value;
    return true;
}

Programa::Programa()
{

}
