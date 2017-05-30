#include <jni.h>
#include <string>

#include "com_example_kwrg_wificontroller_WiFiController.h"

JNIEXPORT jstring JNICALL Java_com_example_kwrg_wificontroller_WiFiController_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "C/C++ This is Wi-Fi Controller";
    return env->NewStringUTF(hello.c_str());
}
