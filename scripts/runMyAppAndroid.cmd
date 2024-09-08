set deviceMyAppPath=/data/tmp/myapp

adb shell cat /proc/sys/kernel/core_pattern
adb shell cat /proc/sys/fs/suid_dumpable

adb shell "echo core > /proc/sys/kernel/core_pattern"
adb shell "echo 2  > /proc/sys/fs/suid_dumpable"

adb shell cat /proc/sys/kernel/core_pattern
adb shell cat /proc/sys/fs/suid_dumpable

adb shell "cd %deviceMyAppPath% && rm core"
adb shell "ls -l %deviceMyAppPath%"

rem adb shell "ulimit -c 99999999 && cd /data/tmp/myapp && ./myapp"
adb shell "cd %deviceMyAppPath% && ./myapp"

adb shell "ls -l %deviceMyAppPath%"
