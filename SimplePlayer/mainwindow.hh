#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QVector>

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
    void on_play_clicked();

    void on_pause_clicked();

    void on_next_clicked();

    void on_previous_clicked();

    void on_sound_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;
    QAudioOutput* audio;
    QVector<QString> mlist;
};
#endif // MAINWINDOW_HH
