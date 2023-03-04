#include <vector>
#include <cmath>
#include <QApplication>
#include <QPushButton>
#include <QVector>
#include "qcustomplot.h"

int main(int argc, char **argv)
{
    QApplication app (argc, argv);
    int sizeWindowX=720;
    int sizeWindowY=720;
    int wGraph=700;
    int hGraph=700;

    QMainWindow window;
    window.setFixedSize(sizeWindowX,sizeWindowY);
    QCustomPlot *graph=new QCustomPlot(&window);
    graph->setGeometry((sizeWindowX-wGraph)/2,(sizeWindowY-hGraph)/2,wGraph,hGraph);

    std::vector<double> coordFirstEl={0.12, 0.91, -0.23};
    std::vector<double> coordSecondEl={0.58, -0.12, 0};
    std::vector<double> psi;
    int freq=265e6;
    int maxYgol=360;
    int c=3e8;
    double step=0.1;
    double l=double(c/freq);

    psi.push_back(step);
    for(int i=1;i<maxYgol/step;i++)
        psi.push_back(psi[i-1]+step);

    // Перенесем начало координат в точку с координатами второго элемента
    std::vector<double> newCoordFirstEl(coordFirstEl.size());
    for(int i=0;i<coordFirstEl.size();i++)
        newCoordFirstEl[i]=coordFirstEl[i]-coordSecondEl[i];

    std::vector<double> differencePhase(psi.size());
    std::vector<double> psiRad(psi.size());

    for(int i=0;i<psiRad.size();i++)
            psiRad[i]=psi[i]*M_PI/180;


    for(int i=0;i<differencePhase.size();i++)
       differencePhase[i]=(2*M_PI/l)*cos(45*M_PI/180)*(newCoordFirstEl[0]*cos(psiRad[i])-newCoordFirstEl[1]*sin(psiRad[i])+newCoordFirstEl[2]*tan(45*M_PI/180));

    QVector<double> qPsi=QVector<double>(psi.begin(), psi.end());
    QVector<double> qDiffPhase=QVector<double>(differencePhase.begin(), differencePhase.end());

    graph->addGraph();
    graph->graph(0)->setData(qPsi,qDiffPhase);
    graph->xAxis->setLabel("Горизонтальный угол, градусы");
    graph->yAxis->setLabel("Разность фаз");
    graph->replot();
    graph->graph(0)->rescaleAxes();

    window.show();

    return app.exec();

}
