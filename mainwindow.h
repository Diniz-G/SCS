#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include <QFileDialog>
#include <QInputDialog>

#include "programa.h"
#include "laboratorio.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_btnAddLab_clicked();

    void on_btnAddProg_clicked();

    void on_inputNomeLab_returnPressed();

    void on_inputQuantidade_returnPressed();

    void on_inputMemoria_returnPressed();

    void on_inputNomeProg_returnPressed();

    void on_inputVersao_returnPressed();

    void on_inputTamanho_returnPressed();

    void on_btnOrdenarNome_clicked();

    void on_btnOrdenarTamanho_clicked();

    void on_btnOrdenarFuncao_clicked();

    void on_btnExcluirProg_clicked();

    void on_tabela2_cellDoubleClicked(int row, int column);

    void on_btnLimparTab_clicked();

    void on_btnAtualizarTab_clicked();

    void on_actionSalvar_triggered();

    void on_actionCarregar_triggered();

    void on_progressBar_valueChanged();

    void on_progressBar_2_valueChanged();

private:
    Ui::MainWindow *ui;
    void inserirNaTabela2(Programa p, int linha);
};
#endif // MAINWINDOW_H
