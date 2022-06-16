#include "widget.h"
#include "treemodel.h"
#include "ui_widget.h"

char filename[] = "default.txt";
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
	ui->setupUi(this);
	Q_INIT_RESOURCE(simpletreemodel);
	setlocale(LC_ALL, 0);
	connect(ui->ButOpen, SIGNAL(released()), this, SLOT(ButtonOpen()));
	connect(ui->ButSave, SIGNAL(released()), this, SLOT(ButtonSave()));
	connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(ButtonRep()));
}


void Widget::UpdateTree() {
	//Получаем предустановленное "дерево" в file:
	QFile file(filename);
	file.open(QIODevice::ReadOnly);
	//Создаем заголовки столбцов:
	QStringList headers;
	headers << tr("Заголовок");// << tr("Описание");
	//Загружаем данные в модель:
	TreeModel* model = new TreeModel(headers, file.readAll());
	file.close();
	ui->treeView->setModel(model);/*
	for (int column = 0; column < model->columnCount(); ++column) ui->treeView->resizeColumnToContents(column);*/
}

void Widget::ButtonOpen()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
		tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

	if (fileName != "") {
		QFile file(fileName);
		if (!file.open(QIODevice::ReadOnly)) {
			QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
			return;
		}
		QTextStream in(&file);
		ui->textEdit->setText(in.readAll());
		ButtonRep();
		//UpdateTree()
		file.close();
	}
}

//Условия выполнения: { находится в строке с кодом, } находится на новой строке
void Widget::ReadAll()
{
	std::string tmp;
	QTextCursor cursor = ui->textEdit->textCursor();
	cursor.select(QTextCursor::SelectionType::Document);
	tmp = cursor.selectedText().toStdString();
	size_t n = std::count(tmp.begin(), tmp.end(), '{');
	n += std::count(tmp.begin(), tmp.end(), '}');
	n += std::count(tmp.begin(), tmp.end(), ';');

	cursor.movePosition(QTextCursor::Start);
	std::string text;
	char control_char, cont;
	std::stack<char> control;
	cursor.select(QTextCursor::SelectionType::LineUnderCursor);
	text = cursor.selectedText().toStdString();
	cursor.clearSelection();
	if (text[text.length() - 1] == '{') {
		control.push(text[text.length() - 1]);
		text.pop_back();
	}
	else {
		control.push('\n');
	}
	TTextLink::IntMemSystem(40);
	PTTextLink tl = new TTextLink(UpdateString(text).c_str());
	TText ntext(tl);
	cursor.movePosition(QTextCursor::Down);
	int i = 0;
	while (i < n - 1)
	{
		cursor.select(QTextCursor::LineUnderCursor);
		text = cursor.selectedText().toStdString();
		cursor.clearSelection();
		if (text[text.length() - 1] == '{') {
			control_char = text[text.length() - 1];
			text.pop_back();
		}
		else if (text[text.length() - 1] == '}') {
			control_char = text[text.length() - 1];
		}
		else {
			control_char = '\n';
		}
		cont = control.top();
		if (cont == '{')
		{
			ntext.InsDownLine(UpdateString(text));
			ntext.GoDownLink();
		}
		else if (cont == '\n')
		{
			if (control_char != '}') {
				ntext.InsNextLine(UpdateString(text));
				ntext.GoNextLink();
			}
		}
		else if (cont == '}')
		{
			control.pop();
			while (control.top() != '{') {
				ntext.GoPrevLink();
				control.pop();
			}
			control.pop();
			ntext.InsNextLine(UpdateString(text));
			ntext.GoNextLink();
		}
		control.push(control_char);
		cursor.movePosition(QTextCursor::Down);
		i++;
	}

	Text = *ntext.getCopy();

	Text.Write(filename);
	text = "";
}


void Widget::ButtonSave()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
		tr("Text Files (*.txt);;C++ Files (*.cpp *.h)"));

	if (fileName != "") {
		QFile file(fileName);
		if (!file.open(QIODevice::WriteOnly)) {
			// error message
		}
		else {
			QTextStream stream(&file);
			stream << ui->textEdit->toPlainText();
			stream.flush();
			file.close();

		}
	}
}

void Widget::ButtonRep()
{
	disconnect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(ButtonRep()));

	QString text = ui->textEdit->toPlainText();
	QTextCursor cursor = ui->textEdit->textCursor();
	cursor.movePosition(QTextCursor::Start);
	for (int i = 0; i < text.size(); ++i) {
		cursor.movePosition(QTextCursor::NextWord, QTextCursor::KeepAnchor);
		QTextCharFormat fmt;
		for (int j = 0; j < types.size(); j++) {
			if (cursor.selectedText() == types[j])
			{
				fmt.setForeground(QColor(0, 100, 200));
				cursor.mergeCharFormat(fmt);
				ui->textEdit->mergeCurrentCharFormat(fmt);

			}
		}
		for (int j = 0; j < funcs.size(); j++) {
			if (cursor.selectedText() == funcs[j])
			{
				fmt.setForeground(QColor(168, 47, 255));
				cursor.mergeCharFormat(fmt);
				ui->textEdit->mergeCurrentCharFormat(fmt);

			}
		}
		cursor.movePosition(QTextCursor::PreviousCharacter, QTextCursor::MoveAnchor);
		cursor.movePosition(QTextCursor::NextWord, QTextCursor::MoveAnchor);
		fmt.setForeground(QColor(0, 0, 0));
		cursor.mergeCharFormat(fmt);
		ui->textEdit->mergeCurrentCharFormat(fmt);
	}
	if (Validator(text.toStdString()) && IsStringEnded(text.toStdString())) {
		ReadAll();
		UpdateTree();
	}
	connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(ButtonRep()));
}

bool Widget::Validator(std::string text) const
{
	std::stack<char> stack;
	size_t i;
	for (i = 0; i < text.length(); i++) {
		if (text[i] == '{') {
			stack.push(text[i]);
		}
		else {
			if (text[i] == '}' && !stack.empty())
				stack.pop();
		}
	}
	if (stack.empty()) {
		return true;
	}
	else {
		return false;
	}
}

bool Widget::IsStringEnded(std::string text) const
{
	size_t n = std::count(text.begin(), text.end(), '\n');
	if (n > 0) {
		std::string tmp = "";
		for (int i = 0; i < text.length(); i++) {
			if (text[i] != '\n') {
				tmp += text[i];
			}
			else {
				if (tmp != "" && (tmp[tmp.length() - 1] == ';' || tmp[tmp.length() - 1] == '{' || tmp[tmp.length() - 1] == '}')) {
					tmp = "";
				}
				else {
					return false;
				}
			}
		}
		if (tmp=="" || tmp[tmp.length() - 1] == '}')
			return true;
		else  
			return false;
	}
	else {
		if (text == "")
			return false;
		if (text[text.length() - 1] != ';' && text[text.length() - 1] != '{' && text[text.length() - 1] != '}')
			return false;
		else
			return true;
	}
}

std::string Widget::UpdateString(std::string line)
{
	std::string newline;
	size_t n = std::count(line.begin(), line.end(), '\t');
	for (int i = 0; i < n; i++)
	{
		newline += ' ';
	}
	for (int i = n; i < line.length(); i++)
	{
		newline += line[i];
	}
	return newline;
}