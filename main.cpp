/*
 * Copyright (c) 2011-2012, Christian Lange
 * (chlange) <chlange@htwg-konstanz.de> <Christian_Lange@hotmail.com>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Christian Lange nor the names of its
 *       contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL CHRISTIAN LANGE BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <QtGui/QApplication>
#include <QtDebug>
#include "jeopardy.h"

QString rootPath;
QString gameStatePath;
QString backupPath;
QString soundPath;
QString imagesPath;
QString answersPath;

void makeDir(QDir dir) {
    if (!dir.exists()) {
        if(!dir.mkpath(".")) {
            QMessageBox::critical(0, "Error", QString("Unable to create directory %1. Please check the permissions "
                "of the directory or set the environment variable \"jeopardyRoot\" to specify a "
                "custom jeopardy home (i.e. export jeopardyRoot=/home/chlange/jeopardy).").arg(dir.path()));
            exit(1);
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString envRoot = qgetenv("jeopardyRoot").constData();
    if(envRoot.isEmpty())
        rootPath = "/usr/share/jeopardy";
    else
        rootPath = envRoot;

    gameStatePath = QString("%1/gameStates").arg(rootPath);
    backupPath = QString("%1/backups").arg(gameStatePath);
    soundPath = QString("%1/sound").arg(rootPath);
    imagesPath = QString("%1/images").arg(rootPath);
    answersPath = QString("%1/answers").arg(rootPath);

    makeDir(QDir(backupPath));
    makeDir(QDir(soundPath));
    makeDir(QDir(imagesPath));    
    makeDir(QDir(answersPath));
    
    a.setWindowIcon(QIcon(QString("%1/icon.svg").arg(imagesPath)));
    Jeopardy w;
    w.init();
    return a.exec();
}


