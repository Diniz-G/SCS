#ifndef PROGRAMA_H
#define PROGRAMA_H

//#include "laboratorio.h"
#include <QObject>

class Programa
{
    QString nome;
    float tamanho;
    QString funcao;
    QString versao;

public:
    Programa();
    QString getNome() const;
    bool setNome(const QString &value);
    float getTamanho() const;
    bool setTamanho(float value);
    QString getFuncao() const;
    bool setFuncao(const QString &value);
    QString getVersao() const;
    bool setVersao(const QString &value);
};

#endif // PROGRAMA_H
