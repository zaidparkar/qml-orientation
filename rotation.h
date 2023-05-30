#ifndef ROTATION_H
#define ROTATION_H

#include <QObject>

class Rotation : public QObject
{
    Q_OBJECT
public:
    explicit Rotation(QObject *parent = nullptr);

    int angleToRotate(int angle);

signals:
    void angleChanged(int angle);

};

#endif // ROTATION_H
