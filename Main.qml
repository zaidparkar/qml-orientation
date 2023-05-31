import QtQuick
import Rotation

Window {
    id: window
    visible: true

    OrientationClass {
        id: myclass
    }

    Image{
        id: img
        width: window.width - 50
        height: window.width - 50
        anchors{centerIn: parent}
        rotation: 360 - myclass.angle
        source: "qrc:/android/assets/cat.jpeg"

        Behavior on rotation {
            NumberAnimation {
                duration: 100
            }
        }
    }

}
