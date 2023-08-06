$stlinklist = usbipd wsl list | Select-String -Pattern "CH34"
$busid = [regex]::Matches($stlinklist, "\d+-\d+").Value
usbipd wsl attach --busid $busid
echo "Attached device with bus-id: " $busid