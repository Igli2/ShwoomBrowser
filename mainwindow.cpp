#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWebFrame>
#include <QWebElementCollection>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->webView->setUrl(QUrl{"https://en.wikipedia.org/wiki/Mushroom"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_new_url()
{
    QUrl url{ui->lineEdit->text()};
    ui->webView->setUrl(url);
}

void MainWindow::apply_shwoom()
{
    std::cout << "Shwoom" << std::endl;
    QWebFrame* web_frame = ui->webView->page()->mainFrame();
    web_frame->evaluateJavaScript(
                "var colors = [\"red\", \"darkorange\", \"yellow\", \"lime\", \"green\", \"aqua\", \"teal\", \"blue\", \"purple\", \"fuchsia\"];"
                "var cc = 0;"
                "var all = document.body.getElementsByTagName('*');"
                "document.body.style.backgroundColor=\"black\";"
                "for (var i = 0; i < all.length; i++) {"
                "   all[i].style.color=colors[cc];"
                "   all[i].style.backgroundColor=\"black\";"
                "   cc += 1;"
                "   if (cc == colors.length) {"
                "       cc = 0;"
                "   }"
                "}"
    );
}

void MainWindow::on_link_clicked()
{
    QString url = ui->webView->url().toString();
    ui->lineEdit->setText(url);
}
