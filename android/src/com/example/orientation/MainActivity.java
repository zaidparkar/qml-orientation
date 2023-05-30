package com.example.orientation;

import org.qtproject.qt.android.bindings.QtActivity;
import android.os.Bundle;
import android.view.OrientationEventListener;

public class MainActivity extends QtActivity {

    public native void sendOrientationJNI(int angle);
    public OrientationEventListener myListener;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        myListener = new OrientationEventListener(this) {
            @Override
            public void onOrientationChanged(int i) {
                if(i >= 0) {
                    if(i == 90 || i == 180 || i == 270 || i == 0)
                        sendOrientationJNI(i);
                }
            }
        };
        myListener.enable();
    }

    protected void onDestroy() {
        super.onDestroy();
        myListener.disable();

    }
}
