#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class QLineEdit;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUi();

public slots:
    void on_sendBtn_clicked();

private:
    QLineEdit *m_in0;
    QLineEdit *m_in1;
    QLineEdit *m_in2;
    QLineEdit *m_in3;
    QLineEdit *m_in4;
    QLineEdit *m_in5;
    QLineEdit *m_in6;
    QLineEdit *m_in8;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
