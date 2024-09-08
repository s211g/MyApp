patch llvm project:

D:\temp\llvm-project-17.0.1.src\lldb\source\Interpreter\OptionGroupPlatform.cpp

    if (m_platform_name == "remote-ohos") {
      ohos_platform = true;
      platform_sp = platforms.Create("remote-linux");
    } else
      platform_sp = platforms.Create(m_platform_name);



D:\temp\llvm-project-17.0.1.src\lldb\source\Host\posix\ConnectionFileDescriptorPosix.cpp

ConnectionStatus
ConnectionFileDescriptor::Connect(llvm::StringRef path,
                                  socket_id_callback_type socket_id_callback,
                                  Status *error_ptr) {

  if (!path.empty()) {
    Log *logPlatform = GetLog(LLDBLog::Platform);
    LLDB_LOGF(logPlatform, "ConnectionFileDescriptor::Connect path %s",
              path.str().c_str());
    const char *fport_cmd = std::getenv("LLDB_FPORT_CMD");
    LLDB_LOGF(logPlatform, "LLDB_FPORT_CMD : '%s' ",
              fport_cmd ? fport_cmd : "");
    std::cout << "ConnectionFileDescriptor::Connect path: "
              << path.str().c_str()
              << " LLDB_FPORT_CMD : " << (fport_cmd ? fport_cmd : "")
              << std::endl;

    std::string port; 
    auto pos = path.str().find(":");
    if (pos != std::string::npos) {
      port = path.str().substr(pos + 1);
    }

    if (fport_cmd) {
        std::string cmd = fport_cmd;        
        if (cmd == "adb") {
          cmd += " forward tcp:" + port + " tcp:" + port;
        } else if (cmd =="hdc") {
          cmd += " fport tcp:" + port + " tcp:" + port;
        } else {
          cmd += " " + port;
        }
        LLDB_LOGF(logPlatform, "System cmd: '%s' ", cmd.c_str());
        std::cout << "System cmd : " << cmd << std::endl;
        std::system(cmd.c_str());
        LLDB_LOGF(logPlatform, "System cmd end ");
    } else if (ohos_platform) {
      std::string cmd = "adb";
      cmd += " forward tcp:" + port + " tcp:" + port;
      LLDB_LOGF(logPlatform, "Default ohos port forwarding, system cmd: '%s' ",
                cmd.c_str());
      std::cout << "Default ohos system cmd : " << cmd << std::endl;
      std::system(cmd.c_str());
      LLDB_LOGF(logPlatform, "System cmd end ");
    }
  }


D:\temp\llvm-project-17.0.1.src\lldb\source\Plugins\Process\elf-core\ProcessElfCore.cpp

  default:
    return parseLinuxNotes(*notes_or_error);
    //return llvm::make_error<llvm::StringError>(
    //    "Don't know how to parse core file. Unsupported OS.",
    //    llvm::inconvertibleErrorCode());
  }
}



