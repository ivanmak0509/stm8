$list = usbipd wsl list | Select-String -Pattern "Link"
$busid = [regex]::Matches($list, "\d+-\d+").Value
usbipd wsl attach --busid $busid
echo "Attached device with bus-id: " $busid
