import QtQuick
import Rotation

Window {
    id: window
    visible: true

    OrientationClass {
        id: myclass
    }

    Connections {
        target: myclass
        function onAngleChanged(angle) {
            img.rotation = Math.abs(360 - angle)
        }
    }

    Image{
        id: img
        width: window.width - 50
        height: window.width - 50
        anchors{centerIn: parent}
        source: "qrc:/android/assets/cat.jpeg"
        Behavior on rotation {
            NumberAnimation {
                duration: 100
            }
        }
    }
}
