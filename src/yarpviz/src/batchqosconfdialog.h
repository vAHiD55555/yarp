/*
 * Copyright (C) 2006-2019 Istituto Italiano di Tecnologia (IIT)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef BATCHQOSCONFDIALOG_H
#define BATCHQOSCONFDIALOG_H

#include <QDialog>
#include <yarp/profiler/NetworkProfiler.h>

namespace Ui {
class BatchQosConfDialog;
}

class BatchQosConfDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BatchQosConfDialog(QWidget *parent = 0);
    ~BatchQosConfDialog();

private slots:
    void openCons();
    void updateQos();
    void configureQos();

private:
    Ui::BatchQosConfDialog *ui;
    yarp::profiler::graph::Graph* graph;
};

#endif // BATCHQOSCONFDIALOG_H
