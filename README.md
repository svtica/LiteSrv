# LiteSrv

[![GitHub release](https://img.shields.io/github/v/release/svtica/LiteSrv)](https://github.com/svtica/LiteSrv/releases/latest)
[![Build Status](https://img.shields.io/github/actions/workflow/status/svtica/LiteSrv/build-and-release.yml)](https://github.com/svtica/LiteSrv/actions)
[![Part of LiteSuite](https://img.shields.io/badge/part%20of-LiteSuite-blue)](https://github.com/svtica/LiteSuite)
[![License: Unlicense](https://img.shields.io/badge/license-Unlicense-green.svg)](LICENSE)

**Lightweight Windows service wrapper for converting applications into managed Windows services.**

LiteSrv is a utility library and executable that enables any application to run as a Windows service with proper service lifecycle management, logging, and configuration capabilities.

## Features

### Service Management
- **Application Wrapping**: Convert any executable into a Windows service
- **Service Lifecycle**: Proper handling of start, stop, pause, and continue operations
- **Dependency Management**: Configure service dependencies and startup order
- **Recovery Options**: Automatic restart and recovery configuration

### Configuration
- **XML Configuration**: Flexible XML-based configuration system
- **Runtime Parameters**: Pass arguments and environment variables to wrapped applications
- **Working Directory**: Set custom working directories for services
- **User Context**: Run services under specific user accounts

### Monitoring & Control
- **Process Monitoring**: Monitor wrapped application health and status
- **Automatic Restart**: Restart failed applications automatically
- **Resource Limits**: Configure memory and CPU limits for wrapped processes
- **Event Logging**: Integration with Windows Event Log

### Integration
- **Command Line Tools**: Service installation, configuration, and management utilities
- **Library Mode**: Can be integrated into other applications as a component
- **WMI Support**: Expose service information through WMI
- **Performance Counters**: Optional performance counter integration

## Installation

1. Download the latest release
2. Extract files to desired location
3. Configure service wrapper settings
4. Install service using provided tools

## Usage

### Basic Service Wrapping
```cmd
LiteSrv.exe install -name "MyService" -exe "C:\MyApp\app.exe" -args "/service"
```

### Advanced Configuration
```cmd
LiteSrv.exe install -name "MyService" -config "service.xml"
```

### Service Management
```cmd
LiteSrv.exe start MyService
LiteSrv.exe stop MyService
LiteSrv.exe uninstall MyService
```

## Configuration File

Create an XML configuration file for advanced service setup:

```xml
<?xml version="1.0" encoding="utf-8"?>
<ServiceConfiguration>
  <Service>
    <n>MyCustomService</n>
    <DisplayName>My Custom Application Service</DisplayName>
    <Description>Custom application running as a service</Description>
    <StartMode>Automatic</StartMode>
  </Service>
  <Application>
    <Executable>C:\MyApp\app.exe</Executable>
    <Arguments>/service /verbose</Arguments>
    <WorkingDirectory>C:\MyApp</WorkingDirectory>
    <Environment>
      <Variable name="CONFIG_PATH" value="C:\MyApp\config" />
    </Environment>
  </Application>
  <Recovery>
    <EnableAutoRestart>true</EnableAutoRestart>
    <RestartDelay>30</RestartDelay>
    <MaxRestartAttempts>3</MaxRestartAttempts>
  </Recovery>
</ServiceConfiguration>
```

## Command Line Options

```
LiteSrv.exe <command> [options]

Commands:
  install         Install a new service
  uninstall       Remove an existing service
  start           Start a service
  stop            Stop a service
  restart         Restart a service
  status          Show service status

Options:
  -name <n>           Service name
  -exe <path>            Executable to wrap
  -args <arguments>      Command line arguments
  -config <file>         Configuration file path
  -user <username>       Service account username
  -password <password>   Service account password
  -auto                  Set automatic startup
  -manual                Set manual startup
  -disabled              Disable service
```

## Technology Stack

- **Platform**: Windows (C++ with .NET interop)
- **Service APIs**: Windows Service Control Manager (SCM)
- **Configuration**: XML with schema validation
- **Logging**: Windows Event Log, file logging

## Development Status

This project is **Work in Progress** and **not actively developed**. Core functionality is stable but some advanced features may be incomplete. Moderate contributions are accepted for improvements and bug fixes.

## System Requirements

- Windows 7 or later
- Administrative privileges for service installation
- .NET Framework 4.5 or higher (for some components)

## Best Practices

### Service Configuration
- Use descriptive service names and display names
- Configure appropriate startup types for your requirements
- Set proper service dependencies when needed
- Use dedicated service accounts with minimal privileges

### Application Compatibility
- Ensure wrapped applications can run without user interaction
- Handle Windows session changes appropriately
- Implement proper shutdown procedures in wrapped applications
- Avoid GUI elements in service mode

### Security
- Run services with least required privileges
- Use dedicated service accounts rather than system accounts
- Secure configuration files with appropriate permissions
- Monitor service behavior and logs regularly

## Troubleshooting

### Common Issues
- **Service Won't Start**: Check executable path and permissions
- **Access Denied**: Verify service account permissions
- **Application Crashes**: Review application logs and compatibility
- **Resource Issues**: Monitor memory and CPU usage

### Debugging
- Enable verbose logging in configuration
- Check Windows Event Log for service-related events
- Use service status commands to monitor state
- Review wrapped application logs

## License

This software is released under [The Unlicense](LICENSE) - public domain.

---

*LiteSrv simplifies the process of running applications as Windows services with professional service management capabilities.*

## 🌟 Part of LiteSuite

This tool is part of **[LiteSuite](https://github.com/svtica/LiteSuite)** - a comprehensive collection of lightweight Windows administration tools.

### Other Tools in the Suite:
- **[LiteTask](https://github.com/svtica/LiteTask)** - Advanced Task Scheduler Alternative  
- **[LitePM](https://github.com/svtica/LitePM)** - Process Manager with System Monitoring
- **[LiteDeploy](https://github.com/svtica/LiteDeploy)** - Network Deployment and Management
- **[LiteRun](https://github.com/svtica/LiteRun)** - Remote Command Execution Utility
- **[LiteSrv](https://github.com/svtica/LiteSrv)** - Windows Service Wrapper

### 📦 Download the Complete Suite
Get all tools in one package: **[LiteSuite Releases](https://github.com/svtica/LiteSuite/releases/latest)**

---

*LiteSuite - Professional Windows administration tools for modern IT environments.*
