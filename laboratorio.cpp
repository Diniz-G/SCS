#include "laboratorio.h"

QString Laboratorio::getNome() const
{
    return nome;
}

bool Laboratorio::setNome(const QString &value)
{
    if(value.size()>=3){ // exemplo: Lab1, Lab2;
        nome = value;
        return true;
    }else return false;
}

int Laboratorio::getQuantidade() const
{
    return quantidade;
}

bool Laboratorio::setQuantidade(int value)
{
    if(value>0){
    quantidade = value;
    return true;
    }else return false;
}

float Laboratorio::getMemoria() const
{
    return memoria;
}

bool Laboratorio::setMemoria(float value)
{
    if(value>0){
    memoria = value;
    return true;
    }else return false;
}

void Laboratorio::inserirPrograma(Programa p)
{
    programas.push_back(p);
}

bool Laboratorio::programaExistente(Programa prog)
{
    if(programas.size() >= 1){
            for(int i = 0; i < programas.size(); i++){
                if(prog.getNome() == programas[i].getNome()){
                    return true;
                }
            }
    }else return false;
}

void Laboratorio::ordenarPorNome()
{
    std::sort(programas.begin(), programas.end(), [](Programa a, Programa b){
        return a.getNome()<b.getNome();
    });
}

void Laboratorio::ordenarPorTamanho()
{
    std::sort(programas.begin(), programas.end(), [](Programa a, Programa b){
        return a.getTamanho()<b.getTamanho();
    });
}

void Laboratorio::ordenarPorFuncao()
{
    std::sort(programas.begin(), programas.end(), [](Programa a, Programa b){
        return a.getFuncao()<b.getFuncao();
    });
}

Programa Laboratorio::operator[](int indice)
{
    return programas[indice];
}

int Laboratorio::size()
{
    return programas.size();
}

bool Laboratorio::apagarPrograma(QString a)
{
    for(int i=0; i<programas.size(); i++){
        if(programas[i].getNome()==a){
            liberarEspaco(programas[i].getTamanho());
            programas.erase(programas.begin()+i);
        }
    }return true;
}

void Laboratorio::apagarTudo()
{
    programas.erase(programas.begin(),programas.end());
}

void Laboratorio::apagarProgramaPorNome(QString a, int i)
{
    if(programas[i].getNome() != a){
        programas.erase(programas.begin()+i);
    }
}

void Laboratorio::apagarProgramaPorVersao(QString a, int i)
{
    if(programas[i].getVersao() != a){
        programas.erase(programas.begin()+i);
    }
}

void Laboratorio::apagarProgramaPorTamanho(QString a, int i)
{
    if(programas[i].getTamanho() != a.toFloat()){
        programas.erase(programas.begin()+i);
    }
}

void Laboratorio::apagarProgramaPorFuncao(QString a, int i)
{
    if(programas[i].getFuncao() != a){
        programas.erase(programas.begin()+i);
    }
}

void Laboratorio::inicializador()
{
    espacoEmUso = 0;
}

bool Laboratorio::alterarEspacoEmUso(float f, int row)
{
    if(f < programas[row].getTamanho() and f>0){
        espacoEmUso -= programas[row].getTamanho() - f;
        return true;
    }else if(f > programas[row].getTamanho() and f>0){
        espacoEmUso += f - programas[row].getTamanho();
        return true;
    }else return false;
}

void Laboratorio::liberarEspaco(float value)
{
    espacoEmUso -= value;
}

bool Laboratorio::salvarDados(QString arq)
{
    QFile arquivo(arq);
    arquivo.open(QIODevice::WriteOnly);
    if(arquivo.isOpen()==1){
        for(auto i:programas){
            QString linha = i.getNome() + "," + i.getVersao() + "," + QString::number(i.getTamanho()) + "," + i.getFuncao() + "\r\n";
            arquivo.write(linha.toLocal8Bit());
        }
        arquivo.close();
        return true;
    }else return false;
}

bool Laboratorio::carregarDados(QString arq)
{
    QFile arquivo(arq);
    arquivo.open(QIODevice::ReadOnly);
    QString linha;
    QStringList dados;
    //Laboratorio labt;
    if(arquivo.isOpen()==1){
        while(!arquivo.atEnd()){
            Programa temp;
            linha = arquivo.readLine();
            dados = linha.split(",");
            temp.setNome(dados[0]);
            temp.setVersao(dados[1]);
            temp.setTamanho(dados[2].toFloat());
            temp.setFuncao(dados[3]);
            inserirPrograma(temp);
        }
        arquivo.close();
        return true;
    }else return false;
}

float Laboratorio::getEspacoEmUso() const
{
    return espacoEmUso;
}

bool Laboratorio::setEspacoEmUso(float value)
{
    if(memoria>=getEspacoEmUso()+value){
        espacoEmUso += value;
        return true;
    }else return false;
}

Laboratorio::Laboratorio()
{

}
