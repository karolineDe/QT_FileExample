#include <QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>
#include <QTextStream>

void write(QString filename);
void read(QString filename);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    read(":/new/prefix1/FileExample.pro");

   QString filename ="C:/Qt/MyFile.txt";

   write(filename);
   read(filename);

   return a.exec();
}

void write(QString filename)
{
    QFile file(filename);

    //Trying to open in WriteOnly and Text mode
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() << " Could not open file for writing";
        return;
    }

    // to write text, we use operator<<(),
    // which is overloaded to take
    // a QTextStream on the left
    // and data types (including QString) on the right

    QTextStream out(&file);
    out << "QFile tutorial";
    file.flush();
    file.close();
}

void read(QString filename)
{
    QFile file(filename);

    // trying to open in Readonly mode
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << " cannot open file for reading";
        return;
    }

    QTextStream in(&file);
    QString myText = in.readAll();
    qDebug() << myText;

    file.close();
}
