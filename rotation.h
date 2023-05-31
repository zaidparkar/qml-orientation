#ifndef ROTATION_H
#define ROTATION_H

#include <QObject>

class Rotation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int angle READ angle WRITE setAngle NOTIFY angleChanged)

public:
    explicit Rotation(QObject *parent = nullptr);

    int angle();
    void setAngle(int newAngle);

signals:
    void angleChanged(int newAngle);

private:
    int rotation;

};

#endif // ROTATION_H
