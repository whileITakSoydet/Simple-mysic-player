#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <io.h>

int positionm = 0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    player = new QMediaPlayer;

    _finddata_t* fileinfo = new _finddata_t;
    intptr_t done = _findfirst("C:/music/*.mp3", fileinfo);
    intptr_t isFind = done;
    while (isFind != -1)
    {
        mlist.push_back(fileinfo->name);
        isFind = _findnext(done, fileinfo);
    }
    delete fileinfo;

    audio = new QAudioOutput;
    player->setAudioOutput(audio);
    player->setSource(QUrl::fromLocalFile("C:/music/" + mlist[positionm]));
    audio->setVolume(0.5);
    ui->name_song->setText(mlist[positionm]);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete player;
    delete audio;
}


void MainWindow::on_play_clicked()
{
    player->play();
}


void MainWindow::on_pause_clicked()
{
    player->pause();
}


void MainWindow::on_next_clicked()
{

    if(positionm != (mlist.size()-1))
    {
        player->stop();
        delete player;
        player = new QMediaPlayer;
        player->setAudioOutput(audio);
        player->setSource(QUrl::fromLocalFile("C:/music/" + mlist[++positionm]));
        ui->name_song->setText(mlist[positionm]);
    }
    else
    {
        positionm = 0;
        delete player;
        player = new QMediaPlayer;
        player->setAudioOutput(audio);
        player->setSource(QUrl::fromLocalFile("C:/music/" + mlist[positionm]));
        ui->name_song->setText(mlist[positionm]);
        player->stop();
    }
    player->play();
}


void MainWindow::on_previous_clicked()
{

    if(positionm > 0)
    {
        player->stop();
        delete player;
        player = new QMediaPlayer;
        player->setAudioOutput(audio);
        player->setSource(QUrl::fromLocalFile("C:/music/" + mlist[--positionm]));
        ui->name_song->setText(mlist[positionm]);
    }
    else
    {
        positionm = (mlist.size() - 1);
        player->stop();
        delete player;
        player = new QMediaPlayer;
        player->setAudioOutput(audio);
        player->setSource(QUrl::fromLocalFile("C:/music/" + mlist[positionm]));
        ui->name_song->setText(mlist[positionm]);
        player->play();
    }
    player->play();
}

void MainWindow::on_sound_sliderMoved(int position)
{
    float pos1 = position;
    float val = pos1 /100;
    audio->setVolume(val);
}

