
adb shell "cat /proc/`pidof myapp`/limits"
adb shell "cd /data/tmp/myapp && ./prlimit `pidof myapp` 0 9999999 99999999"
adb shell "cat /proc/`pidof myapp`/limits"

