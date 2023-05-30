#include "rotation.h"
#include <QDebug>
#include <QJniObject>

Rotation* current = nullptr;

Rotation::Rotation(QObject *parent)
    : QObject{parent}
{
    current = this;
}


#ifdef __cplusplus
extern "C" {
#endif
JNIEXPORT void JNICALL
Java_com_example_orientation_MainActivity_sendOrientationJNI(JNIEnv *env, jobject obj, jint rotation) {

    qint32 newangle = rotation;
    emit current->angleChanged(newangle);

}
#ifdef __cplusplus
}
#endif
