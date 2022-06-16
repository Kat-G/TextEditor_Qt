#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QtWidgets>
#include <QFile>
#include <QDir>
#include <QPushButton>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <QKeyEvent>
#include <QSyntaxHighlighter>
#include <QTextCursor>
#include <locale>
#include <qapplication.h>
#include <QRegularExpression>
#include "TText.h"
#include "TTextLink.h"

namespace Ui { class Widget; }
class Widget : public QWidget {
    Q_OBJECT
    Ui::Widget *ui;
public:
    Widget(QWidget *parent = 0);
private:
    TText Text;

    const QStringList types = { "int ", "char ", "double ", "float", "bool ", "void " };
    const QStringList funcs = { "if", "while","else","for","return " };
    void ReadAll();
    bool Validator(std::string text) const;
    bool IsStringEnded(std::string text) const;
    std::string UpdateString(std::string line);
    void UpdateTree();
private slots: //слоты для действий, выполняемых по кнопкам
    void ButtonOpen();
    void ButtonSave();
    void ButtonRep();
};
#endif // WIDGET_H
