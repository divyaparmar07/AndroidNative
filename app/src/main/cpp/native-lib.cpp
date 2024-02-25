#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_androidnative_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_androidnative_MainActivity_sendYourName(JNIEnv *env, jobject thiz,
                                                         jstring first_name, jstring last_name) {
    // TODO: implement sendYourName()
    char returnString[20];
    const char *fN = env->GetStringUTFChars(first_name, NULL);
    const char *lN = env->GetStringUTFChars(last_name, NULL);

    strcpy(returnString,fN); // copy string one into the result.
    strcat(returnString,lN); // append string two to the result.

    env->ReleaseStringUTFChars(first_name, fN);
    env->ReleaseStringUTFChars(last_name, lN);

    // __android_log_write(ANDROID_LOG_DEBUG, "API123", returnString);

    return env->NewStringUTF(returnString);
}
extern "C"
JNIEXPORT jobjectArray JNICALL
Java_com_example_androidnative_MainActivity_stringArrayFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringArrayFromJNI()

    char *days[]={"Java","Android","Django","SQL","Swift","Kotlin","Springs"};

    jstring str;
    jobjectArray day = 0;
    jsize len = 7;
    int i;

    day = env->NewObjectArray(len,env->FindClass("java/lang/String"),0);

    for(i=0;i<7;i++)
    {
        str = env->NewStringUTF(days[i]);
        env->SetObjectArrayElement(day,i,str);
    }

    return day;
}