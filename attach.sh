#!/bin/bash
powershell.exe Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted
powershell.exe ./wsl-attach-stlink.ps1
