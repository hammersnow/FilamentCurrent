#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QString"
#include "QTextStream"
#include "QDate"
#include "QDateEdit"
#include "QIODevice"
#include "QDebug"
#include "QStringList"
#include "QTextCursor"
#include "QTextDocument"
#include "QProcess"
#include "QColor"
#include "QForeachContainer"
#include "cstdlib"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
QDate selectedDate = ui->dateEdit->date();
QString logFile = "/home/eds_cm/eko/filament/Machine/ED01/" + selectedDate.toString("yyyy-MM") + ".txt";

    QFile file(logFile);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        QString logData;
        bool appendData = false;

        while (!in.atEnd())
        {
            QString line = in.readLine();

            if (line.contains(selectedDate.toString("yyyy-MM-dd")))
            {
                appendData = true;

            }
            else if (line.startsWith("ED01"))
            {
                appendData = false;
            }


            if (appendData && !line.startsWith("ED"))
            {
                QStringList parts = line.split(' ');
                QString numberString = parts[1];
                double number = numberString.toDouble();
                QString formattedLine = line + "<br><br>";

                QString colorStyle;

                if (number >= 3.250 && number <= 3.599)
                {
                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                }

                else if (number >= 3.600 && number <= 3.799)
                {
                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                }

                else if (number >= 3.800 && number <= 3.999)
                {
                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                }
                else if (number >= 4.000 && number <= 4.600)
                {
                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                }

                formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                logData.append(formattedLine);

            }

        }


        file.close();
        ui->textBrowser->setText(logData);

    }




//ED2



    QString logFile1 = "/home/eds_cm/eko/filament/Machine/ED02/" + selectedDate.toString("yyyy-MM") + ".txt";

        QFile file1(logFile1);
        if (file1.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream in(&file1);
            QString logData;
            bool appendData = false;

            while (!in.atEnd())
            {
                QString line = in.readLine();

                if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                {
                    appendData = true;

                }
                else if (line.startsWith("ED02"))
                {
                    appendData = false;
                }


                if (appendData && !line.startsWith("ED"))
                {
                    QStringList parts = line.split(' ');
                    QString numberString = parts[1];
                    double number = numberString.toDouble();
                    QString formattedLine = line + "<br><br>";

                    QString colorStyle;

                    if (number >= 3.250 && number <= 3.599)
                    {
                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                    }

                    else if (number >= 3.600 && number <= 3.799)
                    {
                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                    }

                    else if (number >= 3.800 && number <= 3.999)
                    {
                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                    }
                    else if (number >= 4.000 && number <= 4.600)
                    {
                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                    }

                    formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                    logData.append(formattedLine);

                }

            }


            file1.close();
            ui->textBrowser_2->setText(logData);
        }




        //ED3

        QString logFile2 = "/home/eds_cm/eko/filament/Machine/ED03/" + selectedDate.toString("yyyy-MM") + ".txt";

            QFile file2(logFile2);
            if (file2.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream in(&file2);
                QString logData;
                bool appendData = false;

                while (!in.atEnd())
                {
                    QString line = in.readLine();

                    if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                    {
                        appendData = true;

                    }
                    else if (line.startsWith("ED03"))
                    {
                        appendData = false;
                    }


                    if (appendData && !line.startsWith("ED"))
                    {
                        QStringList parts = line.split(' ');
                        QString numberString = parts[1];
                        double number = numberString.toDouble();
                        QString formattedLine = line + "<br><br>";

                        QString colorStyle;

                        if (number >= 3.250 && number <= 3.599)
                        {
                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                        }

                        else if (number >= 3.600 && number <= 3.799)
                        {
                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                        }

                        else if (number >= 3.800 && number <= 3.999)
                        {
                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                        }
                        else if (number >= 4.000 && number <= 4.600)
                        {
                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                        }


                        formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                        logData.append(formattedLine);

                    }

                }


                file2.close();
                ui->textBrowser_3->setText(logData);
            }



//ED4

            QString logFile3 = "/home/eds_cm/eko/filament/Machine/ED04/" + selectedDate.toString("yyyy-MM") + ".txt";

                QFile file3(logFile3);
                if (file3.open(QIODevice::ReadOnly | QIODevice::Text))
                {
                    QTextStream in(&file3);
                    QString logData;
                    bool appendData = false;

                    while (!in.atEnd())
                    {
                        QString line = in.readLine();

                        if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                        {
                            appendData = true;

                        }
                        else if (line.startsWith("ED04"))
                        {
                            appendData = false;
                        }


                        if (appendData && !line.startsWith("ED"))
                        {
                            QStringList parts = line.split(' ');
                            QString numberString = parts[1];
                            double number = numberString.toDouble();
                            QString formattedLine = line + "<br><br>";

                            QString colorStyle;

                            if (number >= 3.250 && number <= 3.599)
                            {
                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                            }

                            else if (number >= 3.600 && number <= 3.799)
                            {
                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                            }

                            else if (number >= 3.800 && number <= 3.999)
                            {
                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                            }
                            else if (number >= 4.000 && number <= 4.600)
                            {
                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                            }

                            formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                            logData.append(formattedLine);

                        }

                    }


                    file3.close();
                    ui->textBrowser_4->setText(logData);
                }



                //ED5

                QString logFile4 = "/home/eds_cm/eko/filament/Machine/ED05/" + selectedDate.toString("yyyy-MM") + ".txt";

                    QFile file4(logFile4);
                    if (file4.open(QIODevice::ReadOnly | QIODevice::Text))
                    {
                        QTextStream in(&file4);
                        QString logData;
                        bool appendData = false;

                        while (!in.atEnd())
                        {
                            QString line = in.readLine();

                            if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                            {
                                appendData = true;

                            }
                            else if (line.startsWith("ED05"))
                            {
                                appendData = false;
                            }


                            if (appendData && !line.startsWith("ED"))
                            {
                                QStringList parts = line.split(' ');
                                QString numberString = parts[1];
                                double number = numberString.toDouble();
                                QString formattedLine = line + "<br><br>";

                                QString colorStyle;

                                if (number >= 3.250 && number <= 3.599)
                                {
                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                }

                                else if (number >= 3.600 && number <= 3.799)
                                {
                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                }

                                else if (number >= 3.800 && number <= 3.999)
                                {
                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                }
                                else if (number >= 4.000 && number <= 4.600)
                                {
                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                }

                                formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                                logData.append(formattedLine);

                            }

                        }


                        file4.close();
                        ui->textBrowser_5->setText(logData);
                    }



                    //ED6
                    QString logFile5 = "/home/eds_cm/eko/filament/Machine/ED06/" + selectedDate.toString("yyyy-MM") + ".txt";

                        QFile file5(logFile5);
                        if (file5.open(QIODevice::ReadOnly | QIODevice::Text))
                        {
                            QTextStream in(&file5);
                            QString logData;
                            bool appendData = false;

                            while (!in.atEnd())
                            {
                                QString line = in.readLine();

                                if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                {
                                    appendData = true;

                                }
                                else if (line.startsWith("ED06"))
                                {
                                    appendData = false;
                                }


                                if (appendData && !line.startsWith("ED"))
                                {
                                    QStringList parts = line.split(' ');
                                    QString numberString = parts[1];
                                    double number = numberString.toDouble();
                                    QString formattedLine = line + "<br><br>";

                                    QString colorStyle;

                                    if (number >= 3.250 && number <= 3.599)
                                    {
                                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                    }

                                    else if (number >= 3.600 && number <= 3.799)
                                    {
                                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                    }

                                    else if (number >= 3.800 && number <= 3.999)
                                    {
                                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                    }
                                    else if (number >= 4.000 && number <= 4.600)
                                    {
                                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                    }

                                    formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                                    logData.append(formattedLine);

                                }

                            }


                            file5.close();
                            ui->textBrowser_6->setText(logData);
                        }




                        //ED9

                        QString logFile6 = "/home/eds_cm/eko/filament/Machine/ED09/" + selectedDate.toString("yyyy-MM") + ".txt";

                            QFile file6(logFile6);
                            if (file6.open(QIODevice::ReadOnly | QIODevice::Text))
                            {
                                QTextStream in(&file6);
                                QString logData;
                                bool appendData = false;

                                while (!in.atEnd())
                                {
                                    QString line = in.readLine();

                                    if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                    {
                                        appendData = true;

                                    }
                                    else if (line.startsWith("ED09"))
                                    {
                                        appendData = false;
                                    }


                                    if (appendData && !line.startsWith("ED"))
                                    {
                                        QStringList parts = line.split(' ');
                                        QString numberString = parts[1];
                                        double number = numberString.toDouble();
                                        QString formattedLine = line + "<br><br>";
                                        QString colorStyle;

                                        if (number >= 3.250 && number <= 3.599)
                                        {
                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                        }

                                        else if (number >= 3.600 && number <= 3.799)
                                        {
                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                        }

                                        else if (number >= 3.800 && number <= 3.999)
                                        {
                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                        }
                                        else if (number >= 4.000 && number <= 4.600)
                                        {
                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                        }

                                        formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                                        logData.append(formattedLine);

                                    }

                                }


                                file6.close();
                                ui->ed9->setText(logData);
                            }



                            //ED10

                            QString logFile7 = "/home/eds_cm/eko/filament/Machine/ED10/" + selectedDate.toString("yyyy-MM") + ".txt";

                                QFile file7(logFile7);
                                if (file7.open(QIODevice::ReadOnly | QIODevice::Text))
                                {
                                    QTextStream in(&file7);
                                    QString logData;
                                    bool appendData = false;

                                    while (!in.atEnd())
                                    {
                                        QString line = in.readLine();

                                        if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                        {
                                            appendData = true;

                                        }
                                        else if (line.startsWith("ED09"))
                                        {
                                            appendData = false;
                                        }


                                        if (appendData && !line.startsWith("ED"))
                                        {
                                            QStringList parts = line.split(' ');
                                            QString numberString = parts[1];
                                            double number = numberString.toDouble();
                                            QString formattedLine = line + "<br><br>";

                                            QString colorStyle;

                                            if (number >= 3.250 && number <= 3.599)
                                            {
                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                            }

                                            else if (number >= 3.600 && number <= 3.799)
                                            {
                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                            }

                                            else if (number >= 3.800 && number <= 3.999)
                                            {
                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                            }
                                            else if (number >= 4.000 && number <= 4.600)
                                            {
                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                            }

                                            formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                                            logData.append(formattedLine);

                                        }

                                    }


                                    file7.close();
                                    ui->ed10->setText(logData);
                                }


                                //ED11
                                QString logFile8 = "/home/eds_cm/eko/filament/Machine/ED11/" + selectedDate.toString("yyyy-MM") + ".txt";

                                    QFile file8(logFile8);
                                    if (file8.open(QIODevice::ReadOnly | QIODevice::Text))
                                    {
                                        QTextStream in(&file8);
                                        QString logData;
                                        bool appendData = false;

                                        while (!in.atEnd())
                                        {
                                            QString line = in.readLine();

                                            if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                            {
                                                appendData = true;

                                            }
                                            else if (line.startsWith("ED11"))
                                            {
                                                appendData = false;
                                            }


                                            if (appendData && !line.startsWith("ED"))
                                            {
                                                QStringList parts = line.split(' ');
                                                QString numberString = parts[1];
                                                double number = numberString.toDouble();
                                                QString formattedLine = line + "<br><br>";

                                                QString colorStyle;

                                                if (number >= 3.250 && number <= 3.599)
                                                {
                                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                                }

                                                else if (number >= 3.600 && number <= 3.799)
                                                {
                                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                                }

                                                else if (number >= 3.800 && number <= 3.999)
                                                {
                                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                                }
                                                else if (number >= 4.000 && number <= 4.600)
                                                {
                                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                                }

                                                formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                                                logData.append(formattedLine);

                                            }

                                        }


                                        file8.close();
                                        ui->ed11->setText(logData);
                                    }


                                    //ED12


                                    QString logFile9 = "/home/eds_cm/eko/filament/Machine/ED12/" + selectedDate.toString("yyyy-MM") + ".txt";

                                        QFile file9(logFile9);
                                        if (file9.open(QIODevice::ReadOnly | QIODevice::Text))
                                        {
                                            QTextStream in(&file9);
                                            QString logData;
                                            bool appendData = false;

                                            while (!in.atEnd())
                                            {
                                                QString line = in.readLine();

                                                if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                                {
                                                    appendData = true;

                                                }
                                                else if (line.startsWith("ED12"))
                                                {
                                                    appendData = false;
                                                }


                                                if (appendData && !line.startsWith("ED"))
                                                {
                                                    QStringList parts = line.split(' ');
                                                    QString numberString = parts[1];
                                                    double number = numberString.toDouble();
                                                    QString formattedLine = line + "<br><br>";

                                                    QString colorStyle;

                                                    if (number >= 3.250 && number <= 3.599)
                                                    {
                                                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                                    }

                                                    else if (number >= 3.600 && number <= 3.799)
                                                    {
                                                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                                    }

                                                    else if (number >= 3.800 && number <= 3.999)
                                                    {
                                                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                                    }
                                                    else if (number >= 4.000 && number <= 4.600)
                                                    {
                                                        colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                                    }

                                                    formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                                                    logData.append(formattedLine);

                                                }

                                            }


                                            file9.close();
                                            ui->ed12->setText(logData);
                                        }



                                        //ED13

                                        QString logFile10 = "/home/eds_cm/eko/filament/Machine/ED13/" + selectedDate.toString("yyyy-MM") + ".txt";

                                            QFile file10(logFile10);
                                            if (file10.open(QIODevice::ReadOnly | QIODevice::Text))
                                            {
                                                QTextStream in(&file10);
                                                QString logData;
                                                bool appendData = false;

                                                while (!in.atEnd())
                                                {
                                                    QString line = in.readLine();

                                                    if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                                    {
                                                        appendData = true;

                                                    }
                                                    else if (line.startsWith("ED13"))
                                                    {
                                                        appendData = false;
                                                    }


                                                    if (appendData && !line.startsWith("ED"))
                                                    {
                                                        QStringList parts = line.split(' ');
                                                        QString numberString = parts[1];
                                                        double number = numberString.toDouble();
                                                        QString formattedLine = line + "<br><br>";

                                                        QString colorStyle;

                                                        if (number >= 3.250 && number <= 3.599)
                                                        {
                                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                                        }

                                                        else if (number >= 3.600 && number <= 3.799)
                                                        {
                                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                                        }
                                                        else if (number >= 3.800 && number <= 3.999)
                                                        {
                                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                                        }
                                                        else if (number >= 4.000 && number <= 4.600)
                                                        {
                                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                                        }

                                                        formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                                                        logData.append(formattedLine);

                                                    }

                                                }


                                                file10.close();
                                                ui->ed13->setText(logData);
                                            }


                                            //ED14

                                            QString logFile11 = "/home/eds_cm/eko/filament/Machine/ED14/" + selectedDate.toString("yyyy-MM") + ".txt";

                                                QFile file11(logFile11);
                                                if (file11.open(QIODevice::ReadOnly | QIODevice::Text))
                                                {
                                                    QTextStream in(&file11);
                                                    QString logData;
                                                    bool appendData = false;

                                                    while (!in.atEnd())
                                                    {
                                                        QString line = in.readLine();

                                                        if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                                        {
                                                            appendData = true;

                                                        }
                                                        else if (line.startsWith("ED14"))
                                                        {
                                                            appendData = false;
                                                        }


                                                        if (appendData && !line.startsWith("ED"))
                                                        {
                                                            QStringList parts = line.split(' ');
                                                            QString numberString = parts[1];
                                                            double number = numberString.toDouble();
                                                            QString formattedLine = line + "<br><br>";

                                                            QString colorStyle;

                                                            if (number >= 3.250 && number <= 3.599)
                                                            {
                                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                                            }

                                                            else if (number >= 3.600 && number <= 3.799)
                                                            {
                                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                                            }

                                                            else if (number >= 3.800 && number <= 3.999)
                                                            {
                                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                                            }
                                                            else if (number >= 4.000 && number <= 4.600)
                                                            {
                                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                                            }

                                                            formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");

                                                            logData.append(formattedLine);

                                                        }

                                                    }


                                                    file11.close();
                                                    ui->ed14->setText(logData);
                                                }

                                                //ED15
                QString logFile12 = "/home/eds_cm/eko/filament/Machine/ED15/" + selectedDate.toString("yyyy-MM") + ".txt";
                QFile file12(logFile12);
                   if (file12.open(QIODevice::ReadOnly | QIODevice::Text))
                        {
                          QTextStream in(&file12);
                          QString logData;
                          bool appendData = false;
                          while (!in.atEnd())
                           {
                             QString line = in.readLine();
                             if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                              {
                               appendData = true;
                                }
                                 else if (line.startsWith("ED15"))
                                  {
                                    appendData = false;
                                      }

                             if (appendData && !line.startsWith("ED"))
                             {
                             QStringList parts = line.split(' ');
                             QString numberString = parts[1];
                             double number = numberString.toDouble();
                             QString formattedLine = line + "<br><br>";
                             QString colorStyle;

                             if (number >= 3.250 && number <= 3.599)
                             {
                                 colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                             }

                             else if (number >= 3.600 && number <= 3.799)
                             {
                                 colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                             }

                             else if (number >= 3.800 && number <= 3.999)
                             {
                                 colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                             }
                             else if (number >= 4.000 && number <= 4.600)
                             {
                                 colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                             }

                           formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                           logData.append(formattedLine);
                             }
                                }
                                  file12.close();
                                  ui->ed15->setText(logData);
                                                    }



                                                    //ED16
                   QString logFile13 = "/home/eds_cm/eko/filament/Machine/ED16/" + selectedDate.toString("yyyy-MM") + ".txt";
                   QFile file13(logFile13);
                      if (file13.open(QIODevice::ReadOnly | QIODevice::Text))
                           {
                             QTextStream in(&file13);
                             QString logData;
                             bool appendData = false;
                             while (!in.atEnd())
                              {
                                QString line = in.readLine();
                                if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                 {
                                  appendData = true;
                                   }
                                    else if (line.startsWith("ED16"))
                                     {
                                       appendData = false;
                                         }

                                if (appendData && !line.startsWith("ED"))
                                {
                                QStringList parts = line.split(' ');
                                QString numberString = parts[1];
                                double number = numberString.toDouble();
                                QString formattedLine = line + "<br><br>";
                                QString colorStyle;

                                if (number >= 3.250 && number <= 3.599)
                                {
                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                }

                                else if (number >= 3.600 && number <= 3.799)
                                {
                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                }

                                else if (number >= 3.800 && number <= 3.999)
                                {
                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                }
                                else if (number >= 4.000 && number <= 4.600)
                                {
                                    colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                }

                              formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                              logData.append(formattedLine);
                                }
                                   }
                                     file13.close();
                                     ui->ed16->setText(logData);
                                                       }


                      //ED17
                      QString logFile14 = "/home/eds_cm/eko/filament/Machine/ED17/" + selectedDate.toString("yyyy-MM") + ".txt";
                      QFile file14(logFile14);
                         if (file14.open(QIODevice::ReadOnly | QIODevice::Text))
                              {
                                QTextStream in(&file14);
                                QString logData;
                                bool appendData = false;
                                while (!in.atEnd())
                                 {
                                   QString line = in.readLine();
                                   if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                    {
                                     appendData = true;
                                      }
                                       else if (line.startsWith("ED17"))
                                        {
                                          appendData = false;
                                            }

                                   if (appendData && !line.startsWith("ED"))
                                   {
                                   QStringList parts = line.split(' ');
                                   QString numberString = parts[1];
                                   double number = numberString.toDouble();
                                   QString formattedLine = line + "<br><br>";
                                   QString colorStyle;

                                   if (number >= 3.250 && number <= 3.599)
                                   {
                                       colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                   }

                                   else if (number >= 3.600 && number <= 3.799)
                                   {
                                       colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                   }

                                   else if (number >= 3.800 && number <= 3.999)
                                   {
                                       colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                   }
                                   else if (number >= 4.000 && number <= 4.600)
                                   {
                                       colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                   }

                                 formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                                 logData.append(formattedLine);
                                   }
                                      }
                                        file14.close();
                                        ui->ed17->setText(logData);
                                                          }


                         //ED18
                         QString logFile15 = "/home/eds_cm/eko/filament/Machine/ED18/" + selectedDate.toString("yyyy-MM") + ".txt";
                         QFile file15(logFile15);
                            if (file15.open(QIODevice::ReadOnly | QIODevice::Text))
                                 {
                                   QTextStream in(&file15);
                                   QString logData;
                                   bool appendData = false;
                                   while (!in.atEnd())
                                    {
                                      QString line = in.readLine();
                                      if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                       {
                                        appendData = true;
                                         }
                                          else if (line.startsWith("ED18"))
                                           {
                                             appendData = false;
                                               }

                                      if (appendData && !line.startsWith("ED"))
                                      {
                                      QStringList parts = line.split(' ');
                                      QString numberString = parts[1];
                                      double number = numberString.toDouble();
                                      QString formattedLine = line + "<br><br>";
                                      QString colorStyle;

                                      if (number >= 3.250 && number <= 3.599)
                                      {
                                          colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                      }

                                      else if (number >= 3.600 && number <= 3.799)
                                      {
                                          colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                      }

                                      else if (number >= 3.800 && number <= 3.999)
                                      {
                                          colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                      }
                                      else if (number >= 4.000 && number <= 4.600)
                                      {
                                          colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                      }

                                    formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                                    logData.append(formattedLine);
                                      }
                                         }
                                           file15.close();
                                           ui->ed18->setText(logData);
                                                             }


                            //ED19

                            QString logFile16 = "/home/eds_cm/eko/filament/Machine/ED19/" + selectedDate.toString("yyyy-MM") + ".txt";
                            QFile file16(logFile16);
                               if (file16.open(QIODevice::ReadOnly | QIODevice::Text))
                                    {
                                      QTextStream in(&file16);
                                      QString logData;
                                      bool appendData = false;
                                      while (!in.atEnd())
                                       {
                                         QString line = in.readLine();
                                         if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                          {
                                           appendData = true;
                                            }
                                             else if (line.startsWith("ED19"))
                                              {
                                                appendData = false;
                                                  }

                                         if (appendData && !line.startsWith("ED"))
                                         {
                                         QStringList parts = line.split(' ');
                                         QString numberString = parts[1];
                                         double number = numberString.toDouble();
                                         QString formattedLine = line + "<br><br>";

                                         QString colorStyle;

                                         if (number >= 3.250 && number <= 3.599)
                                         {
                                             colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                         }

                                         else if (number >= 3.600 && number <= 3.799)
                                         {
                                             colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                         }

                                         else if (number >= 3.800 && number <= 3.999)
                                         {
                                             colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                         }
                                         else if (number >= 4.000 && number <= 4.600)
                                         {
                                             colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                         }





                                       formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                                       logData.append(formattedLine);
                                         }
                                            }
                                              file16.close();
                                              ui->ed19->setText(logData);
                                                                }

                               //ED20

                               QString logFile17 = "/home/eds_cm/eko/filament/Machine/ED20/" + selectedDate.toString("yyyy-MM") + ".txt";
                               QFile file17(logFile17);
                                  if (file17.open(QIODevice::ReadOnly | QIODevice::Text))
                                       {
                                         QTextStream in(&file17);
                                         QString logData;
                                         bool appendData = false;
                                         while (!in.atEnd())
                                          {
                                            QString line = in.readLine();
                                            if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                             {
                                              appendData = true;
                                               }
                                                else if (line.startsWith("ED20"))
                                                 {
                                                   appendData = false;
                                                     }

                                            if (appendData && !line.startsWith("ED"))
                                            {
                                            QStringList parts = line.split(' ');
                                            QString numberString = parts[1];
                                            double number = numberString.toDouble();
                                            QString formattedLine = line + "<br><br>";
                                            QString colorStyle;

                                            if (number >= 3.250 && number <= 3.599)
                                            {
                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                            }
                                            else if (number >= 3.600 && number <= 3.799)
                                            {
                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                            }

                                            else if (number >= 3.800 && number <= 3.999)
                                            {
                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                            }
                                            else if (number >= 4.000 && number <= 4.600)
                                            {
                                                colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                            }

                                          formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                                          logData.append(formattedLine);
                                            }
                                               }
                                                 file17.close();
                                                 ui->ed20->setText(logData);
                                                                   }


                                  //ED23
                                  QString logFile18 = "/home/eds_cm/eko/filament/Machine/ED23/" + selectedDate.toString("yyyy-MM") + ".txt";
                                  QFile file18(logFile18);
                                     if (file18.open(QIODevice::ReadOnly | QIODevice::Text))
                                          {
                                            QTextStream in(&file18);
                                            QString logData;
                                            bool appendData = false;
                                            while (!in.atEnd())
                                             {
                                               QString line = in.readLine();
                                               if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                                {
                                                 appendData = true;
                                                  }
                                                   else if (line.startsWith("ED23"))
                                                    {
                                                      appendData = false;
                                                        }

                                               if (appendData && !line.startsWith("ED"))
                                               {
                                               QStringList parts = line.split(' ');
                                               QString numberString = parts[1];
                                               double number = numberString.toDouble();
                                               QString formattedLine = line + "<br><br>";
                                               QString colorStyle;

                                               if (number >= 3.250 && number <= 3.599)
                                               {
                                                   colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                               }

                                               else if (number >= 3.600 && number <= 3.799)
                                               {
                                                   colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                               }

                                               else if (number >= 3.800 && number <= 3.999)
                                               {
                                                   colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                               }
                                               else if (number >= 4.000 && number <= 4.600)
                                               {
                                                   colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                               }




                                             formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                                             logData.append(formattedLine);
                                               }
                                                  }
                                                    file18.close();
                                                    ui->ed23->setText(logData);
                                                                      }

                                     //ED24

                                     QString logFile19 = "/home/eds_cm/eko/filament/Machine/ED24/" + selectedDate.toString("yyyy-MM") + ".txt";
                                     QFile file19(logFile19);
                                        if (file19.open(QIODevice::ReadOnly | QIODevice::Text))
                                             {
                                               QTextStream in(&file19);
                                               QString logData;
                                               bool appendData = false;
                                               while (!in.atEnd())
                                                {
                                                  QString line = in.readLine();
                                                  if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                                   {
                                                    appendData = true;
                                                     }
                                                      else if (line.startsWith("ED24"))
                                                       {
                                                         appendData = false;
                                                           }

                                                  if (appendData && !line.startsWith("ED"))
                                                  {
                                                  QStringList parts = line.split(' ');
                                                  QString numberString = parts[1];
                                                  double number = numberString.toDouble();
                                                  QString formattedLine = line + "<br><br>";
                                                  QString colorStyle;

                                                  if (number >= 3.250 && number <= 3.599)
                                                  {
                                                      colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                                  }

                                                  else if (number >= 3.600 && number <= 3.799)
                                                  {
                                                      colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                                  }

                                                  else if (number >= 3.800 && number <= 3.999)
                                                  {
                                                      colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                                  }
                                                  else if (number >= 4.000 && number <= 4.600)
                                                  {
                                                      colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                                  }

                                                formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                                                logData.append(formattedLine);
                                                  }
                                                     }
                                                       file19.close();
                                                       ui->ed24->setText(logData);
                                                                         }


                                        //ED25


                                        QString logFile20 = "/home/eds_cm/eko/filament/Machine/ED25/" + selectedDate.toString("yyyy-MM") + ".txt";
                                        QFile file20(logFile20);
                                           if (file20.open(QIODevice::ReadOnly | QIODevice::Text))
                                                {
                                                  QTextStream in(&file20);
                                                  QString logData;
                                                  bool appendData = false;
                                                  while (!in.atEnd())
                                                   {
                                                     QString line = in.readLine();
                                                     if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                                      {
                                                       appendData = true;
                                                        }
                                                         else if (line.startsWith("ED25"))
                                                          {
                                                            appendData = false;
                                                              }

                                                     if (appendData && !line.startsWith("ED"))
                                                     {
                                                     QStringList parts = line.split(' ');
                                                     QString numberString = parts[1];
                                                     double number = numberString.toDouble();
                                                     QString formattedLine = line + "<br><br>";
                                                     QString colorStyle;

                                                     if (number >= 3.250 && number <= 3.599)
                                                     {
                                                         colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                                     }

                                                     else if (number >= 3.600 && number <= 3.799)
                                                     {
                                                         colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                                     }

                                                     else if (number >= 3.800 && number <= 3.999)
                                                     {
                                                         colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                                     }
                                                     else if (number >= 4.000 && number <= 4.600)
                                                     {
                                                         colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                                     }

                                                   formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                                                   logData.append(formattedLine);
                                                     }
                                                        }
                                                          file20.close();
                                                          ui->ed25->setText(logData);
                                                                            }

                                           //ED26

                                           QString logFile21 = "/home/eds_cm/eko/filament/Machine/ED26/" + selectedDate.toString("yyyy-MM") + ".txt";
                                           QFile file21(logFile21);
                                              if (file21.open(QIODevice::ReadOnly | QIODevice::Text))
                                                   {
                                                     QTextStream in(&file21);
                                                     QString logData;
                                                     bool appendData = false;
                                                     while (!in.atEnd())
                                                      {
                                                        QString line = in.readLine();
                                                        if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                                         {
                                                          appendData = true;
                                                           }
                                                            else if (line.startsWith("ED26"))
                                                             {
                                                               appendData = false;
                                                                 }

                                                        if (appendData && !line.startsWith("ED"))
                                                        {
                                                        QStringList parts = line.split(' ');
                                                        QString numberString = parts[1];
                                                        double number = numberString.toDouble();
                                                        QString formattedLine = line + "<br><br>";
                                                        QString colorStyle;

                                                        if (number >= 3.250 && number <= 3.599)
                                                        {
                                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                                        }

                                                        else if (number >= 3.600 && number <= 3.799)
                                                        {
                                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                                        }

                                                        else if (number >= 3.800 && number <= 3.999)
                                                        {
                                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                                        }
                                                        else if (number >= 4.000 && number <= 4.600)
                                                        {
                                                            colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                                        }

                                                      formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                                                      logData.append(formattedLine);
                                                        }
                                                           }
                                                             file21.close();
                                                             ui->ed26->setText(logData);
                                                                               }


                                              //ED27

                                              QString logFile22 = "/home/eds_cm/eko/filament/Machine/ED27/" + selectedDate.toString("yyyy-MM") + ".txt";
                                              QFile file22(logFile22);
                                                 if (file22.open(QIODevice::ReadOnly | QIODevice::Text))
                                                      {
                                                        QTextStream in(&file22);
                                                        QString logData;
                                                        bool appendData = false;
                                                        while (!in.atEnd())
                                                         {
                                                           QString line = in.readLine();
                                                           if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                                            {
                                                             appendData = true;
                                                              }
                                                               else if (line.startsWith("ED27"))
                                                                {
                                                                  appendData = false;
                                                                    }

                                                           if (appendData && !line.startsWith("ED"))
                                                           {
                                                           QStringList parts = line.split(' ');
                                                           QString numberString = parts[1];
                                                           double number = numberString.toDouble();
                                                           QString formattedLine = line + "<br><br>";
                                                           QString colorStyle;

                                                           if (number >= 3.250 && number <= 3.599)
                                                           {
                                                               colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                                           }

                                                           else if (number >= 3.600 && number <= 3.799)
                                                           {
                                                               colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                                           }

                                                           else if (number >= 3.800 && number <= 3.999)
                                                           {
                                                               colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                                           }
                                                           else if (number >= 4.000 && number <= 4.600)
                                                           {
                                                               colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                                           }

                                                         formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                                                         logData.append(formattedLine);
                                                           }
                                                              }
                                                                file22.close();
                                                                ui->ed27->setText(logData);
                                                                                  }

                                                 //ED28


                                                 QString logFile23 = "/home/eds_cm/eko/filament/Machine/ED28/" + selectedDate.toString("yyyy-MM") + ".txt";
                                                 QFile file23(logFile23);
                                                    if (file23.open(QIODevice::ReadOnly | QIODevice::Text))
                                                         {
                                                           QTextStream in(&file23);
                                                           QString logData;
                                                           bool appendData = false;
                                                           while (!in.atEnd())
                                                            {
                                                              QString line = in.readLine();
                                                              if (line.contains(selectedDate.toString("yyyy-MM-dd")))
                                                               {
                                                                appendData = true;
                                                                 }
                                                                  else if (line.startsWith("ED28"))
                                                                   {
                                                                     appendData = false;
                                                                       }

                                                              if (appendData && !line.startsWith("ED"))
                                                              {
                                                              QStringList parts = line.split(' ');
                                                              QString numberString = parts[1];
                                                              double number = numberString.toDouble();
                                                              QString formattedLine = line + "<br><br>";
                                                              QString colorStyle;

                                                              if (number >= 3.250 && number <= 3.599)
                                                              {
                                                                  colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(204, 29, 29, 255), stop:0.453333 rgba(212, 37, 37, 255), stop:0.98 rgba(234, 134, 32, 255), stop:1 rgba(0, 0, 0, 0));";
                                                              }

                                                              else if (number >= 3.600 && number <= 3.799)
                                                              {
                                                                  colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(179, 204, 29, 255), stop:0.524444 rgba(254, 224, 44, 255), stop:1 rgba(255, 137, 14, 255));";
                                                              }

                                                              else if (number >= 3.800 && number <= 3.999)
                                                              {
                                                                  colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(9, 147, 0, 255), stop:0.56 rgba(88, 254, 0, 255), stop:0.942222 rgba(203, 255, 0, 255));";

                                                              }
                                                              else if (number >= 4.000 && number <= 4.600)
                                                              {
                                                                  colorStyle = "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(56, 96, 38, 255), stop:0.448889 rgba(30, 119, 56, 255), stop:0.98 rgba(35, 203, 104, 255), stop:1 rgba(0, 0, 0, 0));";
                                                              }

                                                            formattedLine.replace(parts[1], "<span style='" + colorStyle + "'>" + parts[1] + "</span");
                                                            logData.append(formattedLine);
                                                              }
                                                                 }
                                                                   file23.close();
                                                                   ui->ed28->setText(logData);
                                                                                     }






//Renk

QString fildate = selectedDate.toString("yyyy-MM-dd");
QString command =  "grep -c 3.[6-7][0-9][0-9] /home/eds_cm/eko/filament/Daily/filament-" + fildate;
QProcess process;
process.start(command);
process.waitForFinished(-1);

QString output = process.readAllStandardOutput();
qDebug() << output;
ui->orange->setText(output);


//Renk2

QString command1 =  "grep -c 3.[2-5][0-9][0-9] /home/eds_cm/eko/filament/Daily/filament-" + fildate;
QProcess process1;
process1.start(command1);
process1.waitForFinished(-1);

QString output1 = process1.readAllStandardOutput();
qDebug() << output1;
ui->redco->setText(output1);

//ed1

QString command2 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED01/fil-" + fildate;
QProcess process2;
process2.start(command2);
process2.waitForFinished(-1);

QString output2 = process2.readAllStandardOutput();
qDebug() << output2;
ui->orange1->setText(output2);

//ed2

QString command3 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED02/fil-" + fildate;
QProcess process3;
process3.start(command3);
process3.waitForFinished(-1);

QString output3 = process3.readAllStandardOutput();
qDebug() << output3;
ui->orange2->setText(output3);

//ed3

QString command4 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED03/fil-" + fildate;
QProcess process4;
process4.start(command4);
process4.waitForFinished(-1);

QString output4 = process4.readAllStandardOutput();
ui->orange3->setText(output4);

//ed4

QString command5 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED04/fil-" + fildate;
QProcess process5;
process5.start(command5);
process5.waitForFinished(-1);

QString output5 = process5.readAllStandardOutput();
ui->orange4->setText(output5);

//ed5

QString command6 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED05/fil-" + fildate;
QProcess process6;
process6.start(command6);
process6.waitForFinished(-1);

QString output6 = process6.readAllStandardOutput();
ui->orange5->setText(output6);

//ed6
QString command7 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED06/fil-" + fildate;
QProcess process7;
process7.start(command7);
process7.waitForFinished(-1);

QString output7 = process7.readAllStandardOutput();
ui->orange6->setText(output7);

//ed9
QString command8 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED09/fil-" + fildate;
QProcess process8;
process8.start(command8);
process8.waitForFinished(-1);

QString output8 = process8.readAllStandardOutput();
ui->orange9->setText(output8);

//ed10
QString command9 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED10/fil-" + fildate;
QProcess process9;
process9.start(command9);
process9.waitForFinished(-1);

QString output9 = process9.readAllStandardOutput();
ui->orange10->setText(output9);

//ed11
QString command10 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED11/fil-" + fildate;
QProcess process10;
process10.start(command10);
process10.waitForFinished(-1);

QString output10 = process10.readAllStandardOutput();
ui->orange11->setText(output10);

//ed12

QString command11 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED12/fil-" + fildate;
QProcess process11;
process11.start(command11);
process11.waitForFinished(-1);

QString output11 = process11.readAllStandardOutput();
ui->orange12->setText(output11);

//d13
QString command12 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED13/fil-" + fildate;
QProcess process12;
process12.start(command12);
process12.waitForFinished(-1);

QString output12 = process12.readAllStandardOutput();
ui->orange13->setText(output12);

//ed14
QString command13 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED14/fil-" + fildate;
QProcess process13;
process13.start(command13);
process13.waitForFinished(-1);

QString output13 = process13.readAllStandardOutput();
ui->orange14->setText(output13);

//ed15
QString command14 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED15/fil-" + fildate;
QProcess process14;
process14.start(command14);
process14.waitForFinished(-1);

QString output14 = process14.readAllStandardOutput();
ui->orange15->setText(output14);

//ed16
QString command15 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED16/fil-" + fildate;
QProcess process15;
process15.start(command15);
process15.waitForFinished(-1);

QString output15 = process15.readAllStandardOutput();
ui->orange16->setText(output15);

//ed17
QString command16 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED17/fil-" + fildate;
QProcess process16;
process16.start(command16);
process16.waitForFinished(-1);

QString output16 = process16.readAllStandardOutput();
ui->orange17->setText(output16);

//ed18
QString command17 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED18/fil-" + fildate;
QProcess process17;
process17.start(command17);
process17.waitForFinished(-1);

QString output17 = process17.readAllStandardOutput();
ui->orange18->setText(output17);

//ed19
QString command18 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED19/fil-" + fildate;
QProcess process18;
process18.start(command18);
process18.waitForFinished(-1);

QString output18 = process18.readAllStandardOutput();
ui->orange19->setText(output18);

//ed20
QString command19 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED20/fil-" + fildate;
QProcess process19;
process19.start(command19);
process19.waitForFinished(-1);

QString output19 = process19.readAllStandardOutput();
ui->orange20->setText(output19);

//ed23
QString command20 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED23/fil-" + fildate;
QProcess process20;
process20.start(command20);
process20.waitForFinished(-1);

QString output20 = process20.readAllStandardOutput();
ui->orange23->setText(output20);

//ed24
QString command21 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED24/fil-" + fildate;
QProcess process21;
process21.start(command21);
process21.waitForFinished(-1);

QString output21 = process21.readAllStandardOutput();
ui->orange24->setText(output21);

//ed25
QString command22 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED25/fil-" + fildate;
QProcess process22;
process22.start(command22);
process22.waitForFinished(-1);

QString output22 = process22.readAllStandardOutput();
ui->orange25->setText(output22);

//ed26

QString command23 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED26/fil-" + fildate;
QProcess process23;
process23.start(command23);
process23.waitForFinished(-1);

QString output23 = process23.readAllStandardOutput();
ui->orange26->setText(output23);

//ed27
QString command24 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED27/fil-" + fildate;
QProcess process24;
process24.start(command24);
process24.waitForFinished(-1);

QString output24 = process24.readAllStandardOutput();
ui->orange27->setText(output24);

//ed28
QString command25 =  "grep -c 3.[0-7][0-9][0-9] /home/eds_cm/eko/filament/Critfil/ED28/fil-" + fildate;
QProcess process25;
process25.start(command25);
process25.waitForFinished(-1);

QString output25 = process25.readAllStandardOutput();
ui->orange28->setText(output25);


//1
int sayi1 = ui->orange1->text().toInt();
if (sayi1 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange1->setStyleSheet(styleSheet);
} else if (sayi1 >= 1 && sayi1 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange1->setStyleSheet(styleSheet);
}

//2
int sayi2 = ui->orange2->text().toInt();
if (sayi2 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange2->setStyleSheet(styleSheet);
} else if (sayi2 >= 1 && sayi2 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange2->setStyleSheet(styleSheet);
}

//3
int sayi3 = ui->orange3->text().toInt();
if (sayi3 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange3->setStyleSheet(styleSheet);
} else if (sayi3 >= 1 && sayi3 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange3->setStyleSheet(styleSheet);
}

//4

int sayi4 = ui->orange4->text().toInt();
if (sayi4 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange4->setStyleSheet(styleSheet);
} else if (sayi4 >= 1 && sayi4 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange4->setStyleSheet(styleSheet);
}

//5
int sayi5 = ui->orange5->text().toInt();
if (sayi5 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange5->setStyleSheet(styleSheet);
} else if (sayi5 >= 1 && sayi5 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange5->setStyleSheet(styleSheet);
}

//6
int sayi6 = ui->orange6->text().toInt();
if (sayi6 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange6->setStyleSheet(styleSheet);
} else if (sayi6 >= 1 && sayi6 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange6->setStyleSheet(styleSheet);
}

//9
int sayi9 = ui->orange9->text().toInt();
if (sayi9 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange9->setStyleSheet(styleSheet);
} else if (sayi9 >= 1 && sayi9 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange9->setStyleSheet(styleSheet);
}

//10

int sayi10 = ui->orange10->text().toInt();
if (sayi10 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange10->setStyleSheet(styleSheet);
} else if (sayi10 >= 1 && sayi10 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange10->setStyleSheet(styleSheet);
}

//11
int sayi11 = ui->orange11->text().toInt();
if (sayi11 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange11->setStyleSheet(styleSheet);
} else if (sayi11 >= 1 && sayi11 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange11->setStyleSheet(styleSheet);
}

//12
int sayi12 = ui->orange12->text().toInt();
if (sayi12 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange12->setStyleSheet(styleSheet);
} else if (sayi12 >= 1 && sayi12 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange12->setStyleSheet(styleSheet);
}

//13

int sayi13 = ui->orange13->text().toInt();
if (sayi13 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange13->setStyleSheet(styleSheet);
} else if (sayi13 >= 1 && sayi13 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange13->setStyleSheet(styleSheet);
}

//14
int sayi14 = ui->orange14->text().toInt();
if (sayi14 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange14->setStyleSheet(styleSheet);
} else if (sayi14 >= 1 && sayi14 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange14->setStyleSheet(styleSheet);
}

//15
int sayi15 = ui->orange15->text().toInt();
if (sayi15 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange15->setStyleSheet(styleSheet);
} else if (sayi15 >= 1 && sayi15 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange15->setStyleSheet(styleSheet);
}


//16
int sayi16 = ui->orange16->text().toInt();
if (sayi16 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange16->setStyleSheet(styleSheet);
} else if (sayi16 >= 1 && sayi16 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange16->setStyleSheet(styleSheet);
}

//17
int sayi17 = ui->orange17->text().toInt();
if (sayi17 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange17->setStyleSheet(styleSheet);
} else if (sayi17 >= 1 && sayi17 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange17->setStyleSheet(styleSheet);
}

//18

int sayi18 = ui->orange18->text().toInt();
if (sayi18 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange18->setStyleSheet(styleSheet);
} else if (sayi18 >= 1 && sayi18 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange18->setStyleSheet(styleSheet);
}

//19
int sayi19 = ui->orange19->text().toInt();
if (sayi19 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange19->setStyleSheet(styleSheet);
} else if (sayi19 >= 1 && sayi19 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange19->setStyleSheet(styleSheet);
}

//20
int sayi20 = ui->orange20->text().toInt();
if (sayi20 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange20->setStyleSheet(styleSheet);
} else if (sayi20 >= 1 && sayi20 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange20->setStyleSheet(styleSheet);
}

//23
int sayi23 = ui->orange23->text().toInt();
if (sayi23 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange23->setStyleSheet(styleSheet);
} else if (sayi23 >= 1 && sayi23 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange23->setStyleSheet(styleSheet);
}

//24
int sayi24 = ui->orange24->text().toInt();
if (sayi24 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange24->setStyleSheet(styleSheet);
} else if (sayi24 >= 1 && sayi24 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange24->setStyleSheet(styleSheet);
}

//25
int sayi25 = ui->orange25->text().toInt();
if (sayi25 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange25->setStyleSheet(styleSheet);
} else if (sayi25 >= 1 && sayi25 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange25->setStyleSheet(styleSheet);
}


//26
int sayi26 = ui->orange26->text().toInt();
if (sayi26 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange26->setStyleSheet(styleSheet);
} else if (sayi26 >= 1 && sayi26 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange26->setStyleSheet(styleSheet);
}

//27
int sayi27 = ui->orange27->text().toInt();
if (sayi27 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange27->setStyleSheet(styleSheet);
} else if (sayi27 >= 1 && sayi27 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange27->setStyleSheet(styleSheet);
}


//28
int sayi28 = ui->orange28->text().toInt();
if (sayi28 == 0) {
    QString styleSheet = "background-color: rgb(212, 208, 200); color: rgb(212, 208, 200); border-radius:10;";
    ui->orange28->setStyleSheet(styleSheet);
} else if (sayi28 >= 1 && sayi28 <= 9) {
    QString styleSheet = "background-color: red; color: red; border-radius:10;";
    ui->orange28->setStyleSheet(styleSheet);
}















                                                }
