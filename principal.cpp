#include "principal.h"
#include "ui_principal.h"

#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    lienzo = QPixmap(500,500);
    lienzo.fill(Qt::white);
    mPaint=new QPainter(&lienzo);
    this->dibujar();

    ui->outCuadro->setPixmap(lienzo);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::dibujar()
{
    //lienzo.fill(Qt::white);

    int x = 30;
    int y = 30;
    int x1= x;
    int x2=y+400;

    //Crear un pencil para los bordes
    QPen pincel;
    pincel.setWidth(5);
    pincel.setColor(Qt::yellow);
    pincel.setJoinStyle(Qt::MiterJoin);
    mPaint->setPen(pincel);
    mPaint->drawLine(x,y,x,y+410);
    mPaint->drawLine(x1,x2,x1+410,x2);
    pincel.setColor(Qt::green);
    mPaint->setPen(pincel);
    int num=100;
    for(int i=y;i<450;i+=100){
        mPaint->drawLine(x-5,i,x+5,i);
       QString numero=QString::number(num);
        mPaint->drawText(x-25,i,numero);
        num-=25;

    }
    int nota=1;
    for(int i=x;i<450;i+=150){
        QString a=QString::number(nota);
        QString Nota="Nota ";
        mPaint->drawText(i+50,x+420,Nota+a);
        nota +=1;
    }
    update();

    /*
    //Establecer el pincel al "pintor"
    painter.setPen(pincel);
    painter.setBrush(Qt::green);

    //Dibujar primera barra
    painter.drawRect(x+50, y+50,100,400);

    //Crear un objeto color
    QColor colorRelleno(190,120,162);
    //Crear un objeto color
    QColor colorBorde(78,3,48);

    //Cambiar el color del pincel
    pincel.setColor(colorBorde);

    //Volver establecer el color al pincel "pintor"(borde)
    painter.setPen(pincel);
    //Establecer el color al brush(relleno)
    painter.setBrush(colorRelleno);

    //Dibujar segunda barra
    painter.drawRect(x+170,y+200,100,250);

    //Creamos los colores de la tercera barra
    QColor cRellenoBarra3(253,253,115);
    QColor cBordeBarra3(174,174,51);

    //Estableciendo colores al painter
    pincel.setColor(cBordeBarra3);
    painter.setPen(pincel);
    painter.setBrush(cRellenoBarra3);

    //Dibujar tercera barra
    painter.drawRect(x+290,y+350,100,100);
    */



}


void Principal::on_actionGuardar_triggered()
{
    QString nombreArchivo = QFileDialog::getSaveFileName(
                this,"Guardar imagen", QString(),"Imagenes (*.png");
    if (!nombreArchivo.isEmpty()){
        if(lienzo.save(nombreArchivo))
            QMessageBox::information(this,"Guardar imagen", "Archivo guardar en: " + nombreArchivo);
    else
            QMessageBox::warning(this,"Guardar imagen","No se pudo guardar el archivo");
    }

}

void Principal::on_cmdCacular_released()
{
    float nota1=  ui->inNota1->value();
    float nota2 = ui->inNota2->value();
    float nota3=  ui->inNota3->value();
    float promedio;
    promedio =(nota1+nota2+nota3)/3.00;
    QString promedioN=QString::number(promedio);
    ui->outPromedio->setText(promedioN);
}

