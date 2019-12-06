#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "laboratorio.h"
#include "programa.h"

Laboratorio lab;
Programa prog;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAddLab_clicked()
{
    lab.inicializador();

    qDebug() << lab.getEspacoEmUso();

    if((ui->inputNomeLab->text()!="") and (ui->inputQuantidade->text()!="") and (ui->inputMemoria->text()!="")){
        if(!lab.setNome(ui->inputNomeLab->text())){
            ui->label_21->setText("*");
            QMessageBox :: warning (this, "Nome inválido", "Insira pelo menos 3 letras.");
        }else{
            ui->label_21->setText(" ");
            ui->label_16->setText(ui->inputNomeLab->text());
            lab.setNome(ui->inputNomeLab->text());
        }
        if(!lab.setQuantidade(ui->inputQuantidade->text().toInt())){
            ui->label_22->setText("*");
            QMessageBox :: warning (this, "Quantidade inválida", "Tente novamente.");
        }else{
            ui->label_22->setText(" ");
            ui->label_17->setText(ui->inputQuantidade->text());
            lab.setQuantidade(ui->inputQuantidade->text().toInt());
        }
        if(!lab.setMemoria(ui->inputMemoria->text().toFloat())){
            ui->label_23->setText("*");
            QMessageBox :: warning (this, "Valor de memória inválido", "Tente novamente.");
        }else{
            ui->label_23->setText(" ");
            ui->label_18->setText(ui->inputMemoria->text());
            lab.setMemoria(ui->inputMemoria->text().toFloat());
        }

       ui->btnAddLab->setText("Alterar Laboratório");

    }else{
        QMessageBox :: warning (this, "Parâmetro vazio", "Tente novamente.");
    }

    ui->inputNomeLab->clear();
    ui->inputQuantidade->clear();
    ui->inputMemoria->clear();
}

void MainWindow::inserirNaTabela2(Programa p, int linha){
    ui->tabela2->setItem(linha,0, new QTableWidgetItem(p.getNome()));
    ui->tabela2->setItem(linha,1, new QTableWidgetItem(p.getVersao()));
    ui->tabela2->setItem(linha,2, new QTableWidgetItem(QString::number(p.getTamanho())));
    ui->tabela2->setItem(linha,3, new QTableWidgetItem(p.getFuncao()));
}

void MainWindow::on_btnAddProg_clicked()
{
    if((ui->inputNomeProg->text()!="") and (ui->inputVersao->text()!="") and (ui->inputTamanho->text()!="")){
        if (prog.setNome(ui->inputNomeProg->text())==1 and
            prog.setTamanho(ui->inputTamanho->text().toFloat())==1 and
            prog.setFuncao(ui->inputFuncao->currentText())==1){

            prog.setNome(ui->inputNomeProg->text());
            prog.setVersao(ui->inputVersao->text());
            prog.setTamanho(ui->inputTamanho->text().toFloat());
            prog.setFuncao(ui->inputFuncao->currentText());

            if(lab.programaExistente(prog)==1 or lab.setEspacoEmUso(prog.getTamanho())==0){
                QMessageBox::critical(this, "ERRO", "Programa já cadastrado ou tamanho do programa excede a capacidade do computador.");
            }else{
                lab.inserirPrograma(prog);
                int quantidade_linhasp = ui->tabela2->rowCount();
                ui->tabela2->insertRow(quantidade_linhasp);
                inserirNaTabela2(prog, quantidade_linhasp);
                QMessageBox :: information(this, "Programa Adicionado", "Programa adicionado com sucesso!");
                on_progressBar_valueChanged();
                on_progressBar_2_valueChanged();
                qDebug() << lab.getEspacoEmUso();
            }

        }else{
            QMessageBox :: warning(this,"Programa não inserido", "Reveja os dados fornecidos.");
        }

        if(!prog.setNome(ui->inputNomeProg->text())){
            ui->label_20->setText("*");
            QMessageBox :: warning (this, "Nome inválido", "Insira pelo menos 3 letras.");
        }else{
            ui->label_20->setText(" ");
        }

        if(!prog.setVersao(ui->inputVersao->text())){
            ui->label_11->setText("*");
            QMessageBox :: warning (this, "Função não inserida", "Insira a função do programa.");
        }else{
            ui->label_11->setText(" ");
        }

        if(!prog.setTamanho(ui->inputTamanho->text().toFloat())){
            ui->label_19->setText("*");
            QMessageBox :: warning (this, "Tamanho inválido", "O tamanho do programa deve ser um inteiro maior que 0.");
        }else{
            ui->label_19->setText(" ");
        }

        ui->inputNomeProg->clear();
        ui->inputVersao->clear();
        ui->inputTamanho->clear();
    }
}

void MainWindow::on_inputNomeLab_returnPressed()
{
    ui->inputQuantidade->setFocus();
}

void MainWindow::on_inputQuantidade_returnPressed()
{
    ui->inputMemoria->setFocus();
}

void MainWindow::on_inputMemoria_returnPressed()
{
    ui->btnAddLab->click();
}

void MainWindow::on_inputNomeProg_returnPressed()
{
    ui->inputVersao->setFocus();
}

void MainWindow::on_inputVersao_returnPressed()
{
    ui->inputTamanho->setFocus();
}

void MainWindow::on_inputTamanho_returnPressed()
{
    ui->inputFuncao->showPopup();
}

void MainWindow::on_btnOrdenarNome_clicked()
{
    lab.ordenarPorNome();
    ui->tabela2->clearContents();
    for(int i=0; i<lab.size(); i++){
         inserirNaTabela2(lab[i],i);
     }
}

void MainWindow::on_btnOrdenarTamanho_clicked()
{
    lab.ordenarPorTamanho();
    ui->tabela2->clearContents();
    for(int i=0; i<lab.size(); i++){
         inserirNaTabela2(lab[i],i);
     }
}

void MainWindow::on_btnOrdenarFuncao_clicked()
{
    lab.ordenarPorFuncao();
    ui->tabela2->clearContents();
    for(int i=0; i<lab.size(); i++){
        inserirNaTabela2(lab[i], i);
    }
}

void MainWindow::on_btnExcluirProg_clicked()
{
    QMessageBox::StandardButton resp = QMessageBox::question(this, "Excluir Programa", "Tem certeza que deseja excluir um programa?");
    if(resp == QMessageBox::Yes){
        bool ok;
        QString texto = QInputDialog::getText(this, "Excluir Programa", "Qual programa deseja excluir?", QLineEdit::Normal,"",&ok);
        if(lab.apagarPrograma(texto)==true){
            on_btnLimparTab_clicked();
            for(int i=0; i<lab.size(); i++){
                ui->tabela2->insertRow(ui->tabela2->rowCount());
                inserirNaTabela2(lab[i], i);
                on_progressBar_valueChanged();
                on_progressBar_2_valueChanged();
                qDebug() << lab.getEspacoEmUso();
            }
            QMessageBox::information(this, "Programa Excluído", "O programa foi excluído com sucesso!");
        }else{
            QMessageBox::warning(this, "Erro", "Erro: programa inexistente.");
        }
    }
}

void MainWindow::on_tabela2_cellDoubleClicked(int row, int column)
{
    if(column == 0){
        QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Nome", "Você deseja alterar o nome?");
        if(resp == QMessageBox::Yes){
            bool ok;
            QString texto = QInputDialog::getText(this, "Alterar Nome", "Insira o novo nome:", QLineEdit::Normal,"",&ok);
            prog.setNome(texto);
            prog.setFuncao(lab[row].getFuncao());
            prog.setVersao(lab[row].getVersao());
            prog.setTamanho(lab[row].getTamanho());
            lab.apagarProgramaPorNome(texto, row);
            lab.inserirPrograma(prog);
            ui->tabela2->setItem(row, column, new QTableWidgetItem(prog.getNome()));
            on_btnAtualizarTab_clicked();
        }
    }
    if(column == 1){
        QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Versão", "Você deseja alterar a versão?");
        if(resp == QMessageBox::Yes){
            bool ok;
            QString texto = QInputDialog::getText(this, "Alterar Versão", "Insira a nova versão:", QLineEdit::Normal,"",&ok);
            prog.setVersao(texto);
            prog.setFuncao(lab[row].getFuncao());
            prog.setNome(lab[row].getNome());
            prog.setTamanho(lab[row].getTamanho());
            lab.apagarProgramaPorVersao(texto, row);
            lab.inserirPrograma(prog);
            ui->tabela2->setItem(row, column, new QTableWidgetItem(prog.getVersao()));
            on_btnAtualizarTab_clicked();
        }
    }
    if(column == 2){
        QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Tamanho", "Você deseja alterar o tamanho?");
        if(resp == QMessageBox::Yes){
            bool ok;
            QString texto = QInputDialog::getText(this, "Alterar Tamanho", "Insira o novo tamanho:", QLineEdit::Normal,"",&ok);
            lab.alterarEspacoEmUso(texto.toFloat(), row);
            prog.setTamanho(texto.toFloat());
            prog.setFuncao(lab[row].getFuncao());
            prog.setVersao(lab[row].getVersao());
            prog.setNome(lab[row].getNome());
            lab.apagarProgramaPorTamanho(texto, row);
            lab.inserirPrograma(prog);
            ui->tabela2->setItem(row, column, new QTableWidgetItem(prog.getTamanho()));
            on_btnAtualizarTab_clicked();
            on_progressBar_valueChanged();
            on_progressBar_2_valueChanged();
            qDebug() << "espaço em uso: " << lab.getEspacoEmUso() << endl;
        }
    }
    if(column == 3){
        QMessageBox::StandardButton resp = QMessageBox::question(this, "Editar Função", "Você deseja alterar a função?");
        if(resp == QMessageBox::Yes){
            bool ok;
            QString texto = QInputDialog::getText(this, "Alterar Função", "Insira a função:", QLineEdit::Normal,"",&ok);
            prog.setFuncao(texto);
            prog.setTamanho(lab[row].getTamanho());
            prog.setVersao(lab[row].getVersao());
            prog.setNome(lab[row].getNome());
            lab.apagarProgramaPorFuncao(texto, row);
            lab.inserirPrograma(prog);
            ui->tabela2->setItem(row, column, new QTableWidgetItem(prog.getFuncao()));
            on_btnAtualizarTab_clicked();
        }
    }
}

void MainWindow::on_btnLimparTab_clicked()
{
    int l = ui->tabela2->rowCount();
    for(int i=0; i<l; i++){
        ui->tabela2->removeRow(0);
    }
}

void MainWindow::on_btnAtualizarTab_clicked()
{
    on_btnLimparTab_clicked();
    for(int i=0; i<lab.size(); i++){
        ui->tabela2->insertRow(ui->tabela2->rowCount());
        inserirNaTabela2(lab[i],i);
    }
}

void MainWindow::on_actionSalvar_triggered()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this,"Salvar Arquivo",lab.getNome(),"*.csv");
    if(lab.salvarDados(filename)==true){
        QMessageBox::information(this,"Arquivo Salvo","Arquivo salvo com sucesso!");
    }else{
        QMessageBox::critical(this, "Erro ao salvar", "O arquivo não foi salvo.");
    }

}

void MainWindow::on_actionCarregar_triggered()
{
    lab.apagarTudo();
    QString filename;
    filename = QFileDialog::getOpenFileName(this, "Abrir Arquivo","","*.csv");
    if(lab.carregarDados(filename)==true){
        ui->tabela2->clearContents();
        on_btnLimparTab_clicked();
        for(int i=0; i<lab.size(); i++){
            ui->tabela2->insertRow(i);
            inserirNaTabela2(lab[i], i);
            ui->label_4->setText("Memória interna adicional disponível(GB):");
        }
        on_btnAtualizarTab_clicked();
        QMessageBox::information(this, "Arquivo Carregado", "Arquivo carregado com sucesso!");
    }else{
        QMessageBox::critical(this, "Erro ao carregar", "O arquivo não foi carregado.");
    }
}

void MainWindow::on_progressBar_valueChanged()
{
    ui->progressBar->setRange(0, lab.getMemoria());
    ui->progressBar->setValue(lab.getEspacoEmUso());
}

void MainWindow::on_progressBar_2_valueChanged()
{
    ui->progressBar_2->setRange(0, lab.getMemoria());
    ui->progressBar_2->setValue(lab.getEspacoEmUso());
}
