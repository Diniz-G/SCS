#ifndef LABORATORIO_H
#define LABORATORIO_H

#include "programa.h"
#include <QObject>
#include <QVector>
#include <algorithm>
#include <QFile>
#include <QStringList>
#include <QDebug>

class Laboratorio
{
private:
    QString nome;
    int quantidade;
    float memoria;
    QVector <Programa> programas;
    float espacoEmUso;

public:
    Laboratorio();
    QString getNome() const;
    bool setNome(const QString &value);
    int getQuantidade() const;
    bool setQuantidade(int value);
    float getMemoria() const;
    bool setMemoria(float value);
    float getEspacoEmUso() const;
    bool setEspacoEmUso(float value);

    void inserirPrograma(Programa prog);
    bool programaExistente(Programa prog);
    void ordenarPorNome();
    void ordenarPorTamanho();
    void ordenarPorFuncao();
    Programa operator[](int i);
    int size();
    bool apagarPrograma(QString a);
    void liberarEspaco(float value);
    void apagarTudo();
    void apagarProgramaPorNome(QString a, int i);
    void apagarProgramaPorVersao(QString a, int i);
    void apagarProgramaPorTamanho(QString a, int i);
    void apagarProgramaPorFuncao(QString a, int i);
    void inicializador();
    bool alterarEspacoEmUso(float f, int row);

    bool salvarDados(QString arq);
    bool carregarDados(QString arq);
};

#endif // LABORATORIO_H
