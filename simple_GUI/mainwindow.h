#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QtCharts>
#include <QComboBox>
#include <QTabWidget>

#include <cmath>
#include <vector>
#include <complex>
#include <chrono>
#include <random>

#include "../MRC_1_IS/Models/JakesModel.hpp"
#include "../MRC_1_IS/Models/MCModel.hpp"
#include "../MRC_1_IS/Models/MEAModel.hpp"
#include "../MRC_1_IS/Models/MEDModel.hpp"
#include "../MRC_1_IS/Models/MEDSModel.hpp"
#include "../MRC_1_IS/Models/MSEModel.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//Main object Class
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QTabWidget *tabManager;
    Ui::MainWindow *ui;

};

//First tab related object Class
class ChannelImpulseResponse : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelImpulseResponse(QWidget *parent = nullptr);

private:

    void recalcSeries();

    //Object and widgets
    QComboBox *funcType = nullptr;
    QPushButton *m_button = nullptr;
    QChart *chart = nullptr;
    QChartView *chartView = nullptr;
    QLineSeries *series = nullptr;

    //Axis control
    QValueAxis *axisX = nullptr;
    QValueAxis *axisY = nullptr;

    //Paramters
    QLineEdit *sig = nullptr;
    QLineEdit *fmax = nullptr;
    QLineEdit *finalTime = nullptr;
    QLineEdit *stepTime = nullptr;

    //Statistics
    QLineEdit *meanLE = nullptr;
    QLineEdit *varLE = nullptr;
    QLineEdit *meanPLE = nullptr;
};

//Second tab object Class
class ChannelAutoCorrelation : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelAutoCorrelation(QWidget *parent = nullptr);

private:

    void calcCorr();

    //Object and widgets
    QPushButton *m_button = nullptr;
    QChart *chart = nullptr;
    QChartView *chartView = nullptr;
    QLineSeries *Parametric_series = nullptr;
    QLineSeries *Empiric_series = nullptr;

    //Axis control
    QValueAxis *axisX = nullptr;
    QValueAxis *axisY = nullptr;

    //Paramters
    QLineEdit *sig = nullptr;
    QLineEdit *fmax = nullptr;
    QLineEdit *finalTime = nullptr;
    QLineEdit *stepTime = nullptr;

};


//Useful Function on for calculate the Theoretical ACF
std::vector<float> envACF(float sig, std::vector<float> acf1, std::vector<float> acf2);

//Useful Function on for calculate the Empirical ACF
std::vector<std::complex<float>> autoCorr(std::vector<std::complex<float>> u, float lag);

//Third tab object Class
class ChannelFrequencyResponse : public QWidget
{
    Q_OBJECT

public:
    explicit ChannelFrequencyResponse(QWidget *parent = nullptr);

private:

    void calcFreqRes();

    //Object and widgets
    QPushButton *m_button = nullptr;
    QChart *chart = nullptr;
    QChartView *chartView = nullptr;
    QScatterSeries *Parametric_series = nullptr;

    //Axis control
    QValueAxis *axisX = nullptr;
    QValueAxis *axisY = nullptr;

    //Paramters
    QLineEdit *sig = nullptr;
    QLineEdit *fmax = nullptr;

};


#endif // MAINWINDOW_H