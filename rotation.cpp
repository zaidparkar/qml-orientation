#include "rotation.h"
#include <QDebug>
#include <QJniObject>

Rotation* current = nullptr;

Rotation::Rotation(QObject *parent)
    : QObject{parent}
{
    current = this;
    setAngle(0);
}

int Rotation::angle()
{
    return rotation;
}

void Rotation::setAngle(int newAngle)
{
    rotation = newAngle;
    emit angleChanged(newAngle);
}


#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT void JNICALL
Java_com_example_orientation_MainActivity_sendOrientationJNI(JNIEnv *env, jobject obj, jint rotation) {

    qint32 newangle = rotation;
    current->setAngle(newangle);

}
#ifdef __cplusplus
}
#endif
