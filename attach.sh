#!/bin/bash
powershell.exe Set-ExecutionPolicy -Scope CurrentUser -ExecutionPolicy Unrestricted
powershell.exe ./wsl-attach.ps1 Link
